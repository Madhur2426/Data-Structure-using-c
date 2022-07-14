#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int capacity;
    int *array;
};
struct stack* create(int cap)
{
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=cap;
    s->array=(int*)malloc(sizeof(int)*cap);
    return(s);
}
void push(struct stack *s,int data)
{
    if(s->top==s->capacity-1)
        printf("\n STACK OVERFLOW \n");
    else
    {
         s->top++;
        s->array[s->top]=data;

    }
}
void pop(struct stack *s)
{
    int del;
    if(s->top==-1)
        printf("\n UNDERFLOW \n");
    else
    {
        del=s->array[s->top];
        s->top--;
    printf("%d POPPED \n",del);
}
}
void main()
{
    int p,q,r,s,t;
   struct stack* g;
   g=create(4);
   push(g,1);
   push(g,2);
   push(g,3);
   push(g,4);
   pop(g);
   pop(g);
   pop(g);
   pop(g);
   pop(g);
}
