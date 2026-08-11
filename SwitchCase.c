#include<stdio.h>
int main(){
    printf("1.Array\n");
    printf("2.Linked List\n");
    printf("3.Tree\n");
    printf("4.Graph\n");
    int choice;
    printf("select a data structure(1-4):");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("non-primitive\n");
        printf("linear\n");
        printf("static\n");
        break;
        case 2:
        printf("non-primitive\n");
        printf("linear\n");
        printf("dyamic\n");
        break;
        case 3:
        printf("non-primitive\n");
        printf("non-linear\n");
        printf("dynamic\n");
        break;
        case 4:
        printf("non-primitive\n");
        printf("non-linear\n");
        printf("dynamic\n");
        break;
        default:
        printf("invalid selection");
    }
    return 0;
}


