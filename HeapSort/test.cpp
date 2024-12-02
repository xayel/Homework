#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "HeapSort.h"

template<typename T>
bool check(const std::vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false; //发现降序，返回错误
        }
    }
    return true; //所有元素都是升序排列
}

int main() {
    const int size = 1000000;
    std::vector<int> vec;

    //测试随机序列
    std::vector<int> randomVec;
    generateRandom(randomVec, size);
    std::vector<int> randomVec_copy = randomVec;
    auto randomVec_start = std::chrono::high_resolution_clock::now();
    heapsort(randomVec);
    auto randomVec_end = std::chrono::high_resolution_clock::now();
    auto randomVec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(randomVec_end - randomVec_start);
    std::cout << "my heapsort took " << randomVec_duration.count() << " milliseconds to execute." << std::endl;
    auto randomVec_copy_start = std::chrono::high_resolution_clock::now();
    make_heap(randomVec_copy.begin(), randomVec_copy.end());
    sort_heap(randomVec_copy.begin(), randomVec_copy.end());
    auto randomVec_copy_end = std::chrono::high_resolution_clock::now();
    auto randomVec_copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(randomVec_copy_end - randomVec_copy_start);
    std::cout << "std::sort_heap took " << randomVec_copy_duration.count() << " milliseconds to execute." << std::endl;
    if (check(randomVec)) {
        std::cout << "Random sequence is sorted correctly in ascending order." << std::endl;
    } else {
        std::cout << "Random sequence is NOT sorted correctly." << std::endl;
    }

    //测试有序序列
    std::vector<int> orderedVec;
    generateRandom(orderedVec, size);
    std::vector<int> orderedVec_copy = orderedVec;
    auto orderedVec_start = std::chrono::high_resolution_clock::now();
    heapsort(orderedVec);
    auto orderedVec_end = std::chrono::high_resolution_clock::now();
    auto orderedVec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(orderedVec_end - orderedVec_start);
    std::cout << "my heapsort took " << orderedVec_duration.count() << " milliseconds to execute." << std::endl;
    auto orderedVec_copy_start = std::chrono::high_resolution_clock::now();
    make_heap(orderedVec_copy.begin(), orderedVec_copy.end());
    sort_heap(orderedVec_copy.begin(), orderedVec_copy.end());
    auto orderedVec_copy_end = std::chrono::high_resolution_clock::now();
    auto orderedVec_copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(orderedVec_copy_end - orderedVec_copy_start);
    std::cout << "std::sort_heap took " << orderedVec_copy_duration.count() << " milliseconds to execute." << std::endl;
    if (check(orderedVec)) {
        std::cout << "Ordered sequence is sorted correctly in ascending order." << std::endl;
    } else {
        std::cout << "Ordered sequence is NOT sorted correctly." << std::endl;
    }

    //测试逆序序列
    std::vector<int> reversedVec;
    generateRandom(reversedVec, size);
    std::vector<int> reversedVec_copy = reversedVec;
    auto reversedVec_start = std::chrono::high_resolution_clock::now();
    heapsort(reversedVec);
    auto reversedVec_end = std::chrono::high_resolution_clock::now();
    auto reversedVec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(reversedVec_end - reversedVec_start);
    std::cout << "my heapsort took " << reversedVec_duration.count() << " milliseconds to execute." << std::endl;
    auto reversedVec_copy_start = std::chrono::high_resolution_clock::now();
    make_heap(reversedVec_copy.begin(), reversedVec_copy.end());
    sort_heap(reversedVec_copy.begin(), reversedVec_copy.end());
    auto reversedVec_copy_end = std::chrono::high_resolution_clock::now();
    auto reversedVec_copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(reversedVec_copy_end - reversedVec_copy_start);
    std::cout << "std::sort_heap took " << reversedVec_copy_duration.count() << " milliseconds to execute." << std::endl;
    if (check(reversedVec)) {
        std::cout << "Reversed sequence is sorted correctly in ascending order." << std::endl;
    } else {
        std::cout << "Reversed sequence is NOT sorted correctly." << std::endl;
    }

    //测试部分元素重复的序列
    std::vector<int> partiallyRepeatedVec;
    generateRandom(partiallyRepeatedVec, size);
    std::vector<int> partiallyRepeatedVec_copy = partiallyRepeatedVec;
    auto partiallyRepeatedVec_start = std::chrono::high_resolution_clock::now();
    heapsort(partiallyRepeatedVec);
    auto partiallyRepeatedVec_end = std::chrono::high_resolution_clock::now();
    auto partiallyRepeatedVec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(partiallyRepeatedVec_end - partiallyRepeatedVec_start);
    std::cout << "my heapsort took " << partiallyRepeatedVec_duration.count() << " milliseconds to execute." << std::endl;
    auto partiallyRepeatedVec_copy_start = std::chrono::high_resolution_clock::now();
    make_heap(partiallyRepeatedVec_copy.begin(), partiallyRepeatedVec_copy.end());
    sort_heap(partiallyRepeatedVec_copy.begin(), partiallyRepeatedVec_copy.end());
    auto partiallyRepeatedVec_copy_end = std::chrono::high_resolution_clock::now();
    auto partiallyRepeatedVec_copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(partiallyRepeatedVec_copy_end - partiallyRepeatedVec_copy_start);
    std::cout << "std::sort_heap took " << partiallyRepeatedVec_copy_duration.count() << " milliseconds to execute." << std::endl;
    if (check(partiallyRepeatedVec)) {
        std::cout << "Partially repeated sequence is sorted correctly in ascending order." << std::endl;
    } else {
        std::cout << "Partially repeated sequence is NOT sorted correctly." << std::endl;
    }

    return 0;
}