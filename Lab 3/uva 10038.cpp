//UVA 10038
//JOlly Jumper
//USER ID: Doniel_121
//Online judge id: 1131325


#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,j=0,a[n+1],d[n],mx,mn,t;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]>a[i+1])
            {
                mx=a[i],mn=a[i+1];
            }
            else
            {
                mx=a[i+1],mn=a[i];
            }
            d[i]=mx-mn;
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(d[j]>d[j+1])
                {
                    t=d[j],d[j]=d[j+1],d[j+1]=t;
                }
            }
        }
        int hudai=0;
        for(i=1;i<n;i++)
        {
            if(d[i]!=i) hudai=1;
        }
        if(hudai==0) printf("Jolly\n");
        else printf("Not jolly\n");
    }
}
