//Structures

#include<stdio.h>
#include<string.h>


struct book
{
    int acc_no;
    char title[20];
    char author[20];
};
struct book b1[3]={1,"The Gods","Ryan",2,"The Eternals","DT",3,"Avengers","Snyder"};
struct library
{
    struct book b1[3];

};

void Add()
{
    int i,n;
    for(i=n;i<n+1;i++)
    scanf("%d  %s   %s\n",&b1[i].acc_no,b1[i].title,b1[i].author);
};

void display()
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("%d  %s   %s\n",b1[i].acc_no,b1[i].title,b1[i].author);
    }
}

int main()
{

//    struct employee e[200];
    int n,i,j;
//    n=5;
//    for(i=0;i<n;i++)
//    {
//        scanf("%d%s%d%d%d",&e[i].ecode,e[i].name,&e[i].d.day,&e[i].d.month,&e[i].d.year);
//    }
//    printf("Enter the current date: \n");
//    scanf("%d%d%d",&d,&m,&y);
    display();
}
