/*饿汉模式*/
class Singleton{
public: 
    Singleton* getInstance(){
        return &s_instance;
    }
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton s_instance;
};
Singleton Singleton::s_instance;