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
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
 


   
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
   
   
}
int main(){
    struct node *root = createNode(10);
    root->left =createNode(20);
    root->right= createNode(30);
    root->left->left = createNode(40);
    root->right->right=createNode(50);
    root->right->right->right = createNode(60);
   
   
    string order;
    cout<<"Enter order of traversal:(inorder/preorder/postorder)"<<endl;
    cin>>order;
    if(order == "inorder"){
        cout<<"Inorder traversal is: "<<endl;
        inorder(root);
    }
    else if(order=="preorder")
    {
        cout<<"preorder traversal is: "<<endl;
        preorder(root);
    }
    else if(order =="postorder"){
        cout<<"postorder traversal is: "<<endl;
        postorder(root);
    }
    else{
        cout<<"Invalid order traversal";
    }
 
 
}
