//Structures

#include<stdio.h>
#include<string.h>

int d,m,y;
struct date
{
    int day;
    int month;
    int year;
};

struct employee
{
    int ecode;
    char name[20];
    struct date d;
};

int time(int day,int month,int year)
{
    if((y-year>3) || (y-year==3 && m-month>0) || (y-year==3 && m-month==0 && d-day>=0)) return 1;
    else return 0;

}
int main()
{

    struct employee e[200];
    int n,i,j;
    n=5;
    for(i=0;i<n;i++)
    {
        scanf("%d%s%d%d%d",&e[i].ecode,e[i].name,&e[i].d.day,&e[i].d.month,&e[i].d.year);
    }
    printf("Enter the current date: \n");
    scanf("%d%d%d",&d,&m,&y);
    for(i=0;i<n;i++)
    {
        if(time(e[i].d.day,e[i].d.month,e[i].d.year)) printf("%s\n",e[i].name);
    }
}
