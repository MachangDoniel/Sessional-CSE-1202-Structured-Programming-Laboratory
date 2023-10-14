//Structures

#include<stdio.h>
#include<string.h>

int main()
{
    struct students
    {
        int roll;
        char name[20];
        char dept[20];
        char course[10];
        int yoj;
    };
    struct students s[450];
    int n,i,j;
    n=100;
    for(i=0;i<n;i++)
        scanf("%d%s%s%s%d",&s[i].roll,s[i].name,s[i].dept,s[i].course,&s[i].yoj);

        //a
//    for(i=0;i<n;i++)
//    {
//        if(s[i].yoj==2019) printf("%s\n",s[i].name);
//    }


    //b
//    for(i=0;i<n;i++)
//    {
//        if(s[i].roll!=0)
//        {
//            printf("%d %s %s %s %d\n",s[i].roll,s[i].name,s[i].dept,s[i].course,s[i].yoj);
//        }
//    }
}
