#include <iostream>
#include <string>
#include "evaluate.h"
#include "priority.h"
#include "stack"

using namespace std;

char* removeSpace(char* s) { //剔除s[]中的白空格
	char* p = s, * q = s;
	while (true) {
		while (isspace(*q)) q++;
		if ('\0' == *q) { *p = '\0'; return s; }
		*p++ = *q++;
	}
}

__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //阶乘运算（迭代版）

double calcu(char op, double b) { //执行一元运算
	  switch (op) {
      case '!': return (double)facI((int)b); //阶乘
      default: exit(-1);
	}
}

double calcu(double a, char op, double b) { //执行二元运算
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': if (0 == b) exit(-1); return a / b; //判浮点数为零可能不安全
	case '^': return pow(a, b);
	default: exit(-1);
	}
}

void readNumber(char*& p, Stack<double>& stk) { //将起始于p的子串解析为数值，并存入操作数栈
	stk.push((double)(*p - '0')); //当前数位对应的数值进栈
	while (isdigit(*(++p))) //只要后续还有紧邻的数字（即多位整数的情况），则
		stk.push(stk.pop() * 10 + (*p - '0')); //弹出原操作数并追加新数位后，新数值重新入栈
	if ('.' != *p) return; //此后非小数点，则意味着当前操作数解析完成
	float fraction = 1; //否则，意味着还有小数部分
	while (isdigit(*(++p))) //逐位加入
		stk.push(stk.pop() + (*p - '0') * (fraction /= 10)); //小数部分
}

double evaluate(char* S) {
	Stack<double> opnd;//运算数栈
	Stack<char> optr;//运算符栈
	optr.push('\0');//尾哨兵'\0'也作为头哨兵首先入栈
	while (!optr.empty()) {//直到运算符栈空停止
		if (isdigit(*S))//若当前字符为操作数
			readNumber(S, opnd);//读入（可能为多位的）操作数
		else
			switch (orderBetween(optr.top(), *S)) {
			case '<'://栈顶运算符优先级更低
				optr.push(*S); S++; break;//计算推迟，当前运算符进栈
			case '='://优先级相等
				optr.pop(); S++; break;//脱括号并接收下一个字符
			case '>': {//栈顶优先级更高，实施相应的计算，结果入栈
				char op = optr.pop();
				if ('!' == op)opnd.push(calcu(op, opnd.pop()));//一元运算符
				else {
					double pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();//二元运算符
					opnd.push(calcu(pOpnd1, op, pOpnd2));//实施计算，结果入栈

				}
				break;
			}
			default: exit(-1); //逢语法错误，不做处理直接退出

			}
		
	}
	return opnd.pop();//弹出并返回最后的计算结果
}


int main(int argc, char* argv[]) { //表达式求值（入口）
	system("cls");
	char* rpn = (char*)malloc(sizeof(char) * 10000);
	cin.getline(rpn, 10000);
	//removeSpace(rpn);//
	double value = evaluate(removeSpace(rpn));
	printf("Value\t= %f = %d\n\n", value, (int)round(value)); //输出表达式的值
	free(rpn);   rpn = NULL;
	
	return 0;
}