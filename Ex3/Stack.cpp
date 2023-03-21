#include <iostream>
using namespace std;
#define N 10
int top=-1;
int stack[N];
void push();
void pop();
void stop();
void isempty();
void isfull();
int main(){
 int opp=0;
  do{
    cout<<"Enter the option:\n1.push\n2.pop\n3.top\n4.isempty\n5.isfull\n6.exit\n";
    cin>>opp;
    switch (opp)
    {
    case 1:
      push();
      break;
    case 2:
       pop();
       break;
    case 3:
      stop();
      break;
      case 4:
      isempty();
      break;
      case 5:
      isfull();
      break;
      }
  }while (opp!=6);
  
  
}
void push(){
      if(top==N-1){
        cout<<"stack is full...";
      }
      else{
        cout<<"Enter the element to be pushed.";
        top++;
        cin>>stack[top];
        cout<<"the element is pushed.\n";
      }
}
void pop(){
      if(top==-1){
        cout<<"stack is empty...";
      }
      else{
        cout<<"the element to be poped."<<stack[top];
        top--;
      }
}
void stop(){
  if(top==-1){
        cout<<"stack is empty...";
      }
      else{
        cout<<"top of the stack."<<stack[top];
      }
}
void isempty(){
  if(top==-1){
        cout<<"stack is empty...";
      }
      else{
        cout<<"Stack is not empty...";
      }
}
void isfull(){
  if(top==N-1){
        cout<<"stack is full...";
      }
      else{
        cout<<"Stack is not full...";
      }
}
