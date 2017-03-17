#pragma once

template <typename type>
struct Node {
	type data;
	Node * p_next = NULL;	//nullptr is not supported in g++
	Node * p_before = NULL;
};

template <class type>
class List {
private:
	Node<type> head;
	Node<type> tail;
	Node<type> * p_now;
	int length;

public:
	int First() {
		if (length == 0) return 0;

		p_now = head.p_next;
		return 1;
	}

	int Next() {
		if (p_now->p_next == &tail || p_now == &head)
			return 0;

		p_now = p_now->p_next;
		return 1;
	}

	void Add(type _data) {
		Node<type> * p_temp = new Node<type>;

		p_temp->data = _data;
		p_temp->p_next = p_now->p_next;
		p_temp->p_next->p_before = p_temp;
		p_temp->p_before = p_now;
		p_now->p_next = p_temp;
		p_now = p_temp;

		length++;
	}

		void Remove() {
			Node<type> * p_temp;

			if(GetLength() == 0) return;

			p_temp = p_now;
			p_now->p_before->p_next = p_now->p_next;
			p_now->p_next->p_before = p_now->p_before;

			if(p_now->p_next == &tail) p_now = p_now->p_before;
			else p_now = p_now->p_next;

			delete p_temp;
			length--;
		}

		void PutData(type _data) {
			p_now->data = _data;
		}

		type GetData() {
			return p_now->data;
		}

		int GetLength() {
			return length;
		}

		int IsEmpty() {
			if (length == 0) return 0;
			else return 1;
		}

		List() {
			Initialize();
		}

		~List() {
			First();
			while (IsEmpty())
				Remove();
		}

	private:
		void Initialize() {
			head.p_next = &tail;
			p_now = &head;
			length = 0;
		}

};
