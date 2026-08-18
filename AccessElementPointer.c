
#include<stdio.h>
void accessArray(int *arr,int n){
    printf("%d",*(arr+1));
}
int main(){
    int arr[6]={10,20,30,40,50,70};
    int n=6;
    accessArray(arr,n);
    return 0;
}