#include<iostream>
using namespace std;
#include<string>

//设计一个学生类,属性有名字和学号。
//可以给姓名和学号赋值，可以显示学生的姓名和学号；


//设计学生类；

class Student
{
public://

    //属性
    string m_Name; //姓名
    int m_ID; //学号
        
    //行为
    //显示姓名和学号
    void ShowStudent()
    {
        cout << "姓名：" << m_Name << "学号：" << m_ID << endl;
    }

    //给姓名赋值
    void SetName(string name){
        m_Name = name;
    }

    void SetID(int id){
        m_ID = id;
    }

};


int main() 
{
    //创建一个具体的学生：实例化对象
    Student s1;

    //给s1进行属性赋值
    s1.SetName("张三");
    //s1.m_Name = "张三";
    s1.SetID(1);
    // s1.m_ID = 1;
    s1.ShowStudent();

    Student s2;
    //s2.m_Name = "李四";
    s2.SetName("李四");
    s2.ShowStudent();

    system("pause");
    return 0;
}