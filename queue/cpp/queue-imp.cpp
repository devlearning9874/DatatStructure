//Operation in queue:
// 1. Enqueue 2. Dequeue 3. isFull() 4. isEmpty() 5. front() 6. rear()
// All of the above operations take O(1) time complexity

#include<iostream>

using namespace std;

class Queue{
   
   public:
    int front, rear,size;
    unsigned capacity;
    int *arr;
};

Queue* createQueue(unsigned capacity){

    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->arr = new int[(queue->capacity * sizeof(int))];
    return queue;
}

bool isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue){
    return (queue->size = 0);
}

void enqueue(Queue* queue, int data){

    if( isFull(queue) ){
        cout<<"Queue Overflow"<<endl;
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear]  = data;
    queue->size = queue->size + 1;
    cout<<data<<" "<<"Enqueued Successfully!"<<endl;
}

int dequeue(Queue* queue){

    if(isEmpty(queue)){
        cout<<"Queue Underflow";
        return INT_MIN;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->arr[queue->front];
}

int rear(Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->arr[queue->rear];
}

int main(){

    Queue* queue = createQueue(1000);

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);


    cout<<dequeue(queue)<<" "<<"Dequeued Successfully!"<<endl;
    cout<<front(queue)<<" "<<"is at front"<<endl;
    cout<<rear(queue)<<" "<<"is at rear"<<endl;

    return 0;

}