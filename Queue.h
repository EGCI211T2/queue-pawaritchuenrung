
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node!=NULL){ 
    //1.connect & change tail
    if(size>0)
    tailPtr->set_next(new_node);
    //2.(may be)change head when the queue is empty
    else 
    {
        tailPtr->new_node;
        headPtr->new_node;
        
    }
    //3. increase size
    size++;
    
}
else cout<<"Out of memory"<<endl;

int Queue::dequeue(){
  if(size>0){
    if(headPtr!=NULL)
    {
        NodePtr t=headPtr;
        headPtr = headPtr-> get_next();
        if()tailPtr = NULL;//แก้นี้ด้วย อย่าลืมมม
        --size;
        delete t;
    }
    
     /* Add head and tail for me please */
          
    
  }
  cout<<"Empty queue";
  return -1;
}


Queue::Queue(){
    //initialize Queue
}
Queue::~Queue(){
    //delete all remaning Queue (i.e. DQ all) 
    cout<<"Dequeue all"<<endl;
    int n=size;
    for(i=0;i<n;i++)
    dequeue();
}


#endif
