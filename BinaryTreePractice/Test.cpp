#include <iostream>
#include "BinaryTree.h"

int main(void){
  BinaryTree<int> * a = new BinaryTree<int>;
  BinaryTree<int> b(12);

  std::cout << a->GetData() << std::endl;
  std::cout << b.GetData() << std::endl;

  a->MakeLeftSubTree(1234);
  b.MakeLeftSubTree();

  std::cout << a->GetLeftSubTree() << std::endl;
  std::cout << b.GetLeftSubTree() << std::endl;

  a->MakeLeftSubTree(4567);
  b.MakeLeftSubTree(6666);

  std::cout << a->GetLeftSubTree() << std::endl;
  std::cout << b.GetLeftSubTree() << std::endl;

  delete a;

  return 0;
}
