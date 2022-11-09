#include "AdminModule.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;
adminModule :: adminModule()
{
    adminUsername = "admin"; adminPass = "admin";
}
void adminModule:: menuAdminModule(){

gg :
    system("cls|clear");
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
    getchar();
    goto gg ;
}
void adminModule :: adminLogin(){
    system("cls|clear");
    string Username,Password;
    cout<<"Admin username : ";
    cin>>Username;
    cout<<endl;
    getchar();
    cout<<"Admin password : ";
    for (int i = 0; i < 5; i++) {
        Password+=getch();
        cout<<"*";
    }
    cout<<endl;
    if(Username==adminUsername && Password ==adminPass)
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
void adminModule :: managerLogin(){


    system("cls|clear");
    string Username,Password;
    cout<<" Manager username : ";
    cin>>Username;
    cout<<endl;
    getchar();
    cout<<" Manager password : ";
    for (int i = 0; i < 5; i++) {
        Password+=getch();
        cout<<"*";
    }
    cout<<endl;
    if(Username == "green" && Password == "green")
    {
        cout<<'\n';
        cout<<"Login successful\n"<<'\n';
        cout<<"Admin panel\n"<<'\n';
       menuManagerModule();
    }
    else {
        cout<<"\nWrong username or password\nPlease Try again\nPress any key to go back\n"<<'\n';
    }

}





//void adminModule :: employeeLogin(){
    //showDetails();
//}
void adminModule :: adminMenu(){
gg :
    system("cls|clear");
    cout<<"\n\n\t\t\t Admin Panel\n";
    cout<<"1 manager create"<<'\n';
    cout<<"2 manager read"<<'\n';
    cout<<"3 manager update"<<'\n';
    cout<<"4 manager delete"<<'\n';
    cout<<"5 admin username and password change"<<'\n';
    cout<<"6 back"<<'\n';
    cout<<"7 exit"<<'\n';
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
            adminPassUserChange();
            return;
            break;
        case 6:
            return;
        case 7:
            exit(0);

        default :
            cout<<"Try again\n"<<'\n';
    }
    goto gg ;
    getch();
}
void adminModule :: adminPassUserChange()
{
    system("cls|clear");
    cout<<"\n\n\t\t\t Reseting Username and Password \n";
    cout<<endl<<endl;
    cout<<"Enter New Username : ";
    cin>>adminUsername;
    cout<<endl;
    cout<<"Enter New Password : ";
    cin>>adminPass;
    cout<<endl;
}
void adminModule :: managerCreate(){
    system("cls|clear");
    cout<<"\n\n\t\t\t ManagerCreatepanel \n";
    fstream file;
    cout<<"How many manager to be added ?\n"<<'\n';
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Insert id :";
        cin>>managerId;
        cout<<endl;
        cout<<"Insert Name : ";
        cin.ignore();getline(cin,managerName);
        cout<<endl;
        cout<<"Insert Gender : ";
        cin>>managerGender;
        cout<<endl;
        cout<<"Insert Post : ";
        cin>>managerPost;
        cout<<endl;
        cout<<"Insert Salary : ";
        cin>>managerSalary;
        cout<<endl;

        file.open("managerRecord.txt",ios::app|ios::out);
        file<<managerId<<endl;
        file<<managerName<<endl;
        file<<managerGender<<endl;
        file<<managerPost<<endl;
        file<<managerSalary<<endl;
        file.close();
    }
}
void adminModule :: managerRead(){
    system("cls|clear");
    fstream file;
    file.open("managerRecord.txt",ios::in);
    cout<<"\n\n\t\t\t\tDisplay Record\n";
    cout<<"ManagerId "<<" | "<<"ManagerName "<<" | "<<"ManagerGender "<<" | "<<"ManagerPost "<<" | "<<"ManagerSalary "<<'\n';

    cout<<"--------------------------------------------------------------------------------"<<"\n";
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank freeze*/
    }
    while(file>>managerId)
    {
        file.ignore();
        getline(file,managerName);
        file>>managerGender>>managerPost>>managerSalary;
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerId;
        cout<<"|  ";
        cout.fill(' ');
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerName<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerGender<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerPost<<"| ";
        cout.setf(ios :: left, ios :: adjustfield);
        cout.width(10);
        cout<<managerSalary<<" $";
        cout<<'\n';
    }
    file.close();
    cout<<"\n\n\nPress any key to go back"<<'\n';
    getch();
}
void adminModule :: managerUpdate(){
    found=0;
    system("cls|clear");
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
    while(file>>managerId)
    {
        file.ignore();
        getline(file,managerName);
        file>>managerGender>>managerPost>>managerSalary;
        if(testId==managerId)
        {
            found=1;
            cout<<"Insert id :";
            cin>>managerId;
            cout<<endl;
            cout<<"Insert Name : ";
            cin.ignore();getline(cin,managerName);
            cout<<endl;
            cout<<"Insert Gender : ";
            cin>>managerGender;
            cout<<endl;
            cout<<"Insert Post : ";
            cin>>managerPost;
            cout<<endl;
            cout<<"Insert Salary : ";
            cin>>managerSalary;
            cout<<endl;
            file1<<managerId<<endl;
            file1<<managerName<<endl;
            file1<<managerGender<<endl;
            file1<<managerPost<<endl;
            file1<<managerSalary<<endl;
        }
        else
        {
            file1<<managerId<<endl;
            file1<<managerName<<endl;
            file1<<managerGender<<endl;
            file1<<managerPost<<endl;
            file1<<managerSalary<<endl;
        }
    }
    file.close();
    file1.close();
    remove("managerRecord.txt");
    rename("managerRecord1.txt","managerRecord.txt");
    if(found)
        cout<<"Successfuly Updated\nPress any key to go back"<<'\n';
    else
        cout<<"Not found \nPress any key to go back"<<'\n';
    getchar();
}
void adminModule :: managerDelete(){
    found=0;
    system("cls|clear");
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
    while(file>>managerId)
    {
        file.ignore();
        getline(file,managerName);
        file>>managerGender>>managerPost>>managerSalary;
        if(testId==managerId)
            found=1;
        if(testId!=managerId)
        {
            file1<<managerId<<endl;
            file1<<managerName<<endl;
            file1<<managerGender<<endl;
            file1<<managerPost<<endl;
            file1<<managerSalary<<endl;
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
    getchar();
}
