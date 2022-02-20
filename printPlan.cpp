#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <clocale>
#include "node.hpp"
using namespace std;

void printPlan(int** rawPlan, int width, int height, bool findPath, node* resultNodeA, node* resultNodeB){
//   💂  🥷  👮  🪖 🌟 🔴
    setlocale(LC_ALL, "");
    node* nodeA = resultNodeA;
    node* nodeB = resultNodeB;

//    wchar_t plan [(height * 2) + 1] [(width * 2) + 1];
    wchar_t plan[height][width];

    for(int j = 0; j < height; j++){
        //design row 2 in character array plan
        for(int i = 0; i < width; i++){
/*
            //  design first row
            if(j == 1){
                plan[j-1][i] = L'┬';
                plan[j-1][i+1] = L'─';
                if(i == 0){
                    plan[j-1][i] = L'┌';
                }else if(i >= width*2 - 2){
                    plan[j-1][i+2] = L'┐';
                }
            }
*/

            //  design data of array
//                plan[j][i] = L'│';

/*            string charStr;
            stringstream ss;
            ss << *(*(rawPlan+j)+i);
            ss >> charStr;*/
            int checkData = *(*(rawPlan+j)+i);
            wchar_t character;
            switch(checkData){
               case 2:
                    character = L'🌲';
                    break;
                case 6:
                case 14:
                     character = L'🪴';
                     break;
                case 7:
                     character = L'🏠';
                     break;
                case 9:
                case 10:
                     character = L'🧍';
                     break;
                case 5:
                case 13:
                     character = L'🌟';
                     break;
                case 16:
                case 8:
                     character = L'🪖';
                     break;
                case 12:
                case 11:
                     character = L'💂';
                     break;
                case 4:
                     character = L'🍭';
                     break;
                case 17:
                case 1:
                case 3:
                     character = L'🟫';
                     break;
                default:
                    character = L'⬛';
                    break;
            }

            plan[j][i] = character;

/*
            if(i >= width*2 - 2){
                plan[j][i+2] = L'│';
            }

            //  design center of seperators row
            plan[j+1][i] = L'┼';
            plan[j+1][i+1] = L'─';
            if(i == 0){
                plan[j+1][i] = L'├';
            }else if(i >= width*2 - 2){
                plan[j+1][i+2] = L'┤';
            }


            //design end of separators row
            if(j >= height*2 - 2){
                plan[j+1][i] = L'┴';
                plan[j+1][i+1] = L'─';
                if(i == 0){
                    plan[j+1][i] = L'└';
                }else if(i >= width*2 - 2){
                    plan[j+1][i+2] = L'┘';
                }
            }
*/
        }
    }

    if(findPath){
        while(nodeA->root != nullptr){
            nodeA = nodeA->root;
            if(nodeA->root == nullptr){
                plan[nodeA->position.first][nodeA->position.second] = L'🥷';
                break;
            }
            switch(*(*(rawPlan+nodeA->position.first)+nodeA->position.second)){
                case 1:
                case 3:
                case 17:
                    plan[nodeA->position.first][nodeA->position.second] = L'🔵';
                    break;
                default:
                break;

            }
        }
        while(nodeB->root != nullptr){
            nodeB = nodeB->root;
            if(nodeB->root == nullptr){
                plan[nodeB->position.first][nodeB->position.second] = L'👮';
                break;
            }
            switch(*(*(rawPlan+nodeB->position.first)+nodeB->position.second)){
                case 1:
                case 3:
                case 17:
                    plan[nodeB->position.first][nodeB->position.second] = L'🔴';
                    break;
                default:
                break;

            }
        }
    }


    //print result on console
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            switch(*(*(rawPlan+i)+j)){
                case 12:
                case 16:
                case 5:
                    printf("\033[1;44m%lc\033[0m", plan[i][j]);
                    break;

                case 13:
                case 8:
                case 11:
                    printf("\033[1;41m%lc\033[0m", plan[i][j]);
                    break;

                default:
                    printf("%lc",plan[i][j]);
                    break;
            }
        }
        printf("\n");
    }

}
