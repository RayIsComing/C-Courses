#include<iostream>
using namespace std;

//继承实现页面
class  BasePage{
private:
    /* data */
public:
     BasePage(/* args */);
    ~ BasePage();
    //属性

    //行为
    void header(){
        cout << "首页、公开课、登录、注册（公共头部）" << endl;
    }
    void footer(){
       cout << "帮助中心（公共底部）" << endl;
    } 
    void left(){
        cout << "Java、Python、C++（公共分类列表）" << endl;
    }
};

 BasePage:: BasePage(/* args */)
{
}

 BasePage::~ BasePage()
{
}

//语法：class 子类 ：继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类

//Java页面

class Java : public BasePage 
{
private:
    /* data */
public:
    void content(){
        cout << "Java视频" << endl;
    }

};


//C++页面

class CPP : public BasePage 
{
private:
    /* data */
public:
    // CPP:Base(/* args */);
    // ~CPP:Base();
    void content(){
    cout << "CPP视频" << endl;
    }
};

// CPP:Base::CPP:Base(/* args */)
// {
// }

// CPP:Base::~CPP:Base()
// {
// }

void test01();


int main(){

    test01();
};


void test01(){
    cout << "Java下载视频页面如下" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}
