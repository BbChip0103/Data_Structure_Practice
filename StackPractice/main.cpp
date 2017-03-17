#include <iostream>
#include "stack.h"

int main(void){
  int temp;

  Stack<char> a;

  a.Push('a');
	std::cout << a.Peek() << "\n";
	std::cout << a.GetSize() << "\n\n";

	a.Push('b');
  std::cout << a.Peek() << "\n";
	std::cout << a.GetSize() << "\n\n";

	if ((a.IsEmpty())) {
		std::cout << a.Pop() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	if ((a.IsEmpty())) {
		std::cout << a.Pop() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

		std::cout << a.Pop() << "\n";
		std::cout << a.GetSize() << "\n\n";

  return 0;
}
