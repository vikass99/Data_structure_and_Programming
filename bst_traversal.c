#include <stdio.h>
#include <malloc.h>



struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

void insert(struct btree**,int);
void inorder(struct btree*);
void preorder(struct btree*);
void postorder(struct btree*);

int main()
{
    struct btree *root;
    int req, i=1, num;
    root=NULL;
    //printf("enter number of element");
    scanf("%d",&req);
    
    while(i++<=req)
    {
       // printf("enter data");
        scanf("%d",&num);
        
        insert(&root, num);
    }
    
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    
    
    return 0;
}

void insert(struct btree **sr, int num)
{
    if(*sr==NULL)
    {
        *sr=(struct btree*) malloc(sizeof(struct btree));
        (*sr)->left=NULL;
        (*sr)->data=num;
        (*sr)->right=NULL;
    }    
    else
    {
        if(num<(*sr)->data)
            insert(&((*sr)->left),num);
        else
            insert(&((*sr)->right),num);
    }
}


void inorder(struct btree *sr)
{
    if(sr !=NULL)
    {
        inorder(sr->left);
        printf("%d",sr->data);
        inorder(sr->right);
    }
    
}

void preorder(struct btree *sr)
{
    if(sr !=NULL)
    {
        printf("%d",sr->data);
        preorder(sr->left);
        preorder(sr->right);
    }
    
}


void postorder(struct btree *sr)
{
    if(sr !=NULL)
    {
        postorder(sr->left);
        postorder(sr->right);
        printf("%d",sr->data);
    }
    
}
