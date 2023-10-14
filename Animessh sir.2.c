#include<stdio.h>

int z[4]={1,2,3,4};
int fun(int x,int y)
{
    x=z[2];
    y=z[3];
    return &x;
}
int main()
{
    FILE *fptr;
    fptr=fopen("F:\\Temp\\student.txt","r");
    if(fptr==NULL)
    {
        perror("The File is NOT opened");
    }
    else
    {
        perror("The File is opened");
    }

    fclose(fptr);
}
