#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char ch[100];
    scanf("%s",&ch);
    for(i=0;i<strlen(ch);i++) printf("%c",ch[i]+2);
}
