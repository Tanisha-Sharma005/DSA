#include<stdio.h>

void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selectionsort(int *arr,int n){
    int indexmin,temp;
    printf("Running selection sort\n");
    for(int i=0;i<n-1;i++){
       indexmin = i;
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[indexmin]){
            indexmin=j;
        }
       }
       temp=arr[i];
       arr[i]=arr[indexmin];
       arr[indexmin]=temp;
    }
}
int main(){
     int arr[] = {12,54,65,7,23,9};
     int n = 6;
     printArray(arr,n);
     selectionsort(arr,n);
     printArray(arr,n);
     return 0;
}