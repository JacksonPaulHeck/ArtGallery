#include "gallery.h"

Gallery :: Gallery(){
    vector<Picture> art;

    this->height = 0;
    this->width = 0;
    this->art = art;
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
void Gallery :: addArt(Picture picture){
    this->art.push_back(picture);
};
void Gallery :: removeArt(int id){
    this->art.pop_back();
};