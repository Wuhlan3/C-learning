#include<mutex>

/*懒汉模式双检锁的单例模式*/

class Singleton{
private:
    static Singleton *s_instance;
    static std::mutex s_mutex;

private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton &){}
    Singleton& operator=(const Singleton &){}

public:
    static Singleton* getInstance(){
        if(s_instance == nullptr){
            std::unique_lock<std::mutex> lock(s_mutex);
            if(s_instance == nullptr){
                s_instance = new Singleton();
            }
        }
        return s_instance;
    }

    static void deleteInstance(){
        std::unique_lock<std::mutex> lock(s_mutex);
        if (s_instance)
    	{
        	delete s_instance;
        	s_instance = nullptr;
    	}
    }
};

std::mutex Singleton::s_mutex;
Singleton* Singleton::s_instance = nullptr;