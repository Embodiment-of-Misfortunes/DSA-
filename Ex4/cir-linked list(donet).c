#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();

void delete_begin();
void delete_end();

 
 
struct node
{
        int data;
        struct node *next;
};
struct node *last=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf(" \n               MENU                            \n");
                printf("1.Create     \n");
                printf("2.Display    \n");
                printf("3.Insert at the beginning    \n");
                printf("4.Insert at the end  \n");
                
                printf("5.Delete from beginning      \n");
                printf("6.Delete from the end        \n");
                
                printf("7.Exit       \n");
                printf("--------------------------------------\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                       
                        case 5:
                                        delete_begin();
                                        break;
                        case 6:
                                        delete_end();
                                        break;
                       
                        
                        case 7:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf(" Wrong Choice..");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        int data;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("enter the data element:");
        scanf("%d",&data);
        if(last==NULL)
        {
        temp->data=data;
        temp->next=temp;
        last=temp;
        }
        else
        {
            temp->data=data;
            temp->next=last->next;
            last->next=temp;
        }
}
void display()
{
       
        if(last==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                struct node *temp;
                temp=last->next;
                do{
                    printf("%d ",temp->data);
                    temp=temp->next;
                    
                }while(temp!=last->next);
                
               
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        int data;
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->data);
        if(last==NULL)
        {
            temp->data=data;
            temp->next=temp;
            last=temp;
        }
        else
        {
            temp->data=data;
            temp->next=last->next;
            last->next=temp;
        }
        
}
void insert_end()
{
       struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        int data;
        printf("Enter the data value for the node:" );
        scanf("%d",&data);
        if(last==NULL)
        {
            temp->data=data;
            temp->next=temp;
            last=temp;
        }
        else
        {
            temp->data=data;
            temp->next=last->next;
            last->next=temp;
            last=temp;
        }
}

void delete_begin()
{
        struct node *temp;
        if(last==NULL)
        {
                printf("List is Empty:");
                return;
        }
        else
        {
            temp=last->next;
            last->next=temp->next;
            free(temp);
        }
}
void delete_end()
{
        struct node *temp;
        if(last==NULL)
        {
                printf("List is Empty:");
                return;
        }
        else
        {
            temp=last->next;
            while(temp->next != last){
             temp=temp->next;   
            }
            temp->next=last->next;
            last=temp;
        }
}
