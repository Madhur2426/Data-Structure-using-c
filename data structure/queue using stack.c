#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack1
{
    int top1;
    int capacity1;
    int* arr1

    ;
};
struct stack2
{
    int top2;
    int capacity2;
    int *arr2;
};
struct stack1* create1(int cap)
{
    struct stack1 *s;
    s=(struct stack1 *)malloc(sizeof(struct stack1));
    s->top1=-1;
    s->capacity1=cap;
    s->arr1=(int*)malloc(sizeof(int)*cap);
    return(s);
}
struct stack2* create2(int cap)
{
    struct stack2 *s;
    s=(struct stack2 *)malloc(sizeof(struct stack2));
    s->top2=-1;
    s->capacity2=cap;
    s->arr2=(int*)malloc(sizeof(int)*cap);
    return(s);
}
void push1(struct stack1 *s,int data)
{
    if(s->top1==s->capacity1-1)
        printf("\n STACK OVERFLOW \n");
    else
    {
        s->top1++;
        s->arr1[s->top1]=data;
    }
}
int pop1(struct stack1 *s)
{
    if(s->top1==-1)
        printf("\n UNDERFLOW \n");
    else
    {
        s->top1--;
    return(s->arr1[s->top1]);
}
}
void pop2(struct stack1 *s,struct stack2 *s2)
{
    int i=sizeof(s->arr1)/sizeof(int);
    if(s->top1==-1)
       {
           printf("\n UNDERFLOW \n");
       }
    else
    {
        while(i>-1)
        {
        s2->top2++;
        s2->arr2[s2->top2]=pop1(s);
        i--;
        }
    }
}
void rearrange(struct stack1 *s,struct stack2 *s2)
{
    int i=sizeof(s2->arr2)/sizeof(int);
    if(s2->top2==-1)
        printf("\n UNDERFLOW \n");
    else
    {
         while(i>-1)
        {
        s->top1++;
        s->arr1[s->top1]=s2->arr2[s2->top2];
        s2->top2--;
        i--;
    }
    }
}
void display(struct stack1 *s)
{
    int i;
    if(s->top1==-1)
        printf("\n underflow \n");
    else
    {
        for(i=0;i<=s->top1;i++)
            printf("%d",s->arr1[s->top1]);
    }
}
int menu()
{
    int choice;
    printf("1.ENTER ELEMENT IN QUEUE \n");
    printf("2.DELETE ELEMENT IN QUEUE \n");
    printf("3.DISPLAY QUEUE ELEMNTS \n");
    printf("4.TO EXIT \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    struct stack1 *s;
    struct stack2 *s2;
    int data,cap,del;
    printf("\n ENTER QUEUE CAPACITY \n");
    scanf("%d",&cap);
    s=create1(cap);
    s2=create2(cap);
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
           printf("ENTER DATA \n");
           scanf("%d",&data);
           push1(s,data);
           break;
        case 2:
                pop2(s,s2);
                rearrange(s,s2);
            break;
        case 3:
            display(s);
            getch();
            break;
        case 4:
            exit(0);
            break;
        default:printf("\n INVALID CHOICE RETRY \n");
        }
    }
}
