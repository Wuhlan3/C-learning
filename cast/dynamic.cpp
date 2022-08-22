#include<iostream>
using namespace std;
class Base {
public:
    virtual void print(){
        cout << "I am Base" << endl;
    }
};

class Son : public Base{
public:
    virtual void print(){
        cout << "I am Son" << endl;
    }
};

int main(){
    //向下转换成功
    Base *a = new Son();
    a->print();

    Son *b = dynamic_cast<Son*>(a);
    if(b){
        b->print();
    }else{
        cout << "convert error" << endl;
    }
    

    //向下转换失败
    Base *c = new Base();
    c->print();

    Son *d = dynamic_cast<Son *>(c);
    if(d){
        d->print();
    }else{
        cout << "convert error" << endl;
    }

    //向上转换
    Son* e = new Son();
    e->print();

    Base *f = dynamic_cast<Base*>(e);
    if(f){
        f->print();
    }else{
        cout << "convert error" << endl;
    }
}