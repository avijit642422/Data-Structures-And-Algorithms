#include<stdio.h>
void linearsearch(int *arr,int n,int key){
    int i;
    for(i=0;i<n;i++){
        if(*(arr+i)==key){
            printf("found at index %d\n",i);
            return;
        }
    }
    printf("not found\n");
}
int main(){
int arr[7]={5,7,2,3,9,1,8};
int key=9;
int n=7;
linearsearch(arr,n,key);
return 0;
}