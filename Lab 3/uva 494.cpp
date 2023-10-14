//UVA 494
//USER ID: Doniel_121
//Online judge id: 1131325



//uva 495
#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100];
    int i,count,word;
    while(gets(ch))
    {
        count=word=0;
        for(i=0;i<strlen(ch);i++)
        {
            if((ch[i]>='a' && ch[i]<='z') || (ch[i]>='A' && ch[i]<='Z')) word=1;
            else count+=word, word=0;
        }
        count+=word;
        printf("%d\n",count);
    }
}
