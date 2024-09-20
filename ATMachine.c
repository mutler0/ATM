
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <stdbool.h>
//Morgan Butler
//2/1/24 
//CIS 2107
//Lab 03 ATM MACHINE
//Displaying the balance of the account throughout transcations being made including, withdrawals and deposits.


int menuOptions(int remainingBalance);

int withdrawalLimit = 1000;
int depositLimit = 10000;
int intialBalance = 5000;
unsigned int withdrawalCounter, depositCounter;

bool ifDecimal(double number){
    double fractpart, intpart;
    fractpart = modf (number , &intpart);
    if (fractpart > 0){
        return true;
    }
    return false;
}

bool ifNegative(double number){
    if (number < 1){
        return true;
    }
    return false;
}


int balance(float remainingBalance){
    printf("\nYour Remaining Balance is $%.2f\n", remainingBalance);
    return remainingBalance;
}

int cashWithdrawal(float remainingBalance){//fix limit
    unsigned int leftOver, counter, userInput, entrances;
    float amount = 0;

    if (withdrawalLimit == 0){
            printf("\nDaily transaction limit has been met.\n\tBack to Main Menu ~~>\n");
            return remainingBalance;
    }
    while (counter < 3){
        printf("\nPlease Enter Withdrawal Amount in $20s. \nOr enter -1 to go back to the menu:\n\t$");
        scanf("%f", &amount);

        if (amount == -1){
            printf("\n\tBack to Main Menu ~~>\n");
            return remainingBalance;
        }

        printf("\n\tWithdrawing $%.2f...\n", amount);

        if (ifDecimal(amount) || ifNegative(amount)){
            printf("\n\t*Invalid input*\nPlease enter desired withdraw amount in intervals of $20\n");
            counter++;

        } else if ((withdrawalLimit - amount) < 0){
            printf("\n\t*ERROR*\nDaily transaction amount has exceeded.\nYou have $%d left to withdraw.\n", withdrawalLimit);
            counter++;

        }else if ((int)amount % 20 == 0){
            remainingBalance -= amount;
            withdrawalLimit -= amount;

            //printf("\n\tWithlimit updated: $%d\n", withdrawalLimit);
            printf("\nYou successfully withdrew $%.2f.\nYour remaining balance is $%.2f\n", amount, remainingBalance);

            printf("\nWould you like a receipt?\n   1 for Yes\t2 for No\n");
            scanf("%u", &userInput);
            if (userInput == 1){
                printf("\n\tPrinting Receipt...\n\tBack to Main Menu ~~>\n");
                withdrawalCounter++;
                return remainingBalance;
            }  else {
                return remainingBalance;
            } 

        } else {
            printf("\n\t*Invalid Input*\nMust enter amount in interval of $20\n");
            counter++;
        }   
    }
    if (counter == 3){
        printf("\n\t*ERROR* \nToo many invalid inputs.\n\t Gooybye.\n");
        exit(0);
    }
    return remainingBalance;
}

int cashDeposit(float remainingBalance){
    unsigned int leftOver, counter, userInput;
    float amount = 0;

    if (depositLimit == 0){
            printf("\nDaily deposition limit has been met.\n\tBack to Main Menu ~~>\n");
            return remainingBalance;
    }

    while (counter < 3){
        printf("\nPlease Enter Deposition Amount in $1s, $5s or $10s. \nOr enter -1 to go back to the menu:\n\t$");
        scanf("%f", &amount);

        if (amount == -1){
            printf("\n\tBack to Main Menu ~~>\n");
            return remainingBalance;
        }

        printf("\n\tDepositing $%.2f...\n", amount);
        if (ifDecimal(amount) || ifNegative(amount)){
            printf("\n\t*Invalid input*\nPlease enter desired deposit amount in intervals of $1s, $5s or $10s.\n");
            counter++;

        }else if ((depositLimit - amount) < 0){
            printf("\n\t*ERROR*\nDaily transaction amount has exceeded.\nYou have $%d left to deposit.\n", depositLimit);
            counter++;
            
        }else {
            remainingBalance += amount;
            depositLimit -= amount;
            printf("\nYou successfully deposited $%.2f.\nYour updated balance is $%.2f\n", amount, remainingBalance);
            
            printf("\nWould you like a receipt?\n   1 for Yes\t2 for No\n");
            scanf("%u", &userInput);
            if (userInput == 1){
                printf("\n\tPrinting receipt...\n\tBack to Main Menu ~~>\n");
                depositCounter++;
                return remainingBalance;
            }else{
                return remainingBalance;
            }
        } 
    }
    if (counter == 3){
        printf("\n\t*ERROR* \nToo many invalid inputs.\n\t Gooybye.\n");
        exit(0);
    } else{
        printf("\nDaily deposition amount has exceeded.\n\tBack to Main Menu ~~>\n");
    }
    return remainingBalance;

}

void quit(){
    
    printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\tThank For Using MB ATM\n");
    printf("\n\t\tReceipt: \n\tSuccessful Deposits: %d\n\tSuccessful Withdrawals: %d \n",depositCounter, withdrawalCounter);
    printf("\n\t\tG'Day!\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    exit(0);
}


int menuOptions(int remainingBalance){
    unsigned int userInput = 3;
    while (userInput!= 4){
        printf("\nPlease Input:\n\t 1 for Balance.\n\t 2 for Cash Withdrawal.\n\t 3 for Cash Deposition.\n\t 4 for Quit. \n");
        scanf("%u", &userInput);

        if (ifDecimal(userInput) || ifNegative(userInput)){
            printf("\nInvalid Input.\nPease Enter 1, 2, 3 or 4");
        } else if (userInput == 1){
            balance(remainingBalance);
        } else if (userInput == 2){
            remainingBalance = cashWithdrawal(remainingBalance);
        } else if (userInput == 3){
            remainingBalance = cashDeposit(remainingBalance);
        } else if (userInput == 4){
            quit();
        } else{
            printf("\nInvalid Input.");
        }   
    }
    return 4;
}

bool pinValidation(){
    float pinAttempt;
    float pin = 3014;
    int attempts = 3;
    
    while (attempts > 0){
        printf("\nPlease Enter 4-digit PIN: ");
        scanf("%f", &pinAttempt);
        if (pinAttempt == pin){
            return true;
        } else {
            attempts--;
            if (attempts == 0){
                printf("\nError Too Many Incorrect Passwords Entered. \nNo more attempts. Goodbye.\n\n");
                return false;
            } else if (ifDecimal(pinAttempt) || ifNegative(pinAttempt)){
                printf("\nInvalid input.");
            } else {
                printf("\nIncorrect PIN.");
            } 
            printf("\nTry again.\n%d more attempts.\n", attempts);
        }
    }
    return false;
}

int main(){
    printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\tWelcome to MB ATM\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    if (pinValidation() == true){
        menuOptions(intialBalance);
    } else {
        exit(0);
    }
}