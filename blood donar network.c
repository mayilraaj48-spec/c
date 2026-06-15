#include <stdio.h>
#include <string.h>

struct Donor {
    int id;
    char name[50];
    int age;
    char bloodGroup[5];
    char phone[15];
    char city[30];
};

struct Donor donors[100];
int count = 0;

void addDonor() {
    donors[count].id = count + 1;

    printf("\nEnter Name: ");
    scanf(" %[^\n]", donors[count].name);

    printf("Enter Age: ");
    scanf("%d", &donors[count].age);

    printf("Enter Blood Group: ");
    scanf("%s", donors[count].bloodGroup);

    printf("Enter Phone Number: ");
    scanf("%s", donors[count].phone);

    printf("Enter City: ");
    scanf("%s", donors[count].city);

    count++;

    printf("\n Donor Registered Successfully!\n");
}

void viewDonors() {
    if(count == 0) {
        printf("\n No Donors Found!\n");
        return;
    }

    printf("\n       DONOR LIST        \n");

    for(int i = 0; i < count; i++) {
        printf("\nID          : %d", donors[i].id);
        printf("\nName        : %s", donors[i].name);
        printf("\nAge         : %d", donors[i].age);
        printf("\nBlood Group : %s", donors[i].bloodGroup);
        printf("\nPhone       : %s", donors[i].phone);
        printf("\nCity        : %s", donors[i].city);
    }
}

void searchDonor() {
    char bg[5];
    int found = 0;

    printf("\nEnter Blood Group: ");
    scanf("%s", bg);

    for(int i = 0; i < count; i++) {
        if(strcmp(donors[i].bloodGroup, bg) == 0) {
            printf("\nName  : %s", donors[i].name);
            printf("\nPhone : %s", donors[i].phone);
            printf("\nCity  : %s\n", donors[i].city);
            found = 1;
        }
    }

    if(!found)
        printf("\n No Matching Donors Found!\n");
}

void updateDonor() {
    int id;

    printf("\nEnter Donor ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(donors[i].id == id) {

            printf("New Name: ");
            scanf(" %[^\n]", donors[i].name);

            printf("New Age: ");
            scanf("%d", &donors[i].age);

            printf("New City: ");
            scanf("%s", donors[i].city);

            printf("\n Record Updated!\n");
            return;
        }
    }

    printf("\nDonor Not Found!\n");
}

void deleteDonor() {
    int id;

    printf("\nEnter Donor ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {

        if(donors[i].id == id) {

            for(int j = i; j < count - 1; j++) {
                donors[j] = donors[j + 1];
            }

            count--;

            printf("\n Donor Deleted Successfully!\n");
            return;
        }
    }

    printf("\n Donor Not Found!\n");
}

int main() {

    int choice;

    do {
        printf("\n      BLOOD DONOR NETWORK      ");
        printf("\n1. Register New Donor");
        printf("\n2. View All Donors");
        printf("\n3. Search By Blood Group");
        printf("\n4. Update Donor");
        printf("\n5. Delete Donor");
        printf("\n6. Exit");
        printf("\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addDonor();
                break;

            case 2:
                viewDonors();
                break;

            case 3:
                searchDonor();
                break;

            case 4:
                updateDonor();
                break;

            case 5:
                deleteDonor();
                break;

            case 6:
                printf("\n Thank You For Using Blood Donor Network\n");
                break;

            default:
                printf("\n Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
