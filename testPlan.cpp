#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <clocale>
using namespace std;

struct node;

void printPlan(int** rawPlan, int width, int height, bool findPath, node* resultNodeA, node* resultNodeB){
// Ӝ  Ӿ  🥷  👮 0x2593 🪖 🌟
    setlocale(LC_ALL, "");

//    wchar_t plan [(height * 2) + 1] [(width * 2) + 1];
    wchar_t plan[height][width];

    if(!findPath){
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

                string charStr;
                stringstream ss;
                ss << *(*(rawPlan+j)+i);
                ss >> charStr;
                wchar_t character;
                if(charStr == "2"){
                    character = L'🌲';
                }else if(charStr == "6" || charStr == "14"){
                    character = L'🪴';
                }else if(charStr == "7" || charStr == "14"){
                    character = L'🏠';
                }else if(charStr == "9" || charStr == "10"){
                    character = L'🧍';
                }else if(charStr == "5" || charStr == "13"){
                    character = L'🌟';
                }else if(charStr == "16" || charStr == "8"){
                    character = L'🪖';
                }else if(charStr == "12" || charStr == "11"){
                    character = L'💂';
                }else if(charStr == "1" || charStr == "3" || charStr == "17"){
                    character = L'🟫';
                }else if(charStr == "4"){
                    character = L'🔴';
                }else{
                    character = L'⬛';
                }

                //🪖 🌟 💂
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
    }



    //print result on console
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%lc",plan[i][j]);
        }
        printf("\n");
    }

}
