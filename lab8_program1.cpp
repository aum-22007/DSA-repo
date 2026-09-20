#include<iostream>
 using namespace std;


 struct node {
    int data;
    node* left;
    node* right;
};
struct node * createNode (int value )
{
struct node * newNode = ( struct node *) malloc ( sizeof ( struct node ));
if ( newNode == NULL )
{
printf (" Memory allocation failed \n");
exit (1) ;
}
newNode -> data = value ;
newNode -> left = NULL ;
newNode -> right = NULL ;
return newNode ;
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
       
   
}
int main(){
    struct node *root = createNode(10);
    root->left =createNode(20);
    root->right= createNode(30);
    root->left->left = createNode(40);
    root->right->right=createNode(50);
   
    inorder(root);
 
}
