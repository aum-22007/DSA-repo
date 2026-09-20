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
void inorder_iterative(struct node *root){
   
    struct node *stack[100];
    struct node *current =root;
    int top = -1;
   
    while(current!=NULL || top!=-1){
        while(current!= NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout<<current->data<<" ";
        current = current->right;
   
    }
         cout<<endl;
}


void preorder_iterative(struct node *root){
    struct node *stack[100];


    int top = -1;
    stack[++top] = root;
    while(top != -1){
        struct node *current = stack[top--];
        cout<<current->data<<" ";
   
    if(current->right != NULL){
        stack [++top ] = current->right ;
    }
    if(current->left!=NULL){
        stack[++top] = current->left;
    }
    }
    cout<<endl;
}
void postorder_iterative(struct node *root){


    if (root == NULL) return;


    struct node *stack1[100], *stack2[100];
    int top1 = -1;
    int top2 = -1;
   
    stack1[++top1] = root;
    while(top1 != -1){
        struct node *current = stack1[top1--];
        stack2[++top2] = current;


        if(current->right != NULL){
            stack1[++top1] = current->right;
        }
        if(current->left != NULL){
            stack1[++top1] = current->left;
        }
    }
   
    while(top2 != -1){
        cout << stack2[top2--]->data << " ";
    }
}


int main(){
    struct node *root = createNode(10);
    root->left =createNode(20);
    root->right= createNode(30);
    root->left->left = createNode(40);
    root->right->right=createNode(50);
    root->right->right->right = createNode(60);


  cout << "Inorder: ";
    inorder_iterative(root);
    cout << "Preorder: ";
    preorder_iterative(root);
    cout << "Postorder: ";
    postorder_iterative(root);
  
}