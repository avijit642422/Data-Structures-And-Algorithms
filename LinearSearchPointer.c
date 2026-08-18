#include<stdio.h>
void linearsearch(int *arr,int n,int key){
    for(int i=0;i<n;i++){
        if(*(arr+i)==key){
            printf("found at index %d\n",i);
         }
}
printf("not fount");
}
int main(){
    int arr[8]={10,20,30,40,50,60,70};
    int n=7;
    int key=40;
    linearsearch(arr,n,key);
    return 0;
}