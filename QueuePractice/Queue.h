#pragma once

template <typename T>
struct Node {
	T data;
	Node * p_next = NULL;
};

template <class T>
class Queue {
private:
	int queue_size;
	Node<T> * front;
	Node<T> * rear;

public:
	bool IsEmpty();
	// Return 1 if queue is empty. otherwise it return 0

	int GetSize();
	// Return queue size;

	void Enqueue(T _data);
	// Stores first data on the queue. Stores the value stored in parameter data

	T Dequeue();
	// Deletes the first data
	// Deleted data will return.
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	T Peek();
	// Return first data, but doesn't delete data
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	Queue();
	// initialize queue

	~Queue();
	// Delete queue
	// If the queue is not empty, delete all remaining nodes and delete queue
};

template <class T>
bool Queue<T>::IsEmpty() {
  if(queue_size == 0) return true;

  return false;
}

template <class T>
int Queue<T>::GetSize() {
	return queue_size;
}

template <class T>
void Queue<T>::Enqueue(const T _data) {
	Node<T> * new_node = new Node<T>;

	if (queue_size >= 1) {
		rear->next = new_node;
	} else if (queue_size == 0) {
		front = new_node;
	}
	new_node->data = _data;
	rear = new_node;
	queue_size++;
}

template <class T>
T Queue<T>::Dequeue() {
	Node<T> * temp_node;
	T temp_data;

	if (queue_size == 0) return 0;

	temp_data = front->data;
	temp_node = front;
	front = front->next;
	delete temp_node;
	queue_size--;

	return temp_data;
}

template <class T>
T Queue<T>::Peek() {
  if (queue_size == 0) return 0;

  return front->data;
}

template <class T>
Queue<T>::Queue() : queue_size(0) {
	front = NULL;
	rear = NULL;
}

template <class T>
Queue<T>::~Queue() {
  while(!IsEmpty()) Dequeue();
}
