#include<stdio.h>
void accessArray(int *arr,int n){
    printf("%d",*(arr+1));
}
int main(){
    int arr[5]={10,20,30,40,50};
    int n=5;
    accessArray(arr,n);
    return 0;
}

