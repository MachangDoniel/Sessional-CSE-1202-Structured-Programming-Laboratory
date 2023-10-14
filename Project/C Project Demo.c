//Doniel Tripura
//Roll 1907121

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct student{
    char name[20];
    char class[10];
    int roll;
    char date[12];
    }s;

FILE *fp;
long sz=sizeof(s);

int main(){

    int ch;
    while(1){
        system("cls"); //screen_clear
        printf("<==School Management System==>\n\n");
        printf("1.Take Admission\n");
        printf("2.Student Info\n");
        printf("3.Search\n");
        printf("4.Modify\n");
        printf("5.Delete\n");
        printf("6.Sort\n");
        printf("0.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
        case 0:
            exit(0);
        case 1:
            input();
            break;
        case 2:
            Display();
            break;
        case 3:
            Search();
            break;
        case 4:
            modify();
            break;
        case 5:
            Delete();
            break;
        case 6:
            sort();
            break;
        }
        printf("\n\nPress Any key to continue...");
        getch(); //screen lock until Enter
    }
    return 0;
}
 void input(){

    char myDate[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1,tm.tm_year+1900);
    strcpy(s.date, myDate);

    fp=fopen("stud.txt","ab");
    printf("Enter Student name: ");
    fflush(stdin); //input buffer clearing
    gets(s.name);
    printf("Enter class: ");
    fflush(stdin);
    gets(s.class);
    printf("Enter roll: ");
    scanf("%d", &s.roll);

    fwrite(&s,sz,1,fp); //fwrite(address of str, size of str, how many record in 1, where to write);
    printf("Record Saved Successfully...");
    fclose(fp);
 }


 void Display(){

    system("cls"); //screen_clear
    printf("<==Student Info==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        printf("%-30s %-20s %-10d %s\n",s.name,s.class,s.roll,s.date);
    }
    fclose(fp);
 }


 void Search(){

    int ch;
    while(1){
        system("cls");
        printf("<==Search==>\n\n");
        printf("1.Search By Roll\n");
        printf("2.Search By Name\n");
        printf("0.Back to the Menu\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 0:
            main();
            break;
        case 1:
            searchByRoll();
            break;
        case 2:
            searchByName();
            break;

        default:
            printf("Invalid Choice\n");
        }
        getch();
    }
 }

void searchByRoll(){
    int roll, f=0;
    printf("Enter roll: ");
    scanf("%d",&roll);
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(roll==s.roll){
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.name,s.class,s.roll,s.date);
            break;
        }
    }
    fclose(fp);
    if(f==0) printf("Record not found\n");
    else  printf("Record found successfully\n");
 }

void searchByName(){
    char name[30];
    int f=0;
    printf("Enter name: ");
    fflush(stdin);
    gets(name);
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(strcmpi(name,s.name)==0){
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.name,s.class,s.roll,s.date);
            break;
        }
    }
    fclose(fp);
    if(f==0) printf("Record not found\n");
    else  printf("Record found successfully\n");
 }

 void modify()
 {
     Display();
     int roll, f=0;
    printf("Modify previous roll: ");
    scanf("%d",&roll);
    fp=fopen("stud.txt","rb+"); //read+write
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(roll==s.roll){
            f=1;
            printf("\nEnter Student's new name: ");
            fflush(stdin); //input buffer clearing
            gets(s.name);
            printf("Enter new class: ");
            fflush(stdin);
            gets(s.class);
            printf("Enter new roll: ");
            scanf("%d", &s.roll);
            fseek(fp,-sz,1);
            fwrite(&s,sz,1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0) printf("Record not found\n");
    else  printf("Record modified successfully\n");
 }

void Delete()
 {
    int roll, f=0;
    printf("Enter roll to delete student data: ");
    scanf("%d",&roll);
    FILE *ft;

    fp=fopen("stud.txt","rb"); //read+write
    ft=fopen("temp.txt","ab");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(roll==s.roll){
            f=1;
        }
        else{
            fwrite(&s,sz,1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("stud.txt");
    rename("temp.txt","stud.txt");
    if(f==0) printf("Record not found\n");
    else  printf("Record deleted successfully\n");
 }

void sort(){
     int ch;
    while(1){
        system("cls");
        printf("<==Sort==>\n\n");
        printf("1.Sort By Roll\n");
        printf("2.Sort By Name\n");
        printf("0.Back to the Menu\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 0:
            main();
            break;
        case 1:
            sortByRoll();
            break;
        case 2:
            sortByName();
            break;

        default:
            printf("Invalid Choice\n");
        }
        getch();
    }

}

void sortByRoll(){
    int c=0,i,j;
    struct student s1[50],t;

    system("cls"); //screen_clear
    printf("<==Student Info==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        s1[c++]=s;
    }

    for(i=0;i<c-1;i++)
    {
        for(j=i+1;j<c;j++)
        {
            if(s1[i].roll>s1[j].roll){
                t=s1[i];
                s1[i]=s1[j];
                s1[j]=t;
            }
        }
    }
    for(i=0;i<c;i++)
    {
        printf("%-30s %-20s %-10d %s\n",s1[i].name,s1[i].class,s1[i].roll,s1[i].date);
    }

    fclose(fp);
 }


void sortByName(){
    int c=0,i,j;
    struct student s1[50],t;

    system("cls"); //screen_clear
    printf("<==Student Info==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        s1[c++]=s;
    }

    for(i=0;i<c-1;i++)
    {
        for(j=i+1;j<c;j++)
        {
            if(strcmp(s1[i].name,s1[j].name)>0){
                t=s1[i];
                s1[i]=s1[j];
                s1[j]=t;
            }
        }
    }
    for(i=0;i<c;i++)
    {
        printf("%-30s %-20s %-10d %s\n",s1[i].name,s1[i].class,s1[i].roll,s1[i].date);
    }

    fclose(fp);
 }
