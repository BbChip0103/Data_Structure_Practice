#include <iostream>
#include "Queue.h"

int main(void){
	Queue<char> a;

	a.Enqueue('a');
	std::cout << a.Peek() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.Enqueue('b');
	std::cout << a.Peek() << "\n";
	std::cout << a.GetSize() << "\n\n";

	if (!(a.IsEmpty())) {
		std::cout << a.Dequeue() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	if (!(a.IsEmpty())) {
		std::cout << a.Dequeue() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	std::cout << a.Dequeue() << "\n";
	std::cout << a.GetSize() << "\n\n";

	return 0;
}
