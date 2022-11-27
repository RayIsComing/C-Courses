#include<iostream>
#include<string>
using namespace std;
//访问权限
//三种
//公共权限
//保护权限
//私有权限

class Person{
public:
    //公共权限
    string m_Name;//姓名
protected:
    //保护权限
    string m_Car; //汽车

private:
    //私有权限
    int m_Password;

//行为
public:
    void Function(){
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
    void ShowPerson(){
        cout << "名字：" << m_Name <<"车辆种类："<< m_Car << "密码:" << m_Password << endl;
    }

};

int main(){
    //实例化一个具体对象出来
    Person p1;

    p1.Function();

    p1.m_Name = "李四";
   // p1.m_Car = "Benz";//保护权限内容在类外不可以访问
   // p1.m_Password = 123;//私有权限的内容在类外不可以访问。   
    p1.ShowPerson();
    system("pause");

    return 0;
}

