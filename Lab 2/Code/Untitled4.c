#include<stdio.h>
#include<math.h>
int main()
{
    long long a,b,c,n,i,ar[1599]={0},x,y,z,ans;
    a=b=c=n=1;
    ar[1]=1;
    while(n!=1501)
    {
        x=2*ar[a];
        y=3*ar[b];
        z=5*ar[c];
        if(x<y && x<z) ans=x;
        else if(x<y && x>z) ans=z;
        else ans=y;
        ar[++n]=ans;
        if(ar[n]==x)
            a++;
        if(ar[n]==y)
            b++;
            if(ar[n]==z)
            c++;
    }
    printf("The 1500'th ugly number is ",ar[1500]);
}
