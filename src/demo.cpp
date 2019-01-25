#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iconv.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <exception>


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

void test1() {
    char *arr = "计算机技术";
    printf("arr size = %d\n", sizeof(arr));
    printf("arr len = %d\n", strlen(arr));


    char buf[100];
    printf("buf size = %d\n", sizeof(buf));
    printf("buf len = %d\n", strlen(buf));


    int kk = 0;
    int *p = &kk;
    printf("p size = %d\n", sizeof(p));

}

void test2() {
    char *arr = "中国你好";
    int len = strlen(arr);

    for (int i = 0; i < len; ++i) {
        printf("%d  ", arr[i]);
    }

    printf("\n");

    printf("arr = %s\n", arr);
}

//////////////////////////编码转换////////////////////////
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen,
                 char *outbuf, size_t outlen) {
    iconv_t cd;
    char **pin = &inbuf;
    char **pout = &outbuf;

    cd = iconv_open(to_charset, from_charset);
    if (cd == 0)
        return -1;
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
        return -1;
    iconv_close(cd);
    *pout = NULL;

    return 0;
}

int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    return code_convert("utf-8", "gb2312", inbuf, inlen, outbuf, outlen);
}

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    return code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
}
//////////////////////////编码转换////////////////////////

void test_u2g_g2u() {
    char *s = "中国";
    int fd = open("u2g.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char buf[10];
    u2g(s, strlen(s), buf, sizeof(buf));
    write(fd, buf, strlen(buf));
    close(fd);

    fd = open("g2u.txt2", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char buf2[10];
    g2u(buf, strlen(buf), buf2, sizeof(buf2));
    write(fd, buf2, strlen(buf2));
    close(fd);
}

void test3() {
    char pattern[] = {'o', 'u', 'l', 'd', 'e'};

    printf("sizeof = %d\n", sizeof(pattern));
    printf("strlen = %d\n", strlen(pattern));
}

void test4() {
    int fd = open("./test_fd.txt", O_RDWR);
    int fd_c = dup(fd);
    char buf[1] = {0};

    read(fd, buf, 1);
    printf("fd read ch = %c\n", buf[0]);

    read(fd_c, buf, 1);
    printf("fd_c read ch = %c\n", buf[0]);

    close(fd);
    close(fd_c);
}

void test6() {
    int i = 1 / 0;
}

void test5() {
    try {
        test6();
    } catch (...) {
        printf("error msg \n");
    }

    printf("%s\n", "发生了异常");
}


// 字符串的效率从高到低依次为：+=、append()、stringstream、sprintf()。
void test7() {
//    std::string strS;
//    strS += "Hello ";
//    strS += "World";
//
//    // printf("",str.c_)




}

void byteorder() {
    union {
        short value;
        char union_bytes[sizeof(short)];
    } test;

    test.value = 0x0102;

    if (test.union_bytes[0] == 1 && test.union_bytes[1] == 2) {
        printf("big endian\n");
    } else if (test.union_bytes[1] == 1 && test.union_bytes[0] == 2) {
        printf("small endian\n");
    } else{
        printf("unknown ...\n");
    }

}


int main1(int argc, char const *argv[]) {

    // test();
    // test();

    // add(3,1,2,3);

    // char ch = 150;
    // printf("ch = %c\n",ch);

    // int *p = NULL;
    // free(p);

    // test2();
    // test_u2g_g2u();

    // printf("sizeof(int) = %d\n",sizeof(int) );
    // printf("sizeof(short) = %d\n",sizeof(short) );

    // int ass[5] = {1};
    // for (int i = 0; i < 5; ++i)
    // {
    //     printf("%d ", ass[i]);
    // }

    // printf("\n");

    // printf("%6.3f\n",1.2f );


    // test5();

    byteorder();


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