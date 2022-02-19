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
void findPath(int map[8][8], node* , vector<pair<nodeptr,int>>* , int);
node* checkCell(int map[8][8], int , int , char , node*);
node* minDepth(node*);
bool depthNodeComp(pair<nodeptr, int>, pair<nodeptr, int>);
void totalPointCalc(node*, int*);
void directionCalc(node*, vector<pair<int,int>>* direction);
void printDirection(vector<pair<int,int>>);

int main(){
    int map[8][8] = {{2,2,2,2,2,2,2,2},
        {2,2,1,1,1,1,4,2},
        {2,2,1,2,2,2,1,2},
        {2,2,1,2,2,2,1,2},
        {2,2,11,1,1,1,1,2},
        {2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2}};
    //soldier : (4,2)
    node *root = newNode(make_pair(4,2), nullptr);
    vector<pair<nodeptr, int>> leafs;

    cout << "before findPath function" << endl;
    findPath(map, root, &leafs, 0);

    cout << leafs.at(0).first << ',' << leafs.at(0).second << endl;

    cout << "after findPath function" << endl;
    sort(leafs.begin(), leafs.end(), depthNodeComp);

    cout << "after sort function" << endl;
    cout << "leafs size: " << leafs.size() << endl;
    int minDepth = leafs.begin()->second;   //minimum size of direction

    cout << "after minDepth calc" << endl;
    int totalPoint = 0;
    cout << leafs.at(0).first << ',' << leafs.at(0).second << endl;
    totalPointCalc(leafs.at(0).first, &totalPoint);   //total point of minimum direction

    cout << "after totalPointCalc function" << endl;

    vector<pair<int, int>> direction;   //minimum direction
    directionCalc(leafs.begin()->first, &direction);
    cout << "direction size: " << direction.size() << endl;
//    printDirection(direction);
//    cout << direction.at(0).first << ',' << direction.at(0).second << endl;

    reverse(direction.begin(), direction.end());

    printDirection(direction);

    return 0;
}

void printDirection(vector<pair<int,int>>direction){
    for(int i = 0; i < direction.size(); i++){
        cout << '(' << direction.at(i).first << ',' << direction.at(i).second << ')';
        if(i < direction.size() - 1){
            cout << " -> ";
        }
    }
    cout << endl;
}

void directionCalc(node* node, vector<pair<int,int>>* direction){
    direction->push_back(node->position);
    if(node->root == nullptr){
        return;
    }
    directionCalc(node->root, direction);
}

void totalPointCalc(node* node, int* total){
    cout << "totalPointCalc execute" << endl;
    cout << node << endl;
    cout << ((node->root == nullptr) ? "nullptr" : "not nullptr") << endl;
    if(node->root == nullptr){
        cout << "\tnode is root" << endl;
        (*total) += node->point;
        return;
    }
    cout << "total: " << *total << endl;
    totalPointCalc(node->root, total);
    (*total) += node->point;
}

node* checkCell(int map[8][8], int i, int j, char soldier, node* root){
    cout << "\t\tcheckCell function executed. i,j: " << i << ',' << j << endl;
    if(root->root != nullptr){
        int x = root->root->position.first;
        int y = root->root->position.second;
        cout << "\t\tx,y: " << x << ',' << y << endl;
        if(x == i && y == j){
            return nullptr;
        }
    }

    int cell = map[i][j];
    node* temp = newNode(make_pair(i, j), root);
    temp->code = cell;

    switch(cell){
        case 2:
            cout << "\t\t swtich case cell: cell == 2" << endl;
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
void findPath(int map[8][8], node *node, vector<pair<nodeptr,int>>* leafs, int depth){
    cout << "findPath function executed:" << endl;

    int i = node->position.first;
    int j = node->position.second;
    int tempDepth[4] = {depth, depth, depth, depth};

    cout << "\ti,j: " << i << ',' << j << endl;

    if(i > 0){
        node->one = checkCell(map, i-1, j, 'a', node);
        if(node->one != nullptr){
            tempDepth[0]++;
            cout << "\tfindPath node->one->code: " << node->one->code << endl;
            if(node->one->code != 4){
                findPath(map, node->one, leafs, tempDepth[0]);
            }else{
                cout << "\tnode->one->code == 4 " << endl;
                pair<nodeptr, int> tempNode (node->one, tempDepth[0]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(j > 0){
        node->two = checkCell(map, i, j-1, 'a', node);
        if(node->two != nullptr){
            tempDepth[1]++;
            cout << "\tfindPath node->two->code: " << node->two->code << endl;
            if(node->two->code != 4){
                findPath(map, node->two, leafs, tempDepth[1]);
            }else{
                cout << "\tnode->two->code == 4 " << endl;
                pair<nodeptr, int> tempNode (node->two, tempDepth[1]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(i < 7){
        node->three = checkCell(map, i+1, j, 'a', node);
        if(node->three != nullptr){
            tempDepth[2]++;
            cout << "\tfindPath node->three->code: " << node->three->code << endl;
            if(node->three->code != 4){
                findPath(map, node->three, leafs, tempDepth[2]);
            }else{
                cout << "\tnode->three->code == 4 " << endl;
                pair<nodeptr, int> tempNode (node->three, tempDepth[2]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(j < 7){
        node->four = checkCell(map, i, j+1, 'a', node);
        if(node->four != nullptr){
            tempDepth[3]++;
            cout << "\tfindPath node->four->code: " << node->four->code << endl;
            if(node->four->code != 4){
                findPath(map, node->four, leafs, tempDepth[3]);
            }else{
                cout << "\tnode->four->code == 4 " << endl;
                pair<nodeptr, int> tempNode (node->four, tempDepth[2]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
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
