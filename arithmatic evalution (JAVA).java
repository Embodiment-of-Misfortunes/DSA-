import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner scan =new Scanner(System.in);
    System.out.println("enter the expression");
    String input =scan.next();
    if(Character.isDigit(input.charAt(0)) && Character.isDigit(input.charAt(input.length()-1)) || 
    input.charAt(0)=='('||
    input.charAt(input.length()-1)==')')
    {
         infix(input);
    }
    else if(Character.isDigit(input.charAt(0)) && Character.isDigit(input.charAt(1))){
      System.out.println("it is postfix"+postfix(input));
      }
    else if(Character.isDigit(input.charAt(input.length()-1)) && Character.isDigit(input.charAt(input.length()-2)))
    {
      System.out.println("it is prefix"+prefix(input));
    }
    
  }
  public static float prefix(String input){
    Stack<Float> stk=new Stack<>();
    int size=input.length()-1;  
    for(int i=size;i>=0;i--){
       if(Character.isDigit(input.charAt(i))){
           stk.push((float)Character.getNumericValue(input.charAt(i)));
       }
       else{
        float o1=stk.peek();
                 stk.pop();
                 
        float o2=stk.peek();
                 stk.pop();
                 
        if(input.charAt(i)=='+'){
          stk.push(o1+o2);
        }
        else if(input.charAt(i)=='-'){
          stk.push(o1-o2);
        }
        else if(input.charAt(i)=='*'){
          stk.push(o1*o2);
        }
        else if(input.charAt(i)=='/'){
          stk.push(o1/o2);
        }
        else if(input.charAt(i)=='^'){
          stk.push((float)(Math.pow(o1,o2)));
        }
        else{
          System.out.println("invalid operator");
          return -1;
        }
       }
    }
   return stk.peek();
  }

  public static float postfix(String input){
    Stack<Float> stk=new Stack<>();
    int size=input.length()-1;
    for(int i=0;i<=size;i++){
       if(Character.isDigit(input.charAt(i))){
           stk.push((float)Character.getNumericValue(input.charAt(i)));
       }
       else{
        float o2=stk.peek();
                 stk.pop();
                 
        float o1=stk.peek();
                 stk.pop();
                 
        if(input.charAt(i)=='+'){
          stk.push(o1+o2);
        }
        else if(input.charAt(i)=='-'){
          stk.push(o1-o2);
        }
        else if(input.charAt(i)=='*'){
          stk.push(o1*o2);
        }
        else if(input.charAt(i)=='/'){
          stk.push(o1/o2);
        }
        else if(input.charAt(i)=='^'){
          stk.push((float)(Math.pow(o1,o2)));
        }
        else{
          System.out.println("invalid operator");
          return -1;
        }
       }
    }
   return stk.peek();
  }

  public static void infix(String input){
    Stack<Character> stk= new Stack<>();
     String post="";
     for(int i=0; i<input.length();i++){
      char c = input.charAt(i);
      if(c>='0' && c<='9')
      {
        post+=c;
      }
      else if(c=='('){
        stk.push('(');

      }
      else if(c==')'){
        while(stk.peek() != '('){
          post+=stk.peek();
          stk.pop();
          
        }
        stk.pop();
      }
      else{
        while(!stk.empty() && prec(input.charAt(i)) <= prec(stk.peek())){
          post+=stk.peek();
          stk.pop();
        }
        stk.push(c);
      }
    }
      while(!stk.empty()){
        post+=stk.peek();
        stk.pop();
      }
      System.out.println("the post fix of give exp.." + post);
     
     System.out.println(postfix(post));

  }
  public static int prec(char c){
    if(c=='^'){
      return 3;}
    else if(c=='/' || c=='*'){
      return 2;}
      else if(c=='+' || c=='-'){
        return 1;}
      else{
        return -1;
      }

  }
}
