#include <iostream>


class C:public A
{
public:
	C(){
		std::cout<<"--- C() ---"<<std::endl;
	}
	~C(){
		std::cout<<"--- ~C() ---"<<std::endl;
	}

	void hello(){
		std::cout<<"--- C::hello() ---"<<std::endl;
	}

	virtual void hello_1(){
		std::cout<<"--- C::hello_1() ---"<<std::endl;
	}
	
};