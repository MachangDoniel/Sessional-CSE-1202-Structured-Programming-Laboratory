//Structures

#include<stdio.h>
#include<string.h>


struct gospel
{
    int num ;
    char mess1[50] ;
    char mess2[50] ;
} m1 = {2,"If you are driven by success","make sure that it is a quality drive"};


struct virus
    {
    char signature[25] ;
    char status[20] ;
    int size ;
    } v[2] = {
    "Yankee Doodle", "Deadly", 1813,
    "Dark Avenger", "Killer", 1795
    } ;

    struct s
    {
        char ch ;
        int i ;
        float a ;
    } ;
    f ( struct s v )
    {
        printf ( "\n%c %d %f", v.ch, v.i, v.a ) ;
    }
    g ( struct s *v )
    {
        printf ( "\n%c %d %f", v -> ch, v -> i, v -> a ) ;
    }
int main()
{
//    struct gospel m2, m3 ;
//    m2 = m1 ;
//    m3 = m2 ;
//    printf ( "\n%d %s %s", m1.num, m1.mess1, m1.mess2 ) ;
//    printf ( "\n%d %s %s", m2.num, m2.mess1, m2.mess2 ) ;
//    printf ( "\n%d %s %s", m3.num, m3.mess1, m3.mess2 ) ;



//    int i ;
//    for ( i = 0 ; i <=1 ; i++ )
//    printf ( "\n%s %s", v[i].signature, v[i].status ) ;
//
//


    struct s var = {'C', 100, 12.55 } ;
    f ( var ) ;
    g ( &var ) ;

}
