#include "driver.h"

using namespace std;

int main(int argc, char ** argv) {
    Gallery gallery;
    vector<Picture> pictures; 
    if(argc != 1){
        parseFile(argv[1], gallery, pictures);
        bruteforce(gallery, pictures, argv[2]);
        highvalue(gallery, pictures, argv[3]);
        custom(gallery, pictures, argv[4]);
    }
    return 0;
}
