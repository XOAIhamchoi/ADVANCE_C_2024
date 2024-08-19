#include "stdio.h"

void text_1()
{
    printf("nguyen xuan oai");
}

void text_2()
{
    printf("toiyeubachkhoa");
}


int main(int argc, char const *argv[])
{
    /* code */
    void (*ptr_func)();
    ptr_func=text_1;
    (*ptr_func)();
    ptr_func=text_2;
    (*ptr_func)();
    return 0;
}
