#include <iostream>
#include "Zuma.h"
#include "Node.h"
#include <string>
using namespace std;
int main()
{
	Zuma zuma;

	// read in the character sequence
	std::string initSeq;
	getline(cin, initSeq);
	for (int i = 0; i < initSeq.length(); i++)
	{
		zuma.push(new Node(initSeq[i]));
	}


	// read in the number of commands
	int commandNum;
	cin >> commandNum;

	for (int i = 0; i < commandNum; i++) {
		int pos;
		cin >> pos;
		char chara;
		cin >> chara;
		zuma.insert(new Node(chara), pos);

		zuma.elimTriElem();
		cout << zuma << endl;
	}
	return 0;
}
