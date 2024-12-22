#include <iostream>
#include <string>
#include <vector>
#include "expression_evaluator.h"

void test(const std::string& expression) {
    ExpressionEvaluator evaluator;

    if (!evaluator.isValid(expression)) {
        std::cout << "ILLEGAL" << std::endl;
    } else {
        try {
            double result = evaluator.evaluate(expression);
            std::cout << "计算结果: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "ILLEGAL" << std::endl;
        }
    }
}

void runTests() {
    std::vector<std::string> expressions = {
        "1 + 2",
        "(3 * (4 + 5)) / 5",
        "10 / 2 - 3",
        "2.52 + 3.57",
        "1 + 2 * 3",
        "1 + + 2",
        "1 * (2 + 3",
        "+ 1 + 2",
        "10 / 0",
        "3 + 6 -",
        "10 & 2"
    };

    for (const auto& expression : expressions) {
        test(expression);
    }
}

int main() {
    runTests();

    std::string expression;
    std::cout << "请输入一个中缀表达式：";
    std::getline(std::cin, expression);

    test(expression);

    return 0;
}