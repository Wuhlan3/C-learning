#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;

//观察者接口 基类
class ObserverInterface{
public:
    virtual void doSomething() = 0;
    virtual ~ObserverInterface(){}
};

//被观察者接口 基类
class SubjectInterface{
public:
    virtual void add(ObserverInterface *) = 0;  
    virtual void remove(ObserverInterface *) = 0;
    virtual void notify() = 0;
    virtual ~SubjectInterface(){}
};

class Me : public SubjectInterface{
public:
    virtual void add(ObserverInterface * observer) override {
        observers.push_back(observer);
    }
    virtual void remove(ObserverInterface * observer) override{
        auto it = find(observers.begin(), observers.end(), observer);
        if(it != observers.end()){
            observers.erase(it);
        }
    }
    virtual void notify()override{
        for(const auto & observer : observers){
            observer->doSomething();
        }
    }
private:
    vector<ObserverInterface *> observers;
};

class Daughter : public ObserverInterface{
    public:
        void doSomething() override{
            std::cout << "爸爸快回来了，快去开门！"<< std::endl;
        }
};

class Wife : public ObserverInterface{
    public:
        void doSomething() override{
            std::cout << "老公打电话来了，快去做饭吧！"<< std::endl;
        }
};

int main(){
    Me me;
    ObserverInterface *daughter = new Daughter();
    ObserverInterface *wife = new Wife();

    //消息订阅
    me.add(daughter);
    me.add(wife);

    //发通知
    me.notify();

    delete wife;
    delete daughter;
}