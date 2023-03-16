#include<stdio.h>  
#include<stdlib.h>  
  
struct node  
{  
    int data;  
    struct node *left;  
    struct node *right;  
}; 
struct node *root = NULL; 
struct node *getNode(int val)  
{  
    struct node *newNode;  
    newNode = malloc(sizeof(struct node));  
    newNode->data   = val;  
    newNode->left  = NULL;  
    newNode->right = NULL;  
    return newNode;  
}
struct node *insertNode(struct node *root, int val)  
{  
     if(root == NULL)  
         return getNode(val);  
  
     if(root->data < val)  
         root->right = insertNode(root->right,val);  
  
     if(root->data > val)  
         root->left = insertNode(root->left,val);  
  
     return root;  
}   
void inorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
    inorder(root->left);   
    printf("%d ",root->data);  
    inorder(root->right);  
} 
void preorder(struct node *root)  
{  
    if(root == NULL)  
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);  
} 
void postorder(struct node *root)  
{  
    if(root == NULL)  
        return;
    
    postorder(root->left);
    postorder(root->right); 
    printf("%d ",root->data);
} 
  
int main()  
{  
   struct node *root = NULL;  
    int data,ch;  
    printf("\n1.To insert a new node.");  
    printf("\n2.Inorder Traversal."); 
    printf("\n3.Preorder Traversal.");
    printf("\n4.Postorder Traversal.");
    printf("\n5.Exit");
        do      
        {  
            printf("\nSelect one of the operations:");
            
            scanf("%d",&ch);              
            switch (ch)  
            {  
            case 1 :   
                printf("\nEnter the value to be inserted\n");  
                scanf("%d",&data);  
                root = insertNode(root,data);                    
                break;                            
            case 2 :   
                printf("\nInorder Traversal of the Binary Tree:");  
                inorder(root);  
                break;
            case 3 :   
                printf("\nPreorder Traversal of the Binary Tree:");  
                preorder(root);  
                break;
            case 4 :   
                printf("\nPostorder Traversal of the Binary Tree:");  
                postorder(root);  
                break;
            case 5:
                printf("Thank You...");
                break;
            default :   
                printf("Wrong Choice\n");  
                break;     
            }  
        } while(ch != 5);  
  
   return 0;  
}  
