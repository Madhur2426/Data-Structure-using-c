#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst* create()
{
 struct bst* p;
 p=(struct bst*)malloc(sizeof(struct bst));
 printf("ENTER DATA \n");
 scanf("%d",&p->data);
 p->left=NULL;
 p->right=NULL;
}
void del(struct bst**root,int data)
{
    struct bst *p,*ptr;
    if(*root==NULL)
        printf("\n TREE IS EMPTY \n");
}
void insert(struct bst **root)
{
    struct bst *r;
    struct bst *p=create();
    if(*root==NULL)
       {
           *root=p;
       }
       else
       {
           r=*root;
           while(1)
           {
            if(r->data==p->data)
            {
                printf("\n DUPLICATE VALUE \n");
                free(p);
                break;
            }
         else if(r->data>p->data)
         {
            if(r->left==NULL)
            {
                r->left=p;
                break;
            }
            else
                r=r->left;
         }
         else
         {
             if(r->right==NULL)
             {
                 r->right=p;
                 break;
             }
             else
                r=r->right;
         }
       }
}
}
void postorder(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            postorder(root->left);
        if(root->right!=NULL)
            postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct bst *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            inorder(root->left);
        printf("%d ",root->data);
        if(root->right!=NULL)
            inorder(root->right);
    }
}
void preorder(struct bst *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        if(root->left!=NULL)
            preorder(root->left);
        if(root->right!=NULL)
            preorder(root->right);
    }
}
int choice()
{
    int choice;
    printf("1.TO INSERT \n");
    printf("2.TO DELETE \n");
    printf("3.PREORDER \n");
    printf("4.INORDER \n");
    printf("5.POSTORDER \n");
    printf("6.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c,remove;
    struct bst *root=NULL;
   while(1)
   {
    system("cls");
       c=choice();
   switch(c)
   {
       case 1:
            insert(&root);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            printf("\n ENTER DATA TO BE DELETED \n");
            scanf("%d",&remove);
            del(&root,remove);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            preorder(root);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
        case 4:
            inorder(root);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
        case 5:
            postorder(root);
            printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
