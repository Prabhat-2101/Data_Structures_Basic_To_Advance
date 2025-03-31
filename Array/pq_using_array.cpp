#include<bits/stdc++.h>
using namespace std;

typedef struct priority_queue{
    int value;
    int priority;
}pq;

pq arr[10000];
int size = -1;

void insert(int val,int prior){
    size++;
    arr[size].value = val;
    arr[size].priority = prior;
}

int peek(){
    int highest_priority = INT_MIN;
    int idx = -1;
    
    for(int i=0;i<size;i++){
        if(arr[i].priority > highest_priority){
            highest_priority = arr[i].priority;
            idx  = i;
        }
        else if(arr[i].priority == highest_priority){
            if(idx > -1 && arr[i].value > arr[idx].value){
                idx = i;
            }
        }
    }
    return idx;
}

void delete(){
    int idx = peek();
    for(int i=idx;i<=size;i++){
        arr[i] = arr[i+1];
    }
    size--;
}

int main(){
    cout<<"Number of elements: ";
    int N;cin>>N;
    cout<<"enter value with priority: \n";
    for(int i=0;i<N;i++){
        int value,priority;
        cin>>value>>priority;
        insert(value,priority);
    }
    
    cout<<"Operations: \n1.Insertion\n2.Deletion\n3.Peek\n4.Exit\n";
    while(true){
        cout<<"Choice: ";
        int choice; cin>>choice;
        switch(choice){
            case 1: insert(val,priority);
            break;
            case 2: delete();
            break;
            case 3: int idx = peek();
            cout<<"Peek element: "<<arr[idx]<<endl;
            break;
            case 4:exit(-1);
            default: cout<<"Invalid choice....\n";
        }
    }
}