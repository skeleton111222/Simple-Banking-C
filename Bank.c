#include <stdio.h>
#include <stdlib.h>

/* Create Account */
void createAccount() {
    FILE *fp = fopen("bank.txt", "a");
    int accNo;
    char name[50];
    float balance;

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Initial Balance: ");
    scanf("%f", &balance);

    fprintf(fp, "%d %s %.2f\n", accNo, name, balance);
    fclose(fp);

    printf("Account created successfully!\n");
}

/* Deposit */
void depositMoney() {
    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int accNo, search;
    char name[50];
    float balance, amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &search);
    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &accNo, name, &balance) != EOF) {
        if (accNo == search) {
            balance += amount;
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", accNo, name, balance);
    }

    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        printf("Deposit successful!\n");
    else
        printf("Account not found!\n");
}

/* Withdraw */
void withdrawMoney() {
    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int accNo, search;
    char name[50];
    float balance, amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &search);
    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &accNo, name, &balance) != EOF) {
        if (accNo == search) {
            if (balance >= amount) {
                balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", accNo, name, balance);
    }

    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
        printf("Account not found!\n");
}

/* Check Balance */
void checkBalance() {
    FILE *fp = fopen("bank.txt", "r");
    int accNo, search;
    char name[50];
    float balance;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &search);

    while (fscanf(fp, "%d %s %f", &accNo, name, &balance) != EOF) {
        if (accNo == search) {
            printf("\nAccount No: %d", accNo);
            printf("\nName: %s", name);
            printf("\nBalance: %.2f\n", balance);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}

/* Main Function */
int main() {
    int choice;
    /* Menu */
    do {
        printf("\n=== Banking System (Text File) ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
