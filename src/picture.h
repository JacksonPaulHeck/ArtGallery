#include <iostream>
struct Coordinate {
    int x, y;
};

class Picture {
    private:
        int id;
        int price;
        int width;
        int height;
        Coordinate coordinates;

    public:
        Picture();
        Picture(int, int, int, int);
        Picture(const Picture&);
        Picture& operator=(const Picture&);
        int getID();
        int getPrice();
        int getWidth();
        int getHeight();
        Coordinate getCoordinates();
        void setID(int);
        void setPrice(int);
        void setWidth(int);
        void setHeight(int);
        void setCoordinates(Coordinate);
        void showPicture();
};