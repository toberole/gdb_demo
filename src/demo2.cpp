#include <stdio.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <boost/asio.hpp>

typedef void (*Func)(void);

typedef int (*Func1)(int, int);

void test_demo02() {
    printf("test_demo02\n");
}

int testx_demo02(int a, int b) {
    return a + b;
}

void test1_demo02(Func f) {
    Func1 f1 = (Func1) f;
    int k = f1(1, 2);
    printf("test1_demo02 k = %d\n", k);
}

typedef struct stu {
    int age;
    char s;
    long int i;

} Student;

boost::asio::io_service io_service;

int main(int argc, char const *argv[]) {
    // Func f = (Func)testx_demo02;
    // test1_demo02(f);


    // printf("Student bytes = %d\n", sizeof(Student));


    // int a = 11;
    // int *p = &a;
    // int **p1 = &p;

    // printf("p = %p\n",p );
    // printf("*p1 = %p\n",*p1 );
/*
	A a;
	B b;
	C c;

	a = b;
	//静态多态 
	a.hello();// A::hello()

	// 动态多态 通过虚拟函数实现
	a.hello_1();
*/


    io_service.post([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "=== io_service.post ===" << std::endl;
    });

    boost::asio::io_service::work work(io_service);

    std::thread th1([]() {
        io_service.post([]() {
            std::cout << "=== th1 io_service.post task === thread_id: " << std::this_thread::get_id() << std::endl;
        });
    });

    std::thread th2([]() {
        io_service.post([]() {
            std::cout << "=== th2 io_service.post task === thread_id: " << std::this_thread::get_id() << std::endl;
        });
    });

    std::cout << "=== main task === thread_id: " << std::this_thread::get_id() << std::endl;

    io_service.reset();

    io_service.run();
    io_service.poll();

    io_service.stop();

//    io_service.poll();
//    std::cout << "------ io_service.poll() after ------" << std::endl;
//    io_service.poll();

    std::cout << "io_service.run() after" << std::endl;

    printf("press any key to exit......\n");
    getchar();
    return 0;
}
