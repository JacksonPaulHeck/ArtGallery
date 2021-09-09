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
};

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
                        w = w + art[i].getWidth();
                        if(w == this->width - 1){
                            h = h + art[i].getHeight();
                        }
                        condition = false;
                    }
                    
                }
                if(condition == true){
                    picture.setCoordinates({w, h});
                    return true;
                }
                w--;
            }
        }
    }
    return false;
};

bool Gallery :: isOverlap (Coordinate l1, Coordinate r1, Coordinate l2, Coordinate r2){
    if (l1.x == r1.x || l1.y == r1.y || l2.x == r2.x || l2.y == r2.y) {
        return true;
    }
    if (l2.x < r1.x && l2.y < r1.y){
        return true;
    }
    return false;
};

void Gallery :: Init(int width, int height){
    Coordinate init = {0,0};
    this->width = width;
    this->height = height;
    root.left = root.right = 0;
    root.x = root.y = 0;
    root.width = width;
    root.height = height;
};

Node * Gallery :: Insert(Picture & picture){
    return Insert(&root, picture);
};


Node * Gallery :: Insert(Node* node, Picture & picture){
    int width = picture.getWidth();
    int height = picture.getHeight();
    node->picture = picture;
    node->picture.setCoordinates({node->x, node->y});
    if(node->left || node->right){
        if(node->left){
            Node * newNode = Insert(node->left, picture);
            if(newNode){
                return newNode;
            }
        }if(node->right){
            Node * newNode = Insert(node->right, picture);
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
        
        node->left->isPlaced = true;
        node->right->isPlaced = false;
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

        node->left->isPlaced = false;
        node->right->isPlaced = false;
    }
    node->width = width;
    node->height = height;
    addArt(node->picture);
    return node;
};

void Gallery :: Traverse(Node * node){
    if (node == nullptr){
        return;
    }
    Traverse(node->left);
    Traverse(node->right);
};

void Gallery :: Delete(Node * node){
    if (node == nullptr){
        return;
    }
    Delete(node->left);
    Delete(node->right);    
    delete node;
    return;
};
void Gallery :: Show(){
    Traverse(&this->root);
};
void Gallery :: Delete(){
    Delete(&this->root);
};




