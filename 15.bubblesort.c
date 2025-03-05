#include<stdio.h>

void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubblesort(int *arr,int n){
    int temp;
    for(int i=0;i<n-1;i++){                  //for number of pass
        for (int j = 0; j <n-i-1; j++)       //for comparison in each pass
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
}
int main(){
     int arr[] = {12,54,65,7,23,9};
     int n = 6;
     printArray(arr,n);
     bubblesort(arr,n);
     printArray(arr,n);
     return 0;
}