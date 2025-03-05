#include<stdio.h>
#include<limits.h>
int maximum(int A[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}
void countsort(int *A,int n){
    int max = maximum(A,n);
}
int main(){
    int A[] = {9,14,4,8,7,5,60};
    int n=7;
    printArray(A,n);
    countsort(A,n);
    printArray(A,n);

    return 0;
}