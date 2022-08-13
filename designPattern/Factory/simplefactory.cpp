#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>

using namespace std;

class Operation
{
    private:
        double A, B;
    public:
        double GetA() const {return A;}
        double GetB() const {return B;}
        void SetA(double x) {A=x;}
        void SetB(double y) {B=y;}
        double virtual GetResult(){return 0;}
        Operation():A(0), B(0){}
};

class Add : public Operation
{
    public:
        double GetResult()
        {
            return GetA()+GetB();
        }
};

class Sub : public Operation
{
    public:
        double GetResult()
        {
            return GetA()-GetB();
        }
};

class Mul : public Operation
{
    public:
        double GetResult()
        {
            return GetA()*GetB();
        }
};

class Div : public Operation
{
    public:
        double GetResult()
        {
            return GetA()/GetB();
        }
};

class SimpleFactory
{
    public:
        static Operation * CreateOpeartor(char ch)
        {
            Operation * p;
            switch(ch)
            {
                case '+':
                    p = new Add();
                    break;
                case '-':
                    p = new Sub();
                    break;
                case '*':
                    p = new Mul();
                    break;
                case '/':
                    p = new Div();
                    break;
            }
            return p;
        }
};

int main(int argc, char *argv[])
{
    double A = 0;
    double B = 0;
    char ch = '\0';
    cin>>A>>ch>>B;
    
    //静态成员函数，没有this指针，不管有没有创建对象，都可以调用
    shared_ptr<Operation> op(SimpleFactory::CreateOpeartor(ch));
    op->SetA(A);
    op->SetB(B);
    cout<<op->GetResult()<<endl;
}