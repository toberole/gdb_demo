#include <iostream>


class B:public A
{
public:
	B(){
		std::cout<<"--- B() ---"<<std::endl;
	}
	~B(){
		std::cout<<"--- ~B() ---"<<std::endl;
	}

	void hello(){
		std::cout<<"--- B::hello() ---"<<std::endl;
	}

	virtual void hello_1(){
		std::cout<<"--- B::hello_1() ---"<<std::endl;
	}
	
};