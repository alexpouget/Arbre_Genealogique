#include "Node.h"
#include "Member.h"


template<typename T>
Node<T>::Node()
{
	father = nullptr;
	mother = nullptr;
}

template<typename T>
Node<T>::Node(T& t)
{
	content = t;
	father = nullptr;
	mother = nullptr;
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
void Node<T>::setFather(Node *node)
{
	father = node;
}

template<typename T>
void Node<T>::setMother(Node *node)
{
	mother = node;
}


template<typename T>
Node<T> * Node<T>::getFather()
{
	return father;
}

template<typename T>
Node<T> * Node<T>::getMother()
{
	return mother;
}

template<typename T>
T Node<T>::getContent()
{
	return content;
}

template class Node<Member>;
