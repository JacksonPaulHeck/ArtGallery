#include "picture.h"
#include <vector>
#include <iostream>

using namespace std;

class Gallery {
    private:
        int width;
        int height;
        vector<Picture> art;
    public:
        Gallery();
        int getHeight();
        int getWidth();
        vector<Picture> getArt();
        void setHeight(int);
        void setWidth(int);
        void addArt(Picture &);
        void removeArt(int);
        void showArt();
        bool findSpot(Picture &);
        bool isOverlap(Coordinate, Coordinate, Coordinate, Coordinate);
};
