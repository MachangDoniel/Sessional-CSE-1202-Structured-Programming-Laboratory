#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int n;
    while(1)
    {
        system("cls"); //system_clear
        printf("<==University Management System==>\n\n");
        printf("1.  Admin Panel.\n");
        printf("2.  Teacher's Panel.\n");
        printf("3.  Student's Panel.\n");
        printf("\n=>  Enter Your Choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 0:
            exit(0);
        case 1:
            admin();
            break;
//        case 2:
//            teacher();
//            break;
//        case 3:
//            student();
//            break;
        }
        getch();
        printf("\n\nPress Any key to continue...");
    }
    return 0;
}
void admin()
{
    int n;
    while(1){

        system("cls"); //system_clear
        printf("<==University Management System==>\n\n");
        printf("#   Admin Panel.\n\n");
        printf("1.   Register.\n");
        printf("2.   Login.\n");
        printf("0.   Exit.\n");
        scanf("%d",&n);
        switch(n)
        {
        case 0:
            exit(0);
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        }
        getch();
    }
        printf("\n\nPress Any key to continue...");
}

struct login
{
    char fname[20];
    char lname[20];
    char uname[20];
    char password[20];
};

void Register()
{
    FILE *log;
    log=fopen("login121.txt","w");
    struct login l;
    printf("Enter First name: ");
    scanf("%s",l.fname);
    printf("Enter Last name: ");
    scanf("%s",l.lname);
    printf("Enter Username: ");
    scanf("%s",l.uname);
    printf("Enter password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\n\nYour User name is UserID\n");
    printf("Now login with UserID and Password\n");
    printf("\nPress any key to continue....");
    getch();
    system("cls");
    Login();
}

void Login()
{
    char username[20],password[20];
    FILE *log;
    log=fopen("login121.txt","r");
    struct login l;
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("#   Admin Panel.\n\n");
    printf("UserID: ");
    scanf("%s",&username);
    printf("Password: ");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.uname)==0 && strcmp(password,l.password)==0)
        {
            int n;
            while(1){
                printf("Successful login\n");
                system("cls");
                printf("<==University Management System==>\n\n");
                printf("#   Admin Panel.\n\n");
                printf("#   %s\n\n",l.uname);
                printf("1.Teacher.\n");
                printf("2.Student.\n");
                printf("\n0.Exit.\n");
                printf("\nEnter Your Choice: ");
                scanf("%d",&n);
                switch(n)
                {
                case 0:
                    exit(0);
                case 1:
                    AdTeacher();
                    break;
                case 2:
                    AdStudent();
                    break;
                }
                getch();
            }
        }
        else
        {
            printf("UserID or password didn't match\n");
        }
    }
    fclose(log);
}





 //Teacher Party


struct teacher{
    char name[20];
    char course[10];
    int id;
    char date[12];
}t;


void AdTeacher()
{
    int n;
    while(1){
        system("cls"); //screen_clear
        printf("<==Varsity Management System==>\n\n");
        printf("1.Add Teacher\n");
        printf("2.Teacher Info\n");
        printf("3.Modify\n");
        printf("4.Delete\n");
        printf("0.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&n);

        switch(n){
        case 0:
            exit(0);
        case 1:
            tinput();
            break;
        case 2:
            tdisplay();
            break;
        case 3:
            tmodify();
            break;
        case 4:
            tdelete();
            break;
        }
        printf("\n\nPress Any key to continue...");
        getch(); //screen lock until Enter
    }
}

FILE *fp;
long sz=sizeof(t);

 void tinput(){

    char myDate[12];
    time_t tt=time(NULL);
    struct tm tm=*localtime(&tt);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1,tm.tm_year+1900);
    strcpy(t.date, myDate);

    fp=fopen("teacher.txt","ab");
    printf("Enter Teacher name: ");
    fflush(stdin); //input buffer clearing
    gets(t.name);
    printf("Assign Course: ");
    fflush(stdin);
    gets(t.course);
    printf("Enter id: ");
    scanf("%d", &t.id);

    fwrite(&t,sz,1,fp); //fwrite(address of str, size of str, how many record in 1, where to write);
    printf("Record Saved Successfully...");
    fclose(fp);
 }
  void tdisplay(){

    system("cls"); //screen_clear
    printf("<==Teacher Info==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Course","id","Date");
    fp=fopen("teacher.txt","rb");
    while(fread(&t,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        printf("%-30s %-20s %-10d %s\n",t.name,t.course,t.id,t.date);
    }
    fclose(fp);
 }

void tmodify()
{
    int id, f=0;
    system("cls");
    printf("Modify\n\n");
    printf("Enter previous id to Modify: ");
    scanf("%d",&id);
    fp=fopen("teacher.txt","rb+"); //read+write
    while(fread(&t,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(id==t.id){
            f=1;

            printf("\nEnter Teacher's new name: ");
            fflush(stdin); //input buffer clearing
            gets(t.name);
            printf("Enter new course: ");
            fflush(stdin);
            gets(t.course);
            printf("Enter new id: ");
            scanf("%d", &t.id);
            fseek(fp,-sz,1);
            fwrite(&t,sz,1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0) printf("Record not found\n");
    else  printf("Record modified successfully\n");
 }

void tdelete()
 {
    int id, f=0;
    printf("Enter id to delete data: ");
    scanf("%d",&id);

    FILE *ft;

    fp=fopen("teacher.txt","rb"); //read+write
    ft=fopen("temp.txt","ab");
    while(fread(&t,sz,1,fp)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(id==t.id){
                printf("%s\n",t.name);
            f=1;
        }
        else{
            fwrite(&t,sz,1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("teacher.txt");
    rename("temp.txt","teacher.txt");
    if(f==0) printf("Record not found\n");
    else  printf("Record deleted successfully\n");
 }





 //Student Party

 struct student{
    char name[20];
    char class[10];
    int roll;
    char date[12];
}s;


void AdStudent()
{
    int n;
    while(1){
        system("cls"); //screen_clear
        printf("<==Varsity Management System==>\n\n");
        printf("1.Add Student\n");
        printf("2.Student Info\n");
        printf("3.Modify\n");
        printf("4.Delete\n");
        printf("0.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&n);

        switch(n){
        case 0:
            exit(0);
        case 1:
            sinput();
            break;
        case 2:
            sdisplay();
            break;
        case 3:
            smodify();
            break;
        case 4:
            sdelete();
            break;
        }
        printf("\n\nPress Any key to continue...");
        getch(); //screen lock until Enter
    }
}

FILE *fs;
long szs=sizeof(s);

void sinput(){

    char myDate[12];
    time_t tt=time(NULL);
    struct tm tm=*localtime(&tt);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1,tm.tm_year+1900);
    strcpy(s.date, myDate);

    fs=fopen("student.txt","ab");
    printf("Enter Student name: ");
    fflush(stdin); //input buffer clearing
    gets(s.name);
    printf("Enter Class: ");
    fflush(stdin);
    gets(s.class);
    printf("Enter roll: ");
    scanf("%d",&s.roll);

    fwrite(&s,szs,1,fs); //fwrite(address of str, size of str, how many record in 1, where to write);
    printf("Record Saved Successfully...");
    fclose(fs);
 }
void sdisplay(){

    system("cls"); //screen_clear
    printf("<==Student Info==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
    fp=fopen("student.txt","rb");
    while(fread(&s,szs,1,fs)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        printf("%-30s %-20s %-10d %s\n",s.name,s.class,s.roll,s.date);
    }
    fclose(fs);
 }

void smodify()
{
    int roll, f=0;
    system("cls");
    printf("Modify\n\n");
    printf("Enter previous roll to Modify: ");
    scanf("%d",&roll);
    fp=fopen("student.txt","rb+"); //read+write
    while(fread(&s,szs,1,fs)==1) //fread(address of str, size of str, how many record in 1, where to write);
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
            fseek(fs,-szs,1);
            fwrite(&s,szs,1,fs);
            fclose(fs);
            break;
        }
    }
    if(f==0) printf("Record not found\n");
    else  printf("Record modified successfully\n");
 }

void sdelete()
 {
    int roll, f=0;
    printf("Enter roll to delete data: ");
    scanf("%d",&roll);

    FILE *ft;

    fp=fopen("student.txt","rb"); //read+write
    ft=fopen("temp.txt","ab");
    while(fread(&s,szs,1,fs)==1) //fread(address of str, size of str, how many record in 1, where to write);
    {
        if(roll==s.roll){
                printf("%s\n",s.name);
            f=1;
        }
        else{
            fwrite(&s,szs,1,ft);
        }
    }
    fclose(fs);
    fclose(ft);
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(f==0) printf("Record not found\n");
    else  printf("Record deleted successfully\n");
 }
