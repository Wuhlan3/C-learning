#include<vector>
#include"Screen.cpp"
class Window_mgr{
private:
    std::vector<Screen> screens = {Screen(24, 80, ' ')};   //默认情况下，Window_mgr包含一个标准尺寸的空白Screen
    //可以省略掉=等号。 现在vector中只有一个元素
};