//Sorting a given array
#include <iostream>
#include <cstdlib>

void bubblesort(int arr[],int size); //sorting the elements using the bubble sort method
void selectionsort(int arr[], int size); //sorting the elements using the selection sort method
void insertionsort(int arr[], int size); // sorting the elements using the insertion sort method

int main(){
    int userchoice=0; // saves the userchoice 
    int end=0;
    while(end==0){
    printf("The Menu\n");
    printf("1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&userchoice);
    if (userchoice==1||userchoice==2||userchoice==3){
        int size;// size of the input array
        printf("Enter the size of the array: ");
        scanf("%d",&size);
        int array[size];
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
        switch(userchoice){
            case 1:
            bubblesort(array,size);
            break;
            case 2:
            selectionsort(array,size);
            break;
            case 3:
            insertionsort(array,size);
            break;
        }}
    else{
        end=1;
        }}
return 0;}

void bubblesort(int arr[],int size){
    for (int i=0; i<size-1;i++){
        for (int j=0; j< size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1]; // swapping the array elements
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The sorted array through bubble sort is: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void selectionsort(int arr[], int size){
    for (int i=0;i<size-1;i++){
        int minindex=i;
        for (int j=i+1;j<size;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
            int temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
        }
    }
    printf("The sorted array through selection sort: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void insertionsort(int arr[],int size){
    for (int i=1;i<size;i++){
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printf("The sorted array through insertion sort is: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


