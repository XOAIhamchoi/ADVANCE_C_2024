#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct stack
{
    int *items;
    int size;
    int top;
}stack_t;

void initialize(stack_t* stack,int size)
{
    stack->items = (int*)malloc(sizeof(int)*size);  
    stack->size = size;
    stack->top = -1;
}
int is_empty(stack_t stack)
{
    return stack.top == -1 ? true:false;
}
int is_full(stack_t stack)
{
    return stack.top == stack.size-1 ? true:false;
}
void push_stack(stack_t* stack,int value)
{
    if(is_full(*stack))
    {
        printf("stack is overload\n");
        return;
    }
    stack->items[++stack->top]= value;
}
int pop_stack(stack_t* stack)
{
    if(is_empty(*stack))
    {
        printf("stack is empty\n");
        return -1;
    }
    return stack->items[stack->top--];
}
int top(stack_t stack)
{
    if(is_empty(stack))
    {
        printf("stack is empty\n");
        return -1;
    }
    return stack.items[stack.top];
}

int main(int argc, char const *argv[])
{
    stack_t stack1;
    initialize(&stack1, 5);


    push_stack(&stack1, 10);
    push_stack(&stack1, 20);
    push_stack(&stack1, 30);
    push_stack(&stack1, 40);
    push_stack(&stack1, 50);
    push_stack(&stack1, 60); // over load because size of stack is 5

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop_stack(&stack1)); // poping a value from stack
    printf("Pop element: %d\n", pop_stack(&stack1));// 

    printf("Top element: %d\n", top(stack1));

    return 0;
}



