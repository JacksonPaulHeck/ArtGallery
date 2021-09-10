#include "gallery.h"

Gallery :: Gallery(){
    vector<Picture> art;

    this->height = 0;
    this->width = 0;
    this->art = art;


    this->root = Node();
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
    this->art.push_back(picture);
};

void Gallery :: init(int width, int height){
    Coordinate init = {0,0};
    this->width = width;
    this->height = height;
    root.left = root.right = 0;
    root.x = root.y = 0;
    root.width = width;
    root.height = height;
};

Node * Gallery :: insert(Picture & picture){
    return insert(&root, picture);
};


Node * Gallery :: insert(Node* node, Picture & picture){
    int width = picture.getWidth();
    int height = picture.getHeight();
    node->picture = picture;
    node->picture.setCoordinates({node->x, node->y});
    if(node->left || node->right){
        if(node->left){
            Node * newNode = insert(node->left, picture);
            if(newNode){
                return newNode;
            }
        }if(node->right){
            Node * newNode = insert(node->right, picture);
            if(newNode){
                return newNode;
            }
        }
        return 0;
    }
    if(width > node->width || height > node->height){
        return 0;
    }
    int w = node->width - width;
    int h = node->height - height;
    node->left = new Node();
    node->right = new Node();
    if(w <= h){
        node->left->x = node->x + width;
        node->left->y = node->y;
        node->left->width = w;
        node->left->height = height;
        node->left->picture = picture;
        node->left->picture.setCoordinates({node->x + width, node->y});

        node->right->x = node->x;
        node->right->y = node->y + height;
        node->right->width = node->width;
        node->right->height = h;
        node->right->picture = picture;
        node->right->picture.setCoordinates({node->x, node->y + height});
    }else{
        node->left->x = node->x;
		node->left->y = node->y + height;
		node->left->width = width;
		node->left->height = h;
        node->left->picture = picture;
        node->left->picture.setCoordinates({node->x, node->y + height});

		node->right->x = node->x + width;
		node->right->y = node->y;
		node->right->width = w;
		node->right->height = node->height;
        node->right->picture = picture;
        node->right->picture.setCoordinates({node->x + width, node->y});
    }
    node->width = width;
    node->height = height;
    addArt(node->picture);
    return node;
};

void Gallery :: deleteTree(Node * node){
    if (node == nullptr){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);    
    delete node;
    return;
};
void Gallery :: deleteTree(){
    deleteTree(&this->root);
};
