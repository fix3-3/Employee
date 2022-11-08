#include "ManagerModule.h"
#include <iostream>
using namespace std;

void managerModule :: menuManagerModule(){
gg :
    system("cls");
    cout<<"Manager crud\n"<<'\n';
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
     getchar();
    goto gg ;
}
void managerModule :: createEmployee(){
    system("cls");
    cout<<"\n\n\t\t\t employeeCreatepanel \n";
    fstream file;
    cout<<"How many employee to be added ?\n"<<'\n';
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Insert id :";
        cin>>employeeId;
        cout<<endl;
        cout<<"Insert Name : ";
        cin.ignore();getline(cin,employeeName);
        cout<<endl;
        cout<<"Insert Gender : ";
        cin>>employeeGender;
        cout<<endl;
        cout<<"Insert Post : ";
        cin>>employeePost;
        cout<<endl;
        cout<<"Insert Salary : ";
        cin>>employeeSalary;
        cout<<endl;

        file.open("employeeRecord.txt",ios::app|ios::out);
        file<<employeeId<<endl;
        file<<employeeName<<endl;
        file<<employeeGender<<endl;
        file<<employeePost<<endl;
        file<<employeeSalary<<endl;
        file.close();

       }
}
void managerModule :: readEmployee(){
    system("cls");
    fstream file;
    file.open("employeeRecord.txt",ios::in);
    cout<<"\n\n\t\t\t\tDisplay Record\n";
    cout<<"employeeId "<<" | "<<"employeeName "<<" | "<<"employeeGender "<<" | "<<"employeePost "<<" | "<<"employeeSalary "<<'\n';

    cout<<"--------------------------------------------------------------------------------"<<"\n";
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank freeze*/
    }
    while(file>>employeeId)
    {
        file.ignore();
        getline(file,employeeName);
        file>>employeeGender>>employeePost>>employeeSalary;
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<employeeId;
        cout<<"|  ";
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<employeeName<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<employeeGender<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<employeePost<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<employeeSalary<<" $";
        cout<<'\n';
    }
    file.close();
    cout<<"\n\n\nPress any key to go back"<<'\n';
    getchar();

}
void managerModule :: updateEmployee(){

}
void managerModule :: deletEmployee(){

}
