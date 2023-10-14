//Structures

#include<stdio.h>
#include<string.h>


int main()
{
    int i,n,j;
    scanf("%d",&n);
    struct student
    {
        char name[20];
        int roll;
        int mark[3];
    };
    struct student s[n];


    printf("input values: \n");
    int sum[n];
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        printf("Enter your Name:");
        scanf("%s",s[i].name);
        printf("Enter your Roll:");
        scanf("%s",&s[i].roll);
        printf("Enter your Marks:");
        for(j=0;j<3;j++)
        {
            scanf("%d",&s[i].mark[j]);
            sum[i]+=s[i].mark[j];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("The %d th student's name: %s\nRoll: %d\nTotal Marks: %d\n",i+1,s[i].name,s[i].roll,sum[i]);
    }
}
