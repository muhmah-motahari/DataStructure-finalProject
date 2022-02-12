#include <iostream>
using namespace std;

typedef struct node node;
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

struct node* newNode(pair<int,int>, node*);
void findPath(int map[8][8], node* , pair<int,int> );
node* checkCell(int map[8][8], int , int , char , node*);

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
    node *root = newNode(make_pair(4,2), nullptr);
    return 0;
}
node* checkCell(int map[8][8], int i, int j, char soldier, node* root){
    int x = root->root->position.first;
    int y = root->root->position.second;
    if(x == i && y == j){
        return nullptr;
    }

    int cell = map[i][j];
    node* temp = newNode(make_pair(i, j), root);
    temp->code = cell;

    switch(cell){
        case 2:
            return nullptr;
            break;
        case 6:
            return nullptr;
            break;
        case 7:
            return nullptr;
            break;
        case 9:
            return nullptr;
            break;
        case 10:
            return nullptr;
            break;
        case 14:
            return nullptr;
            break;
        case 15:
            return nullptr;
            break;
        default:
            if(soldier == 'a'){
                switch(cell){
                    case 5:
                        temp->point = 1000;
                        break;
                    case 12:
                        temp->point = -10;
                        break;
                    case 16:
                        temp->point = -500;
                        break;
                    default:
                        break;
                }
            }else if(soldier == 'b'){
                switch(cell){
                    case 8:
                        temp->point = -500;
                        break;
                    case 11:
                        temp->point = -10;
                        break;
                    case 13:
                        temp->point = 1000;
                        break;
                    default:
                        break;
                }
            }
    }
    return temp;
}
void findPath(int map[8][8], node *node){
    int i = node->position.first;
    int j = node->position.second;

    node->one = checkCell(map, i-1, j, 'a', node);
    if(node->one != nullptr){
        if(node->one->code != 4){
            findPath(map, node->one, make_pair(i-1, j));
        }
    }
    node->two = checkCell(map, i, j-1, 'a', node);
    if(node->two != nullptr){
        if(node->two->code != 4){
            findPath(map, node->two, make_pair(i, j-1));
        }
    }
    node->three = checkCell(map, i+1, j, 'a', node);
    if(node->three != nullptr){
        if(node->three->code != 4){
            findPath(map, node->three, make_pair(i+1, j));
        }
    }
   node->four = checkCell(map, i, j+1, 'a', node);
    if(node->four != nullptr){
        if(node->four->code != 4){
            findPath(map, node->four, make_pair(i, j+1));
        }
    }
}
node* newNode(pair<int,int> position, node* root){
    node* node = new struct node();
    node->position = position;
    node->one = nullptr;
    node->two = nullptr;
    node->three = nullptr;
    node->four = nullptr;
    node->root = root;
    node->point = 0;
    node->code = 0;
    return node;
}
