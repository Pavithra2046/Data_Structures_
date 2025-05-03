void bubblesort(int arr[],int size){
    for (int i=0; i<size-1;i++){
        for (int j=0; j< size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The sorted array: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void selectionsort(int arr[], int ind[], int size){
    for (int i=0;i<size-1;i++){
        int minindex=i;
        for (int j=i+1;j<size;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }}
            int temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
            int temp2=ind[i];
            ind[i]=ind[minindex];
            ind[minindex]=temp2;
        
    }
    printf("The sorted array: ");
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
    printf("The sorted array: ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
