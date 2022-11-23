#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <ctime>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//#include<string.h>

class Employee
{
    public:
        int x,found;
        string employeeId, employeeSalary, testId,employeeName, employeeGender, employeePost,employeeUsername,employeePass,dt,changePass,pass,username;
        void employeeLogin();
        void showDetails();
        void frommenuAdminModule();
        void editDetails();
        void Attendance();
        void passchange();
        //Employee();

    protected:

    private:
};

#endif // EMPLOYEE_H
