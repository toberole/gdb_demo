#include <stdio.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

typedef void (*Func)(void);
typedef int (*Func1)(int ,int);

void test_demo02(){
	printf("test_demo02\n");
}

int testx_demo02(int a,int b){
	return a+b;
}

void test1_demo02(Func f){
	Func1 f1 = (Func1)f;
	int k = f1(1,2);
	printf("test1_demo02 k = %d\n",k);
}

typedef struct stu
{
    int age;
    char s;
    long int i;
    
}Student;



int main(int argc, char const *argv[])
{
	// Func f = (Func)testx_demo02;
	// test1_demo02(f);


    // printf("Student bytes = %d\n", sizeof(Student));


	// int a = 11;
	// int *p = &a;
	// int **p1 = &p;

	// printf("p = %p\n",p );
	// printf("*p1 = %p\n",*p1 );

	A a;
	B b;
	C c;

	a = b;
	//静态多态 
	a.hello();// A::hello()

	// 动态多态 通过虚拟函数实现
	a.hello_1();

	
	printf("press any key to exit......\n");
	getchar();
	return 0;
}
