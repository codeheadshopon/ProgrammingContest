#include<stdio.h>
void fact(int n)
{
    int k;
    int t;
    int a[100000]; //array will have the capacity to store 200 digits.
    int i,j,temp,m,x;

       a[0]=1;  //initializes array with only 1 digit, the digit 1.
       m=1;    // initializes digit counter

       temp = 0; //Initializes carry variable to 0.
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp; //x contains the digit by digit product
               a[j]=x%10; //Contains the digit to store in position j
               temp = x/10; //Contains the carry value that will be stored on later indexes
            }
             while(temp>0) //while loop that will store the carry value on array.
             {
               a[m]=temp%10;
               temp = temp/10;
               m++; // increments digit counter
             }
      }

      //printf("%d!\n",k);
              for(i=0;i<=m-1;i++)
              {//printing answer
                printf("%d",a[i]);
              }
              //printf("%d -> %d\n",n,k);


}
int main()
{
    int m,n;
    while(scanf("%d",&m)==1)
    {
        long long int x;
        fact(m);
        //printf("%lld\n",x);
    }
    return 0;

}