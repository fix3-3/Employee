#include <iostream>
#include "AdminModule.h"
#include "ManagerModule.h"
#include "Employee.h"
#include "AdminModule.cpp"
#include "ManagerModule.cpp"
#include "Employee.cpp"

using namespace std;

int main()
{
    adminModule ob1;
    ob1.menuAdminModule();
    managerModule ob2;

    return 0;
}
