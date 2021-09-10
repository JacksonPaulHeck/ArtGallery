#include "gallery.h"
#include <fstream>
#include <string>
#include <vector>

void parseFile(char *, Gallery &, vector<Picture> &);
void bruteforce(Gallery, vector<Picture>, const char *);
void highvalue(Gallery, vector<Picture>, const char *);
void custom(Gallery, vector<Picture>, const char *);
int getCost(Gallery &);
void genPermutations(vector<vector<Picture>>&, vector<Picture>&, int, int);