#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void heapsort(std::vector<T>& vec) {
    std::make_heap(vec.begin(), vec.end());  //创建一个最大堆
    for (size_t i = vec.size() - 1; i > 0; --i) {
        std::pop_heap(vec.begin(), vec.begin() + i + 1);  //调用std::pop_heap将堆顶元素（最大值）与当前堆的最后一个元素交换并重新调整堆
    }
}

//生成随机序列函数
void generateRandom(std::vector<int>& vec, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000); //从1到1000000
    vec.clear();
    vec.reserve(size); // 预分配内存
    for (int i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
}

//生成有序序列函数
void generateOrdered(std::vector<int>& vec, int size) {
    vec.clear();
    vec.reserve(size);
    for (int i = 1; i <= size; ++i) {
        vec.push_back(i);
    }
}

//生成逆序序列函数
void generateReversed(std::vector<int>& vec, int size) {
    vec.clear();
    vec.reserve(size);
    for (int i = size; i > 0; --i) {
        vec.push_back(i);
    }
}

//生成部分元素重复序列函数
void generatePartiallyRepeated(std::vector<int>& vec, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); //从1到100，由抽屉原理，必有重复元素
    vec.clear();
    vec.reserve(size);
    for (int i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
}