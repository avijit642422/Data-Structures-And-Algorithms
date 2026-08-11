#include<stdio.h>
int main(){
    int arr[8]={1,4,6,8,10,3};
    int n=6;
    int key=10;
    for(int i=0;i<=n;i++){
        if(arr[i]==key){
            printf("found of index %d",i);
            break;
        }else{
            printf("not found");
        }

    }
    return 0;
}
