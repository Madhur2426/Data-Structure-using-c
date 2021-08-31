#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct graph
{
    int v;
    int e;
    struct node **adj;
};
struct graph* create(int v,int e)
{
 int i;
 struct graph *g;
 g=(struct graph*)malloc(sizeof(struct graph));
 g->v=v;
 g->e=e;
 g->adj=(struct node**)malloc(sizeof(struct node**)*g->v);
 for(i=0;i<g->v;i++)
        g->adj[i]=NULL;
 return(g);
}
void adjlistofgraph(struct graph *g)
{
    int i,u,v;
    struct node *n;
    for(i=0;i<g->e;i++)
    {
        printf("ENTER VERTICES OF EDGES:");
        scanf("%d%d",&u,&v);
        n=(struct node*)malloc(sizeof(struct node));
        n->data=v;
        n->next=g->adj[u-1];
        g->adj[u-1]=n;
        n=(struct node*)malloc(sizeof(struct node));
        n->data=u;
        n->next=g->adj[v-1];
        g->adj[v-1]=n;
    }
}
void display(struct graph *g)
{
    int i;
    struct node*n;
    for(i=0;i<g->v;i++)
    {
        n=g->adj[i];
        while(n)
        {

            printf("%d \t",n->data);
            n=n->next;

        }
        printf("\n");
    }
}
void main()
{
    struct graph *g;
    g=create(6,9);
    adjlistofgraph(g);
    display(g);
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
       3 2
       4 3 1
       5 4 2 1
       6 5 3 2
       6 4 3
       5 4*/
}
