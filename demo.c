#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void test() {
    static int k = 0;
    k++;
    printf("k = %d\n", k);
}

// 可变参数
#include <stdarg.h>

void add(int num, ...) {
    // 定义一个接受可变参数的列表
    va_list v;
    // 将形参num之后的所有参数保存到列表中
    va_start(v, num);

    for (int i = 0; i < num; ++i) {
        // 按照int型解析可变参数
        int data = va_arg(v,
        int);

        printf("data: %d\n", data);
    }

    // 释放列表
    va_end(v);
}

int main(int argc, char const *argv[]) {

    // test();
    // test();

    add(3,1,2,3);


    printf("%s\n", "press any key to exit");
    getchar();
    return 0;
}

int main1() {
    char *firstName = "123";
    char *lastName = "456";
    char *name = (char *) malloc(strlen(firstName) + strlen(lastName));
    strcpy(name, firstName);
    strcat(name, lastName);
    printf("%s\n", name);

    char arr[1] = {-1};
    printf("arr = %s\n", arr);

    getchar();
    return 0;
}