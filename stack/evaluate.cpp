#include <iostream>
#include <string>
#include "evaluate.h"
#include "priority.h"
#include "stack"

using namespace std;

char* removeSpace(char* s) { //�޳�s[]�еİ׿ո�
	char* p = s, * q = s;
	while (true) {
		while (isspace(*q)) q++;
		if ('\0' == *q) { *p = '\0'; return s; }
		*p++ = *q++;
	}
}

__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //�׳����㣨�����棩

double calcu(char op, double b) { //ִ��һԪ����
	  switch (op) {
      case '!': return (double)facI((int)b); //�׳�
      default: exit(-1);
	}
}

double calcu(double a, char op, double b) { //ִ�ж�Ԫ����
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': if (0 == b) exit(-1); return a / b; //�и�����Ϊ����ܲ���ȫ
	case '^': return pow(a, b);
	default: exit(-1);
	}
}

void readNumber(char*& p, Stack<double>& stk) { //����ʼ��p���Ӵ�����Ϊ��ֵ�������������ջ
	stk.push((double)(*p - '0')); //��ǰ��λ��Ӧ����ֵ��ջ
	while (isdigit(*(++p))) //ֻҪ�������н��ڵ����֣�����λ���������������
		stk.push(stk.pop() * 10 + (*p - '0')); //����ԭ��������׷������λ������ֵ������ջ
	if ('.' != *p) return; //�˺��С���㣬����ζ�ŵ�ǰ�������������
	float fraction = 1; //������ζ�Ż���С������
	while (isdigit(*(++p))) //��λ����
		stk.push(stk.pop() + (*p - '0') * (fraction /= 10)); //С������
}

double evaluate(char* S) {
	Stack<double> opnd;//������ջ
	Stack<char> optr;//�����ջ
	optr.push('\0');//β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
	while (!optr.empty()) {//ֱ�������ջ��ֹͣ
		if (isdigit(*S))//����ǰ�ַ�Ϊ������
			readNumber(S, opnd);//���루����Ϊ��λ�ģ�������
		else
			switch (orderBetween(optr.top(), *S)) {
			case '<'://ջ����������ȼ�����
				optr.push(*S); S++; break;//�����Ƴ٣���ǰ�������ջ
			case '='://���ȼ����
				optr.pop(); S++; break;//�����Ų�������һ���ַ�
			case '>': {//ջ�����ȼ����ߣ�ʵʩ��Ӧ�ļ��㣬�����ջ
				char op = optr.pop();
				if ('!' == op)opnd.push(calcu(op, opnd.pop()));//һԪ�����
				else {
					double pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();//��Ԫ�����
					opnd.push(calcu(pOpnd1, op, pOpnd2));//ʵʩ���㣬�����ջ

				}
				break;
			}
			default: exit(-1); //���﷨���󣬲�������ֱ���˳�

			}
		
	}
	return opnd.pop();//�������������ļ�����
}


int main(int argc, char* argv[]) { //���ʽ��ֵ����ڣ�
	system("cls");
	char* rpn = (char*)malloc(sizeof(char) * 10000);
	cin.getline(rpn, 10000);
	//removeSpace(rpn);//
	double value = evaluate(removeSpace(rpn));
	printf("Value\t= %f = %d\n\n", value, (int)round(value)); //������ʽ��ֵ
	free(rpn);   rpn = NULL;
	
	return 0;
}