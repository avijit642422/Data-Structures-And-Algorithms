#include<stdio.h>
#define max 5
int stack[max];
int top=-1;
int isfull(){
return top==max-1;
}
int isempty(){
    return top==-1;
}
//push fuction
void push(int value){
    if(isfull()){
        printf("the stack is overflow");
    }else{
        top++;
        stack[top]=value;
        printf("push value %d\n",value);
    }
}
//pop function
int pop(){
    if(isempty()){
        return -1;
    }else{
        int popped=stack[top];
        top--;
        return popped;
    }
}
//peck function
int peck(){
    if(isempty()){
        return -1;
    }else{
        int peck=stack[top];
        return peck;
    }
}
//display function
void display(){
    if(isempty()){
        printf ("empty");
        return;
    }else{
        printf("given stack:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){
push(10);
push(20);
push(30);
display();
printf("the top element is: %d\n",peck());
printf("popped element is: %d\n",pop());
display();
return 0;
}