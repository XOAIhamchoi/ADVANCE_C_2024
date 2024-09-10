#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    int data;
    struct node* next;
}node_t;



node_t* CreateNote(int value)
{
    node_t* note = (node_t*)malloc(sizeof(node_t));
    note->data = value;
    note->next = NULL;
    return note;
}
bool Empty(node_t *linked_list)
{
    return (linked_list==NULL)?true:false; 
}
int Size(node_t* linked_list) // lay kich thuoc cua list
{
    int count = 0;
    node_t* ptr = linked_list;
    while(ptr->next != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
void PushBack(node_t** linked_list, int value)
{
    node_t* new_note = CreateNote(value);
    if(Empty(*linked_list))
    {
        *linked_list= new_note;
        return; 
    }
    node_t* ptr = *linked_list;
    while(ptr->next != NULL)
    {
        ptr= ptr->next;
    }
    ptr->next = new_note;

}
void PushFront(node_t** linked_list, int value)
{
    node_t* new_note = CreateNote(value);
    if(Empty(*linked_list))
    {
        *linked_list= new_note;
        return;
    }
    new_note->next = *linked_list;
    *linked_list= new_note;     


}
void PopBack(node_t** linked_list)
{
    if(Empty(*linked_list))
    {
        printf("linked list is empty\n");
        return;
    }
    node_t* ptr1= *linked_list;

    if(ptr1->next == NULL)
    {
        free(ptr1);
        *linked_list = NULL;
        return;
    }

    while(ptr1->next->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    node_t* temp = ptr1->next;
    ptr1->next= NULL;
    free(temp);
}
void PopFront(node_t** linked_list)
{
    if(Empty(*linked_list))
    {
        printf("linked list is empty\n");
        return;
    }
    node_t* ptr1= *linked_list;

    if(ptr1->next == NULL)
    {
        free(ptr1);
        *linked_list = NULL;
        return;
    }
    node_t* temp = *linked_list;
    *linked_list = temp->next;
    free(temp);
    return;
}
int Front(node_t* linked_list) // lay gia tri cua node dau tien
{
    if(Empty(linked_list))
    {
        printf("linked list is empty\n");
        return -1;
    }
    return linked_list->data;
}
int Back(node_t* linked_list) // lay gia tri cua node dau tien
{
    if(Empty(linked_list))
    {
        printf("linked list is empty\n");
        return -1;
    }
    node_t* ptr = linked_list;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;  
}
int Get(node_t* linked_list, int pos)// lay gia tri tai mot vi tri bat ky
{
    if(pos<0)
    {
        printf("this value of the position is wrong\n");
        return -1;
    }
    
    if(pos > Size(linked_list))
    {
        printf("inconvennient position\n");
        return -1;
    }
    
    node_t* ptr = linked_list;
    int count = 0;
    while(count < pos)
    {
        ptr=ptr->next;
        count++;
    }
    
    return ptr->data;

    
    
}
void Insert(node_t** linked_list, int value, int pos)// them 1 node vao mot vi tri bat k
{
    if(pos<0)
    {
        printf("this value of the position is wrong\n");
        return;
    }
    if(pos > Size(*linked_list))
    {
        printf("inconvennient position\n");
        return;
    }
    if(pos == 0)
    {
        PushFront(linked_list,value);
        return;
    }
    node_t* new_note = CreateNote(value);
    node_t* ptr = *linked_list;
    int count=0; 
    while(count<pos-1)
    {
        count++;
        ptr = ptr->next; 
    }
    new_note->next=ptr->next; 
    ptr->next= new_note;
    return;      
}
void DeleteList(node_t **linked_list, int pos) // xoa 1 node tai mot vi tri bat ky
{
    if(pos<0)
    {
        printf("this value of the position is wrong\n");
        return;
    }
    if(pos > Size(*linked_list))
    {
        printf("inconvennient position\n");
        return;
    }
    if(pos == 0)
    {
        PopFront(linked_list);
        return;
    }
    node_t* ptr = *linked_list;
    int count=0; 
    while(count<pos-1)
    {
        count++;
        ptr = ptr->next;
    }
    node_t* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return; 
}


int main()
{
    node_t *linked_list=NULL;
  

    PushBack(&linked_list, 1);
    PushBack(&linked_list, 2);
    PushBack(&linked_list, 3);
    PushBack(&linked_list, 5);
    PushFront(&linked_list,0);
    Insert(&linked_list,4,4);
    DeleteList(&linked_list,3);
    PopBack(&linked_list);
    

    printf("Value test: %d\n", Get(linked_list, 0));
    printf("Value test: %d\n", Get(linked_list, 1));
    printf("Value test: %d\n", Get(linked_list, 2));
    printf("Value test: %d\n", Get(linked_list, 3));
    printf("Value test: %d\n", Get(linked_list, 4));
    printf("Value test: %d\n", Get(linked_list, 5));
    return 0;
}
