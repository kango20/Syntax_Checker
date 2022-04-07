#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
using namespace std;

template<class T>
class ListNode{
    public:
        ListNode(); //default constructor
        ListNode(T d); //overloaded constructor
        ~ListNode(); //destructor
        ListNode *next;
        ListNode *prev;
        T data;
};

template<class T>
ListNode<T>::ListNode(){ //default constructor
}

template<class T>
ListNode<T>::ListNode(T d){ //overloaded constructor
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

template<class T>
ListNode<T>::~ListNode(){ //destructor
  next = NULL;
  prev = NULL;
}

template<class T>
class GenStack{
  public:
    GenStack(); // default constructor
    GenStack(T stackSize); // overloaded constructor, parameter that changes size of array when instantiated
    ~GenStack(); // destructor

    //core functions
    void push(T data);
    T pop();
    T peek(); //aka top()

    //helper/aux functions
    bool isEmpty();
    unsigned int getSize();

  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
};

template<class T>
GenStack<T>::GenStack(){
  front = NULL;
  back = NULL;
  size = 0;
}

template<class T>
GenStack<T>::GenStack(T stackSize){
  front = NULL;
  back = NULL;
  size = stackSize;
} // overloaded constructor, parameter that changes size of array when instantiated

template<class T>
GenStack<T>::~GenStack(){ // destructor
  ListNode<T> * curr = front;
  while(curr != NULL){
    ListNode<T> * temp = current;
    current = current -> next;
    delete temp;
  }
}

//core functions
template<class T>
void GenStack<T>::push(T data){ //insert data onto stack
  ListNode<T> * node = new ListNode<T>(data);

  if(isEmpty()){
      back = node;
  }
  else{
      //it's not empty
      node->next = front;
      front->prev = node;
  }
  front = node;
  ++size;
}

template<class T>
T GenStack<T>::pop(){ //remove data from stack
  if(isEmpty()){
      throw runtime_error("stack is empty!");
  }

  ListNode<T> *temp = front;

  if(front->next == NULL){
      back = NULL;
  }
  else{
      //more than one node in the list
      front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template<class T>
T GenStack<T>::peek(){ //looks at the front/top value of the stack
  if(isEmpty()){
    throw runtime_error("Stack is empty, nothing to peek");
  }
  return front->data;

} //aka top()

//helper/aux functions
template<class T>
bool GenStack<T>::isEmpty(){ //returns true if stack is empty
  return (size == 0);
}

template<class T>
unsigned int GenStack<T>::getSize(){ //returns the size of the stack
  return size;
}


#endif
