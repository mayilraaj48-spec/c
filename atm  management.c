#include<stdio.h>
#include<string.h>

struct account{
    int acc_no;
    char name[20];
    float balance;
} a[100];

void deposit(int acc_no, float amount);
void balance_enquiry(int acc_no);
void search_account(int acc_no);

int main(){
    int n, i, acc_no;
    printf("enter the number of accounts:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter details for account %d:\n",i+1);
        printf("account number:");
        scanf("%d",&a[i].acc_no);
        printf("name:");
        scanf("%19s",a[i].name);
        printf("balance:");
        scanf("%f",&a[i].balance);
    }

    printf("enter account number to search:");
    scanf("%d", &acc_no);
    search_account(acc_no);

    return 0;
}

void deposit(int acc_no, float amount){
    int i;
    for(i=0;i<100;i++){
        if(a[i].acc_no == acc_no){
            a[i].balance += amount;
            printf("amount deposited successfully\n");
            return;
        }
    }
    printf("account not found\n");
}

void search_account(int acc_no){
    int i;
    for(i=0;i<100;i++){
        if(a[i].acc_no == acc_no){
            printf("account number: %d\n", a[i].acc_no);
            printf("name: %s\n", a[i].name);
            printf("balance: %.2f\n", a[i].balance);
            return;
        }
    }
    printf("account not found\n");
}

void balance_enquiry(int acc_no){
    int i;
    for(i=0;i<100;i++){
        if(a[i].acc_no == acc_no){
            printf("account number: %d\n", a[i].acc_no);
            printf("name: %s\n", a[i].name);
            printf("balance: %.2f\n", a[i].balance);
            return;
        }
    }
    printf("account not found\n");
}
