#pragma once

#ifndef NULL
#define NULL 0
#endif

template <class T>
class Node {
private:
  T data;
  Node * p_left;
  Node * p_right;

public:
  Node();
  Node(T _data);
  T GetData();
  void SetData(const T _data);
  Node * GetLeft();
  void SetLeft(const Node<T> * _data);
  Node * GetRight();
  void SetRight(const Node<T> * _data);
};

template <class T>
Node<T>::Node(){
  this->p_left = NULL;
  this->p_right = NULL;
}

template <class T>
Node<T>::Node(T _data){
  this->data = _data;
  this->p_left = NULL;
  this->p_right = NULL;
}

template <class T>
T Node<T>::GetData(){
  return this->data;
}

template <class T>
void Node<T>::SetData(const T _data){
  this->data = _data;
}

template <class T>
Node<T> * Node<T>::GetLeft(){
  return this->p_left;
}

template <class T>
void Node<T>::SetLeft(const Node<T> * _p_left){
  this->p_left = _p_left;
}

template <class T>
Node<T> * Node<T>::GetRight(){
  return this->p_right;
}

template <class T>
void Node<T>::SetRight(const Node<T> * _p_right){
  this->p_right = _p_right;
}

template <class T>
class BinaryTree {
private:
  Node<T> * current_node;

public:
  BinaryTree();
  // 루트 노드를 생성한다.
  // Creates a root node

  BinaryTree(const T _data);
  // 루트 노드를 생성하고, 입력된 값을 대입한다.
  // Creates a root node, and set input value

  T GetData();
  // 노드에 저장된 데이터를 반환한다.
  // Return stored data in the node.

  void SetData(T _data);
  // 노드에 데이터를 저장한다. _data로 전달된 값을 저장한다.
  // Stores the data passed to _data in the node.

  Node<T> * GetLeftSubTree();
  // 왼쪽 서브 트리의 주소 값을 반환한다.
  // Returns the address of the left subtree.

  void MakeLeftSubTree();
  // 왼쪽 서브 트리를 연결한다.
  // Connect the left sub tree

  Node<T> * GetRightSubTree();
  // 오른쪽 서브 트리의 주소 값을 반환한다.
  // Returns the address of the right subtree.

  void MakeRightSubTree();
  // 오른쪽 서브 트리를 연결한다.
  // Connect the right sub tree

  void PostorderTraverse();
  // 메모리 누수를 방지하기 위해, 후위 순회를 통해 노드를 삭제한다
  // To prevent memory leak, Use postorder traverse to remove

  void PostorderTraverse(const Node<T> * _p_node);
  // 메모리 누수를 방지하기 위해, 후위 순회를 통해 노드를 삭제한다
  // To prevent memory leak, Use postorder traverse to remove

private:

};

template <class T>
BinaryTree<T>::BinaryTree(){
  current_node = new Node<T>;
}

template <class T>
BinaryTree<T>::BinaryTree(const T _value){
  BinaryTree();
  current_node->SetData(_value);
}

template <class T>
T BinaryTree<T>::GetData(){
  if(current_node == NULL){
    // error
  } else {
    return current_node->GetData();
  }

}

template <class T>
void BinaryTree<T>::SetData(T _data){
  if(current_node == NULL){
    // error
  } else {
    current_node->SetData(_data);
  }
}

template <class T>
Node<T> * BinaryTree<T>::GetLeftSubTree(){
  if(current_node == NULL){
    // error
  } else {
    return current_node->GetLeft();
  }
}

template <class T>
void BinaryTree<T>::MakeLeftSubTree(){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return;
  } else {
    p_temp = current_node->GetLeft();
  }

  if(p_temp == NULL){
    p_temp = new Node<T>;
  }
  else{
    //remove first, making node is second
  }
}

template <class T>
Node<T> * BinaryTree<T>::GetRightSubTree(){
  if(current_node == NULL){
    // error
  } else {
    return current_node->GetRight();
  }
}

template <class T>
void BinaryTree<T>::MakeRightSubTree(){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return;
  } else {
    p_temp = current_node->GetRight();
  }

  if(p_temp == NULL){
    p_temp = new Node<T>;
  }
  else{
    //remove first, making node is second
  }
}

template <class T>
void BinaryTree<T>::PostorderTraverse(){
  PostorderTraverse(current_node);
}

template <class T>
void BinaryTree<T>::PostorderTraverse(const Node<T> * _p_node){
  const Node<T> * traverse_node = _p_node;

  if(traverse_node == NULL){
    return;
  }

  //std::cout << GetData() << std::endl;

  PostorderTraverse(traverse_node->GetLeft());
  PostorderTraverse(traverse_node->GetRight());
}
