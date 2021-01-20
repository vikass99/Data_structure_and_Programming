#include <stdio.h>
#include <malloc.h>

struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

void insert(struct btree**,int);
int height(struct btree*);

int main()
{
    struct btree *root;
    int req, i=1, num;
    root=NULL;
    int ht;
    //printf("enter number of element");
    scanf("%d",&req);
    
    while(i++<=req)
    {
       // printf("enter data");
        scanf("%d",&num);
        
        insert(&root, num);
    }
    
    ht=height(root);
    printf("%d",ht);
    
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



int height(struct btree *sr)
{
    int lcount=0,rcount=0;
    
    if (sr==NULL)
        return 0;
    else
    {
        int lcount = height(sr->left); 
        int rcount = height(sr->right); 
  
        return(lcount>=rcount?lcount+1:rcount+1);
    }
}
