#pragma once

template <typename T>
struct Node {
  T data;
  Node * p_left;
  Node * p_right;
};

template <class T>
class BinaryTree {
private:
  

public:
  Node<T> * MakeNode();
  // 이진트리 노드를 생성하고, 그 주소값을 반환한다.
  // Creates a binary tree node and returns its address value.

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
};

template <class T>
Node<T> * BinaryTree<T>::MakeNode(){

}

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
