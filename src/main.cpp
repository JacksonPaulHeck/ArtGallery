#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gallery.h"

using namespace std;

void parseFile(char *, Gallery &, vector<Picture> &);
void bruteforce(Gallery &, vector<Picture> &, char *);
void highvalue(Gallery &, vector<Picture> &, char *);
void custom(Gallery &, vector<Picture> &, char *);


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
            Picture picture(id, price, height, width);
            pictures.push_back(picture);
        }
    } else {
        cout << "Unable to open file";
    }
    myfile.close();
}

void bruteforce (Gallery & gallery, vector<Picture> & pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;
    for(int i = 0; i < pictures.size(); i++) {
        outFile << pictures[i].getID() << " " << pictures[i].getPrice() << " " << pictures[i].getHeight() << " " << pictures[i].getWidth() << endl;
    }
    outFile.close();
}

void highvalue (Gallery & gallery, vector<Picture> & pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;
    for(int i = 0; i < pictures.size(); i++) {
        outFile << pictures[i].getID() << " " << pictures[i].getPrice() << " " << pictures[i].getHeight() << " " << pictures[i].getWidth() << endl;
    }
    outFile.close();
}

void custom (Gallery & gallery, vector<Picture> & pictures, char* outputFile) {
    ofstream outFile(outputFile);
    outFile << gallery.getHeight() << endl;
    outFile << gallery.getWidth() << endl;
    for(int i = 0; i < pictures.size(); i++) {
        outFile << pictures[i].getID() << " " << pictures[i].getPrice() << " " << pictures[i].getHeight() << " " << pictures[i].getWidth() << endl;
    }
    outFile.close();
}