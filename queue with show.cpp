#include <iostream>
using namespace std;
#define N 10
int front=-1,rear=-1;
int queue[N];
void insert();
void del();
void show();
void isempty();
void isfull();
int main(){
  
  int opp=0;
  do{
    
    cout<<"\nEnter the option:\n1.insert\n2.delete\n3.show\n4.isempty\n5.isfull\n6.exit\n";
    cin>>opp;
    switch (opp)
    {
    case 1:
      insert();
      break;
    case 2:
       del();
       break;
    case 3:
      show();
      break;
      case 4:
      isempty();
      break;
      case 5:
      isfull();
      break;
    default:cout<<"enter the valid operator...";
      break;
    }
  }while (opp!=6);
  
  
}
void insert(){
      if(rear==N-1){
        cout<<"queue is full...";
      }
      else{
        cout<<"Enter the element to be inserted:";
        rear++;
        cin>>queue[rear];
        cout<<"the element is inserted.\n";
      }
}
void del(){
      if(front==rear){
        cout<<"queue is empty...";
      }
      else{
         front++; 
        cout<<"the element to be deleted:"<<queue[front];
        
      }
}
void show(){
    if(front==rear){
        cout<<"queue is empty...";
    }
    else{
  cout<<"elements in queu";
  int i=front+1;
  for(i;i<=rear;i++){
      
      cout<<queue[i]<<" ";
  }
    }
}
void isempty(){
  if(rear==front){
        cout<<"queue is empty...";
      }
      else{
        cout<<"queue is not empty...";
      }
}
void isfull(){
  if(rear==N-1){
        cout<<"queue is full...";
      }
      else{
        cout<<"queue is not full...";
      }
}
