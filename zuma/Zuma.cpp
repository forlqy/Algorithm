#include "Zuma.h"
//public:
Zuma::Zuma() {
	header_.setPrev(0);//×îºÃÎªnullptr
	header_.setNext(&trailer_);
	trailer_.setNext(0);
	trailer_.setPrev(&header_);
	size_ = 0;
}

Zuma::~Zuma() {
	if (size_ == 0) {
		return;
	}
	cursorTo(0);
	while (cursor_ != &trailer_) {
		cursor_ = cursor_->getNext();
		delete cursor_->getPrev();
	}
}

void Zuma::insert(Node* t, int pos) {
	cursorTo(pos);
	t->setPrev(cursor_->getPrev());
	t->setNext(cursor_);
	cursor_->getPrev()->setNext(t);
	cursor_->setPrev(t);
	size_++;
}

void Zuma::push(Node* newNode) {
	insert(newNode, size_);
}

void Zuma::erase(int aheadNum, Node* curr) {
	Node* begin = curr->getPrev();
	for (int i = aheadNum; i > 0; i--) {
		begin = begin->getPrev();
		delete begin->getNext();
	}
	cursor_ = curr;

	begin->setNext(cursor_);
	cursor_->setPrev(begin);
	size_ = size_ - aheadNum;
}

void Zuma::elimTriElem() {
	bool updated = true;
	while (updated) {
		updated = false;
		cursorTo(0);
		int count = 1;
		while (cursor_ != &trailer_) {
			cursor_ = cursor_->getNext();
			if (cursor_->getLetter() == cursor_->getPrev()->getLetter()) {
				count++;
			}
			else if (count > 2) {
				erase(count, cursor_);
				updated = true;
				count = 1;
			}
			else {
				count = 1;
			}
		}
	}
}


std::ostream& operator<<(std::ostream& os, Zuma& ll)
{
	if (ll.size_ == 0)
	{
		return os << '-';
	}
	ll.cursorTo(0);
	while (ll.cursor_ != &ll.trailer_)
	{
		os << ll.cursor_->getLetter();
		ll.cursor_ = ll.cursor_->getNext();
	}
	return os;
}

//private:
void Zuma::cursorTo(int pos) {
	cursor_ = header_.getNext();
	for (int i = 0; i < pos; i++) {
		cursor_ = cursor_->getNext();
	}
}


