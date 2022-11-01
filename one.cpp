#include "one.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;
one::one()
{
}
void  one :: menuOne(){

gg :
    system("clear");
    cout<<"\n\n\t\t\t Main Panel \n";
    cout<<"1 adminLogin\n"<<'\n';
    cout<<"2 managerLogin\n"<<'\n';
    cout<<"3 employeeLogin\n"<<'\n';
    cout<<"4 Exit\n"<<'\n';
    //ctor
    cin>>x;
    switch(x)
    {
        case 1:
            adminLogin();
            break;
        case 2:
            managerLogin();
            break;
        case 3:
            employeeLogin();
            break;
        case 4:
            exit(0);
        default :
            cout<<"Try again\n"<<'\n';
    }
    getch();
    goto gg ;
}
void one :: adminLogin(){
    system("clear");
    string managerUser,managerPass;
    cout<<"Admin username :"<<'\n';
    cin>>managerUser;
    getch();
    cout<<"Admin password :"<<'\n';
    for (int i = 0; i < 5; i++) {
        managerPass+=getch();
        cout<<"*";
    }
    if(managerUser=="admin" && managerPass == "admin")
    {
        cout<<'\n';
        cout<<"Login successful\n"<<'\n';
        cout<<"Admin panel\n"<<'\n';
        adminMenu();

    }
    else {
        cout<<"\nWrong username or password\nPlease Try again\nPress any key to go back\n"<<'\n';
    }

}
void one :: managerLogin(){
}
void one :: employeeLogin(){
}
void one :: adminMenu(){
gg :
    system("clear");
    cout<<"\n\n\t\t\t Admin Panel\n";
    cout<<"1 manager create"<<'\n';
    cout<<"2 manager read"<<'\n';
    cout<<"3 manager update"<<'\n';
    cout<<"4 manager delete"<<'\n';
    cout<<"5 back"<<'\n';
    cout<<"6 exit"<<'\n';
    //ctor
    cin>>x;
    switch(x)
    {
        case 1:
            managerCreate();
            break;
        case 2:
            managerRead();
            getch();
            break;
        case 3:
            managerUpdate();
            getch();
            break;
        case 4:
            managerDelete();
            getch();
            break;
        case 5:
            return;
        case 6:
            exit(0);
        default :
            cout<<"Try again\n"<<'\n';
    }
    goto gg ;
    getch();
}
void one :: managerCreate(){
    system("clear");
    cout<<"\n\n\t\t\t ManagerCreatepanel \n";
    fstream file;
    cout<<"How many manager to be added ?\n"<<'\n';
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Insert id :"<<'\n';
        cin>>managerId;
        cout<<"Insert Name :"<<'\n';
        cin>>managerName;
        file.open("managerRecord.txt",ios::app|ios::out);
        file<<managerId<<" "<<managerName<<'\n';
        file.close();
    }
}
void one :: managerRead(){
    system("clear");
    fstream file;
    file.open("managerRecord.txt",ios::in);
    cout<<"\n\n\t\t\t\tDisplay Record\n";
    cout<<"managerId"<<" | "<<"Managerame"<<'\n';
    cout<<"-----------------------"<<"\n";
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank freeze*/
    }
    while(file>>managerId>>managerName)
    {
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerId;
        cout<<"|  ";
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerName;
        cout<<'\n';
    }
    file.close();
    cout<<"\n\n\nPress any key to go back"<<'\n';
    getch();
}
void one :: managerUpdate(){
    found=0;
    system("clear");
    fstream file,file1;
    file.open("managerRecord.txt",ios::in);
    file1.open("managerRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank 2 freeze*/
    }
    cout<<"ManagerId to be updaated :\n";
    cin>>testId;
    while(file>>managerId>>managerName)
    {
        if(testId==managerId)
        {
            found=1;
            cout<<"Insert id :"<<'\n';
            cin>>managerId;
            cout<<"Insert Name :"<<'\n';
            cin>>managerName;
            file1<<managerId<<" "<<managerName<<'\n';
        }
        else
            file1<<managerId<<" "<<managerName<<'\n';
    }
    file.close();
    file1.close();
    remove("managerRecord.txt");
    rename("managerRecord1.txt","managerRecord.txt");
    if(found)
        cout<<"Successfuly Updated\nPress any key to go back"<<'\n';
    else
        cout<<"Not found \nPress any key to go back"<<'\n';
    getch();
}
void one :: managerDelete(){
    found=0;
    system("clear");
    fstream file,file1;
    file.open("managerRecord.txt",ios::in);
    file1.open("managerRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank 2 freeze*/
    }
    cout<<"ManagerId to be deleted\n";
    cin>>testId;
    while(file>>managerId>>managerName)
    {
        if(testId==managerId)
            found=1;
        if(testId!=managerId)
        {
            file1<<managerId<<" "<<managerName<<'\n';
        }
    }
    file.close();
    file1.close();
    remove("managerRecord.txt");
    rename("managerRecord1.txt","managerRecord.txt");
    if(found)
        cout<<"Successfuly Deleted\nPress any key to go back"<<'\n';
    else
        cout<<"Not found\nPress any key to go back"<<'\n';
    getch();
}
