#include<stdio.h>
#include<stdbool.h>
void selectionsort(int arr[],int size){
    for(int step=0;step<size-1;step++){
        bool flag=true;
        int min_idx=step;
        for(int i=step+1;i<size;i++){
            if(arr[i]<arr[min_idx]){
                min_idx=i;

            }
        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[step]; 
        arr[step]=temp;
        flag=false;
        if(flag==true) break;
        printf("pass%d :",step+1);
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    } 
}
int main(){
    int data[]={5,1,4,2,3};
    int size=sizeof(data)/sizeof(data[0]);
    selectionsort(data,size);
    printf("sorted array:\n");
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }

}