#include <iostream>
using namespace std;

typedef struct node node;
struct node{
    pair<int,int> position;
    struct node* one;
    struct node* two;
    struct node* three;
    struct node* four;
    struct node* five;
    struct node* six;
    struct node* seven;
    struct node* eight;
    unsigned int point;
};

struct node* newNode(pair<int,int> position);
void findPath(int map[8][8], node *tree, pair<int,int> destination);

int main(){
    int map[8][8] = {{2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,4,2},
        {2,2,2,2,2,2,1,2},
        {2,2,2,2,2,2,1,2},
        {2,2,11,1,1,1,1,2},
        {2,2,2,2,2,2,4,2},
        {2,2,2,2,2,2,4,2},
        {2,2,2,2,2,2,4,2}};
    //soldier : (4,2)
    node *root = newNode(make_pair(4,2));
    return 0;
}

void findPath(int map[8][8], node *node, pair<int,int> destination){
    int i = node->position.first;
    int j = node->position.second;

    if(map[i-1][j+1] == 1){
        node->one = newNode(make_pair(i-1,j+1));
    }
}
struct node* newNode(pair<int,int> position){
    struct node* node = new struct node();
    node->position = position;
    node->one = nullptr;
    node->two = nullptr;
    node->three = nullptr;
    node->four = nullptr;
    node->five = nullptr;
    node->six = nullptr;
    node->seven = nullptr;
    node->eight = nullptr;
    node->point = 0;
    return node;
}
