#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubblesort(int *arr,int n){
    int temp;
    int issorted = 0;
    for(int i=0;i<n-1;i++){                    //for number of pass
        printf("Working on pass number %d\n",i+1); 
        issorted = 1;               
        for (int j = 0; j <n-i-1; j++)       //for comparison in each pass
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                issorted = 0;
            }
        }
        if(issorted)
        return;
    }
}
int main(){
     int arr[] = {1,2,3,4,5,6};
     int n = 6;
     printArray(arr,n);
     bubblesort(arr,n);
     printArray(arr,n);
     return 0;
}