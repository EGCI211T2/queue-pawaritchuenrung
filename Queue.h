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
    /* Add head and tail for me please */
   //1. connect & Change tail
   if(size>0){
    tailPtr->set_next(new_node);
    tailPtr = new_node;
   }
   else{
    tailPtr = new_node;
    headPtr = new_node;
   

   }
   size++;
  //2. (may be) change head  when the queue is empty
 
  //3. increase size

 }
 else
    cout<<"Out of memory"<<endl;
}

int Queue::dequeue(){
  if(size>0){
    if(headPtr!=NULL){
    NodePtr t=headPtr;
    int value= t->get_value();
    headPtr=headPtr->get_next();
    if(headPtr==NULL) tailPtr = NULL;
     /* Add head and tail for me please */
     --size;
    delete t;  
    cout << "dequeing " << value << endl;
    return value;
   
  }
}
else
  cout<<"Empty Queue"<<endl;
  return -1;
}


Queue::Queue(){
    //initialize Queue
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
   
}

Queue::~Queue(){
    cout << "Clearing queue" << endl;

    while(size > 0){
        dequeue();
    }
}


#endif
