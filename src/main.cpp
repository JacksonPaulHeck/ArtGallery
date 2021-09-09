#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gallery.h"

using namespace std;

void parseFile(char *, Gallery &, vector<Picture> &);
void bruteforce(Gallery, vector<Picture>, char *);
void highvalue(Gallery, vector<Picture>, char *);
void custom(Gallery, vector<Picture>, char *);
int getCost(Gallery &);
void genPermutations(vector<vector<Picture>>&, vector<Picture>&, int, int);

int main(int argc, char ** argv) {
    Gallery gallery;
    vector<Picture> pictures; 
    if(argc != 1){
        parseFile(argv[1], gallery, pictures);
        bruteforce(gallery, pictures, argv[2]);
        highvalue(gallery, pictures, argv[3]);
        custom(gallery, pictures, argv[4]);
    }
    else {
        cout << "No Input or Output files given" << endl;
    }
    return 0;
}

void parseFile (char * filename, Gallery & gallery, vector<Picture> & pictures){
    string line;
    int id, price, height, width, numOfPictures;
    ifstream myfile (filename);
    if(myfile.is_open()) {
        getline(myfile, line, ' ');
        int w = stoi(line);
        getline(myfile, line);
        int h = stoi(line);
        gallery.init(w, h);
        getline(myfile, line);
        numOfPictures = stoi(line);
        for (int i = 0; i < numOfPictures; i++){
            getline(myfile, line, ' ');
            id = stoi(line);
            getline(myfile, line, ' ');
            price = stoi(line);
            getline(myfile, line, ' ');
            width = stoi(line);
            getline(myfile, line);
            height = stoi(line);
            Picture picture(id, price, width, height);
            pictures.push_back(picture);
        }
    } else {
        cout << "Unable to open file";
    }
    myfile.close();
}

void bruteforce (Gallery gallery, vector<Picture> pictures, char* outputFile) {
    ofstream outFile(outputFile);
    if(pictures.size() <= 10){
        outFile << gallery.getHeight() << endl;
        outFile << gallery.getWidth() << endl;
        vector<Gallery> possGalleries;
        vector<vector<Picture>> possPerms;
        genPermutations(possPerms, pictures, pictures.size(), pictures.size());
        int maxPrice = 0;

        for (int i = 0; i < possPerms.size(); i++) {
            Gallery currentGall;
            currentGall.init(gallery.getWidth(), gallery.getHeight());
            for (int j = 0; j < possPerms[i].size(); j++) {
                currentGall.insert(possPerms[i][j]);
            }

            int currentGallPrice = getCost(currentGall);

            if (currentGallPrice > maxPrice) {
                maxPrice = currentGallPrice;
                gallery = currentGall;
            }
        }

        outFile << getCost(gallery) << endl;

        for(int i = 0; i < gallery.getArt().size(); i++) {
            outFile << gallery.getArt()[i].getID() 
                << " " 
                << gallery.getArt()[i].getPrice() 
                << " " 
                << gallery.getArt()[i].getWidth() 
                << " " 
                << gallery.getArt()[i].getHeight()  
                << " " 
                << gallery.getArt()[i].getCoordinates().x 
                << " " 
                << gallery.getArt()[i].getCoordinates().y
                <<  endl;
        }
    }else{
        outFile << "data set size exceeds maximum" << endl;
    }
    outFile.close();

}

void highvalue (Gallery gallery, vector<Picture> pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;
    for(int r = 0; r < pictures.size()-1; r++){
        int max = r;
        for(int k = r; k < pictures.size(); k++){
            if(pictures[max].getPrice() < pictures[k].getPrice()){
                max = k;
            }
        }
        Picture temp(pictures[r].getID(), pictures[r].getPrice(), pictures[r].getWidth(), pictures[r].getHeight());
 
        pictures[r].setWidth(pictures[max].getWidth());
        pictures[r].setHeight(pictures[max].getHeight());
        pictures[r].setCoordinates(pictures[max].getCoordinates());
        pictures[r].setPrice(pictures[max].getPrice());
        pictures[r].setID(pictures[max].getID());

        pictures[max].setWidth(temp.getWidth());
        pictures[max].setHeight(temp.getHeight());
        pictures[max].setCoordinates(temp.getCoordinates());
        pictures[max].setPrice(temp.getPrice());
        pictures[max].setID(temp.getID());
        

    }

    for(int j = 0; j < pictures.size(); j++){
        gallery.insert(pictures[j]);
    }

    outFile << getCost(gallery) << endl;

    for(int i = 0; i < gallery.getArt().size(); i++) {
        outFile << gallery.getArt()[i].getID() 
                << " " 
                << gallery.getArt()[i].getPrice() 
                << " " 
                << gallery.getArt()[i].getWidth() 
                << " " 
                << gallery.getArt()[i].getHeight()  
                << " " 
                << gallery.getArt()[i].getCoordinates().x 
                << " " 
                << gallery.getArt()[i].getCoordinates().y
                <<  endl;
    }
    outFile.close();
}

void custom (Gallery gallery, vector<Picture> pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;
    for(int r = 0; r < pictures.size()-1; r++){
        int max = r;
        for(int k = r; k < pictures.size(); k++){
            double ratioMax = pictures[max].getPrice() * 1.0 / (pictures[max].getWidth() * pictures[max].getHeight());
            double ratioK = pictures[k].getPrice() * 1.0 / (pictures[k].getWidth() * pictures[k].getHeight());
            if( ratioMax < ratioK){
                max = k;
            }
        }
        Picture temp(pictures[r].getID(), pictures[r].getPrice(), pictures[r].getWidth(), pictures[r].getHeight());
 
        pictures[r].setWidth(pictures[max].getWidth());
        pictures[r].setHeight(pictures[max].getHeight());
        pictures[r].setCoordinates(pictures[max].getCoordinates());
        pictures[r].setPrice(pictures[max].getPrice());
        pictures[r].setID(pictures[max].getID());

        pictures[max].setWidth(temp.getWidth());
        pictures[max].setHeight(temp.getHeight());
        pictures[max].setCoordinates(temp.getCoordinates());
        pictures[max].setPrice(temp.getPrice());
        pictures[max].setID(temp.getID());
    }

    for(int j = 0; j < pictures.size(); j++){
        gallery.insert(pictures[j]);
    }

    outFile << getCost(gallery) << endl;

    for(int i = 0; i < gallery.getArt().size(); i++) {
        outFile << gallery.getArt()[i].getID() 
                << " " 
                << gallery.getArt()[i].getPrice() 
                << " " 
                << gallery.getArt()[i].getWidth() 
                << " " 
                << gallery.getArt()[i].getHeight()  
                << " " 
                << gallery.getArt()[i].getCoordinates().x 
                << " " 
                << gallery.getArt()[i].getCoordinates().y
                <<  endl;
    }
    outFile.close();
}

int getCost(Gallery & gallery){
    int total = 0;
    for (int i = 0; i < gallery.getArt().size(); i++){
        total = total + gallery.getArt()[i].getPrice();
    }
    return total;
}

void genPermutations(vector<vector<Picture>>& allPerms, vector<Picture>& perm, int size, int n) {

    if (size == 1) {
        allPerms.push_back(perm);
        return;
    }

    for (int i = 0; i < size; i++) {
        genPermutations(allPerms, perm, size - 1, n);

        //if size is odd, swap first and last element
        if (size % 2 == 1) {
            Picture temp = perm[0];
            perm[0] = perm[size - 1];
            perm[size - 1] = temp;
        }
        //if size is even, swap ith and last element
        else {
            Picture temp = perm[i];
            perm[i] = perm[size - 1];
            perm[size - 1] = temp;
        }
    }
    
}
