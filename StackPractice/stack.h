#pragma once

template <typename T>
struct Node {
  T data;
  Node * p_next = NULL;
};

template <class T>
class Stack {
private:
  int stack_size;
  Node<T> * head;
  Node<T> dummy_node;

public:
  int IsEmpty();
  // Return 0 if stack is empty. otherwise it return 1

  int GetSize();
  // Return stack size;

  void Push(T _data);
  // Stores data on the stack. Stores the value stored in parameter data

  T Pop();
  // Deletes stored data lastly
  // Deleted data will return.
  // In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

  T Peek();
  // Return last data, but doesn't delete data
  // In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

  Stack();
  // Initialize stack

  ~Stack();
  // Delete stack
  // If the stack is not empty, delete all remaining nodes and delete stack
};


template <class T>
int Stack<T>::IsEmpty() {
  if(stack_size == 0) return 0;
}

template <class T>
int Stack<T>::GetSize() {
  return stack_size;
}

template <class T>
void Stack<T>::Push(T _data) {
  Node<T> * new_node = new Node<T>;

  new_node->data = _data;
  new_node->p_next = head;
  head = new_node;
  stack_size++;
}

template <class T>
T Stack<T>::Pop() {
  Node<T> * temp_node;
  T temp_data;

  if (stack_size == 0) return 0;

  temp_data = head->data;
  temp_node = head;
  head = head->p_next;
  delete temp_node;
  stack_size--;

  return temp_data;
}

template <class T>
T Stack<T>::Peek() {
  if (stack_size == 0) return 0;

  return head->data;
}

template <class T>
Stack<T>::Stack() : stack_size(0) {
  head = &dummy_node;
}

template <class T>
Stack<T>::~Stack() {
  while(IsEmpty()) Pop();
}
