#include "ManagerModule.h"
#include <iostream>
using namespace std;

void managerModule :: menuManagerModule(){
gg :
    system("cls");
    cout<<" Employee CRUD\n"<<'\n';
    cout<<"1 Create New Employee\n"<<'\n';
    cout<<"2 Read Employee\n"<<'\n';
    cout<<"3 Update Employee\n"<<'\n';
    cout<<"4 Delete An Employee\n"<<'\n';
    cout<<"5 Change Username And Password\n"<<'\n';
    cout<<"6 Back\n"<<'\n';
    cout<<"7 Exit\n"<<'\n';
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
            changeManagerPass();
            break;
        case 6:
            return;
        case 7:
            exit(0);
        default :
            cout<<"Try again\n"<<'\n';
    }
    // getch();
     getchar();
    goto gg ;
}
void managerModule :: changeManagerPass()
{
    system("cls");
    cout<<"\n\n\t\t\t Reseting Username and Password \n";
    string confirmPass, newUsername, newPassword, checkusername, oldUsername, oldPassword, username, password;
    int choice, flag = 1;
    cout<<endl;
    cout<<"* Enter 1 to change Username"<<endl;
    cout<<"* Enter 2 to change Password"<<endl;
    cout<<"* Enter 3 to go back"<<endl;
    cin>>choice;
    string user[100], pass[100];
    int i = 0;
    ifstream read;
    read.open("MangerPass.txt");
    while(read>>username>>password)
    {
        user[i] = username;
        pass[i] = password;
        i++;
    }
    int n = 0;
    /*while(n<3)
    {
        cout<<user[n]<<endl;
        n++;
    }*/
    read.close();

    if(choice==1)
    {
        system("cls");
        cout<<"\n\n\t\t\t Reseting Username \n"<<endl;
        cout<<"Enter Your Existing Username : ";
        cin>>oldUsername;
        cout<<endl;
        cout<<"Enter Your Existing Password : ";
        for(int i = 1; i<=50; i++)
        {
            char c;
            c = getch();
            if(c==13)break;
            oldPassword+=c;
            cout<<"*";
        }
        cout<<endl;
        cout<<"Enter New Username Without any Space : ";
        cin>>newUsername;
        cout<<endl;
        //fstream file;
        //file.open("MangerPass.txt",ios::in);
        /*while(file>>checkusername>>password)
        {
            if(checkusername==newUsername)
            {
                flag = 0;
                break;
            }
        }*/
        for(int j = 0; j<i; j++)
        {
            if(user[j]==newUsername)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            //fstream file1,file2;
            ofstream file;
            file.open("MangerPass.txt");
            int flag1 = 0;
            //file1.open("MangerPass.txt",ios::in);
            //file2.open("MPass.txt",ios::app|ios::out);
            //while(file1>>username>>password)
            for(int j = 0; j<i; j++)
            {
                if(user[j]==oldUsername && oldPassword==pass[j])
                {
                    flag1 = 1;
                    file<<newUsername<<endl;
                    file<<pass[j]<<endl;
                    //file2<<newUsername<<endl;
                    //file2<<password<<endl;

                }
                else
                {
                    file<<user[j]<<endl;
                    file<<pass[j]<<endl;
                    //file2<<username<<endl;
                    //file2<<password<<endl;
                }
            }
            file.close();
            //file1.close();
            //file2.close();
            //remove("MangerPass.txt");
            //rename("MPass.txt","MangerPass.txt");
            if(flag1){
                cout<<"Username Is Updated"<<endl<<endl;
            }
            else
            {
                cout<<"Cannot Update As Old Password and Username Does Not Match"<<endl<<endl;
            }
        }
        else
        {
            cout<<"Cannot Update As ";
            cout<<"New Username Already Exist"<<endl<<endl;
        }
        cout<<"Press Any Key To Go Back"<<endl;
        getchar();

    }
    else if(choice==2)
    {
        system("cls");
        int f = 0;
        cout<<"\n\n\t\t\t Reseting Password \n"<<endl;
        cout<<"Enter Your Existing Username : ";
        cin>>oldUsername;
        cout<<"Enter Your Existing Password : ";
        for(int i = 1; i<=50; i++)
        {
            char c;
            c = getch();
            if(c==13)break;
            oldPassword+=c;
            cout<<"*";
        }

        cout<<endl;
        cout<<"Enter New Password : ";
        for(int i = 1; i<=50; i++)
        {
            char c;
            c = getch();
            if(c==13)break;
            newPassword+=c;
            cout<<"*";
        }
        cout<<endl;
        cout<<"Confirm Password : ";
        for(int i = 1; i<=50; i++)
        {
            char c;
            c = getch();
            if(c==13)break;
            confirmPass+=c;
            cout<<"*";
        }
        cout<<endl;
        if(newPassword!=confirmPass)f = 2;

        ofstream file;
        file.open("MangerPass.txt");
        //fstream file1,file2;
        //file1.open("MangerPass.txt",ios::in);
        //file2.open("ManagerPass.txt",ios::app|ios::out);
       // while(file1>>username>>password)
        for(int j = 0; j<i; j++)
        {
            if(user[j]==oldUsername && oldPassword==pass[j] && newPassword==confirmPass)
            {
                    f = 1;
                    file<<user[j]<<endl;
                    file<<newPassword<<endl;
                    //file2<<username<<endl;
                    //file2<<newPassword<<endl;
            }
            else
            {
                    file<<user[j]<<endl;
                    file<<pass[j]<<endl;
                    //file2<<username<<endl;
                    //file2<<password<<endl;
            }
        }
        file.close();
        //file1.close();
        //file2.close();
        //remove("MangerPass.txt");
        //rename("ManagerPass.txt","MangerPass.txt");
        if(f==1){cout<<"Password Is Updated"<<endl<<endl;}
        else if(f==2){cout<<"New Password Is Not Same As Confirm Password"<<endl<<endl;}
        else
        {
            cout<<"Cannot Update as Username Does Not Exist"<<endl<<endl;
        }
        cout<<"Press Any Key To Go Back"<<endl;
        getchar();
    }
    else if(choice==3)
    {
        return;
    }
    else
    {
        cout<<"Invalid Choice"<<endl;
        cout<<endl<<"Enter any Key to Go Back"<<endl;
        getchar();
    }

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

    found=0;
    system("cls");
    fstream file,file1;
    file.open("employeeRecord.txt",ios::in);
    file1.open("employeeRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank 2 freeze*/
    }
    cout<<"employeeId to be updaated :\n";
    cin>>testId;
    while(file>>employeeId)
    {
        file.ignore();
        getline(file,employeeName);
        file>>employeeGender>>employeePost>>employeeSalary;
        if(testId==employeeId)
        {
            found=1;
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
            file1<<employeeId<<endl;
            file1<<employeeName<<endl;
            file1<<employeeGender<<endl;
            file1<<employeePost<<endl;
            file1<<employeeSalary<<endl;
        }
        else
        {
            file1<<employeeId<<endl;
            file1<<employeeName<<endl;
            file1<<employeeGender<<endl;
            file1<<employeePost<<endl;
            file1<<employeeSalary<<endl;
        }
    }
    file.close();
    file1.close();
    remove("employeeRecord.txt");
    rename("employeeRecord1.txt","employeeRecord.txt");
    if(found)
        cout<<"Successfuly Updated\nPress any key to go back"<<'\n';
    else
        cout<<"Not found \nPress any key to go back"<<'\n';
    getchar();



}
void managerModule :: deletEmployee(){
    found=0;
    system("cls");
    fstream file,file1;
    file.open("employeeRecord.txt",ios::in);
    file1.open("employeeRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank 2 freeze*/
    }
    cout<<"employeeId to be deleted\n";
    cin>>testId;
    while(file>>employeeId)
    {
        file.ignore();
        getline(file,employeeName);
        file>>employeeGender>>employeePost>>employeeSalary;
        if(testId==employeeId)
            found=1;
        if(testId!=employeeId)
        {
            file1<<employeeId<<endl;
            file1<<employeeName<<endl;
            file1<<employeeGender<<endl;
            file1<<employeePost<<endl;
            file1<<employeeSalary<<endl;
        }
    }
    file.close();
    file1.close();
    remove("employeeRecord.txt");
    rename("employeeRecord1.txt","employeeRecord.txt");
    if(found)
        cout<<"Successfuly Deleted\nPress any key to go back"<<'\n';
    else
        cout<<"Not found\nPress any key to go back"<<'\n';
    getchar();

}
