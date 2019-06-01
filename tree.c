#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root,*temp,*temp1;
/*void create()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("write boy");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;

}*/
struct node* insert(int data,struct node* root)
{
    struct node* temp1,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp1=root;
  /*  printf("enter data\n");
    scanf("%d",&temp->data);*/
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        if(root->data>temp->data)
        {
            root->left=insert(data,temp1->left);
        }
        else if(root->data<temp->data)
        {
            root->right=insert(data,root->right);
        }
        
    }
    return root;
    
}
void inorder(struct node* root) 
{ 
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
} 
struct node *delet(struct node* root,int data)
{
    struct node* temp=root;
    if(data>temp->data)
    {
        temp->right=delet(temp->right,data);
    }
    else if(data<temp->data)
    {
        temp->left=delet(temp->left,data);
    }
    else
    {
        if(temp->data==data)
        {
            if(temp->left==temp->right)
            {
                free(temp);
                return NULL;
            }
            else if(temp->left==NULL)
            {
                struct node* temp1;
                temp1=temp;
                temp=temp->right;
                free(temp1);
                return temp;
            }
            else if(temp->right==NULL)
            {
                struct node* temp1;
                temp1=temp;
                temp=temp->left;
                free(temp1);
                return temp;
            }
            else
            {
                struct node* p1,*p2;
                p1=temp->right;
                p2=temp->right;
                while(p1->left!=NULL)
                {
                    p1=p1->left;                    
                }

                p1->left=temp->left;
                 
                return p2;
            }
            
        }
    }
    return temp;
    
}
int main()
{
    root=insert(3,root);
    insert(1,root);
    insert(0,root);
    insert(11,root);
    insert(7,root);
    insert(23,root);
    insert(56,root);
    delet(root,0);
    inorder(root);
    return 0;
}