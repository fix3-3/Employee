#include <iostream>
#include "AdminModule.h"
#include "ManagerModule.h"
#include "Employee.h"

using namespace std;

int main()
{
    adminModule ob1;
    ob1.menuAdminModule();
    managerModule ob2;
//    ob1::menuone();  //how to implement?
    // ob2.menutwo();

    return 0;
}
