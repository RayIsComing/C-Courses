#include <iostream>
#include "PeopleA.h"
#include "PeopleB.h"
using namespace std;
int main()
{
    PeopleA::Student stdu1(101, 18, "wang");
    cout << PeopleA::fun(5, 3) << endl;
    PeopleB::Student stdu1(101, 18, "wang");
    cout << PeopleB::fun(5, 3) << endl;
    return 0;
}