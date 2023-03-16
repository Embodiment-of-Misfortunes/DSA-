#include <iostream>
#include <conio>
using namespace std;
int main()
{
//clrscr();
int i,n,arr[50],s,flag=1;
cout<<"Enter the size of array: ";
cin >>n;
cout<< "\n Enter the value in ascending order:";
for(i=0; i<n; i++)
{
 cout << "\n  Enter the value for "<< i+1<< ": ";
 cin>>arr[i];
}
cout <<" \n Enter the number you want to search:";
cin >>s;
for(i=0;i<n;i++)
{
if (arr [i] == s)
{
cout << "SEARCH SUCCESSFUL";
cout << "The given number at: "<<i+1;
flag=0;
break;
}
}
if(flag ==1)
{
cout<<"SEARCH UNSUCCESSFUL";
}
return 0;
}
