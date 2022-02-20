#ifndef INC_PRINTPLAN
#define INC_PRINTPLAN

#include <iostream>
#include "node.hpp"
using namespace std;

void printPlan(int** rawPlan, int width, int height, bool findPath, node* resultNodeA, node* resultNodeB);

#endif
