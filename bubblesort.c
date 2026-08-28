#include<stdio.h>
void bubblesort(int arr[],int size){
    for(int step=0;step<size-1;step++){
        for(int i=0;i<size-step-1;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
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
    bubblesort(data,size);
    printf("sorted array:\n");
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }

}







