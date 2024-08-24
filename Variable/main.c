#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
     register  long i;
    
    clock_t start, end;

    start = clock();

    for ( i = 0; i < 99999999; i++);

    end = clock();

    printf("Time: %f\n", (double)(end - start)/1000);
    
    
    return 0;
}