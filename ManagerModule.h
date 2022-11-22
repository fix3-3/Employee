#ifndef MANAGERMODULE_H
#define MANAGERMODULE_H
#include "ManagerModule.h"
#include<bits/stdc++.h>
using namespace std;

// #include "one.h"

class managerModule
{
    public:
        int n,x,found;
        int employeeusedID;   //****
        string employeeName,employeeId,testId,employeeGender, employeePost, employeeSalary;

        //two();
        void menuManagerModule();
        void createEmployee();
        void readEmployee();
        void updateEmployee();
        void deletEmployee();
        void changeManagerPass();
    protected:

    private:
};

#endif // TWO_H
