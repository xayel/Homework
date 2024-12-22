#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <iostream>

class ExpressionEvaluator {
public:
    double evaluate(const std::string& expression);
    bool isValid(const std::string& expression);

private:
    int precedence(char op);
    double applyOperation(double a, double b, char op);
    bool isOperator(char c);
};

bool ExpressionEvaluator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int ExpressionEvaluator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double ExpressionEvaluator::applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::invalid_argument("Division by zero");
            return a / b;
    }
    return 0;
}

bool ExpressionEvaluator::isValid(const std::string& expression) {
    int balance = 0;
    bool lastWasOperator = true;
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (isspace(c)) continue;
        if (c == '(') {
            balance++;
            lastWasOperator = true;
        } else if (c == ')') {
            if (balance == 0 || lastWasOperator) return false;
            balance--;
            lastWasOperator = false;
        } else if (isOperator(c)) {
            if (lastWasOperator) return false;
            lastWasOperator = true;
        } else if (isdigit(c) || (c == '.' && isdigit(expression[i - 1]))) {
            lastWasOperator = false;
        } else {
            return false;
        }
    }
    return balance == 0 && !lastWasOperator;
}

double ExpressionEvaluator::evaluate(const std::string& expression) {
    if (!isValid(expression)) throw std::invalid_argument("ILLEGAL");

    std::stack<double> values;
    std::stack<char> ops;
    size_t i = 0;

    while (i < expression.length()) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i]) || expression[i] == '.') {
            std::string value;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                value += expression[i++];
            }
            values.push(std::stod(value));
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
            i++;
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.pop();
            i++;
        } else if (isOperator(expression[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(expression[i]);
            i++;
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

#endif