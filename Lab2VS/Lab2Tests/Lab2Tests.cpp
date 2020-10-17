#include "CppUnitTest.h"
#include "../Lab2/functions/lib/sort.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace Lab2Tests
{
	TEST_CLASS(Lab2Tests)
	{
	public:

		TEST_METHOD(binarySearch_emptyList)
		{
			vector<int> test{};
			try
			{
				binarySearch(test, 999);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "You tried to find element in empty list!");
			}
		}

		TEST_METHOD(binarySearch_oneElement)
		{
			vector<int> test{ 999 };
			//First looking for the [index] of element in the array. 
			//Then we check the element[index] to compare them.
			Assert::AreEqual(999, test.at(binarySearch(test, 999)));
		}

		TEST_METHOD(binarySearch_twoElements)
		{
			vector<int> test{ 1, 999 };

			Assert::AreEqual(999, test.at(binarySearch(test, 999)));
		}

		TEST_METHOD(binarySearch_manyElement)
		{
			vector<int> test{ 1, 2, 3, 7, 14, 21, 999, 999, 999, 999 };

			Assert::AreEqual(7, test.at(binarySearch(test, 7)));
		}

		TEST_METHOD(binarySearch_indexOfDuplicateElements)
		{
			vector<int> test{ 1, 2, 3, 7, 14, 21, 999, 999, 999, 999, 1000, 1001, 1002, 1003, 1004 };

			Assert::AreEqual(999, test.at(binarySearch(test, 999)));
		}

		TEST_METHOD(binarySearch_noElement)
		{
			vector<int> test{ 1, 2, 3, 7, 14, 21, 999, 999, 999, 999, 1000, 1001, 1002, 1003, 1004 };

			Assert::AreEqual(-1, binarySearch(test, -999));
		}

		TEST_METHOD(quickSort__emptyList)
		{
			vector<int> test{};
			try
			{
				quickSort(test, 0, test.size() - 1);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "You tried to sort an empty list!");
			}
		}

		TEST_METHOD(quickSort__twoElements)
		{
			vector<int> test{ 1,0 };
			quickSort(test, 0, test.size() - 1);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
		}

		TEST_METHOD(quickSort__manyElements)
		{
			vector<int> test{ 1,0,3,2,4,5,6 };
			quickSort(test, 0, test.size() - 1);
			// Element index: 0 1 2 3 4 5 6			
			// Sorted array : 0 1 2 3 4 5 6
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 4);
			Assert::AreEqual(test.at(5), 5);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(quickSort_duplicatedElements)
		{
			vector<int> test{ 3,1,3,2,0,3 };
			quickSort(test, 0, test.size() - 1);
			// Element index: 0 1 2 3 4 5	
			// Sorted array : 0 1 2 3 3 3
			// Check every number in array
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 3);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(quickSort__negativeTwoElements)
		{
			vector<int> test{ -1,-2 };
			quickSort(test, 0, test.size() - 1);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), -2);
			Assert::AreEqual(test.at(1), -1);
		}

		TEST_METHOD(quickSort__negativeManyElements)
		{
			vector<int> test{ -1,0,-3,2,4,-5,6 };
			quickSort(test, 0, test.size() - 1);
			// Element index:  0  1  2 3 4 5 6			
			// Sorted array : -5 -3 -1 0 2 4 6
			Assert::AreEqual(test.at(0), -5);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), -1);
			Assert::AreEqual(test.at(3), 0);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 4);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(quickSort_negativeDuplicatedElements)
		{
			vector<int> test{ 3,1,-3,2,0,-3 };
			quickSort(test, 0, test.size() - 1);
			// Element index:  0  1 2 3 4 5	
			// Sorted array : -3 -3 0 1 2 3
			// Check every number in array
			Assert::AreEqual(test.at(0), -3);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), 0);
			Assert::AreEqual(test.at(3), 1);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(insertionSort__emptyList)
		{
			vector<int> test{};
			try
			{
				insertionSort(test);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "You tried to sort an empty list!");
			}
		}

		TEST_METHOD(insertionSort__twoElements)
		{
			vector<int> test{ 1,0 };
			insertionSort(test);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
		}

		TEST_METHOD(insertionSort__manyElements)
		{
			vector<int> test{ 1,0,3,2,4,5,6 };
			insertionSort(test);
			// Element index: 0 1 2 3 4 5 6			
			// Sorted array : 0 1 2 3 4 5 6
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 4);
			Assert::AreEqual(test.at(5), 5);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(insertionSort_duplicatedElements)
		{
			vector<int> test{ 3,1,3,2,0,3 };
			insertionSort(test);
			// Element index: 0 1 2 3 4 5	
			// Sorted array : 0 1 2 3 3 3
			// Check every number in array
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 3);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(insertionSort__negativeTwoElements)
		{
			vector<int> test{ -1,-2 };
			insertionSort(test);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), -2);
			Assert::AreEqual(test.at(1), -1);
		}

		TEST_METHOD(insertionSort__negativeManyElements)
		{
			vector<int> test{ -1,0,-3,2,4,-5,6 };
			insertionSort(test);
			// Element index:  0  1  2 3 4 5 6			
			// Sorted array : -5 -3 -1 0 2 4 6
			Assert::AreEqual(test.at(0), -5);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), -1);
			Assert::AreEqual(test.at(3), 0);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 4);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(insertionSort_negativeDuplicatedElements)
		{
			vector<int> test{ 3,1,-3,2,0,-3 };
			insertionSort(test);
			// Element index:  0  1 2 3 4 5	
			// Sorted array : -3 -3 0 1 2 3
			// Check every number in array
			Assert::AreEqual(test.at(0), -3);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), 0);
			Assert::AreEqual(test.at(3), 1);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(bogoSort__emptyList)
		{
			vector<int> test{};
			try
			{
				bogoSort(test);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "You tried to sort an empty list!");
			}
		}

		TEST_METHOD(bogoSort__twoElements)
		{
			vector<int> test{ 1,0 };
			bogoSort(test);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
		}

		TEST_METHOD(bogoSort__manyElements)
		{
			vector<int> test{ 1,0,3,2,4,5,6 };
			bogoSort(test);
			// Element index: 0 1 2 3 4 5 6			
			// Sorted array : 0 1 2 3 4 5 6
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 4);
			Assert::AreEqual(test.at(5), 5);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(bogoSort_duplicatedElements)
		{
			vector<int> test{ 3,1,3,2,0,3 };
			bogoSort(test);
			// Element index: 0 1 2 3 4 5	
			// Sorted array : 0 1 2 3 3 3
			// Check every number in array
			Assert::AreEqual(test.at(0), 0);
			Assert::AreEqual(test.at(1), 1);
			Assert::AreEqual(test.at(2), 2);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 3);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(bogoSort__negativeTwoElements)
		{
			vector<int> test{ -1,-2 };
			bogoSort(test);
			// Element index: 0 1			
			// Sorted array : 0 1
			Assert::AreEqual(test.at(0), -2);
			Assert::AreEqual(test.at(1), -1);
		}

		TEST_METHOD(bogoSort__negativeManyElements)
		{
			vector<int> test{ -1,0,-3,2,4,-5,6 };
			bogoSort(test);
			// Element index:  0  1  2 3 4 5 6			
			// Sorted array : -5 -3 -1 0 2 4 6
			Assert::AreEqual(test.at(0), -5);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), -1);
			Assert::AreEqual(test.at(3), 0);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 4);
			Assert::AreEqual(test.at(6), 6);
		}

		TEST_METHOD(bogoSort_negativeDuplicatedElements)
		{
			vector<int> test{ 3,1,-3,2,0,-3 };
			quickSort(test, 0, test.size() - 1);
			// Element index:  0  1 2 3 4 5	
			// Sorted array : -3 -3 0 1 2 3
			// Check every number in array
			Assert::AreEqual(test.at(0), -3);
			Assert::AreEqual(test.at(1), -3);
			Assert::AreEqual(test.at(2), 0);
			Assert::AreEqual(test.at(3), 1);
			Assert::AreEqual(test.at(4), 2);
			Assert::AreEqual(test.at(5), 3);
		}

		TEST_METHOD(countSort__emptyList)
		{
			vector<char> test{};
			try
			{
				countSort(test);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "You tried to sort an empty list!");
			}
		}

		TEST_METHOD(countSort__twoElements)
		{
			vector<char> test{ 'b', 'a' };
			countSort(test);
			// Element index: 0 1			
			// Sorted array : a b
			Assert::AreEqual(test.at(0), 'a');
			Assert::AreEqual(test.at(1), 'b');
		}

		TEST_METHOD(countSort__manyElements)
		{
			vector<char> test{ 'b', 'a', 'z', 'd', 's', '%', '!', '2', 'x', 'g' };
			countSort(test);
			// Element index: 0 1 2 3 4 5 6 7 8 9
			// Sorted array : ! % 2 a b d g s x z
			Assert::AreEqual(test.at(0), '!');
			Assert::AreEqual(test.at(1), '%');
			Assert::AreEqual(test.at(2), '2');
			Assert::AreEqual(test.at(3), 'a');
			Assert::AreEqual(test.at(4), 'b');
			Assert::AreEqual(test.at(5), 'd');
			Assert::AreEqual(test.at(6), 'g');
			Assert::AreEqual(test.at(7), 's');
			Assert::AreEqual(test.at(8), 'x');
			Assert::AreEqual(test.at(9), 'z');
		}
	};
}