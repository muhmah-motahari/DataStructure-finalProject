#include <iostream>
#include <string>
#include <stdio.h>
#include <clocale>
using namespace std;

int main(){
//    ┌ ─ ┬ ┐ │ ○ ├ ┼ ┤ × └ ┴ ┘
    setlocale(LC_ALL, "");
    std::cout.imbue( std::locale("") );

    //wchar_t* str1 = L"┌";
    wchar_t str2 = L'┌';
    wchar_t str3 = 0x007c;
    wchar_t str4 = 0x007c;
    wchar_t str5 = 0x007c;

    wchar_t str6 = 0x2580;
    wchar_t str7 = 0x2581;
    wchar_t str8 = 0x2582;
    wchar_t str9 = 0x2583;
    wchar_t str10 = 0x2584;
    wchar_t str11 = 0x2585;
    wchar_t str12 = 0x2586;
    wchar_t str13 = 0x2587;
    wchar_t str14 = 0x2588;
    wchar_t str15 = 0x2589;
    wchar_t str16 = 0x258a;
    wchar_t str17 = 0x258b;
    wchar_t str18 = 0x258c;
    wchar_t str19 = 0x258d;
    wchar_t str20 = 0x258e;
    wchar_t str21 = 0x258f;

    wchar_t str22 = 0x2590;
    wchar_t str23 = 0x2591;
    wchar_t str24 = 0x2592;
    wchar_t str25 = 0x2593;//   the best
    wchar_t str26 = 0x2594;
    wchar_t str27 = 0x2595;
    wchar_t str28 = 0x2596;
    wchar_t str29 = 0x2597;
    wchar_t str30 = 0x2598;
    wchar_t str31 = 0x2599;
    wchar_t str32 = 0x259a;
    wchar_t str33 = 0x259b;
    wchar_t str34 = 0x259c;
    wchar_t str35 = 0x1f3ff;
    wchar_t str36 = 0x1fab4;
    //wchar_t str37 = L'👨‍🦯';
//    char ch1{ u16'┼'};
    //char32_t ch2{0x00c6};
/*
    printf("1: %ls", str1);
    printf("\n");
    printf("2: %lc", str2);
    printf("\n");
    printf("3: %lc", str3);
    printf("\n");
    printf("4: %lc", str4);
    printf("\n");*/


    printf("5: %lc", str5);
    printf("\n");


    printf("1: %lc", str6);
    printf("\n");
    printf("2: %lc", str7);
    printf("\n");
    printf("3: %lc", str8);
    printf("\n");
    printf("4: %lc", str9);
    printf("\n");
    printf("5: %lc", str10);
    printf("\n");
    printf("6: %lc", str11);
    printf("\n");
    printf("7: %lc", str12);
    printf("\n");
    printf("8: %lc", str13);
    printf("\n");
    printf("9: %lc", str14);
    printf("\n");
    printf("1: %lc", str15);
    printf("\n");
    printf("2: %lc", str16);
    printf("\n");
    printf("3: %lc", str17);
    printf("\n");
    printf("4: %lc", str18);
    printf("\n");
    printf("5: %lc", str19);
    printf("\n");
    printf("6: %lc", str20);
    printf("\n");
    printf("7: %lc", str21);
    printf("\n");

    printf("8: %lc", str22);
    printf("\n");
    printf("9: %lc%lc%lc", str23, str23, str23);
    printf("\n");
    printf("0: %lc%lc%lc%lc", str23, str23, str23, str24);
    printf("\n");
    printf("1: %lc", str25);
    printf("\n");
    printf("2: %lc", str26);
    printf("\n");
    printf("3: %lc", str27);
    printf("\n");
    printf("4: %lc", str28);
    printf("\n");
    printf("5: %lc", str29);
    printf("\n");
    printf("6: %lc", str30);
    printf("\n");
    printf("7: %lc", str31);
    printf("\n");
    printf("8: %lc", str32);
    printf("\n");
    printf("9: %lc", str33);
    printf("\n");
    printf("0: %lc", str34);
    printf("\n");
    printf("1: %lc", str35);
    printf("\n");
    printf("2: %lc", str36);
    printf("\n");
    //printf("3: %lc", str37);
    printf("\n");


    printf("5: %lc", str5);
    printf("\n");

//    cout << "\033[1;41m" ;
    wchar_t str80 = 0x1fab4;
    //wstring str81 {"\033[1;41m\0x1fab"};// + str80 + "\033[0m";
    printf("\033[1;41m%lc\033[0m", str80);

//    cout << "\033[0m";

    cout << endl << endl;

// cout << "\033[1;41m bold red text \033[0m\n";
 cout << "asdf" << endl;


/*    printf("7: %lc", ch2);
    printf("\n");
*/
    return 0;
}
