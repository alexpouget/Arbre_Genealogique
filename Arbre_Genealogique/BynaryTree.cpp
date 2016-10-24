#include "BynaryTree.h"
#include "Member.h"
#include <iostream>

template<typename T>
BynaryTree<T>::BynaryTree()
{
}

template<typename T>
BynaryTree<T>::BynaryTree(Node<T> *node)
{
	racine = node;
	hauteur = 1;
}

template<typename T>
BynaryTree<T>::~BynaryTree()
{
}
template<typename T>
void BynaryTree<T>::addFather(Node<T>* node, T  &fatherValue)
{
	if (node->getFather() && node->getMother() == nullptr) {
		hauteur++;
	}
	node->setFather(new Node<T>(fatherValue));
}
template<typename T>
void BynaryTree<T>::addMother(Node<T>* node, T &motherValue)
{
	if (node->getFather() && node->getMother() == nullptr) {
		hauteur++;
	}
	node->setMother(new Node<T>(motherValue));
	
}

template<typename T>
void BynaryTree<T>::addSon(BynaryTree<T>* fatherValue, BynaryTree<T>* motherValue, T &sonValue)
{
	racine = new Node<T>(sonValue);
	hauteur = fatherValue->getSize() >= motherValue->getSize()?(fatherValue->getSize() +1):(motherValue->getSize()+1);
	racine->setFather(fatherValue->getRacine());
	racine->setMother(motherValue->getRacine());
}

template<typename T>
Node<T>* BynaryTree<T>::getRacine()
{
	return racine;
}

template<typename T>
Node<T>* BynaryTree<T>::getFather(Node<T>* node)
{
	return node->getFather();
}

template<typename T>
Node<T>* BynaryTree<T>::getMother(Node<T>* node)
{
	return node->getMother();
	
}

template<typename T>
bool BynaryTree<T>::isLeaf(Node<T>* node)
{
	if (nullptr == node->getFather() && nullptr == node->getMother()) {
		return true;
	}
	return false;
}

template<typename T>
int BynaryTree<T>::getSize()
{
	hauteur = evalSize(racine);
	return hauteur;
}

template<typename T>
void BynaryTree<T>::listPersonne(std::string color, Node<T>* node)
{
	if (node == nullptr) {
		node = getRacine();
	}
	if (node->getContent().getEyesColor().compare(color)==0) {
		std::cout << node->getContent().getFirstName() << std::endl;
	}
	if (node->getFather() != nullptr) {
		listPersonne(color, node->getFather());
	}
	if (node->getMother() != nullptr) {
		listPersonne(color, node->getMother());
	}
	
}

template<typename T>
void BynaryTree<T>::getdescendance(Node<T>* node, Node<T>* search)
{
	if (search == nullptr) {
		search = getRacine();
	}
	if (search == node) {
		std::cout << node->getContent().getFirstName() << std::endl;
		return;
	}
	if(search->getFather()==node){
		std::cout << node->getContent().getFirstName() << std::endl;
		getdescendance(search,getRacine());
		return;
	}
	if (search->getMother() == node) {
		std::cout << node->getContent().getFirstName() << std::endl;
		getdescendance(search, getRacine());
		return;
	}
	if (search->getFather() != nullptr) {
		getdescendance(node, search->getFather());
	}
	if (search->getMother() != nullptr) {
		getdescendance(node, search->getMother());
	}
}

template<typename T>
void BynaryTree<T>::getdescendanceByColor(std::string type, Node<T>* node, Node<T>* search)
{
	if (search == nullptr) {
		search = getRacine();
	}
	if (search == node) {
		if (node->getContent().getEyesColor().compare(type)==0) {
			std::cout << node->getContent().getFirstName() << std::endl;
		}
		return;
	}
	if (search->getFather() == node) {
		if (node->getContent().getEyesColor().compare(type) == 0) {
			std::cout << node->getContent().getFirstName() << std::endl;
		}
		getdescendance(search, getRacine());
		return;
	}
	if (search->getMother() == node) {
		if (node->getContent().getEyesColor().compare(type) == 0) {
			std::cout << node->getContent().getFirstName() << std::endl;
		}
		getdescendance(search, getRacine());
		return;
	}
	if (search->getFather() != nullptr) {
		getdescendance(node, search->getFather());
	}
	if (search->getMother() != nullptr) {
		getdescendance(node, search->getMother());
	}
}


template<typename T>
void BynaryTree<T>::parcours(std::string type, Node<T>* node)
{
	if (node == nullptr) {
		node = getRacine();
	}
	
	if (type.compare("PRE")==0) {
		std::cout << "PRE type" << std::endl;
		std::cout << node->getContent().getFirstName() << std::endl;
		if (node->getFather() != nullptr) {
			parcours(type, node->getFather());
		}
		if (node->getMother() != nullptr) {
			parcours(type, node->getMother());
		}	
	}
	else if (type.compare("IN")==0) {
		std::cout << "IN type" << std::endl;
		if (node->getFather() != nullptr) {
			parcours(type, node->getFather());
		}
		std::cout << node->getContent().getFirstName() << std::endl;
		if (node->getMother() != nullptr) {
			parcours(type, node->getMother());
		}
	}else {
		std::cout << "POST type" << std::endl;
		if (node->getFather() != nullptr) {
			parcours(type, node->getFather());
		}
		if (node->getMother() != nullptr) {
			parcours(type, node->getMother());
		}
		std::cout << node->getContent().getFirstName() << std::endl;
	}
	
}

template<typename T>
int BynaryTree<T>::evalSize(Node<T>* node)
{
	if (node == nullptr) {
		return 0;
	}
	if (node->getMother()==nullptr && node->getFather()==nullptr) {
		return 1;
	}
	if (evalSize(node->getFather()) < evalSize(node->getMother())) {
		return 1 + evalSize(node->getMother());
	}
	return 1 + evalSize(node->getFather());
}

template<typename T>
int BynaryTree<T>::getAverageAge()
{
	return getAllAge(getRacine())/nbNode(getRacine());
}

template<typename T>
int BynaryTree<T>::nbNode(Node<T>* node)
{
	if (node == nullptr) {
		return 0;
	}
	return 1 + nbNode(node->getFather()) + nbNode(node->getMother());
}

template<typename T>
int BynaryTree<T>::getAllAge(Node<T>* node)
{
	if (node == nullptr) {
		return 0;
	}
	return node->getContent().getAge() + getAllAge(node->getFather()) + getAllAge(node->getMother());
}



template class BynaryTree<Member>;