
#include<stdio.h>
void TraversArray(int *arr,int n){
    for(int i=0;i<n;i++){
    printf("%d ",*(arr+i));
    }
}
int main(){
    int arr[6]={10,20,30,40,50,70};
    int n=6;
    TraversArray(arr,n);
    return 0;
}