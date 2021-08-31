#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct array
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct array *create(int cap)
{
    struct array *a;
    a=(struct array*)malloc(sizeof(struct array));
    a->capacity=cap;
    a->lastindex=-1;
    a->ptr=(int*)malloc(sizeof(int)*a->capacity);
    return(a);
}
int getitem(struct array *arr,int index)
{
    if(arr->lastindex<index||index<0)
    {
        printf("\n INAVLID INDEX \n");
        return(-9999);
    }
    else
    return(arr->ptr[index]);
}
void edititem(struct array* arr,int index)
{
    int data;
    if(index<0||arr->lastindex<index)
       printf("\n INVALID INDEX \n");
    else
    {
        printf("\n ENTER ELEMENT \n");
        scanf("%d",&data);
        arr->ptr[index]=data;
    }
}
int countitems(struct array*arr)
{
 return(arr->lastindex+1);
}
void search(struct array*arr,int search)
{
   int i;
   if(arr->lastindex==-1)
    printf("\n EMPTY \n");
   else
   {
     for(i=0;i<=arr->lastindex;i++)
     {
         if(arr->ptr[i]==search)
            printf("\n ELEMENT %d FOUND AT INDEX %d \n",search,i);
     }
   }
}
void insert(struct array*arr,int index,int value)
{
    int i;
    if(arr->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(index<0||(arr->lastindex+2)<=index)
        printf("\n INVALID INDEX \n");
    else
    {
        for(i=arr->lastindex;i>=index;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=value;
        arr->lastindex++;
    }
}
void removedata(struct array *arr,int index)
{
    int i;
    if(arr->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(index<0||arr->lastindex<index)
        printf("\n INVALID INDEX \n");
    else
    {
        i=index;
        while(i<arr->lastindex)
        {
            arr->ptr[i]=arr->ptr[i+1];
            i++;
        }
        arr->lastindex=arr->lastindex-1;
    }
}
void display(struct array*arr)
{
    int i;
    if(arr->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else
    {
 for(i=0;i<=arr->lastindex;i++)
    printf("%d\t",arr->ptr[i]);
}
}
void main()
{
    struct array *arr;
    arr=create(4);
    insert(arr,0,45);
    insert(arr,0,52);
    insert(arr,0,21);
    search(arr,45);
    removedata(arr,0);
    edititem(arr,1);
    display(arr);
}
