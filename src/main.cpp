#include "driver.h"

using namespace std;

int main(int argc, char ** argv) {
    Gallery gallery;
    vector<Picture> pictures; 
    const char * bruteforceOutput = "./output/test-bruteforce.txt";
    const char * highvalueOutput = "./output/test-highvalue.txt";
    const char * customOutput = "./output/test-custom.txt";
    if(argc != 1){
        parseFile(argv[1], gallery, pictures);
        bruteforce(gallery, pictures, bruteforceOutput);
        highvalue(gallery, pictures, highvalueOutput);
        custom(gallery, pictures, customOutput);
    }
    return 0;
}
