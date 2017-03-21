#include <iostream>
#include "Dequeue.h"

int main(void){
	Dequeue<char> a;

	a.AddFront('a');
	std::cout << "앞에다 푸쉬" << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.AddFront('b');
	std::cout << "앞에다 푸쉬" << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.AddRear('c');
	std::cout << "뒤에다 푸쉬" << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.AddRear('d');
	std::cout << "뒤에다 푸쉬" << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.AddFront('e');
	std::cout << "앞에다 푸쉬" << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	if (!(a.IsEmpty())) {
		std::cout << "앞에서 팝" << "\n";
		std::cout << a.RemoveFront() << "\n";
		std::cout << a.PeekFront() << "\n";
		std::cout << a.PeekRear() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	if (!(a.IsEmpty())) {
		std::cout << "뒤에서 팝" << "\n";
		std::cout << a.RemoveRear() << "\n";
		std::cout << a.PeekFront() << "\n";
		std::cout << a.PeekRear() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	std::cout << "앞에서 팝" << "\n";
	std::cout << a.RemoveFront() << "\n";
	std::cout << a.PeekFront() << "\n";
	std::cout << a.PeekRear() << "\n";
	std::cout << a.GetSize() << "\n\n";

	return 0;
}
