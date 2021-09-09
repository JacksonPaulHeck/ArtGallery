#include "picture.h"
#include <vector>
#include <iostream>

using namespace std;

struct Node{
    Node * left;
    Node * right;
    int x;
    int y;
    int width;
    int height;
    Picture picture;
    bool isPlaced;
};

class Gallery {
    private:
        int width;
        int height;
        vector<Picture> art;
        //Bin Packing
        Node root;
        int binWidth;
        int binHeight;
        Node *Insert(Node *, Picture &);
    public:
        Gallery();
        Gallery& operator=(const Gallery&);
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
        //Bin Packing
        void Init(int, int);
        Node * Insert(Picture & picture);
        //Node * Insert(int, int);
        void Show();
        void Traverse(Node *);
        void Delete();
        void Delete(Node *);
};
