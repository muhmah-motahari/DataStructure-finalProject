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
    int point;
    unsigned int code;
};

struct node* newNode(pair<int,int> position);
void findPath(int map[8][8], node *tree, pair<int,int> destination);
node* checkCell(int map[8][8], int i, int j, char soldier);

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
node* checkCell(int map[8][8], int i, int j, char soldier){
    int cell = map[i][j];
    node* temp = newNode(make_pair(i, j));
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
void findPath(int map[8][8], node *node, pair<int,int> destination){
    int i = node->position.first;
    int j = node->position.second;

    node->one = checkCell(map, i-1, j+1, 'a');
    if(node->one != nullptr){
        if(node->one->code != 4){
            findPath(map, node->one, make_pair(i-1, j+1));
        }
    }
    node->two = checkCell(map, i-1, j, 'a');
    if(node->two != nullptr){
        if(node->two->code != 4){
            findPath(map, node->two, make_pair(i-1, j));
        }
    }
    node->three = checkCell(map, i-1, j-1, 'a');
    if(node->three != nullptr){
        if(node->three->code != 4){
            findPath(map, node->three, make_pair(i-1, j-1));
        }
    }
    node->eight = checkCell(map, i, j+1, 'a');
    if(node->eight != nullptr){
        if(node->eight->code != 4){
            findPath(map, node->eight, make_pair(i, j+1));
        }
    }
    node->four = checkCell(map, i, j-1, 'a');
    if(node->four != nullptr){
        if(node->four->code != 4){
            findPath(map, node->four, make_pair(i, j-1));
        }
    }
    node->seven = checkCell(map, i+1, j+1, 'a');
    if(node->seven != nullptr){
        if(node->seven->code != 4){
            findPath(map, node->seven, make_pair(i+1, j+1));
        }
    }
    node->six = checkCell(map, i+1, j, 'a');
    if(node->six != nullptr){
        if(node->six->code != 4){
            findPath(map, node->six, make_pair(i+1, j));
        }
    }
    node->five = checkCell(map, i+1, j-1, 'a');
    if(node->five != nullptr){
        if(node->five->code != 4){
            findPath(map, node->five, make_pair(i+1, j-1));
        }
    }

}
node* newNode(pair<int,int> position){
    node* node = new struct node();
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
    node->code = 0;
    return node;
}
