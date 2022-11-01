#ifndef ONE_H
#define ONE_H
// #include "two.h"
#include <bits/stdc++.h>
using namespace std;


class one
{
    public:
        int x,n,found;
        string managerName,managerId,testId;
        one();
        void menuOne();
        void adminLogin();
        void managerLogin();
        void employeeLogin();
        void adminMenu();
        void managerCreate();
        void managerRead();
        void managerUpdate();
        void managerDelete();

            protected:

            private:
        };

#endif // ONE_H
