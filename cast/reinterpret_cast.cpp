#include <iostream> // std::cout std::endl

class int_type
{
public:
    int value;
};

int main(void)
{
    int_type t;
    t.value = 233;
    int *p = reinterpret_cast<int *>(&t);
    *p = 666;
    std::cout << t.value << std::endl;
    return 0;
}

/*
上面代码中将int_type类型的对象t的地址强制从int_type *转换成int *。

类int_type只有一个成员变量并且是int类型的，占用的大小就是int的大小。
所以使用int的指针操作int_type的地址是没有问题的，不会操作到无关的内存。如果使用static_cast，编译器检测这两个类型不是同一种类型，所以会报错。

注意：如果上面使用long long *p来操作int_type，由于long long会操作8个字节的内存，而int_type只有4字节，这样将会导致内存中的数据错误。
所以使用reinterpret_cast的时候要非常小心。
*/