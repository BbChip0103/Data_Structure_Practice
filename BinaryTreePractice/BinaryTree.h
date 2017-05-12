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
  void SetLeft(Node<T> * const _data);
  Node * GetRight();
  void SetRight(Node<T> * const _data);
};

template <class T>
Node<T>::Node(){
  this->p_left = NULL;
  this->p_right = NULL;
}

template <class T>
Node<T>::Node(T _data){
  Node();
  this->data = _data;
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
void Node<T>::SetLeft(Node<T> * const _p_left){
  this->p_left = _p_left;
}

template <class T>
Node<T> * Node<T>::GetRight(){
  return this->p_right;
}

template <class T>
void Node<T>::SetRight(Node<T> * const _p_right){
  this->p_right = _p_right;
}

template <class T>
class BinaryTree {
private:
  Node<T> * root_node;
  Node<T> * current_node;

public:
  BinaryTree();
  // 루트 노드를 생성한다.
  // Creates a root node

  BinaryTree(const T _data);
  // 루트 노드를 생성하고, 입력된 값을 대입한다.
  // Creates a root node, and set input value

  ~BinaryTree();
  // 남은 노드를 다 지우고 객체를 삭제한다.
  // Remove remained node, And remove object

  T GetData();
  // 노드에 저장된 데이터를 반환한다.
  // Return stored data in the node.

  void SetData(const T _data);
  // 노드에 데이터를 저장한다. _data로 전달된 값을 저장한다.
  // Stores the data passed to _data in the node.

  T GetLeftSubTree();
  // 왼쪽 서브 트리의 값을 반환한다.
  // Returns the value of the left subtree.

  void MakeLeftSubTree();
  // 왼쪽 서브 트리를 연결한다.
  // Connect the left sub tree

  void MakeLeftSubTree(const T _data);
  // 왼쪽 서브 트리를 연결하고 값을 대입한다.
  // Connect the left sub tree, And insert value

  T GetRightSubTree();
  // 오른쪽 서브 트리의 값을 반환한다.
  // Returns the value of the right subtree.

  void MakeRightSubTree();
  // 오른쪽 서브 트리를 연결한다.
  // Connect the right sub tree

  void MakeRightSubTree(const T _data);
  // 오른쪽 서브 트리를 연결하고 값을 대입한다.
  // Connect the right sub tree, And insert value

  void Remove();

  void Remove(Node<T> * const _p_node);

  void PostorderTraverse();
  // 메모리 누수를 방지하기 위해, 후위 순회를 통해 노드를 삭제한다
  // To prevent memory leak, Use postorder traverse to remove

  void PostorderTraverse(Node<T> * const _p_node);
  // 메모리 누수를 방지하기 위해, 후위 순회를 통해 노드를 삭제한다
  // To prevent memory leak, Use postorder traverse to remove

private:

};

template <class T>
BinaryTree<T>::BinaryTree(){
  current_node = new Node<T>;
  root_node = current_node;
}

template <class T>
BinaryTree<T>::BinaryTree(const T _data){
  BinaryTree();
  SetData(_data);
}

template <class T>
BinaryTree<T>::~BinaryTree(){
  if(root_node != NULL){
    Remove(root_node);
  }
}

template <class T>
T BinaryTree<T>::GetData(){
  if(current_node == NULL){
    // error
    return 0;
  } else {
    return current_node->GetData();
  }
}

template <class T>
void BinaryTree<T>::SetData(const T _data){
  if(current_node == NULL){
    // error
  } else {
    current_node->SetData(_data);
  }
}

template <class T>
void BinaryTree<T>::MakeLeftSubTree(){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return;
  }else if(current_node->GetLeft() == NULL){
    p_temp = new Node<T>;
    current_node->SetLeft(p_temp);
  }
  else{
    Remove(current_node->GetLeft());

    p_temp = new Node<T>;
    current_node->SetLeft(p_temp);
  }
}

template <class T>
void BinaryTree<T>::MakeLeftSubTree(const T _data){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return;
  }else if(current_node->GetLeft() == NULL){
    p_temp = new Node<T>;
    current_node->SetLeft(p_temp);
  }
  else{
    Remove(current_node->GetLeft());

    p_temp = new Node<T>;
    current_node->SetLeft(p_temp);
  }

  p_temp->SetData(_data);
}

template <class T>
T BinaryTree<T>::GetLeftSubTree(){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return 0;
  } else {
    p_temp = current_node->GetLeft();
  }

  if(p_temp == NULL){
    // error
    return 0;
  } else {
    return p_temp->GetData();
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
    current_node->SetLeft(p_temp);
  }
  else{
    Remove(current_node->GetRight());

    p_temp = new Node<T>;
    current_node->SetRight(p_temp);
  }
}

template <class T>
void BinaryTree<T>::MakeRightSubTree(const T _data){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return;
  } else {
    p_temp = current_node->GetRight();
  }

  if(p_temp == NULL){
    p_temp = new Node<T>;
    current_node->SetLeft(p_temp);
  }
  else{
    Remove(current_node->GetRight());

    p_temp = new Node<T>;
    current_node->SetRight(p_temp);
  }

    p_temp->SetData(_data);
}

template <class T>
T BinaryTree<T>::GetRightSubTree(){
  Node<T> * p_temp;

  if(current_node == NULL){
    // error
    return 0;
  } else {
    p_temp = current_node->GetRight();
  }

  if(p_temp == NULL){
    // error
    return 0;
  } else {
    return p_temp->GetData();
  }
}

template <class T>
void BinaryTree<T>::Remove(){
  Remove(current_node);
}

template <class T>
void BinaryTree<T>::Remove(Node<T> * const _p_node){
  Node<T> * const traverse_node = _p_node;

  if(traverse_node == NULL){
    return;
  }

  Remove(traverse_node->GetLeft());
  Remove(traverse_node->GetRight());

  delete traverse_node;
}

template <class T>
void BinaryTree<T>::PostorderTraverse(){
  PostorderTraverse(current_node);
}

template <class T>
void BinaryTree<T>::PostorderTraverse(Node<T> * const _p_node){
  Node<T> * const traverse_node = _p_node;

  if(traverse_node == NULL){
    return;
  }

  std::cout << traverse_node << std::endl;

  PostorderTraverse(traverse_node->GetLeft());
  PostorderTraverse(traverse_node->GetRight());
}
