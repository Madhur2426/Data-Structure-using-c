#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
struct queue *create()
{
struct queue *q;
 int cap;
 printf("\n enter capacity\n ");
 scanf("%d",&cap);
q=(struct queue*)malloc(sizeof(struct queue));
q->front=-1;
q->rear=-1;
q->capacity=cap;
q->arr=(int*)malloc(sizeof (int)*cap);
return(q);
}
int isfull(struct queue *q)
{
    return((q->rear+1)%q->capacity==q->front);
}
int isempty(struct queue *q)
{
    return(q->front==-1);
}
void insert(struct queue *q)
{
    int x;
    if(q->capacity<0)
    printf("\n INVALID CAPACITY \n");
   else if(isfull(q))
        printf("\n queue is full \n");
   else{
    printf("\n enter data \n");
    scanf("%d",&x);
    q->rear = (q->rear + 1)% q->capacity;
    q->arr[q->rear] = x;
    if(q->front==-1)
    q->front=q->rear;
}
}
int dequeue(struct queue *q)
{
    int del;
    if(isempty(q))
       {
           printf("\n QUEUE IS EMPTY \n");
           return(-9999);
       }
    else
    {
    del= q->arr[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front=(q->front+1)%q->capacity;
    }
    return(del);
}
  void queueDisplay(struct queue *q)
    {
        int i;
        if (isempty(q))
            printf("\nQueue is Empty\n");
        else if(q->rear>=q->front)
        {
        for (i=q->front;i<=q->rear;i++)
            printf(" %d \t", q->arr[i]);
    }
    else
    {
        if(q->rear<q->front){
            for(i=0;i<=q->rear;i++)
                printf("%d \t",q->arr[i]);
        }
        for(int i=q->front;i<=q->capacity-1;i++)
            printf("%d \t",q->arr[i]);
    }
    }
int menu()
{
    int choice;
    printf("\n1.TO INSERT IN QUEUE\n");
    printf("2.TO DELETE FROM QUEUE \n");
    printf("3.TO DISPLAY QUEUE ELEMENTS \n");
    printf("4.TO EXIT\n");
    printf("\n ENTER CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    struct queue*q;
    int c,remove;
   printf("\nENTER ANY KEY TO CONTINUE\n");
   q=create();
   while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1:
            insert(q);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            remove=dequeue(q);
            if(remove==-99999)
                printf("\n -9999999 \n");
            else
            printf("%d DELETED \n",remove);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            queueDisplay(q);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
        case 4:exit(0);
           break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
