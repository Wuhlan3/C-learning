#include<iostream>
using namespace std;

class Prototype{
public:
    Prototype(){}
    virtual ~Prototype(){}
    virtual Prototype * Clone() = 0;
};

class ConcretePrototype : public Prototype{
public:
    ConcretePrototype():parameter(0){}
    ConcretePrototype(const ConcretePrototype & rhs){
        parameter = rhs.parameter;
    }
    ConcretePrototype* Clone(){
        return new ConcretePrototype(*this);
    }
private : 
    int parameter;
};

int main(int argc , char **argv)
{
    //生成对象
    ConcretePrototype * conProA = new ConcretePrototype ();
 
    //复制自身
    ConcretePrototype * conProB = conProA->Clone();
 
    delete conProA;
    conProA= NULL ;
 
    delete conProB;
    conProB= NULL ;
 
    return 0;
}