#include "Node.h"

Node::Node() {
	letter_ = -1;
	prev_ = 0;//online judge��֧��c++11����������nullptr����
	next_ = 0;
}

Node::Node(char letter) {
	letter_ = letter;
	prev_ = 0;
	next_ = 0;
}

Node::~Node() {

}