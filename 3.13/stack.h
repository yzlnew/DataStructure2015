template <class T>
class Stack {			//栈的类定义
public:
	Stack(){ };			//构造函数
	virtual void Push(T x) = 0;             //进栈
	virtual bool Pop(T& x) = 0;	     //出栈
	virtual bool getTop(T& x)const = 0; //取栈顶
	virtual bool IsEmpty()const = 0;	     //判栈空
	virtual bool IsFull()const = 0;	     //判栈满
};