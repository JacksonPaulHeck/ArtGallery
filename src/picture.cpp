#include "picture.h"

Picture :: Picture(){
    this->id = 0;
    this->width = 0;
    this->height = 0;
    this->price = 0;
    this->coordinates = {0, 0};
}

Picture :: Picture(int id, int price, int width, int height){
    this->id = id;
    this->price = price;
    this->height = height;
    this->width = width;
}

int Picture :: getID(){
    return this->id;
}

int Picture :: getPrice(){
    return this->price;
}

int Picture :: getHeight(){
    return this->height;
}

int Picture :: getWidth(){
    return this->width;
}

Coordinate Picture :: getCoordinates(){
    return this->coordinates;
}

void Picture :: setID(int id){
    this->id = id;
}

void Picture :: setPrice(int price){
    this->price = price;
}

void Picture :: setHeight(int height){
    this->height = height;
}

void Picture :: setWidth(int width){
    this->width = width;
}

void Picture :: setCoordinates(int x, int y){
    this->coordinates.x = x;
    this->coordinates.y = y;
}
