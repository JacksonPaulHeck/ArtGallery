#include "picture.h"
#include <vector>

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
        void addArt(Picture);
        void removeArt(int);
};