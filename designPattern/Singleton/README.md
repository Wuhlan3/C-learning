# 单例模式

## 什么是单例模式？

单例模式是指整个系统生命周期内，保证一个类只能产生一个实例，确保该类的唯一性。

> 例如，Windows 中只能打开一个任务管理器，这样可以避免因打开多个任务管理器窗口而造成内存资源的浪费，或出现各个窗口显示内容的不一致等错误。
>
> 在计算机系统中，还有 Windows 的回收站、操作系统中的文件系统、多线程中的线程池、显卡的驱动程序对象、打印机的后台处理服务、应用程序的日志对象、数据库的连接池、网站的计数器、Web 应用的配置对象、应用程序中的对话框、系统中的缓存等常常被设计成单例。

## 单例模式有什么特点呢？

构造函数和析构函数为私有类型，目的是禁止外部构造和析构。

- 构造函数和析构函数为私有类型，目的是禁止外部构造和析构。
- 拷贝构造函数和赋值构造函数是私有类型，目的是禁止外部拷贝和赋值，确保实例的唯一性。
- 类中有一个获取实例的静态方法，可以全局访问。

## C++单例模式的三种实现

### 1.普通懒汉式单例（线程不安全）

懒汉式：单例实例在第一次被使用时才进行初始化。

第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。

```C++
class Singleton
{
private:
    static Singleton* s_instance;
private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
public:
    static Singleton* getInstance() 
    {
        if(s_instance == nullptr) 
            s_instance = new Singleton();
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
```

> 补充一下，类中static函数的作用：
>
> 在类里的函数前加static，则这个函数就与对象无关了，这个类产生的所有对象共用这一个静态成员函数，
> 静态成员函数可以在尚未创建任何对象时就被调用，他只可以操作类中的静态数据成员。

### 2.加锁的懒汉式单例（双检锁）

双检锁，既保证了效率又保证了安全。

为什么要双检锁呢？假设有两个线程同时调用`getInstance()`，那么很有可能两个线程都通过了第一个判空，之后两个线程在争抢锁。这个时候里面就需要再次判空。外层的判空，是为了减少争抢锁排队的情况；内层的判空，是为了确保只new一个实例（重复new会导致内存泄漏，且违背单例模式）。

```c++
#include<mutex>
class Singleton
{
private:
    static Singleton* s_instance;
    static std::mutex s_mutex;

private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    //双检锁，第一次调用时，实例化
    static Singleton* getInstance() 
    {
        if(s_instance == nullptr){
            std::unique_lock<std::mutex> lock(s_mutex);
            if(s_instance == nullptr){
                s_instance = new Singleton();
            }
        } 
        return s_instance;
    }
    static void deleteInstance()
    {
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
```

### 3.饿汉模式

程序启动时就创建一个唯一的实例对象。

可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。

```c++
class Singleton
{
public:
    static Singleton* getInstance()
    {
        return &s_instance;
    }
private:
    Singleton(){};
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    static Singleton s_instance;
};
Singleton Singleton::s_instance; // 在程序入口之前就完成单例对象的初始化
```

### 单例模式是否会被破坏？

- 反射（虽然C++没有这个机制，但可以了解一下）
- 序列化（反序列化的过程中可能再创一个对象）
- 克隆