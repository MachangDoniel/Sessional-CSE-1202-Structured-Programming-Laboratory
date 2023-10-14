//Structures

#include<stdio.h>
#include<string.h>

int main()
{
    struct bank
    {
        int account_number;
        char name[20];
        float balance;
    };
//    struct bank s[200];
    int n,i,j;
    n=3;

    //a
//    for(i=0;i<n;i++)
//        scanf("%d%s%f",&s[i].account_number,s[i].name,&s[i].balance);


//    for(i=0;i<n;i++)
//    {
//        if(s[i].balance<100) printf("Account Number: %d\nName: %s\n",s[i].account_number,s[i].name);
//    }


    //b
    struct bank s[3]={1907121,"Doniel",99,1908121,"Usha",1000,1907043,"Nibir",19};
    int ac_no,code;
    float amount;
    for(i=0;i<n;i++)
    {

//        printf("%d %s %f\n",s[i].account_number,s[i].name,s[i].balance);

        scanf("%d%f%d",&ac_no,&amount,&code);
        for(j=0;j<n;j++)
        {
            if(ac_no==s[j].account_number)
            {
                if(s[j].balance>=amount) printf("Withdraw successful.\nBalance: %f\n",s[j].balance-amount);
                else printf("The balance is insufficient for the specified withdrawal.\nBalance: %f\n",s[j].balance);

                break;
            }
        }
    }
}
