#include <iostream>

#include "BSTree.hpp"


int main(void)
{
    BSTree<int> t1({0, 1});
    BSTree<int> t2;
    t2.Add(1);
    t2.Add(2);
    Iterator<int> it1 = t1.begin();
    ++it1;
    std::cout << *it1 << std::endl;
    (void) t1.end();
    // std::cout << (it1 == t1.end()) << std::endl;


    // for (auto it = t1.begin(); it!= t1.end(); ++it) 
    // {
    //     std::cout << "| " << std::endl;
    // }
    // t1.Intersection(t2);
    // BSTree<int> t3 = t2.IntersectionCopy(t2);
    

    return 0;
}