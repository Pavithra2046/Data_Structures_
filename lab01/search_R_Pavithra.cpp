//Searching elements using linear search and binary search
#include <iostream>
#include <cstdlib>
#include "sortfile.h"

int linearsearch(int arr[],int size,int target); //searching the element through linear search
int binarysearch(int arr[],int ind[],int size,int target); //searching the element through binary search

int main(){
    int userchoice=0; // saves the userchoice 
    int end=0;
    int target;
    while(end==0){
    printf("The Menu\n");
    printf("1. Linear Search\n2. Binary Search\n3. Exit");
    printf("Enter your choice: ");
    scanf("%d",&userchoice);
    if (userchoice==1||userchoice==2){
        int size;// size of the input array
        printf("Enter the size of the array: ");
        scanf("%d",&size);
        int array[size];
        int index[size]; //keeps track of the indexes of the original array
        printf("Enter elements of the array:\n");
        int count=0;
        int temp_ele=0;
            while(count<size){
                scanf("%d",&temp_ele);
                if(temp_ele>=0){
                    array[count]=temp_ele;
                    count++;
                }
                else{
                    printf("Invalid number! Enter again.\n");
                }
        }  
    int result;
        switch(userchoice){
            case 1:
                printf("Enter the target element: ");
                scanf("%d",&target);
            result = linearsearch(array,size,target);
            if (result!=-1){
                printf("The element is found at index %d\n",result);
            }
            else{
                printf("Element was not found in the array\n");
            }
            break;
            case 2:
            printf("Enter the target element: ");
            scanf("%d",&target);
            result=binarysearch(array,index,size,target);
            if (result!=-1){
                printf("The element is found at index %d of the original array\n",result);
            }
            else{
                printf("Element was not found in the array\n");
            }
            break;
            case 3:
            printf("You exited the program! ");
            end=1;
            break;
        }
    }
    return 0;
}}
int linearsearch(int arr[],int size,int target){
    for (int i=0; i<size; i++){
        if (arr[i]==target){
        return i;
    }}
    return -1;
}

int binarysearch(int arr[],int ind[],int size, int target){
    selectionsort(arr,ind,size);
    int left=0;
    int right=size-1;
    while (left<right){
        int middle=(left+right)/2;
        if (arr[middle]==target){
            return ind[middle];
        }
        if (arr[middle]>target){
            right=middle-1;
        }
        else{
            left=middle+1;
        }
        
    }
}