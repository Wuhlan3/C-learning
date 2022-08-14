
/*懒汉模式线程不安全的单例模式*/
class Singleton{
private:
    static Singleton * s_instance;
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
public:
    //线程不安全
    static Singleton* getInstance(){
        if(s_instance == nullptr){
            s_instance = new Singleton();
        }
        return s_instance;
    }
    static void deleteInstance()
    {
    	if (s_instance)
    	{
        	delete s_instance;
        	s_instance = nullptr;
    	}
    }
};

Singleton* Singleton::s_instance = nullptr;