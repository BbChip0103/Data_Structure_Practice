#pragma once

template <typename T>
struct Node {
	T data;
	Node * p_before = NULL;
	Node * p_next = NULL;
};

template <class T>
class Dequeue {
private:
	int dequeue_size;
	Node<T> * p_dummy_front, * p_dummy_rear;

public:
	bool IsEmpty();
	// Return 'true' if Dequeue is empty. otherwise it return 'false'

	int GetSize();
	// Return Dequeue size;

	void AddFront(T data);
	// Stores data in the front on the Dequeue. Stores the value stored in parameter data

	void AddRear(T data);
	// Stores data in the rear on the Dequeue. Stores the value stored in parameter data

	T RemoveFront();
	// Deletes stored data in the front
	// Deleted data will ret1urn.
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	T RemoveRear();
	// Deletes stored data in the rear
	// Deleted data will ret1urn.
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	T PeekFront();
	// Return data in the front, but doesn't delete data
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	T PeekRear();
	// Return data in the Rear, but doesn't delete data
	// In order to call this function, must have at least one piece of data
	// If dequeue is empty, return 0

	Dequeue();
	// Initialize Dequeue

	~Dequeue();
	// Delete Dequeue
	// If the Dequeue is not empty, delete all remaining nodes and delete Dequeue
};

template <class T>
bool Dequeue<T>::IsEmpty() {
  if(dequeue_size == 0) return true;
	else return false;
}

template <class T>
int Dequeue<T>::GetSize() {
	return dequeue_size;
}

template <class T>
void Dequeue<T>::AddFront(const T _data) {
	Node<T> * new_node = new Node<T>;

	new_node->data = _data;
	new_node->p_before = p_dummy_front;
	new_node->p_next = p_dummy_front->p_next;
	p_dummy_front->p_next->p_before = new_node;
	p_dummy_front->p_next = new_node;

	dequeue_size++;
}

template <class T>
void Dequeue<T>::AddRear(const T _data) {
	Node<T> * new_node = new Node<T>;

	new_node->data = _data;
	new_node->p_before = p_dummy_rear->p_before;
	new_node->p_next = p_dummy_rear;
	p_dummy_rear->p_before->p_next = new_node;
	p_dummy_rear->p_before = new_node;

	dequeue_size++;
}

template <class T>
T Dequeue<T>::RemoveFront() {
	Node<T> * p_temp_node;
	T temp_data;

	if (dequeue_size == 0) return 0;

	temp_data = p_dummy_front->p_next->data;
	p_temp_node = p_dummy_front->p_next;
	p_dummy_front->p_next = p_temp_node->p_next;
	p_temp_node->p_next->p_before = p_dummy_front;
	delete p_temp_node;
	dequeue_size--;

	return temp_data;
}

template <class T>
T Dequeue<T>::RemoveRear() {
		Node<T> * p_temp_node;
		T temp_data;

		if (dequeue_size == 0) return 0;

		temp_data = p_dummy_rear->p_before->data;
		p_temp_node = p_dummy_rear->p_before;
		p_dummy_rear->p_before = p_temp_node->p_before;
		p_temp_node->p_before->p_next = p_dummy_rear;
		delete p_temp_node;
		dequeue_size--;

		return temp_data;
}

template <class T>
T Dequeue<T>::PeekFront() {
  if (dequeue_size == 0) return 0;
  else return p_dummy_front->p_next->data;
}

template <class T>
T Dequeue<T>::PeekRear() {
  if (dequeue_size == 0) return 0;
  else return p_dummy_rear->p_before->data;
}

template <class T>
Dequeue<T>::Dequeue() : dequeue_size(0) {
	p_dummy_front = new Node<T>;
	p_dummy_rear = new Node<T>;

	p_dummy_front->p_next = p_dummy_rear;
	p_dummy_rear->p_before = p_dummy_front;
}

template <class T>
Dequeue<T>::~Dequeue() {
  while(!IsEmpty()){
		RemoveFront();
		std::cout<<"해제\n";
	}

	delete p_dummy_front;
	delete p_dummy_rear;
}
