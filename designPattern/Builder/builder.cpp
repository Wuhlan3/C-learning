#include <iostream>
#include <string>
using namespace std;
class Car{
public:
    Car()=default;
    Car(string wheel_in,string engine_in,string carbody_in)
    :wheel{wheel_in}
    ,engine{engine_in}
    ,carbody{carbody_in}{
    }
    string wheel;   //车轮
    string engine;  //引擎
    string carbody; //车身
    void printCar(){
        cout << wheel << " " << engine << " " << carbody << endl;
    }
};

//builder接口
class builderInterface{
public:
    virtual std::string buildWheel()=0;
    virtual std::string buildEngine()=0;
    virtual std::string buildCarbody()=0;
    virtual ~builderInterface(){}
};


//hava汽车类
class havalBuilder:public builderInterface{
public:
    std::string buildWheel()override{return "goodyear";}
    std::string buildEngine()override{return "Toyato";}
    std::string buildCarbody()override{return "haval";}
};

//benz汽车类
class benzBuilder:public builderInterface{
public:
    std::string buildWheel()override{return "michelin";}
    std::string buildEngine()override{return "benz";}
    std::string buildCarbody()override{return "benz";}
};

//bmw汽车类
class bmwBuilder:public builderInterface{
public:
    std::string buildWheel()override{return "goodyear";}
    std::string buildEngine()override{return "bmw";}
    std::string buildCarbody()override{return "bmw";}
};

//director类
//封装了builder的具体执行过程。
class Director{
public:
    Director(builderInterface* builder){
        _pBuilder=builder;
    }
    Car bulidCar(){
        return Car(_pBuilder->buildWheel(),_pBuilder->buildEngine(),_pBuilder->buildCarbody());
    }
    ~Director(){
        if(_pBuilder) delete _pBuilder;
    }
private:
    builderInterface *_pBuilder;
};

int main(){
    Director dir1(new havalBuilder);
    auto haval=dir1.bulidCar();

    Director dir2(new benzBuilder);
    auto benz=dir2.bulidCar();

    Director dir3(new bmwBuilder);
    auto bmw=dir3.bulidCar();

    haval.printCar();
    benz.printCar();
    bmw.printCar();

    return 0;
}