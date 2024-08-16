#include "stdio.h"
#include "stdarg.h"

#define sum(...) tong(__VA_ARGS__,-1)

int tong(int lable, ...)
{
    int value = lable;
    int tong = value;
    va_list va;
    va_start(va,lable);
    while((value = va_arg(va,int))!=-1)
    {
        tong += value;
    }
    va_end(va);
    return tong;


}


int main(int argc, char const *argv[])
{

    printf("SUM = %d\n",sum(1,2,3,4,5));
    return 0;
}
