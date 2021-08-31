#include<stdlib.h>
#include<stdio.h>
int size;
struct node
{
    int data;
};
struct node *start=NULL;
struct node * create(int size)
{
    int i;
    struct node *n;
    start=(struct node*)malloc(sizeof(struct node)*size);
    n=start;
    for(i=0;i<size;i++)
       (n+i)->data=-1;
    return(n);
}
int key(int k,int size)
{
    return(k%size);
}
void insert(struct node *h,int size)
{
    struct node *n;
    struct node *q,*t;
    int k,value,i,a=0;
    int j;
    for(i=0;i<size;i++)
    {
        t=start;
        printf("\n ENTER VALUE TO BE INSERTED \n");
        scanf("%d",&value);
        k=key(value,size);
        printf("%d",k);
        q=(t+k);
        if(q->data==-1)
            q->data=value;
        else
        {
            printf("\n COLLISION OCCURED \n");
            for(j=1;j<=size;j++)
            {
                a=(k+j)%size;
                n=t+a;
                if((t+a)->data==-1)
                {
                    (t+a)->data=value;
                    printf("\n inserted \n");
                    k=a;
                    break;
                }
            }
        }
    }
}
void display(struct node *h,int size)
{
    int i;
    struct node *p=start;
    printf("\n KEY \t VALUE \n");
    for(i=0;i<size;i++)
    {
        if((p+i)->data!=-1)
            printf("%d\t%d\n",i,(p+i)->data);
    }
}
void searchdata(struct node *h,int size)
{
    int i,key;
    struct node *n=start;
    struct node *p;
    printf("\n enter key \n");
    scanf("%d",&key);
    if(key>=0&&key<=size-1)
    {
            printf("key is %d and value is %d",key,(n+key)->data);
    }
    else
        printf("\n key is invalid \n");
}
int main()
{
    struct node *h;
    printf("ENTER SIZE \n");
    scanf("%d",&size);
    h=create(size);
    insert(h,size);
    display(h,size);
    searchdata(h,size);
    searchdata(h,size);
    return(0);
}
