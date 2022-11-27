#include <iostream>
#include <cstring>
using namespace std;

class CEmployee {
    private:
        char szName[30];//名字
    public:
        int salary;
        void setName(char* Name);
        void getName(char* Name);
        float averageSalary(CEmployee e1, CEmployee e2);
};

void CEmployee::setName(char* Name){
    strcpy(szName,Name);
}

void CEmployee::getName(char* Name){
    strcpy(szName,Name);
}

float CEmployee::averageSalary(CEmployee e1, CEmployee e2){
    cout << e1.szName;
    salary = (e1.salary + e2.salary)/2;
    return salary;
}

int main(){
    float x;

    CEmployee e1, e2;
    //strcpy(e1.szName,"Tom123456789");
    e1.setName((char*)"Tom");
    e1.salary = 5000;
    e2.salary = 3001 ;
    x = e2.averageSalary(e1,e2);

    return 0;
}


