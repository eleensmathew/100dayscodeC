#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct node {
    struct node *right;
    struct node *left;
    int data;
    int height;
};

struct node *newnode(int val){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->right=temp->left=NULL;
    temp->height=1;
    return temp;
}
int height(struct node *nodr){
    if (nodr==NULL){
        return 0;
    }
    return nodr->height;

}
int max(int a,int b){
    return (a>=b?a: b);
}
struct node *rightrotate(struct node * nodr ){
    struct node * x=nodr->left;//               n           x
    struct node * temp=x->right;//             /             \                              //            x       ->
    x->right=nodr;//                          x               n
    nodr->left=temp;//                         \n            /
                                          //    temp       temp
    nodr->height=max(height(nodr->left),height(nodr->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}                            

struct node *leftrotate(struct node * nodr ){
    struct node * x=nodr->right;//              n           x
    struct node * temp=x->left;//                \         /                            //            x       ->
    x->left=nodr;//                               x  ->    n
    nodr->right=temp;//                          /          \   
                                          //   temp       temp
    nodr->height=max(height(nodr->left),height(nodr->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}            
int get_balance(struct node * nodr){
    if (nodr==NULL)return 0;
    return (height(nodr->left)-height(nodr->right));
}                

struct node * insert (struct node * nodr,int data){
    if (nodr==NULL){
        return (newnode(data));
    }    
    if (data> nodr->data){
            nodr->right=insert(nodr->right,data);
    }
    else if(data<nodr->data){
        nodr->left=insert(nodr->left,data);
    }
    else{  //invalid: same values entered 
        return nodr;
    }
    int balance =get_balance(nodr);  //checkif the node is balanced

    //left left
    if (balance >1 && data < nodr ->left->data){
        return rightrotate(nodr);
    } 

    //right right
    if (balance <-1 && data > nodr ->right->data){
        return rightrotate(nodr);
    } 

    //left right
    if (balance >1 && data > nodr ->left->data){
        nodr->left=leftrotate(nodr->left);
        return rightrotate(nodr);
    } 
    //right left 
    if (balance <-1 && data < nodr ->right->data){
        nodr->right=rightrotate(nodr->right);
        return leftrotate(nodr);
    } 
    return nodr;
}
struct node * min_value_of_branch(struct node *nodr){
    struct node *current=nodr;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;

}
struct node *delete (struct node * root, int key){
    if (root==NULL){      //
        return root; 
    }    

    if (key<root->data){
        root->left=delete(root->left,key);
    }
    else if (key>root->data){
        root->right=delete(root->right,key);
    }

     else{   //node to be deleted is found
            if(root->right==NULL && root->left==NULL)return NULL;  //no child
            else if (root->right==NULL)  //only left child
            {struct node * temp=root->left;
            free (root);
            return temp;
            
            } 
            else if (root->left==NULL)  //only right child
            {struct node * temp=root->right;
            free (root);
            return temp;
            }
            else{
                struct node *smol=min_value_of_branch(root->right);
                root->data=smol->data;
                root->right=delete(root->right,smol->data);
            }
            if (root==NULL) return root;  //if tree only had one node 
            int balance =get_balance(root);
            
            if(balance>1 &&get_balance(root->left>=0))  //ll
                return rightrotate(root);
            if(balance>1 &&get_balance(root->left<0)){   //lr
                root->left=leftrotate(root->left);
                return rightrotate(root);}
            if(balance<-1 &&get_balance(root->right>=0));//rr
                return leftrotate(root);
            if(balance<-1 &&get_balance(root->right<0)){//rl
                root->right=rightrotate(root->right);
                return leftrotate(root);}
            return root;

            




     }
}
struct node * create(){
    int numnodes;
    printf("Enter number of nodes: ");
    scanf("%d",&numnodes);
    int one;
    printf("enter node value: ");
    scanf("%d",&one);
    struct node * first=NULL;
    struct node *root =insert(first,one);
    struct node * p=root;
    for(int i=0;i<numnodes-1;i++){
        printf("enter node value: ");
        scanf("%d",&one);
        p=insert(p,one);
    }
    return root;
}
int main(){
    struct node * root=create();
    preorder(root);
}
