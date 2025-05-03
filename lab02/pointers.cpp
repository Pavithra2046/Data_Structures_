#include <iostream>
#include <cstdlib>
#include <math.h>

int lengthofnumber(int *num);
void palindrome(int *num);
void armstrongnumber(int *num);
void perfectnumber(int *num);

int main(){

    int *userchoice = (int *)malloc(sizeof(int));
    int *num = (int *)malloc(sizeof(int));
    int *end = (int *)calloc(1,sizeof(int));

    while (*end!=1){
    printf("The Menu\n1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n");
    printf("Enter the choice: ");
    scanf("%d",userchoice);

    if (*userchoice==1||*userchoice==2||*userchoice==3){
        printf("Enter the number: ");
        scanf("%d",num);
        switch(*userchoice){
            case 1:
            palindrome(num);
            break;
            case 2:
            armstrongnumber(num);
            break;
            case 3:
            perfectnumber(num);
            break;
        }
    }
    else{
        *end=1;
        printf("You have exited the program!\n");
    }}
    free(num);
    free(userchoice);
    free(end);
    return 0;
}

// calculates the length of a string
int lengthofnumber(int *num){

    int *temp1=(int *)malloc(sizeof(int));
    int *length=(int *)calloc(1,sizeof(int));
    *temp1=*num;

    while(*temp1>0){
        *length=*length+1;
        *temp1=*temp1/10;
    }

    return *length;
    free(temp1);
    free(length);
}

// checks if a given number is a palindrome
void palindrome(int *num){

    int *palin=(int *)calloc(1,sizeof(int));
    int *temp2=(int *)malloc(sizeof(int));
    int *l=(int *)calloc(1,sizeof(int));
    *temp2=*num;

    while(*temp2>0){
        *palin=(*palin*10)+(*temp2%10);
        *temp2=*temp2/10;
    }

    printf("%d\n",*palin);

    if (*palin==*num){
        printf("The given number is a palindrome\n");
    }
    else{
        printf("The given number is not a palindrome\n");
    }
    free(temp2);
    free(palin);
    free(l);

}

// checks if a given number is an Armstrong number
void armstrongnumber(int *num){

    int *sum=(int *)calloc(1,sizeof(int));
    int *temp3=(int *)malloc(sizeof(int));
    int *length=(int *)calloc(1,sizeof(int));
    int *digit=(int *)calloc(1,sizeof(int));
    int *power=(int *)calloc(1,sizeof(int));

    *length=lengthofnumber(num);
    *temp3=*num;

    while (*temp3 > 0) {
        *digit = *temp3 % 10; 
        *power = 1;           
        for (int i = 0; i < *length; i++) {
            *power = *power * (*digit);
        }
        *sum = *sum + *power; 
        *temp3 = *temp3 / 10; 
    }

    if (*sum==*num){
        printf("The given number is an Armstrong number\n");
    }

    else{
        printf("The given number is not an Armstrong number\n");
    }
    free(sum);
    free(temp3);
    free(length);
}

// checks if a given number is a perfect number
void perfectnumber(int *num){

    int *perf=(int *)calloc(1,sizeof(int));
    int *i=(int *)calloc(1,sizeof(int));

    for (*i=1; *i<*num; (*i)++){
        if (*num%*i==0){
            *perf=*perf+*i;
        }
    }

    if (*perf==*num){
        printf("The given number is a perfect number\n");
    }
    
    else{
        printf("The given number is not a perfect number\n");
    }
    free(perf);
    free(i);
}