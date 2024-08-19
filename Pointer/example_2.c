#include "stdio.h"
#include "assert.h"

void sum(int a, int b)
{
    printf("sum of %d + %d is %d\n",a,b,a+b);
}

void subtract(int a,int b)
{
    printf("subtract of %d - %d is %d\n",a,b,a-b);
}

void multiple(int a, int b)
{
    printf("multiple of %d x %d is %d \n",a,b, a*b );
}
double divide(int a, int b)
{
    assert(b!=0);
    return (double)a/b;
}
int main(int argc, char const *argv[])
{
    /* code */
    void (*ptr_func)(int,int );
    ptr_func=sum;
    (*ptr_func)(2,3);
    ptr_func=subtract;
    (*ptr_func)(2,3);
    ptr_func=multiple;
    (*ptr_func)(2,3);
    double (*ptr_func_1)(int,int);
    ptr_func_1=divide;
    printf("divide is %f\n",(*ptr_func_1)(3,2));
    return 0;
}

