#include<stdio.h>
int main(){
    int B,W,LL,LC,LR,M,N,I,J;
    int choice;
    printf("enter B:");
    scanf("%d",&B);
    printf("enter W:");
    scanf("%d",&W);
    printf("enter LC:");
    scanf("%d",&LC);
    printf("enter LR:");
    scanf("%d",&LR);
    printf("enter M:");
    scanf("%d",&M);
    printf("enter N:");
    scanf("%d",&N);
    printf("enter I:");
    scanf("%d",&I);
    printf("enter J:");
    scanf("%d",&J);
    printf("enetr the choice:");
    scanf("%d",& choice);


switch (choice){
    case 1:
    int x=B+W*((I-LR)*N+(J-LC));
    printf("the row major address is:%d",x);
    break;
    case 2:
    int y=B+W*((J-LC)*M+(I-LR));
    printf("the column mejor address is:%d",y);
    break;
    default:
    printf("invalid choice");
}
    return 0;


}
