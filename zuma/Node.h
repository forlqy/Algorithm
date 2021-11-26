#pragma once
class Node {
public:
	Node();
	Node(char leetter);
	~Node();
	void setPrev(Node* prev) { prev_ = prev; }
	void setNext(Node* next) { next_ = next; }
	void setLetter(char letter) { letter_ = letter; }
	Node* getPrev() { return prev_; }
	Node* getNext() { return next_; }
	char getLetter() { return letter_; }
private:
	Node* prev_;
	Node* next_;
	char letter_;
};