#include "AdminModule.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;
adminModule :: adminModule()
{
    //adminUsername = "admin"; adminPass = "admin";
}
void adminModule:: menuAdminModule(){

gg :
    system("cls");
    cout<<"\n\n\t\t\t Main Panel \n";
    cout<<"1 AdminLogin\n"<<'\n';
    cout<<"2 ManagerLogin\n"<<'\n';
    cout<<"3 EmployeeLogin\n"<<'\n';
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
    system("cls");
    string Username,Password;
    fstream file;
    file.open("AdminPassword.txt",ios::in);
    file>>adminUsername;
    file>>adminPass;
    file.close();
    cout<<"Admin username : ";
    cin>>Username;
    cout<<endl;
    getchar();
    cout<<"Admin password : ";
    for (int i = 0; i < 50; i++) {
        char c;
        c = getch();
        if(c==13)break;
        Password+=c;
        cout<<"*";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Enter to proceed . . . . ."<<endl;
    getch();
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


    system("cls");
    string Username,Password, filePassword, fileUsername;
    int flag = 0;
    cout<<" Manager username : ";
    cin>>Username;
    cout<<endl;
    getchar();
    cout<<" Manager password : ";
    for (int i = 0; i < 50; i++) {
        char c;
        c = getch();
        if(c==13)break;
        Password+=c;
        cout<<"*";
    }
    cout<<endl;
    fstream file;
    file.open("MangerPass.txt", ios :: in);
    while(file>>fileUsername>>filePassword){
        if(Username == fileUsername && Password == filePassword)
        {
            flag = 1;
            cout<<'\n';
            cout<<" Login successful\n"<<'\n';
            cout<<" Enter to continue\n"<<'\n';
            getchar();
            menuManagerModule();
        }
    }
    file.close();
    if(flag==0){
        cout<<"\nWrong username or password\nPlease Try again\nPress any key to go back\n"<<'\n';
    }

}






void adminModule :: adminMenu(){
gg :
    system("cls");
    cout<<"\n\n\t\t\t Admin Panel\n";
    cout<<"1 Create Manager"<<'\n';
    cout<<"2 Read Manager"<<'\n';
    cout<<"3 Update Manager"<<'\n';
    cout<<"4 Delete Manager"<<'\n';
    cout<<"5 Admin Username And Password Change"<<'\n';
    cout<<"6 logout"<<'\n';
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
    system("cls");
    cout<<"\n\n\t\t\t Reseting Username and Password \n";
    string confirmPass;
    cout<<endl<<endl;
    cout<<"Enter New Username : ";
    cin>>adminUsername;
    cout<<endl;
    cout<<"Enter New Password : ";
    cin>>adminPass;
    cout<<endl;
    cout<<"Confirm New Password : ";
    cin>>confirmPass;
    if(adminPass==confirmPass){
        fstream file;
        file.open("AdminPassword.txt",ios::out);
        file<<adminUsername<<endl;
        file<<adminPass;
        cout<<endl;
        cout<<"Successfully Changed"<<endl;
        file.close();
    }
    else
    {
        cout<<endl;
        cout<<"Unable to change due to mismatch in Confirm Password"<<endl;
    }
    cout<<"Enter any Key to go back"<<endl;
    getchar();
}
void adminModule :: managerCreate(){
    system("cls");
    cout<<"\n\n\t\t\t ManagerCreatepanel \n"<<endl<<endl;
    fstream file;
    file.open("MangerUsedId.txt",ios::in);
    file>>usedID;
    file.close();
    cout<<"How many manager to be added ?\n"<<'\n';
    cin>>n;
    for(int i=0;i<n;i++){
        system("cls");
        cout<<"\n\n\t\t\t ManagerCreatepanel \n"<<endl<<endl;
        usedID++;
        cout<<"ID : "<<usedID<<'\n';
        fstream file1;
        file.open("MangerUsedId.txt",ios::out);
        file<<usedID;
        file.close();
        cout<<"Insert Name : ";
        while(1){
            getline(cin,managerName);
            if(managerName.length()!=0)
            {
                break;
            }
        }
        cout<<endl;
        cout<<"Insert Gender : ";
        while(1){
            cin>>managerGender;
            if(managerGender.length()!=0)
            {
                break;
            }
        }
        cout<<endl;
        cout<<"Insert Post : ";
        while(1){
            getline(cin,managerPost);
            if(managerPost.length()!=0)
            {
                break;
            }
        }
        cout<<endl;
        cout<<"Insert Salary : ";
        while(1){
            cin>>managerSalary;
            if(managerSalary.length()!=0)
            {
                break;
            }
        }
        cout<<endl;
        file1.open("MangerPass.txt",ios::app|ios::out);
        file1<<to_string(usedID)<<endl;
        file1<<to_string(usedID)<<endl;
        file1.close();
        file.open("managerRecord.txt",ios::app|ios::out);
        file<<usedID<<endl;
        file<<managerName<<endl;
        file<<managerGender<<endl;
        file<<managerPost<<endl;
        file<<managerSalary<<endl;
        file.close();
        cout<<endl;
        cout<<"Succesfully New Manager is Added"<<endl;
        getchar();
        if(i!=n-1)
        getchar();
    }
    cout<<endl<<"Press any key to go back"<<endl;
    getchar();
}
void adminModule :: managerRead(){
    system("cls");
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
    getchar();
}
void adminModule :: managerUpdate(){
    found=0;
   int  updateNo;
    system("cls");
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
            cout<<"1 new name"<<'\n';
            cout<<"2 new gender"<<'\n';
            cout<<"3 new post"<<'\n';
            cout<<"4 new salary"<<'\n';
            cin>>updateNo;
            if(updateNo==1)
            {
                cout<<"Insert Name : ";
                while(1){
                    getline(cin,managerName);
                    if(managerName.length()!=0)
                    {
                        break;
                    }
                }
                cout<<endl;
            }
            else if(updateNo==2)
            {
                cout<<"Insert Gender : ";
                while(1){
                    cin>>managerGender;
                    if(managerGender.length()!=0)
                    {
                        break;
                    }
                }
                cout<<endl;
            }
            else if(updateNo==3)
            {
                cout<<"Insert Post : ";
                while(1)
                {
                    getline(cin,managerPost);
                    if(managerPost.length()!=0)
                    {
                        break;
                    }
                }
                cout<<endl;

            }
            else if(updateNo==4)
            {
                cout<<"Insert Salary : ";
                while(1)
                {
                    cin>>managerSalary;
                    if(managerSalary.length()!=0)
                    {
                        break;
                    }
                }
                cout<<endl;
            }
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
    if(updateNo!=1)
    getchar();
}
void adminModule :: managerDelete(){
    found=0;
    system("cls");
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
