#include "Employee.h"
#include "AdminModule.h"
#include <bits/stdc++.h>
using namespace std;

void Employee :: frommenuAdminModule()
{

    adminModule A;
    A.menuAdminModule();


}

void Employee :: employeeLogin(){

    system("cls");
    string Username,Password, filePassword, fileUsername;
    int flag = 0;
    cout<<" Employee username : ";
    cin>>Username;
    cout<<endl;
    getchar();
    cout<<" Employee password : ";
    for (int i = 0; i < 50; i++) {
        char c;
        c = getch();
        if(c==13)break;
        Password+=c;
        cout<<"*";
    }
    cout<<endl;
    ifstream file;
    file.open("EmployeePass.txt");
    while(file>>fileUsername>>filePassword){
        //cout<<Username<<" "<<
        //cout<<fileUsername<<" "<<filePassword<<endl;
        if(Username == fileUsername && Password == filePassword)
        {
            flag = 1;
            cout<<"-----------Login Successful-----------"<<endl;
            cout<<"**************press enter*************"<<endl;
            destination1:
            getchar();
            cout<<"1 Read\n"<<'\n';
            cout<<"2 Update\n"<<'\n';
            cout<<"3 Attendance\n"<<'\n';
            cout<<"4 Log_Out\n"<<'\n';
            cout<<"5 Change Username & Password\n"<<'\n';
            cout<<"6 Exit\n"<<'\n';

            //cout<<"4 Exit\n"<<'\n';
            cin>>x;
                switch(x)
                {
                    case 1:
                        showDetails();
                        goto destination1;
                        break;
                    case 2:
                        editDetails();
                        goto destination1;
                        break;
                    case 3:
                        Attendance();
                        goto destination1;
                        break;
                    case 4:
                        cout<<"LOGGED OUT SUCCESSFULLY"<<endl;
                        frommenuAdminModule();
                        break;
                    case 5:
                        cout<<"----------Change Username & Password----------"<<endl;
                        passchange();
                        break;
                    case 6:
                        exit(0);
                    default :
                        cout<<"Try again\n"<<'\n';
                }
                getchar();
        }

    }
    file.close();
    if(flag==0){
        cout<<"\nWrong username or password\nPlease Try again\nPress any key to go back\n"<<'\n';
    }



}


 void Employee :: showDetails(){

     system("cls||clear");

     fstream f,f1;
        f.open("employeeRecord.txt");
        //emp:
        cout<<"Check details for ID :";
        cin>>testId;
            while(f>>employeeId)
            {
                f.ignore();
                getline(f,employeeName);
                f>>employeeGender>>employeePost>>employeeSalary;
                if(testId==employeeId)
                {
                    //f>>employeeId>>employeeName>>employeeGender>>employeePost>>employeeSalary;
                //f.close();
                cout<<"*************************************************Employee details************************************************"<<endl<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<"Employee Id";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(25);
                cout<<"Employee Name";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<"Employee Gender";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<"Employee Post";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Salary"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;

                //cout<<employeeId<<"    |"<<employeeName<<"    |"<<employeeGender<<"        |"<<employeePost<<"    |"<<employeeSalary<<endl;
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<employeeId;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(25);
                cout<<employeeName;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<employeeGender;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(20);
                cout<<employeePost;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<employeeSalary<<"$";


                cout<<'\n';

                }


            }
            f.close();
            cout<<"Press any key to go back"<<endl;
            getchar();
            //goto emp;



 }
 void Employee :: editDetails(){

       found=0;
   int  updateNo;
    system("cls");
    fstream file,file1;
    file.open("employeeRecord.txt",ios::in);
    file1.open("employeeRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";
        // adminMenu(); /*blank 2 freeze*/
    }
    cout<<"EmployeeId to be updaated :\n";
    cin>>testId;
    while(file>>employeeId)
    {
        file.ignore();
        getline(file,employeeName);
        file>>employeeGender>>employeePost>>employeeSalary;
        if(testId==employeeId)
        {
            found=1;
            cout<<"1 new name"<<'\n';
            cout<<"2 new gender"<<'\n';

            cin>>updateNo;
            if(updateNo==1)
            {
                cout<<"Insert Name : ";
                while(1){
                    getline(cin,employeeName);
                    if(employeeName.length()!=0)
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
                    cin>>employeeGender;
                    if(employeeGender.length()!=0)
                    {
                        break;
                    }
                }
                cout<<endl;
            }
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
    if(updateNo!=1)
    getchar();



 }

 void Employee :: Attendance()
{

    fstream attendant,f;
    f.open("employeeRecord.txt");
    attendant.open("employeeattendance.txt",ios::app|ios::out|ios::in);

    while(f>>employeeId)
            {
                f.ignore();
                getline(f,employeeName);
                f>>employeeGender>>employeePost>>employeeSalary;
                cout<<"Employee ID: "<<employeeId<<endl<<"Press Present(p) or Absent(a) :"<<endl;
                char c;
                cin>>c;
        if(c=='p')
        {
            time_t now = time(0); // get current dat/time with respect to system

            char* dt = ctime(&now); // convert it into string

            //cout << "The local date and time is: " << dt << endl; // print local date and time

            tm* gmtm = gmtime(&now); // for getting time to UTC convert to struct
            dt = asctime(gmtm);
            //cout << "The UTC date and time is:" << dt << endl; // print UTC date and time
            //cout<<endl<<dt<<endl;
            attendant<<dt<<endl<<employeeId<<endl;

        }


    }



}

void Employee :: passchange()
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
    read.open("EmployeePass.txt");
    while(read>>username>>password)
    {
        user[i] = username;
        pass[i] = password;
        i++;
    }
    int n = 0;

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
            file.open("EmployeePass.txt");
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

                }
                else
                {
                    file<<user[j]<<endl;
                    file<<pass[j]<<endl;
                }
            }
            file.close();

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
        file.open("EmployeePass.txt");
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
            }
            else
            {
                    file<<user[j]<<endl;
                    file<<pass[j]<<endl;
            }
        }
        file.close();

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
