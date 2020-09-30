#include "functions/lib/double_linked_list.hpp"
#include <stdexcept>
using namespace std;
int main() 
{    
    DoubleLinkedList test;
    test.pushBack(0);
    test.pushBack(1);
    test.pushBack(2);
    test.pushBack(3);
    test.pushBack(4);
    test.pushBack(5);
    test.pushBack(6);
    test.pushBack(7);

    DoubleLinkedList test1;
    test1.pushBack(8);
    test1.pushBack(9);
    test1.pushBack(10);
    test1.pushBack(11);
    test1.pushBack(12);
    test1.pushBack(13);
    test1.pushBack(14);
    test1.pushBack(15);

    test.pushBack(test1);
    test.printToConsole();
    //cout << test.at(8);
    /*cout << test.getSize();
    cout << "\n";
    for (size_t i = 0; i < test.getSize(); i++)
    {
        cout << "\n" << test.at(i);
    }*/    
    
    
    return 0;
}
