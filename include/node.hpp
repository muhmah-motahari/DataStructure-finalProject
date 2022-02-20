#ifndef INC_NODE
#define INC_NODE

#include <iostream>
using namespace std;

struct node{
    pair<int,int> position;
    struct node* one;
    struct node* two;
    struct node* three;
    struct node* four;
    struct node* root;
    int point;
    unsigned int code;
};

#endif
