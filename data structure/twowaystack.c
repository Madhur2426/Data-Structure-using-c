#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct twowaystack
{
    int capacity;
    int topleft;
    int topright;
    int *ptr;
};
struct twowaystack *create(int cap)
{
    struct twowaystack *s;
    int i;
    s=(struct twowaystack *)malloc(sizeof( struct twowaystack));
    s->capacity=cap;
    s->topleft=-1;
    s->topright=cap;
   s->ptr=(int*)malloc(sizeof(int)*cap);
    return(s);
}
void pushright(struct twowaystack *s)
{
    int data;
    if(s->topright-1==s->topleft)
        printf("\n OVERFLOW \n");
    else
    {
        printf("\n ENTER DATA \n");
        scanf("%d",&data);
        s->topright-=1;
        s->ptr[s->topright]=data;
    }
}
void pushleft(struct twowaystack *s)
{
    int data;
    if(s->topleft+1==s->topright)
        printf("\n OVERFLOW \n");
    else
    {
        printf("\n ENTER DATA \n");
        scanf("%d",&data);
        s->topleft+=1;
        s->ptr[s->topleft]=data;
    }
}
int popleft(struct twowaystack *s)
{
    int del;
   if(s->topleft==-1)
       {
        return(-9999);
       }
    else
    {
        del=s->ptr[s->topleft];
        s->topleft--;
        return(del);
    }
}
int popright(struct twowaystack *s)
{
    int del;
    if(s->topright==s->capacity)
      {
          return(-9999);
      }
    else
    {
        del=s->ptr[s->topright];
        s->topright++;
        return(del);
    }
}
int menu()
{
    int choice;
    printf("1.PUSH RIGHT \n");
    printf("2.PUSH LEFT \n");
    printf("3.POP RIGHT \n");
    printf("4.POP LEFT \n");
    printf("5.EXIT \n");
    printf("ENTER YOYUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
int main()
{
    int cap,del,c,remove;
    struct twowaystack *s;
    printf("\n ENTER STACK CAPACITY \n");
    scanf("%d",&cap);
    s=create(cap);
    while(1)
    {
        system("cls");
        c=menu();
        switch(c)
        {
            case 1:
                pushright(s);
                break;
            case 2:
                pushleft(s);
                break;
            case 3:
                del=popright(s);
                if(del==-9999)
            printf("\n UNDERLOW \n");
                else
                 printf("\n ELEMENT DELETED %d\n",del);
                break;
            case 4:
                remove=popleft(s);
                if(remove==-9999)
               printf("\n UNDERLOW \n");
                else
                printf("\n ELEMENT DELETED %d\n",remove);
                break;
            case 5:
                exit(0);
                break;
            default: printf("\n INVALID CHOICE,RETRY \n");
        }
        getch();
    }
}
