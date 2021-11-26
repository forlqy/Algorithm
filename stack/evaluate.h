#pragma once


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "Stack.h" //สนำรีป
#include "priority.h"

__int64 facI(int n);
double calcu(double a, char op, double b);
double calcu(char op, double b);
void readNumber(char*&, Stack<double>&);
Operator optr2rank(char);
char orderBetween(char, char);
double evaluate(char* expr, char*& rpn);