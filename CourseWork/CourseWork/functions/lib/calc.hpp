#pragma once
#include <iostream>
#include <string>
#include <math.h>

#include "stack.hpp"

bool checkCountBracket(const std::string& str);

bool checkMatchingBracket(const std::string& str);

bool checkEmptyBracket(const std::string& str);

void checkExpression(const std::string& str);

void remDupSpaces(std::string& str);

Stack parse(std::string& str);

bool isDigit(const std::string& str);

bool isFunc(const std::string& str);

bool isOperator(const std::string& str);

void checkTokens(const Stack& tokens);

size_t getPrioritet(const std::string& str);

Stack convertToPostfix(Stack& tokens);

void convertConst(std::string& str);

std::string convertFunc(std::string& str);

double calculate(const Stack& postfix);