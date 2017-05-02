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

  BinaryTree(T _data);
  // 루트 노드를 생성하고, 지정된 값을 대입한다.
  // Creates a root node, and set input value

//  Node<T> * MakeNode();

  T GetData(Node<T> * _p_node);
  // 노드에 저장된 데이터를 반환한다.
  // Return stored data in the node.

  void SetData(Node<T> * _p_tree, T _data);
  // 노드에 데이터를 저장한다. _data로 전달된 값을 저장한다.
  // Stores the data passed to _data in the node.

  Node<T> * GetLeftSubTree(Node<T> * _p_node);
  // 왼쪽 서브 트리의 주소 값을 반환한다.
  // Returns the address of the left subtree.

  Node<T> * GetRightSubTree(Node<T> * _p_node);
  // 오른쪽 서브 트리의 주소 값을 반환한다.
  // Returns the address of the right subtree.

  void MakeLeftSubTree(Node<T> * _p_main, Node<T> * _p_sub);
  // 왼쪽 서브 트리를 연결한다.
  // Connect the left sub tree

  void MakeRightSubTree(Node<T> * _p_main, Node<T> * _p_sub);
  // 오른쪽 서브 트리를 연결한다.
  // Connect the right sub tree

  void PostorderTraverse();
  // 메모리 누수를 방지하기 위해, 후위 순회를 통해 노드를 삭제한다
  // To prevent memory leak, Use postorder traverse to remove

private:

};

template <class T>
BinaryTree<T>::BinaryTree(){
  current_node = new Node<T>;


}

template <class T>
BinaryTree<T>::BinaryTree(T _value){
  BinaryTree();
  current_node->SetData(_value);
}

/*
template <class T>
Node<T> * BinaryTree<T>::MakeNode(){

}
*/

template <class T>
T BinaryTree<T>::GetData(Node<T> * _p_node){

}

template <class T>
void BinaryTree<T>::SetData(Node<T> * _p_tree, T _data){

}

template <class T>
Node<T> * BinaryTree<T>::GetLeftSubTree(Node<T> * _p_node){

}

template <class T>
Node<T> * BinaryTree<T>::GetRightSubTree(Node<T> * _p_node){

}

template <class T>
void BinaryTree<T>::MakeLeftSubTree(Node<T> * _p_main, Node<T> * _p_sub){

}

template <class T>
void BinaryTree<T>::MakeRightSubTree(Node<T> * _p_main, Node<T> * _p_sub){

}

template <class T>
void BinaryTree<T>::PostorderTraverse(){

  PostorderTraverse();
}
