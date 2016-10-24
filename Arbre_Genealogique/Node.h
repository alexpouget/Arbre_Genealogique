#pragma once

template <typename T>
class Node
{
public:
	Node();
	Node(T&);
	~Node();

	void setFather(Node*);
	void setMother(Node*);
	Node* getFather();
	Node* getMother();
	T getContent();

private:
	T content;
	Node* father;
	Node* mother;
};
