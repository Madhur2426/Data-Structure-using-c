#include<stdio.h>
#include<stdlib.h>
#define READY 1
#define WAITING 2
#define PROCESSED 3
struct queue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
struct node
{
    int vno;
    struct node *next;
};
struct graph
{
    int v;
    struct node **adj;
    int *status;
};
int isfull(struct queue *q)
{
    if(q->front==0&&q->rear==q->capacity-1)
        return(1);
    else
        return(0);
}
int isempty(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
        return(0);
    else
        return(1);
}
void insert(struct queue *q,int x)
{
    if(q->capacity<0)
    printf("\n INVALID CAPACITY \n");
   else if(isfull(q))
        printf("\n queue is full \n");
        else
        {
        if(q->front==-1&&q->rear==-1)
        {
            q->front=0;
            q->rear=0;
            q->arr[q->rear]=x;
        }
        else if(q->front==0&&q->rear==0)
        {
            q->rear++;
            q->arr[q->rear]=x;
        }
        else
        {
            q->rear++;
            q->arr[q->rear]=x;
        }
        }
}
int dequeue(struct queue *q)
{
    int del;
    if(q->front==-1&&q->rear==-1)
        printf("\n QUEUE IS EMPTY \n");
    else
    {
        if(q->front==0&&q->rear==0)
        {
            del=q->arr[q->front];
            q->front--;
            q->rear--;
            return(del);
        }
        else if(q->front==q->rear)
        {
            del=q->arr[q->front];
            q->front=-1;
            q->rear=-1;
            return(del);
        }
        else
        {
            del=q->arr[q->front];
            q->front++;
            return(del);
        }
    }
    return(-99999);
}
struct graph *creategraph(int v,int e)
{
 int i,x,y;
 struct node *n;
 struct graph *g;
 g=(struct graph*)malloc(sizeof(struct graph));
 g->v=v;
 g->status=(int*)malloc(sizeof(int)*v);
 for(i=0;i<v;i++)
 g->status[i]=-1;
 g->adj=(struct node**)malloc(sizeof(struct node**)*v);
 for(i=0;i<v;i++)
 g->adj[i]=NULL;
 for(i=0;i<e;i++)
 {
     printf("ENTER VERTICES OF EDGES:");
     scanf("%d%d",&x,&y);
     n=(struct node*)malloc(sizeof(struct node));
     n->vno=y;
     n->next=g->adj[x-1];
     g->adj[x-1]=n;
     n=(struct node*)malloc(sizeof(struct node));
     n->vno=x;
     n->next=g->adj[y-1];
     g->adj[y-1]=n;
 }
 return(g);
}
void BFS(struct graph *g)
{
    int v,i;
    struct queue *q;
    struct node *temp;
    q=(struct queue*)malloc(sizeof(struct queue));
q->front=-1;
q->rear=-1;
q->capacity=g->v;
q->arr=(int*)malloc(sizeof (int)*g->v);
    for(i=0;i<g->v;i++)
        g->status[i]=READY;
    insert(q,1);
    g->status[0]=WAITING;
    while(isempty(q))
    {
        v=dequeue(q);
        printf("v%d  ",v);
        g->status[v-1]=PROCESSED;
        temp=g->adj[v-1];
        while(temp)
        {
            if(g->status[temp->vno-1]==READY)
            {
                insert(q,temp->vno);
                g->status[temp->vno-1]=WAITING;
            }
            temp=temp->next;
        }
    }
}
void main()
{
    struct graph *g;
    g=creategraph(6,9);
    BFS(g);
   /*INPUT
      1 2
      1 3
      2 3
      2 4
      3 4
      3 5
      4 5
      4 6
      5 6*/
    /*OUTPUT
    V1 V3 V2 V5 V4 V6 */
}
