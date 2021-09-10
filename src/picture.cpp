#include "picture.h"
#include <cstdio>

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
    this->coordinates = {0, 0};
}

Picture :: Picture(const Picture& orig) {
    this->id = orig.id;
    this->price = orig.price;
    this->height = orig.height;
    this->width = orig.width;
    this->coordinates = orig.coordinates;
}

Picture& Picture :: operator=(const Picture& orig) {
    this->id = orig.id;
    this->price = orig.price;
    this->height = orig.height;
    this->width = orig.width;
    this->coordinates = orig.coordinates;
    return *this;
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

void Picture :: setCoordinates(Coordinate spot){
    this->coordinates.x = spot.x;
    this->coordinates.y = spot.y;

}
