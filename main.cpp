#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
#include "testPlan.cpp"

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
void findPath(int**, node* , vector<pair<nodeptr,int>>* , int, char);
node* checkCell(int**, int , int , char , node*);
bool depthNodeComp(pair<nodeptr, int>, pair<nodeptr, int>);
void totalPointCalc(node*, int*);
void directionCalc(node*, vector<pair<int,int>>* direction);
void printDirection(vector<pair<int,int>>);
bool findLoop(node*, pair<int,int>);

int main(int argc, char* argv[]){
    ifstream file;
    file.open(argv[1], fstream::in);

    int height, width;
    stringstream tempi, tempj;
    tempi << argv[2];
    tempi >> height;
    tempj << argv[3];
    tempj >> width;

    int** plan = new int*[height];
    for(int i = 0; i < height; i++){
        plan[i] = new int[width];
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            file >> *(*(plan+i)+j);
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << *(*(plan+i)+j) << ' ';
        }
        cout << endl;
    }

    printPlan(plan, width, height, false, nullptr, nullptr);

    pair<int,int> soldierA;
    cout << "Please enter location of soldier A: ";
    cin >> soldierA.first >> soldierA.second;

    pair<int,int> soldierB;
    cout << "Please enter location of soldier B: ";

    node *rootB = newNode(make_pair(soldierB.first,soldierB.second), nullptr);
    vector<pair<nodeptr, int>> leafsB;

    node *rootA = newNode(make_pair(soldierA.first,soldierA.second), nullptr);
    vector<pair<nodeptr, int>> leafsA;


    cout << "before findPath function" << endl;
    findPath(plan, rootA, &leafsA, 0, 'a');
    findPath(plan, rootB, &leafsB, 0, 'b');

    cout << "***leafsA size: " << leafsA.size() << endl;
    cout << "***leafsB size: " << leafsB.size() << endl;


    cout << "after findPath function" << endl;
    sort(leafsA.begin(), leafsA.end(), depthNodeComp);
    sort(leafsB.begin(), leafsB.end(), depthNodeComp);

    cout << "after sort function" << endl;
    cout << "leafsA size: " << leafsA.size() << endl;
    cout << "leafsB size: " << leafsB.size() << endl;


    int totalPointA = 0;
    int totalPointB = 0;

    cout << leafsA.at(0).first << ',' << leafsA.at(0).second << endl;
    //cout << leafsB.at(0).first << ',' << leafsB.at(0).second << endl;

    if(leafsA.size() > 0){
        totalPointCalc(leafsA.at(0).first, &totalPointA);   //total point of minimum direction
    }else{
        cout << "Soldier A cant move every where!" << endl;
    }
    if(leafsB.size() > 0){
        totalPointCalc(leafsB.at(0).first, &totalPointB);   //total point of minimum direction
    }else{
        cout << "Soldier B cant move every where!" << endl;
    }


    cout << "after totalPointCalc function" << endl;



    vector<pair<int, int>> directionA;   //minimum direction
    vector<pair<int, int>> directionB;   //minimum direction
    directionCalc(leafsA.begin()->first, &directionA);
    if(leafsB.size() > 0){
        directionCalc(leafsB.begin()->first, &directionB);
    }
    cout << "directionA size: " << directionA.size() << endl;
    cout << "directionB size: " << directionB.size() << endl;
//    printDirection(direction);
//    cout << direction.at(0).first << ',' << direction.at(0).second << endl;

    reverse(directionA.begin(), directionA.end());
    reverse(directionB.begin(), directionB.end());

    printDirection(directionA);
    printDirection(directionB);


    cout << "leafs.second A,b: " << leafsA.begin()->second << " , " << leafsB.begin()->second << endl;
    if(leafsA.begin()->second < leafsB.begin()->second){

        cout << "\t\t****Soldier A won****" << endl;

    }else if(leafsA.begin()->second > leafsB.begin()->second){

        cout << "\t\t****Soldier B won****" << endl;

    }else{
        if(totalPointA > totalPointB){

            cout << "\t\t****Soldier A won****" << endl;
            cout << "\t\tDirection length of A and B is equals but total point of A greater than B" << endl;

        }else if(totalPointA < totalPointB){

            cout << "\t\t****Soldier B won****" << endl;
            cout << "\t\tDirection length of B and A is equals but total point of B greater than A" << endl;

        }else{
            cout << "\t\t****Point and direction length of soldier A and B is equals****" << endl;
        }
    }

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

node* checkCell(int** map, int i, int j, char soldier, node* root){
    cout << "\t\tcheckCell function executed. i,j: " << i << ',' << j << endl;
    if(root->root != nullptr){
        if(findLoop(root, make_pair(i,j))){
            return nullptr;
        }
    }

    int cell = *(*(map+i)+j);
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
void findPath(int** map, node *node, vector<pair<nodeptr,int>>* leafs, int depth, char soldier){
    cout << "findPath function executed:" << endl;

    int i = node->position.first;
    int j = node->position.second;
    int tempDepth[4];
    tempDepth[0] = depth;
    tempDepth[1] = depth;
    tempDepth[2] = depth;
    tempDepth[3] = depth;

    cout << "\ti,j: " << i << ',' << j << endl;

    if(i > 0){
        node->one = checkCell(map, i-1, j, soldier, node);
        if(node->one != nullptr){
            tempDepth[0]++;
            cout << "\tfindPath node->one->code: " << node->one->code << endl;
            cout << "\t*** tempDepth[0]++ => " << tempDepth[0] << endl;
            if(node->one->code != 4){
                findPath(map, node->one, leafs, tempDepth[0], soldier);
            }else{
                cout << "\tnode->one->code == 4 " << endl;
                cout << "\t******* tempDepth[0] => " << tempDepth[0] << endl;
                pair<nodeptr, int> tempNode (node->one, tempDepth[0]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(j > 0){
        node->two = checkCell(map, i, j-1, soldier, node);
        if(node->two != nullptr){
            tempDepth[1]++;
            cout << "\tfindPath node->two->code: " << node->two->code << endl;
            cout << "\t*** tempDepth[1]++ => " << tempDepth[1] << endl;
            if(node->two->code != 4){
                findPath(map, node->two, leafs, tempDepth[1], soldier);
            }else{
                cout << "\tnode->two->code == 4 " << endl;
                cout << "\t******* tempDepth[1] => " << tempDepth[1] << endl;
                pair<nodeptr, int> tempNode (node->two, tempDepth[1]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(i < 7){
        node->three = checkCell(map, i+1, j, soldier, node);
        if(node->three != nullptr){
            tempDepth[2]++;
            cout << "\tfindPath node->three->code: " << node->three->code << endl;
            cout << "\t*** tempDepth[2]++ => " << tempDepth[2] << endl;
            if(node->three->code != 4){
                findPath(map, node->three, leafs, tempDepth[2], soldier);
            }else{
                cout << "\tnode->three->code == 4 " << endl;
                cout << "\t******* tempDepth[2] => " << tempDepth[2] << endl;
                pair<nodeptr, int> tempNode (node->three, tempDepth[2]);
                leafs->push_back(tempNode);
                cout << "leafs.size: " << leafs->size() << endl;
            }
        }
    }

    if(j < 7){
        node->four = checkCell(map, i, j+1, soldier, node);
        if(node->four != nullptr){
            tempDepth[3]++;
            cout << "\tfindPath node->four->code: " << node->four->code << endl;
            cout << "\t*** tempDepth[3]++ => " << tempDepth[3] << endl;
            if(node->four->code != 4){
                findPath(map, node->four, leafs, tempDepth[3], soldier);
            }else{
                cout << "\tnode->four->code == 4 " << endl;
                cout << "\t******* tempDepth[3] => " << tempDepth[3] << endl;
                pair<nodeptr, int> tempNode (node->four, tempDepth[3]);
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


bool depthNodeComp(pair<nodeptr, int> first, pair<nodeptr, int> second){
    return (first.second < second.second);
}

bool findLoop(node* rootNode, pair<int,int> location){
    bool result = false;
    node* tempNode = rootNode;
    do{
        if(tempNode->position == location){
            result = true;
        }
        if(tempNode->root != nullptr){
            tempNode = tempNode->root;
        }
    } while(tempNode->root != nullptr);

    return result;
}
