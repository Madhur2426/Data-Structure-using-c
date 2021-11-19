#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct BST
{
    struct BST*left;
    int item;
    struct BST*right;
};
void del(struct BST **r, int data)
{
    struct BST *ptr,*parptr,*pred,*parpred;
    if(*r==NULL)
        printf("Underflow");
    else{
        parptr=NULL;
        ptr=*r;
        while(ptr->item!=data&&ptr!=NULL)
        {
            if(ptr->item>data)
            {
                parptr=ptr;
                ptr=ptr->left;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->right;
            }
        }
        if(ptr==NULL)
            printf("Data not found");
        else
        {
            if(ptr->left==NULL && ptr->right==NULL)
            {
                if(parptr==NULL)
                    *r=NULL;
                else if(ptr==parptr->left)
                    parptr->left=NULL;
                else
                    parptr->right=NULL;
                free(ptr);
            }
            else if(ptr->left==NULL||ptr->right==NULL)
            {
                if(parptr==NULL)
                {
                    if(ptr->left!=NULL)
                        *r=ptr->left;
                    else
                        *r=ptr->right;
                }
                else if(ptr==parptr->left)
                {
                    if(ptr->left!=NULL)
                        parptr->left=ptr->left;
                    else
                        parptr->left=ptr->right;
                }
                else
                {
                    if(ptr->left!=NULL)
                        parptr->right=ptr->left;
                    else
                        parptr->right=ptr->right;
                }
                free(ptr);
            }
            else
            {
                pred=ptr->left;
                parpred=ptr;

                while(pred->right!=NULL)
                {
                    parpred=pred;
                    pred=pred->right;
                }
                ptr->item=pred->item;
                if(pred==parpred->left)
                {
                    parpred->left=pred->left;
                }
                else
                {
                    parpred->right=pred->left;
                }
                free(pred);
            }
        }
    }
}
void insert(struct BST **r,int data)
{
    struct BST* n,*ptr;
    n=(struct BST*)malloc(sizeof(struct BST));
    n->item=data;
    n->left=NULL;
    n->right=NULL;

    if(*r==NULL)
        *r=n;
    else
    {
        ptr=*r;
        while(1)
        {
            if(ptr->item==data)
            {
                printf("Duplicate items cannot be inserted");
                free(n);
                break;
                //duplicate data
            }
            else if(ptr->item>data)
            {
                if(ptr->left==NULL)
                {
                    ptr->left=n;
                    break;
                }
                else
                    ptr=ptr->left;
                //insert in left sub tree
            }
            else
            {
                if(ptr->right==NULL)
                {
                    ptr->right=n;
                    break;
                }
                else
                    ptr=ptr->right;
                //insert in right sub tree
            }
        }
    }

}
void postorder(struct BST *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            postorder(root->left);
        if(root->right!=NULL)
            postorder(root->right);
        printf("%d ",root->item);
    }
}
void inorder(struct BST *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            inorder(root->left);
        printf("%d ",root->item);
        if(root->right!=NULL)
            inorder(root->right);
    }
}
void preorder(struct BST *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->item);
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
    int c,remove,data;
    struct BST *root=NULL;
   while(1)
   {
    system("cls");
       c=choice();
   switch(c)
   {
       case 1:
            printf("\n ENTER DATA TO BE INSERTED \n");
            scanf("%d",&data);
            insert(&root,data);
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
