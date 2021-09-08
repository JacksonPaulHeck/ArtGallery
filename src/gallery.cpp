#include "gallery.h"

Gallery :: Gallery(){
    vector<Picture> art;

    this->height = 0;
    this->width = 0;
    this->art = art;
};
Gallery& Gallery:: operator=(const Gallery& orig) {
    this->height = orig.height;
    this->width = orig.width;

    for (int i = 0; i < orig.art.size(); i++) {
        this->art.push_back(orig.art[i]);
    }

    return *this;
};
int Gallery :: getHeight(){
    return this->height;
};
int Gallery :: getWidth(){
    return this->width;
};
vector<Picture> Gallery :: getArt(){
    return this->art;
};
void Gallery :: setHeight(int height){
    this->height = height;
};
void Gallery :: setWidth(int width){
    this->width = width;
};
void Gallery :: addArt(Picture & picture){
    if(this->art.size() == 0){
        picture.setCoordinates({0, 0});
        this->art.push_back(picture);
    }else if(findSpot(picture)){
        this->art.push_back(picture);
    }
};
void Gallery :: removeArt(int id){
    this->art.pop_back();
};
void Gallery :: showArt(){
    cout << "Size of Gallery: "
         << this->width
         << ", "
         << this->height
         << endl;
    for(int i = 0; i < art.size(); i++){
        cout << "ID: " << this->art[i].getID();
        cout << "   Coordinates: " 
             << this->art[i].getCoordinates().x
             << ", "
             << this->art[i].getCoordinates().y;
        cout << "   Size:"
             << this->art[i].getWidth()
             << ", "
             << this->art[i].getHeight()
             << endl;
    }
}
bool Gallery :: findSpot(Picture& picture){
    Coordinate l1, r1, l2, r2 = {0,0};
    for(int h = 0; h < this->height; h++){
        for(int w = 0; w < this->width; w++){
                l2 = {w, h};
                r2 = {
                        w + picture.getWidth(),
                        h + picture.getHeight()
                };
            if(r2.x < this->width && r2.y < this->height){
                bool condition = true;
                for(int i = 0; i < this->art.size(); i++){
                    l1 = art[i].getCoordinates();
                    r1 = {
                            art[i].getCoordinates().x + art[i].getWidth(), 
                            art[i].getCoordinates().y + art[i].getHeight()
                    };
    
                    if(isOverlap(l1, r1, l2, r2)){
                        condition = false;
                    }
                }
                if(condition == true){
                    picture.setCoordinates({w, h});
                    return true;
                }
            }
        }
    }
    return false;
}

bool Gallery :: isOverlap (Coordinate l1, Coordinate r1, Coordinate l2, Coordinate r2){
    if (l1.x == r1.x || l1.y == r1.y || l2.x == r2.x || l2.y == r2.y) {
        //cout << "is line" << endl;
        return true;
    }
    if (l2.x < r1.x && l2.y < r1.y){
        /*
         * cout << "L2: " << l2.x << ", " << l2.y
         * << " R2: " << r2.x << ", " << r2.y
         * << " R1: " << r1.x << ", " << r1.y
         * << " L1: " << l1.x << ", " << l1.y
         * << endl;
        */
        return true;
    }
    
    //cout << "Not Overlap" << endl;
    return false;
}
