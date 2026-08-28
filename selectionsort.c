#include<stdio.h>
void selectionsort(int arr[],int size){
    for(int step=0;step<size-1;step++){
        int min_idx=step;
        for(int i=step+1;i<size;i++){
            if(arr[i]<arr[min_idx]){
                min_idx=i;

            }
        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[step];
        arr[step]=temp;
        printf("pass%d :",step+1);
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
            }
            printf("\n");
    } 
}
int main(){
    int data[]={6,4,7,8,1,9,5};
    int size=sizeof(data)/sizeof(data[0]);
    selectionsort(data,size);
    printf("sorted array:\n");
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }

}