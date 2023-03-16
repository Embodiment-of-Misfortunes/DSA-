//eg. input: 25 15 10 4 12 22 18 24 50 35 31 44 70 66 90
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

int tree_height(struct node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
void print_level(struct node* root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no
    
    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        printf("%d -> ", root->data);
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}
void print_tree_level_order(struct node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
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
            case 5:printf("\nLevel order Traversal of the Binary Tree:"); 
            print_tree_level_order(root);
                    break;
            case 6:
                printf("Thank You...");
                break;
            default :   
                printf("Wrong Choice\n");  
                break;     
            }  
        } while(ch != 6);  
  
   return 0;  
}  
