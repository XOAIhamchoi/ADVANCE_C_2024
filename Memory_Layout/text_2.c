// Cấp phát vùng nhớ trên heap và sửa dụng vùng nhớ đó.

#include <stdio.h>
#include <stdlib.h>

void function_1() {
    int size = sizeof(int)*10;
    int *list_num = (int *)malloc(size);

    printf("Malloc size: %d byte.\n", size);

    for(int index=0;index<10;index++) {
        list_num[index] = index;
    }

    for(int index=0;index<10;index++) {
        // printf("Address: 0x%p, Value: %d.\n", &list_num[index], list_num[index]);
        printf("Address: 0x%p, Value: %d.\n", list_num+index, *(list_num+index));
    }
    
    free(list_num);
}

int main(void) {

    function_1();
    return 0;
}