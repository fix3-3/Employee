#include "ManagerModule.h"
#include <iostream>
using namespace std;

void managerModule :: menuManagerModule(){
    cout<<"Admin crud\n"<<'\n';
    cout<<"1 create\n"<<'\n';
    cout<<"2 read\n"<<'\n';
    cout<<"3 update\n"<<'\n';
    cout<<"4 delet\n"<<'\n';
    cout<<"5 Back\n"<<'\n';
    cout<<"6 Exit\n"<<'\n';
    cin>>x;
    switch(x)
    {
        case 1:
            createEmployee();
            break;
        case 2:
            readEmployee();
            break;
        case 3:
            updateEmployee();
            break;
        case 4:
            deletEmployee();
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
void managerModule :: createEmployee(){

}
void managerModule :: readEmployee(){

}
void managerModule :: updateEmployee(){

}
void managerModule :: deletEmployee(){

}
