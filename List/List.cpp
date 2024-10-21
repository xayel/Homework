#include "List.h"
#include <iostream>

int main()
{
    List<int> lst;
    for (int i = 0; i < 10; ++i)
    {
        lst.push_back(i);
    }

    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << "\t";
    }
    std::cout << std::endl;

    lst.pop_back();
    lst.pop_front();
    lst.push_front(1 + 2);
    lst.push_back(1 + 3);

    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << "\t";
    }
    std::cout << std::endl;

    List<int> lst1 = {1, 2, 3, 4, 5};

    std::cout << lst1.size() << "\t" << lst1.empty() << "\t" << lst1.front() << "\t" << lst1.back() << std::endl;

    lst1 = std::move(lst);
    List<int> lst2 = List<int> {5, 6};
    
    for (auto &x : lst1)
    {
        std::cout << x << "\t";
    }
    std::cout << std::endl;

    for (auto &x : lst2)
    {
        std::cout << x << "\t";
    }
    std::cout << std::endl;

    lst2.clear();
    std::cout << lst2.size() << "\t" << lst2.empty() << std::endl;

    return 0;
}