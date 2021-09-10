#include "gallery.h"
#include <fstream>
#include <string>
#include <vector>

void parseFile(char *, Gallery &, vector<Picture> &);
void bruteforce(Gallery, vector<Picture>, char *);
void highvalue(Gallery, vector<Picture>, char *);
void custom(Gallery, vector<Picture>, char *);
int getCost(Gallery &);
void genPermutations(vector<vector<Picture>>&, vector<Picture>&, int, int);