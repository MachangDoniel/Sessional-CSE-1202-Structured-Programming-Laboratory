//UVA 100
//USER ID: Doniel_121
//Online judge id: 1131325


 #include<stdio.h>

 int main()
 {
     int x,y;
     while(scanf("%d %d",&x,&y)!= EOF)
    {
     int A,B,n,mx=0,i,j,count;
     if(x<y) A=x,B=y;
     else A=y,B=x;
     if(A==0) A++;
     for(i=A;i<=B;i++)
     {
         n=i;
         count=1;
         while(n!=1)
         {
             count++;
             if(n%2!=0) n=3*n+1;
             else n/=2;
         }
         if(mx<count) mx=count;
     }
     printf("%d %d %d\n",x,y, mx);
     }
 }
