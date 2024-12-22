#include <iostream>
#include <string>
#include <vector>
#include "expression_evaluator.h"

void runTests() {
    ExpressionEvaluator evaluator;

    // 测试表达式
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
        if (evaluator.isValid(expression)) {
            try {
                double result = evaluator.evaluate(expression);
                std::cout << " 计算结果: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cout << " ILLEGAL" << std::endl;
            }
        } else {
            std::cout << " ILLEGAL" << std::endl;
        }
    }
}

int main() {
    
	runTests();

    return 0;
}