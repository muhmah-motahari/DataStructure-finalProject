#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node node;
typedef struct node* nodeptr;
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
void findPath(int map[8][8], node* , vector<pair<nodeptr,int>>, int);
node* checkCell(int map[8][8], int , int , char , node*);
node* minDepth(node*);
bool depthNodeComp(pair<nodeptr, int>, pair<nodeptr, int>);
int totalPointCalc(node*, int);
void directionCalc(node*, vector<pair<int,int>> direction);

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
    vector<pair<nodeptr, int>> leafs;
    findPath(map, root, leafs, 0);
    sort(leafs.begin(), leafs.end(), depthNodeComp);
    int minDepth = leafs.begin()->second;   //minimum size of direction
    int totalPoint = totalPointCalc(leafs.begin()->first, 0);   //total point of minimum direction

    vector<pair<int, int>> direction;   //minimum direction
    directionCalc(leafs.begin()->first, direction);
    reverse(direction.begin(), direction.end());

    return 0;
}

void directionCalc(node* node, vector<pair<int,int>> direction){
    direction.push_back(node->position);
    if(node->root == nullptr){
        return;
    }
    directionCalc(node->root, direction);
}

int totalPointCalc(node* node, int total){
    if(node->root == nullptr){
        return total;
    }
    total += node->root->point;
    totalPointCalc(node->root, total);
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
void findPath(int map[8][8], node *node, vector<pair<nodeptr,int>> leafs, int depth){
    int i = node->position.first;
    int j = node->position.second;
    int tempDepth[4] = {depth, depth, depth, depth};

    node->one = checkCell(map, i-1, j, 'a', node);
    if(node->one != nullptr){
        tempDepth[0]++;
        if(node->one->code != 4){
            findPath(map, node->one, leafs, tempDepth[0]);
        }else{
            leafs.push_back(make_pair(node->one, tempDepth[0]));
        }
    }
    node->two = checkCell(map, i, j-1, 'a', node);
    if(node->two != nullptr){
        tempDepth[1]++;
        if(node->two->code != 4){
            findPath(map, node->two, leafs, tempDepth[1]);
        }else{
            leafs.push_back(make_pair(node->one, tempDepth[1]));
        }
    }
    node->three = checkCell(map, i+1, j, 'a', node);
    if(node->three != nullptr){
        tempDepth[2]++;
        if(node->three->code != 4){
            findPath(map, node->three, leafs, tempDepth[2]);
        }else{
            leafs.push_back(make_pair(node->one, tempDepth[2]));
        }
    }
   node->four = checkCell(map, i, j+1, 'a', node);
    if(node->four != nullptr){
        tempDepth[3]++;
        if(node->four->code != 4){
            findPath(map, node->four, leafs, tempDepth[3]);
        }else{
            leafs.push_back(make_pair(node->one, tempDepth[3]));
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
int minDepth(node* root, node* result){
    if(root == nullptr){
        return 0;
    }

    if((root->one == nullptr) && (root->two == nullptr) && (root->three == nullptr) && (root->four == nullptr)){
        result = root;
        return 1;
    }


}

bool depthNodeComp(pair<nodeptr, int> first, pair<nodeptr, int> second){
    return (first.second < second.second);
}
