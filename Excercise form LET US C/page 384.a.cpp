//Structures

#include<stdio.h>
#include<string.h>

int main()
{
    struct gospel
    {
    int num ;
    char mess1[50] ;
    char mess2[50] ;
    } m ;
    m.num = 1 ;
    strcpy ( m.mess1, "If all that you have is hammer" ) ;
    strcpy ( m.mess2, "Everything looks like a nail" ) ;
    /* assume that the strucure is located at address 1004 */
    printf ("%d\n%s\n%s\n", m.num, m.mess1, m.mess2) ;
}
