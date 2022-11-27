#include<iostream>
using namespace std;

//多态；

//动物类
class Animal
{
public:
    //虚函数：virtual关键字。
    virtual void Speak(){
        cout <<"动物在说话" <<endl;
    }
};

//猫类
class Cat :public Animal
{
private:
    /* data */
public:

    void Speak(){
        cout <<"小猫在说话" <<endl;
    }
};

//执行说话函数
//地址早绑定，编译阶段就确定了编译地址。
//如果想执行让猫说话，那么
void doSpeak(Animal &animal){
    animal.Speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
}


int main(){

    test01();
    system("pause");

    return 0;
}