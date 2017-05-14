#include <iostream>
#include "BinaryTree.h"

void re_main(){
  BinaryTree<int> * a = new BinaryTree<int>;
  BinaryTree<int> b(12);

  std::cout << a->GetData() << std::endl;
  std::cout << b.GetData() << std::endl;
/*
  a->MakeLeft(1234);
  b.MakeLeft();

  std::cout << a->GetLeft() << std::endl;
  std::cout << b.GetLeft() << std::endl;

  a->MakeLeft(4567);
  b.MakeLeft(6666);

  std::cout << a->GetLeft() << std::endl;
  std::cout << b.GetLeft() << std::endl;

  a->MakeLeft(4567);
  b.MakeLeft(6666);

  a->MoveLeft();
  b.MoveLeft();

  std::cout << a->GetData() << std::endl;
  std::cout << b.GetData() << std::endl;

  a->MoveRoot();
  b.MoveRoot();

  std::cout << a->GetData() << std::endl;
  std::cout << b.GetData() << std::endl;
*/
  delete a;

}

int main(void){

  re_main();


  return 0;
}
