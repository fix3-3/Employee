#include "two.h"
#include <iostream>
// #include <conio.h>
using namespace std;

two::two()
{
    //ctor
}
void two :: menuTwo(){
    cout<<"Admin crud\n"<<'\n';
    cout<<"1 create\n"<<'\n';
    cout<<"2 read\n"<<'\n';
    cout<<"3 update\n"<<'\n';
    cout<<"4 delet\n"<<'\n';
    cout<<"5 Back\n"<<'\n';
    cout<<"6 Exit\n"<<'\n';
    //ctor
    cin>>x;
    switch(x)
    {
        case 1:
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            update();
            break;
        case 4:
            delet();
            break;
        case 5:
          // menuOne();
            break;
        case 6:
            exit(0);
        default :
            cout<<"Try again\n"<<'\n';
    }
    // getch();
}
void two :: create(){

}
void two :: read(){

}
void two :: update(){

}
void two :: delet(){

}
