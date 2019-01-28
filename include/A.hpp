#include <iostream>


class A
{
public:
	A(){
		std::cout<<"--- A() ---"<<std::endl;
	}
	~A(){
		std::cout<<"--- ~A() ---"<<std::endl;
	}

	void hello(){
		std::cout<<"--- A::hello() ---"<<std::endl;
	}

	virtual void hello_1(){
		std::cout<<"--- A::hello_1() ---"<<std::endl;
	}
};