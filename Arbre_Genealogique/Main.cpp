#include <iostream>
#include "Member.h"
#include "Node.h"
#include "BynaryTree.h"

using namespace std;

int main() {
	Member m("alex", "pouget", 1994, "bleu");
	Member m1("jean", "pouget", 1994, "bleu");
	Member m2("michelle", "pouget", 1994, "bleu");
	Member m3("jean-michel", "pouget", 1994, "bleu");
	Node<Member> *n = new Node<Member>(m);
	n->setFather(new Node<Member>(m1));
	BynaryTree<Member> *b = new BynaryTree<Member>(n);
	b->addMother(n, m2);
	b->addFather(n->getMother(), m3);
	cout << "hello world "<< b->getRacine()->getContent().getFirstName() << endl;
	cout << "hello papa " << b->getFather(n)->getContent().getFirstName() << endl;
	cout << "hello maman " << b->getMother(n)->getContent().getFirstName() << endl;
	cout << "hello grand pere " << b->getMother(n)->getFather()->getContent().getFirstName() << endl;
	cout << "grand pere est une feuille " << b->isLeaf(b->getMother(n)->getFather()) << endl;
	cout << "l'arbre a une taille de : " << b->getSize() << endl;
	b->parcours("PRE");
	cout << "liste descendance : "<< endl;
	b->getdescendance(b->getMother(n)->getFather());
	cout << "Age Moyen : " << b->getAverageAge() << endl;
	
	
	system("PAUSE");
	return 0;
}