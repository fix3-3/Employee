#include "ManagerModule.h"
#include <iostream>
#include<windows.h>
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
    cout<<"6 Attendence Check\n"<<'\n';
    cout<<"7 Logout\n"<<'\n';
    cout<<"8 Exit\n"<<'\n';
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
            checkAttendence();
            break;
        case 7:
            return;
        case 8:
            exit(0);
        default :
            cout<<"Try again\n"<<'\n';
    }

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
        cout<<endl<<endl;
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

        cout<<endl<<endl;
        cout<<"Enter New Password : ";
        for(int i = 1; i<=50; i++)
        {
            char c;
            c = getch();
            if(c==13)break;
            newPassword+=c;
            cout<<"*";
        }
        cout<<endl<<endl;
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
            }
            else
            {
                    file<<user[j]<<endl;
                    file<<pass[j]<<endl;
            }
        }
        file.close();
        cout<<endl;
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
        return;
    }

}


void managerModule :: createEmployee(){
    system("cls");


    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);    //for create.employee text color
    SetConsoleTextAttribute(h,9);


    cout<<"\n\n\t\t\t EmployeeCreatepanel \n";
    fstream file;
    file.open("employeeusedID.txt",ios::in);   //****
    file>>employeeusedID;
    file.close();

    cout<<"How many employee to be added ?\n"<<'\n';
    cin>>n;
    for(int i=0;i<n;i++){
        employeeusedID++;   //****
        cout<<"ID : "<<employeeusedID<<'\n';
        file.open("employeeusedID.txt",ios::out);
        file<<employeeusedID;
        file.close();    //****


        // for non input enter
        cout<<"Insert Name : ";
         while(1){
            getline(cin,employeeName);
            if(employeeName.length()!=0)
            {
                break;
            }
          }
         cout<<endl;



        cout<<"Insert Gender : ";
        while(1){
            getline(cin,employeeGender);
            if(employeeGender.length()!=0)
            {
                break;
            }
          }
          cout<<endl;


        cout<<"Insert Post : ";
        while(1){
            getline(cin,employeePost);
            if(employeePost.length()!=0)
            {
                break;
            }
          }
        cout<<endl;


        cout<<"Insert Salary : ";
        while(1){
            getline(cin,employeeSalary);
            if(employeeSalary.length()!=0)
            {
                break;
            }
          }
        cout<<endl;


        //updated ckk ok
        fstream file1;
        file1.open("EmployeePass.txt",ios::app|ios::out);
        file1<<to_string(employeeusedID)<<endl;
        file1<<to_string(employeeusedID)<<endl;
        file1<<to_string(employeeusedID)<<endl;
        file1.close();



        file.open("employeeRecord.txt",ios::app|ios::out);
        //file<<employeeId<<endl;     //****
        file<<employeeusedID<<endl;
        file<<employeeName<<endl;
        file<<employeeGender<<endl;
        file<<employeePost<<endl;
        file<<employeeSalary<<endl;
        file.close();

       if(i!=n-1)
       getchar();
       }
}


void managerModule :: readEmployee(){
    system("cls");

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);    //for read.employee text color
    SetConsoleTextAttribute(h,14);

    fstream file;
    file.open("employeeRecord.txt",ios::in);
    /*cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t|  Display Record  |  \t\t\t\t\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~";
    cout<<'\n'<<'\n';
    cout<<"employeeId "<<"  | "<<"employeeName "<<"  | "<<"employeeGender "<<"  | "<<"employeePost "<<"  | "<<"employeeSalary "<<'\n';

    cout<<"-----------------------------------------------------------------------------------"<<"\n";*/
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
        /*cout<<"*************************************************Employee details************************************************"<<endl<<endl;
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
                cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;*/

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
    file.close();
    //cout<<"\n\n\n Thanks for appointed me!";
    cout<<"\n\t\t\tPress any key to go back"<<'\n';
    getchar();

}


void managerModule :: updateEmployee(){

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);    //for update.employee text color
    SetConsoleTextAttribute(h,2);


    found=0;
    int employeeupdateNo;       //****
    system("cls");
    fstream file,file1;
    file.open("employeeRecord.txt",ios::in);
    file1.open("employeeRecord1.txt",ios::app|ios::out);
    if(!file)
    {
        cout<<"You need to insert first \nPress any key\n";

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
            //cout<<"Insert id :";    //arefin
            //cin>>employeeId;
            //cout<<endl;
            cout<<"1 new name"<<'\n';
            cout<<"2 new gender"<<'\n';
            cout<<"3 new post"<<'\n';
            cout<<"4 new salary"<<'\n';

            cin>>employeeupdateNo;
            if(employeeupdateNo==1)
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


            else if(employeeupdateNo==2)
            {
                cout<<"Insert Gender : ";
                while(1){
                getline(cin,employeeGender);
                if(employeeGender.length()!=0)
                  {
                      break;
                  }
                }
                cout<<endl;
            }


            else if(employeeupdateNo==3)
            {
                cout<<"Insert Post : ";
                while(1){
                getline(cin,employeePost);
                if(employeePost.length()!=0)
                  {
                      break;
                  }
                }
                cout<<endl;
            }


            else if(employeeupdateNo==4)
            {
                cout<<"Insert Salary : ";
                while(1){
                getline(cin,employeeSalary);
                if(employeeSalary.length()!=0)
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
        cout<<"Successfuly Updated :: Thanks for your patience\nPress any key to go back"<<'\n';
    else
        cout<<"Not found \nPress any key to go back"<<'\n';

    getchar();
}



void managerModule :: deletEmployee(){

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);    //for delete.employee text color
    SetConsoleTextAttribute(h,4);


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
    if(found){
        //cout<<"Successfuly Deleted :: You fired me? okay, one day i will eat your company"<<endl;
        cout<<"\t\t\t\tPress any key to go back"<<'\n';
    }
    else
        cout<<"Not found\nPress any key to go back"<<'\n';

    getchar();
}
void managerModule :: checkAttendence()
{
    string day, month, time,  date , year;
    int f = 0;
    system("cls");
    cout<<endl<<endl<<"   ATTENDENCE CHECK   "<<endl<<endl;
    cout<<"Enter First Three Initial of Day : ";
    while(1)
    {
        cin>>day;
        if(day.length()!=0 && day.length()==3)
        {
            if(day[0]>90)day[0] = day[0]-32;
            if(day[1]<97)day[1] = day[1] + 32;
            if(day[2]<97)day[2] = day[2]+ 32;
            break;
        }
    }
    cout<<endl;
    cout<<"Enter First Three Initial of Month : ";
    while(1)
    {
        cin>>month;
        if(month.length()!=0 && month.length()==3)
        {
            if(month[0]>90)month[0] = month[0]-32;
            if(month[1]<97)month[1] = month[1] + 32;
            if(month[2]<97)month[2] = month[2]+ 32;
            break;
        }
    }
    cout<<endl;
    cout<<"Enter Date : ";
    while(1)
    {
        cin>>date;
        if(date.length()!=0)break;
    }
    cout<<endl;
    cout<<"Enter year : ";
    while(1)
    {
        cin>>year;
        if(year.length()!=0)break;
    }
    cout<<endl;
    fstream ff, attendant;
    ff.open("employeeRecord.txt");
    map<string,string>idName;
    while(ff>>employeeId)
        {
            ff.ignore();
            getline(ff,employeeName);
            ff>>employeeGender>>employeePost>>employeeSalary;
            idName[employeeId] = employeeName;
        }
    ff.close();
    attendant.open("employeeattendance.txt",ios::app|ios::out|ios::in);
    while(attendant>>attendDay>>attendMonth>>attendDate>>attendTime>>attendYear>>attendId)
    {
        if(attendDay==day&&attendMonth==month&&attendDate==date&&attendYear==year)
        {
            f = 1;
            cout<<attendId<<" "<<idName[attendId]<<" "<<attendTime<<endl<<endl;
        }
    }
    attendant.close();
    if(f==0)
    {
        cout<<"No Record Exist For This Day, Month and Date"<<endl<<endl;
    }


    cout<<"Press Any Key To Go Back"<<endl;
    getch();



}

