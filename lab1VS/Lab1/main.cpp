#include "functions/lib/double_linked_list.hpp"
#include <stdexcept>
using namespace std;
int main() 
{   
    try
    {
        DoubleLinkedList test;
        test.pushBack(0);
        test.pushBack(1);
        test.pushBack(2);
        test.pushBack(3);
        test.pushFront(4);
        test.pushFront(5);
        test.pushFront(6);
        test.pushFront(7);

        test.set(7, 999);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}