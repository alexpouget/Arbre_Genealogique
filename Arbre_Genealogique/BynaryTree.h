#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class BynaryTree
{
public:
	BynaryTree();
	BynaryTree(Node<T>*);
	~BynaryTree();

	//ajout
	void addFather(Node<T>*, T&);
	void addMother(Node<T>*, T&);
	void addSon(BynaryTree<T>*, BynaryTree<T>*, T&);
	
	Node<T>* getRacine();
	Node<T>* getFather(Node<T>*);
	Node<T>* getMother(Node<T>*);
	bool isLeaf(Node<T>*);
	int getSize();
	void listPersonne(std::string, Node<T>* node = nullptr);
	void getdescendance(Node<T>* node, Node<T>* search = nullptr);
	void getdescendanceByColor(std::string, Node<T>* node, Node<T>* search = nullptr);
	void parcours(std::string, Node<T>* node = nullptr);
	int evalSize(Node<T>* node = nullptr);
	int getAverageAge();
	int BynaryTree<T>::nbNode(Node<T>* node);
	int BynaryTree<T>::getAllAge(Node<T>* node);

	
private :
	Node<T>* racine;
	int hauteur;

};

