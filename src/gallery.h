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
};

class Gallery {
    private:
        int width;
        int height;
        vector<Picture> art;
        //Bin Packing
        Node root;
        Node * insert(Node *, Picture &);
    public:
        Gallery();
        Gallery& operator=(const Gallery&);
        int getHeight();
        int getWidth();
        vector<Picture> getArt();
        void setHeight(int);
        void setWidth(int);
        void addArt(Picture &);
        //Bin Packing
        void init(int, int);
        Node * insert(Picture & picture);
        void deleteTree();
        void deleteTree(Node *);
};
