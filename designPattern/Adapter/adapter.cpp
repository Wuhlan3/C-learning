#include<iostream>
using namespace std;
/*适配者模式*/

class Cat{
public:
    void catBedding(){cout<<"meow meow meow"<<endl;}
    void catRoll(){cout<<"roll roll"<<endl;}
};

class Dog{
public:
    void dogBedding(){cout<<"wang wang wang"<<endl;}
    void dogRoll(){cout<<"roll roll"<<endl;}
};

class Target{
public:
    virtual void Bedding() = 0;
    virtual void Roll() = 0;
};

class adapterCat : public Target{
public:
    adapterCat(Cat* c) : cat(c) {}
    void Bedding()override{cat->catBedding();}
    void Roll()override{cat->catRoll();}
private:
    Cat* cat;
};

class adapterDog : public Target{
public:
    adapterDog(Dog* d) : dog(d) {}
    void Bedding()override{dog->dogBedding();}
    void Roll()override{dog->dogRoll();}
private:
    Dog* dog;
};

int main() {
  Cat* cat = new Cat();
  Dog* dog = new Dog();
  adapterCat c(cat);
  adapterDog d(dog);

  c.Bedding();
  c.Roll();
  d.Bedding();
  d.Roll();
}