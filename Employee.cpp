#include "Employee.h"
#include <bits/stdc++.h>
using namespace std;


void Employee :: employeeLogin(){

    //ifstream in("EmployeePass.txt");
    string pass,username;
    cout<<"Enter Username: ";
    cin>>username;
    cout<<endl;
    cout<<"Enter Password: ";
    cin>>pass;
    cout<<endl;
    int f = 0;
    //while(file>>employeeUsername>>employeePass)
    //{
        if(username=="Admin"&& pass=="Admin")
        {
            f = 1;
            showDetails();
        }

    //}
    if(f==0)
    {
        cout<<"Wrong Username And Password"<<endl;
        cout<<"Press any key to go back"<<endl;
    getchar();
    }

}


 void Employee :: showDetails(){

     system("cls|clear");

     fstream f,f1;
        f.open("employeeRecord.txt");
        cout<<"Check this Employee details :";
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
                cout<<"***********************************Employee details***********************************"<<endl<<endl;
                cout<<"--------------------------------------------------------------------------------------"<<endl;
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Id";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Name";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Gender";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Post";
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<"Employee Salary"<<endl;
                //cout<<employeeId<<"    |"<<employeeName<<"    |"<<employeeGender<<"        |"<<employeePost<<"    |"<<employeeSalary<<endl;
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<employeeId;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<employeeName;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
                cout<<employeeGender;
                cout<<"|  ";
                cout.fill(' ');
                cout.setf(ios :: left, ios :: adjustfield);
                cout.width(10);
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




 }

