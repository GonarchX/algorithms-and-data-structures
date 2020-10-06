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
		//List size of test = 3
		DoubleLinkedList test1;
		test.pushBack(3);
		test.pushBack(4);
		//List size of test1 = 2

		test.pushBack(test1);
		//List size after pushBack = 5
        cout << test.getSize();
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}