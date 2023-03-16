#include <stdio.h>
int main() {
    int i,n,sc,ar[100],flag=0;
    int f,se,temp;
    int start,end,mid;
    printf("enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        printf("%d -",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter the no. to be search");
    scanf("%d",&sc);
    f=0;
    se=1;
   for(i=0;i<=n;i++){

       if(sc>=ar[f] && sc<=ar[se]){

           start=f;
           end=se;
           while(start<=end)
            {
            mid=(start+end)/2;
            if(ar[mid]==sc){
                printf("the number at :%d",mid+1);

                return 0;
            }
            else if(sc<ar[mid]){
                end=mid-1;
            }
            else if(sc>ar[mid]){
                start=mid+1;
            }
          }
        }
        else if(sc==ar[n-1]){
           printf("the number at :%d",n);
            return 0;
        }
        temp=f+se;
        f=se;
        se=temp;
        }
    return 0;
}
