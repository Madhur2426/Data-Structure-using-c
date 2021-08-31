#include<stdlib.h>
#include<stdio.h>
int size;
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create(int size)
{
    int i;
    struct node *n;
    start=(struct node*)malloc(sizeof(struct node)*size);
    n=start;
    for(i=0;i<size;i++)
    {
        (n+i)->data=0;
        (n+i)->next=NULL;
    }
}
int key(int k,int size)
{
    return(k%size);
}
void insert(int size)
{
    struct node *n;
    struct node *t,*p,*q;
    int k,value,i;
    for(i=0;i<size;i++)
    {
        n=start;
        printf("\n ENTER VALUE TO BE INSERTED \n");
        scanf("%d",&value);
        k=key(value,size);
        t=(struct node*)malloc(sizeof(struct node));
        t->next=NULL;
        t->data=value;
        q=(n+k);
        if(q->data==0)
        {
            q->data=value;
            q->next=NULL;
        }
        else
        {
            p=(n+k);
            if(p->next==NULL)
            {
            t->next=NULL;
            p->next=t;
            }
            else{
            t->next=p->next;
            p->next=t;
            }

        }
    }
}
void display(int size)
{
    int i;
    struct node *n=start;
    struct node *t,*p,*q;
    printf("\n VALUE \t KEY \n");
    for(i=0;i<size;i++)
        {
         p=(n+i);
         if(p->data!=0&&p->next==NULL)
                printf("%d\t%d\n",p->data,(p->data)%size);
         else
         {
         q=(n+i);
             if(q->data!=0)
             {
                 t=(n+i);
                 while(t)
                 {
                     printf("%d\t%d\n",(t)->data,((t)->data)%size);
                     t=t->next;
                 }
             }
         }
        }
}
void searchdata(int size)
{
    int i,key;
    struct node *n=start;
    struct node *p;
    printf("\n enter key \n");
    scanf("%d",&key);
    if(key>=0&&key<=size-1)
    {
            if((n+key)->next==NULL)
            printf("Key is %d value is %d",key,(n+key)->data);
            else
            {
                p=(n+key);
                while(p!=NULL)
                {
                     printf("Key is %d value is %d \n",key,p->data);
                     p=p->next;
                }
            }
    }
    else
        printf("\n key is invalid \n");
}
int main()
{
    printf("ENTER SIZE \n");
    scanf("%d",&size);
    create(size);
    insert(size);
    display(size);
    searchdata(size);
    searchdata(size);
    return(0);
}
