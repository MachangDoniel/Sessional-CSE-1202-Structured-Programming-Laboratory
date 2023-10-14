//UVA 136
//USER ID: Doniel_121
//Online judge id: 1131325



 #include<stdio.h>

 int main()
 {
     int i,n,x,y,z,a,b,c,arr[2000],ans;
     x=y=z=0;
     arr[0]=1;
     for(i=1;i<1500;i++)
     {
         a=2*arr[x];
         b=3*arr[y];
         c=5*arr[z];
         if(a<b)
         {
             if(a<c)
             {
                 ans=a;
             }
             else
             {
                 ans=c;
             }
         }
         else
         {
             if(b<c)
             {
                 ans=b;
             }
             else
             {
                 ans=c;
             }
         }
         arr[i]=ans;
         if(ans==a) x++;
         if(ans==b) y++;
         if(ans==c) z++;
     }
     printf("The 1500'th ugly number is %d.\n",ans);
 }
