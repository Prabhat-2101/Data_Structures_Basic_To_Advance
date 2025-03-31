//IMPLEMENTATION OF DOUBLE ENDED QUEQE USING ARRAY
//MAIN DISADVANTAGE:- SIZE CAN NOT BE CHANGED AT RUN TIME

#include<stdio.h>
#define SIZE 10 
int Queqe[SIZE];
int front = -1;
int rear = -1;

void print_choice(){
    printf("________________________________________________\n");
    printf("IMPLEMENTATION OF DOUBLE ENDED QUEQE USING ARRAY\n");
    printf("OPERATION CAN BE PERFORMED: \n");
    printf("1.INSERT AT FRONT\t2.INSERT AT REAR\n");
    printf("3.DELETE AT FRONT\t4.DELETE AT REAR\n");
    printf("5.DISPLAY\t\t\t6. EXIT\n");
    printf("OVERFLOW: Queqe is full\n");
    printf("UNDERFLOW: Queqe is Empty\n");
    printf("________________________________________________\n");
}

void insert_at_front(){
    int val;
    if(front == 0)
        printf("QUEQE OVERFLOW\n");
    else{
        printf("Enter element: ");
        scanf("%d",&val);
        if(front == -1){
            front++;
            rear++;
        }
        else if(front > 0)
            front--;
        Queqe[front] = val;
    }
}

void insert_at_rear(){
    int val;
    if(rear == SIZE-1)
        printf("QUEQE OVERFLOW\n");
    else{
        printf("Enter element: ");
        scanf("%d",&val);
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        Queqe[++rear] = val;
    }
}

void delete_at_front(){
    if(rear == -1 || front > rear)
        printf("QUEQE UNDERFLOW\n");
    else
        printf("Deleted element: %d\n",Queqe[front++]);
}

void delete_at_rear(){
    if(rear == -1)
        printf("QUEQE UNDERFLOW\n");
    else{
        if(front == rear){
            printf("Deleted element: %d\n",Queqe[rear]);
            front = -1;
            rear = -1;
        }
        else
            printf("Deleted element: %d\n",Queqe[rear--]);
    }
}

void display(){
    printf("CURRENT QUEQE: ");
    for(int i = front; i<= rear; i++)
        printf("%d ",Queqe[i]);
    printf("\n");
}

int main(){
    //calling choice function to print choice list
    print_choice();
    while(1){
        int choice;
        printf("CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_at_front();
            break;
            case 2: insert_at_rear();
            break;
            case 3: delete_at_front();
            break;
            case 4: delete_at_rear();
            break;
            case 5: display();
            break;
            case 6: printf("Exiting......");
            return 0;
            default: printf("INVALID CHOICE\n");
        }
    }
    return 0;
}