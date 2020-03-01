#include <iostream>
using namespace std;
class A {
public:
    void func1 () {};
    void func2 () {};
public:
    virtual void vfunc () {};
    virtual void vfunc2 () {};
    virtual ~A () {};//析构函数
private:
    int m_a;
    int m_b;
};
int main () {
    A a;
    cout << "sizeof() = " << sizeof(a) << endl;
}
