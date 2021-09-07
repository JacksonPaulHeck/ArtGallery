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

int main(int argc, char ** argv) {
    Gallery gallery;
    vector<Picture> pictures; 
    if(argc != 1){
        parseFile(argv[1], gallery, pictures);
        bruteforce(gallery, pictures, argv[2]);
        highvalue(gallery, pictures, argv[3]);
        custom(gallery, pictures, argv[4]);
        for(int i = 0; i < pictures.size(); i++){
            gallery.addArt(pictures[i]);
        }

        int cost = getCost(gallery);
        cout << "Art in Gallery: Cost: " << cost << endl;
        gallery.showArt();
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
        gallery.setWidth(stoi(line));
        getline(myfile, line);
        gallery.setHeight(stoi(line));
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
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;

    


    for(int i = 0; i < gallery.getArt().size(); i++) {
        outFile << gallery.getArt()[i].getID() << " " << gallery.getArt()[i].getPrice() << " " << gallery.getArt()[i].getHeight() << " " << gallery.getArt()[i].getWidth() << endl;
    }
    outFile.close();
}

void highvalue (Gallery gallery, vector<Picture> pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;

   //get highest cost from vector
   //add to gallery
   //loop
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
        gallery.addArt(pictures[j]);
    }

    for(int i = 0; i < gallery.getArt().size(); i++) {
        outFile << gallery.getArt()[i].getID() << " " << gallery.getArt()[i].getPrice() << " " << gallery.getArt()[i].getHeight() << " " << gallery.getArt()[i].getWidth() << endl;
    }
    outFile.close();
}

void custom (Gallery gallery, vector<Picture> pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;

    


    for(int i = 0; i < gallery.getArt().size(); i++) {
        outFile << gallery.getArt()[i].getID() << " " << gallery.getArt()[i].getPrice() << " " << gallery.getArt()[i].getHeight() << " " << gallery.getArt()[i].getWidth() << endl;
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
