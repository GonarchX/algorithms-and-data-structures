#include "CppUnitTest.h"
#include "../Lab1/functions/lib/double_linked_list.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Tests
{
	TEST_CLASS(Lab1Tests)
	{
	public:
		TEST_METHOD(atTest)
		{
			DoubleLinkedList test;
			test.pushBack(0); //Node with index 0
			test.pushBack(1); //Node with index 1
			test.pushBack(2); //Node with index 2
			test.pushBack(999); //Node with index 3
			test.pushBack(4); //Node with index 4
			Assert::AreEqual(test.at(3), 999);
		}

		TEST_METHOD(atExceptionTest)
		{
			DoubleLinkedList test;
			test.pushBack(999); //Node with index 0
			try
			{
				test.at(1); //Check node with index 1
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
		}
		TEST_METHOD(GetSizeTest_0) //List size is 4
		{
			DoubleLinkedList test;
			test.pushBack(1);
			test.pushBack(2);
			test.pushBack(3);
			test.pushBack(4);
			Assert::IsTrue(test.getSize() == 4);
		}
		TEST_METHOD(GetSizeTest_4) //List size is 4
		{
			DoubleLinkedList test;
			Assert::IsTrue(test.getSize() == 0);
		}
		TEST_METHOD(isEmptyTest_false)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			Assert::IsFalse(test.isEmpty());
		}
		TEST_METHOD(isEmptyTest_true)
		{
			DoubleLinkedList test;
			Assert::IsTrue(test.isEmpty());
		}		
		TEST_METHOD(pushBackTest_changeSize)
		{
			DoubleLinkedList test;

			Assert::IsTrue(test.isEmpty()); //List size = 0

			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			Assert::IsFalse(test.isEmpty()); //List size != 0
		}		
		TEST_METHOD(pushBackTest_checkLastNodeData)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			Assert::AreEqual(test.at(0), 0); //Node #1 = 0

			test.pushBack(999);
			Assert::AreEqual(test.getSize(), size_t(2)); //List size = 2
			Assert::AreEqual(test.at(test.getSize() - 1), 999); //Node #2 = 999
		}
		TEST_METHOD(pushFrontTest_changeSize)
		{
			DoubleLinkedList test;

			Assert::IsTrue(test.isEmpty()); //List size = 0

			test.pushFront(0);
			test.pushFront(1);
			test.pushFront(2);

			Assert::IsFalse(test.isEmpty()); //List size != 0
		}
		TEST_METHOD(pushFrontTest_checkFirstNodeData)
		{
			DoubleLinkedList test;
			test.pushFront(0);
			Assert::AreEqual(test.at(0), 0); //Node #1 = 0

			test.pushFront(999);
			Assert::AreEqual(test.getSize(), size_t(2)); //List size = 2
			Assert::AreEqual(test.at(0), 999); //Node #2 = 999
		}
		TEST_METHOD(popBackTest_changeSize_1to0)
		{
			DoubleLinkedList test;
			Assert::IsTrue(test.isEmpty()); //List size = 0
			test.pushBack(0); //Node #1 = 0
			Assert::IsFalse(test.isEmpty()); //List size = 1

			test.popBack(); //Delete Node
			Assert::IsTrue(test.isEmpty()); //List size = 0
		}
		TEST_METHOD(popBackTest_changeSize_0to0)
		{
			DoubleLinkedList test;

			test.popBack();//Delete last element from empty list
			Assert::IsTrue(test.isEmpty());
		}
		TEST_METHOD(popBackTest_checkDeletedLastElement)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			//In this example, we are trying to access the deleted item
			test.popBack();
			try
			{
				int check = test.at(test.getSize() - 1);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
		}
		TEST_METHOD(popFrontTest_changeSize_1to0)
		{
			DoubleLinkedList test;
			Assert::IsTrue(test.isEmpty()); //List size = 0
			test.pushBack(0); //Node #1 = 0
			Assert::IsFalse(test.isEmpty()); //List size = 1

			test.popFront(); //Delete Node
			Assert::IsTrue(test.isEmpty()); //List size = 0
		}
		TEST_METHOD(popFrontTest_changeSize_0to0)
		{
			DoubleLinkedList test;

			test.popFront();//Delete first element from empty list
			Assert::IsTrue(test.isEmpty());
		}
		TEST_METHOD(popFrontTest_checkDeletedLastElement)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			//In this example, we are trying to access the deleted item
			int check = test.at(0);
			test.popFront();			
			
			Assert::AreNotEqual(check, test.at(0));
		}
		TEST_METHOD(insertTest_changeSize)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);
			//Now list size = 3
			test.insert(999, 1);
			//Now list size = 4

			Assert::AreEqual(test.getSize(), size_t(4));
		}
		TEST_METHOD(insertTest_checkNewElement)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);
			//Now list size = 3
			test.insert(999, 2);
			//Now list size = 4

			Assert::AreEqual(test.at(2), 999);
		}
		TEST_METHOD(insertTest_assertCheck)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			try
			{
				test.insert(999, 3);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
		}
		TEST_METHOD(setTest_checkElementAfter)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);
			
			test.set(999, 2);

			Assert::AreEqual(test.at(2), 999);
		}
		TEST_METHOD(setTest_assertCheck)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			try
			{
				test.set(999, 3);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
		}
		TEST_METHOD(removeTest_checkSize_3to2)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);
			//List size = 3
			test.remove(test.getSize() - 1);
			//List size after remove = 2
			Assert::AreEqual(test.getSize(), size_t(2));
		}
		TEST_METHOD(removeTest_checkDeletedNode)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(999);
			test.pushBack(2);

			test.remove(1);
			//List size after remove = 2
			Assert::AreNotEqual(test.at(1), 999);
		}
		TEST_METHOD(clearTest_checkSize)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			test.clear();
			//List size after clear = 0
			Assert::AreEqual(test.getSize(), size_t(0));
		}
		TEST_METHOD(clearTest_checkNodesAfterClearing)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			test.clear();
			
			try
			{
				test.at(0);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
			try
			{
				test.at(1);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
			try
			{
				test.at(2);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Index is greater than list size");
			}
		}
		TEST_METHOD(pushBackListTest_checkSize)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);
			//List size of test = 3
			DoubleLinkedList test1;
			test1.pushBack(3);
			test1.pushBack(4);
			//List size of test1 = 2

			test.pushBack(test1);
			//List size after pushBack = 5
			Assert::AreEqual(test.getSize(), size_t(5));
		}
		TEST_METHOD(pushBackListTest_checkConnectedNodes)
		{
			DoubleLinkedList test;
			test.pushBack(0);
			test.pushBack(1);
			test.pushBack(2);

			DoubleLinkedList test1;
			test1.pushBack(3);
			test1.pushBack(4);

			test.pushBack(test1);
			Assert::AreEqual(test.at(3), 3);
			Assert::AreEqual(test.at(4), 4);
		}
	};
}