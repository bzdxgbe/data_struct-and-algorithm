# data_struct-and-algorithm
this is an example about common data_struct and algorithm
    使用中文注释时应在注释内容与注释符号前后各添加一个空格以防止编码问题导致的错误解码;

shell相关:
        dirname/basename  str1                 #显示str1中最后一个"/"之前或之后的内容
        使用示例:
            dirname /usr/bin/sort           #显示/usr/bin
            basename /usr/bin/sort          #显示sort
            basename /include/stdio.h .h    #显示"stdio"即最后一个/之后的内容并删除其中的".h"
        readelf -s test.so                  #读取动态相关符号信息

    使用1024位长度的公钥/私钥加密信息时,其输出密文均固定为128字节,除去秘钥信息,最大允许输入明文长度均为117位,明文长度不足117位时会被补位;


    使用宏定义仅执行一次的函数如初始化函数可用 do {}while(0) 结构,     
    #define test_func(err) do{
        if (cb ) {
            test_struct hhh = {     // 结构体直接赋值
                .a = !!err,         // 对于0/1判断可用两次!!
                .b = 0
            };
            cb(&hhh, ud);
        }
    }while (0)
    test_func(err) 等价于 if(cb) cb(err, ud)

c相关:
    1: 结构体前向声明可防止未定义结构体并进行使用时的报错问题,一般在头文件前向声明,在源文件进行定义;
            struct test_struct1;
            typedef struct test_struct1 hhhhhh;

    2: 常见关键字:
            volatile            #用于直接从内存读写以绕过cpu的高速缓冲机制;
            atomic              #用于不同线程之间在不使用mutex的情况下实现数据的并发访问,比使用mutex保护的效率要高很多,本质是汇编底层加锁;
                                注意要么使用atomic申明变量,要么使用原子操作接口,如下:
                                加锁示例:
                                        pthread_mutex_lock(&count_lock);
                                        global_int++;
                                        pthread_mutex_unlock(&count_lock);
                                原子示例:
                                        type __sync_fetch_and_add (type *ptr, type value);      #返回更新前的值
                                        type __sync_add_and_fetch (type *ptr, type value);      #返回更新后的值

                                        #include <stdio.h>
                                        #include <stdlib.h>
                                        typedef volatile signed int type1;
                                        int main(int argc, char **argv){
                                            type1 count = 4;
                                            printf("count:%d\n",count);
                                            type1 retval = __sync_fetch_and_add(&count,10);
                                            printf("retval:%d    count:%d\n",retval,count);
                                            return 0;
                                        }


    3: 内存对齐:
            #pragma pack(n)     #改变编译器内存对齐方式,常用在网络报文处理,n可为(1,2,4,8,16),不使用这条指令则采取默认的字节对齐方式;
                                使用示例:
                                        #pragma pack(8)     #设置编译器按8字节对齐
                                        ...结构体定义...
                                        #pragma pack()      #恢复编译器默认对齐方式
    
    4: 柔性数组
            char a[0]           #柔性数组无元素且不占空间,本质是一个偏移量而非指针,它紧跟上一个元素之后的地址;
                                注意柔性数组成员前必须有一个其它类型成员,其所在结构体要分配大于结构体的内存以便柔性数组指向大于结构体的内存部分;
                                
                    5: 结构体内部对齐或预留:
            struct test1 {
                int a;
                uint8_t b:1;        //位域,b只使用了本子节的一个bit
                uint8_t pad[3];     //内存4字节对齐,也可做预留
                char c[0];          //柔性数组     
            }

    6: 关于static:
            静态全局变量及静态局部变量均在全局数据区,不会随着函数的退出而释放空间,前者只在声明它的整个文件可见,后者只在声明它的整个函数内可见;
            静态函数只能在声明它的文件当中可见,不能被其它文件使用;

    7: 关于符号隐藏:
            GCC4.0之后支持通过 -fvisibility=default/hidden 来设置当前编译库中符号的可见性:
                设为default时,没有显式标识为hidden的符号都处理为可见；
                设为hidden时，没有显式标识为可见的符号都处理为隐藏。
            当希望仅隐藏部分接口时可直接在接口前面加  __attribute__((visibility("default")));
                    __attribute__((visibility("default"))) void MyFunction1() {}   
                    __attribute__((visibility("hidden"))) void MyFunction2() {}
                    隐藏单个函数
                        #define HIDDENAPI __attribute__((visibility("hidden")))
                        HIDDENAPI void eaior_req_release(eaior_req_st *req);
                    #注意显示声明的可见性属性会覆盖编译时通过-fvisibility选项指定的值。

                GCC可见性pragma的优点是可以快速地标识一整块函数，而不需要将可见性属性应用到每个函数中。这个pragma的用法如下：
                    -L          编译时去找的动态库目录，即所有 -l 选项里的库都先从 -L 指定的目录去找，然后是默认的地方;
                    -rpath      运行时去找的动态库目录;
                    -rpath-link 编译时去找的动态库目录,例如需A.so，而A.so本身又需B.so的，此时A.so就会先从 -rpath-link 给的路径里找。
                -Wl,--exclude-libs=ALL
                    不自动导出库中的符号，也就是默认将库中的符号隐藏。
            gcc隐藏动态库符号相关:
                    https://www.cnblogs.com/my_life/articles/11118877.html
                    https://blog.51cto.com/liulixiaoyao/814329
                    http://www.javashuo.com/article/p-gwuzmvle-bm.html
                    
                    
                        8: 关于回调:
            typedef int* (*call_back)(int err, chat *req, void *ud);
            call_back loc

    9: 位域:
            https://blog.csdn.net/u011285208/article/details/88296030
    
    10: 文件缓冲:
            https://www.cnblogs.com/solohac/p/4154171.html      https://cloud.tencent.com/developer/article/1176374


exec使用:           https://blog.csdn.net/zxr916/article/details/109902966
xperf 使用          https://blog.csdn.net/superchickenchicken/article/details/109742765
window-api          https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getnamedpipeclientprocessid
windbg相关:         https://blog.csdn.net/hnzwx888/article/details/93372254         https://www.cnblogs.com/jijm123/p/16392465.html
app-verifier相关    https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/application-verifier#installing-appverifier

公私钥生成及使用示例
https://blog.csdn.net/qq_40110291/article/details/113351497?spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-113351497-blog-107019997.t5_layer_eslanding_A_4&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-113351497-blog-107019997.t5_layer_eslanding_A_4&utm_relevant_index=13

https://blog.csdn.net/makenothing/article/details/88429511?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-88429511-blog-53084585.pc_relevant_multi_platform_whitelistv4eslandingctr2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-88429511-blog-53084585.pc_relevant_multi_platform_whitelistv4eslandingctr2&utm_relevant_index=1


https://blog.csdn.net/qq_40110291/article/details/113351497?spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-113351497-blog-107019997.t5_layer_eslanding_A_4&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-113351497-blog-107019997.t5_layer_eslanding_A_4&utm_relevant_index=13
