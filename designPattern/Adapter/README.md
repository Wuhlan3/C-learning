## 适配器模式
适配器模式( Adapter)，将一个类的接口转换成客户希望的另外接口。（比如变压器et） 
Adapter模式使得原本由于接口不兼容而不能一起工作的类可以一起工作。
主要解决的原本的类已经有了，但却不能直接使用，而且短时间内无法改造它，或者压根就无法改造的时候就需要适配它。

比如说，类Cat和类Dog都已经固定好了，它们都有同样的动作，但是动作的接口不一样。如果想要通过同样的接口来命令它们，就可以用到适配器模式。