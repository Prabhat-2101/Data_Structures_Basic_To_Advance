//IMPLEMENTATION OF QUEQE USING ARRAY

#include<stdio.h>
#define size 3
int Queqe[size];
int front = -1;
int rear = -1;

void choice(){
    printf("______________________________________________\n");
    printf("|IMPLEMENTATION OF QUEQE USING ARRAY \n");
    printf("|OPERATIONS CAN BE PERFORMED: \n");
    printf("|1.ENQUEQE\t2.DEQUEQE\n|3.DISPLAY\t4.EXIT\n");
    printf("______________________________________________\n");
}

void enqueqe(){
    int val;
    if(rear == size-1)
        printf("Queqe is Full\n");
    else{
        printf("Enter element: ");
        scanf("%d",&val);
        if(front == -1)
            front = 0;
        Queqe[++rear] = val;
    }
}

void dequeqe(){
    if(rear == -1 || front > rear)
        printf("Queqe is empty\n");
    else
        printf("Dequeqe performed and Deleted element: %d\n",Queqe[front++]);
}

void display_queqe(int a[]){
    for(int i = front; i<= rear; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    choice();
    while(1){
        int choice,val;
        printf("CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueqe();
                    break;
            case 2: dequeqe();
                    break;
            case 3: display_queqe(Queqe);
                    break;
            case 4: printf("Exiting.....");
                    return 0;
            default:printf("Invalid input\n");
        }
    }
    return 0;
}