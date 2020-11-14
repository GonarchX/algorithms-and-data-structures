#include "CppUnitTest.h"
#include "../Lab3/functions/lib/binary_search_tree.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabTest3
{
	TEST_CLASS(LabTest3)
	{
	public:
		TEST_METHOD(BinarySearchTree_emptyTree)
		{
			BinSearchTree Tree;
			// If the tree is empty, then the "contains" method will return a false result.
			Assert::IsFalse(Tree.contains(999));
		}
		TEST_METHOD(BinarySearchTree_contains_missingElement)
		{
			BinSearchTree Tree;
			Tree.insert(1);
			Assert::IsFalse(Tree.contains(999));
		}
		TEST_METHOD(BinarySearchTree_containsAndCheck_oneElement)
		{
			BinSearchTree Tree;
			Tree.insert(1);
			Assert::IsTrue(Tree.contains(1));
		}
		TEST_METHOD(BinarySearchTree_containsAndCheck_twoElements)
		{
			BinSearchTree Tree;
			Tree.insert(1);
			Tree.insert(2);
			Assert::IsTrue(Tree.contains(2));
		}
		TEST_METHOD(BinarySearchTree_containsAndCheck_manyElements)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			Tree.insert(1);
			Tree.insert(10);
			Tree.insert(9);
			Tree.insert(12);
			Tree.insert(11);
			//      Tree looks like:			
			//          3
			//         / \
			//        2  10
			//       /  /  \
			//      1  9   12
			//      	  /
			//      	 11

			Assert::IsTrue(Tree.contains(3));
			Assert::IsTrue(Tree.contains(2));
			Assert::IsTrue(Tree.contains(1));
			Assert::IsTrue(Tree.contains(10));
			Assert::IsTrue(Tree.contains(9));
			Assert::IsTrue(Tree.contains(12));
			Assert::IsTrue(Tree.contains(11));

			//Check the absence of an element that is not in the tree
			Assert::IsFalse(Tree.contains(999));
			Assert::IsFalse(Tree.contains(888));
		}
		TEST_METHOD(BinarySearchTree_remove_exception_manyElements)
		{
			//Check exception
			try
			{
				BinSearchTree Tree;
				Tree.remove(99);
			}
			catch (const char* message)
			{
				Assert::AreEqual(message, "Tree not contains this key!");
			}
		}
		TEST_METHOD(BinarySearchTree_remove_exception_emptyList)
		{
			//Check exception
			try
			{
				BinSearchTree Tree;
				Tree.insert(3);
				Tree.insert(2);
				Tree.insert(1);
				Tree.insert(10);
				Tree.insert(9);
				Tree.insert(12);
				Tree.insert(11);

				//Tree not contain node with data "999"
				Tree.remove(999);
			}
			catch (const char* message)
			{
				Assert::AreEqual(message, "Tree not contains this key!");
			}
		}
		TEST_METHOD(BinarySearchTree_remove_noLeafs_removingRootNode)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.remove(3);
			Assert::IsTrue(!Tree.contains(3));
		}
		TEST_METHOD(BinarySearchTree_remove_noLeafs)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			// Tree looks like:			
			// 3
			// | 
			// 2

			Tree.remove(2);

			//After removing
			// 3
			Assert::IsTrue(!Tree.contains(2) && Tree.contains(3));
		}
		TEST_METHOD(BinarySearchTree_remove_oneLeaf_removingRootNode)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			// Tree looks like:			
			// 3
			// | 
			// 2

			Tree.remove(3);

			//After removing
			// 3
			Assert::IsTrue(!Tree.contains(3) && Tree.contains(2));
		}
		TEST_METHOD(BinarySearchTree_remove_oneLeaf)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			Tree.insert(1);
			// Tree looks like:			
			// 3
			// | 
			// 2
			// |
			// 1

			Tree.remove(2);

			//After removing
			// 3
			// |
			// 1
			Assert::IsTrue(!Tree.contains(2) && Tree.contains(3) && Tree.contains(1));
		}
		TEST_METHOD(BinarySearchTree_remove_twoLeaf_removeRootNode)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			Tree.insert(4);
			//      Tree looks like:			
			//          3
			//         / \
			//        2   4

			Tree.remove(3);
			//      Tree looks like:			
			//          4
			//         / 
			//        2  
			Assert::IsTrue(!Tree.contains(3) && Tree.contains(4) && Tree.contains(2));
		}
		TEST_METHOD(BinarySearchTree_remove_twoLeaf)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(0);
			Tree.insert(6);
			Tree.insert(4);
			Tree.insert(9);
			//      Tree looks like:			
			//          3
			//         / \
			//        0   6
			//			 / \
			//			4   9

			Tree.remove(6);
			//      Tree looks like:			
			//          3
			//         / \
			//        0   9
			//			 /
			//			4  

			Assert::IsTrue(!Tree.contains(6) && Tree.contains(3) && Tree.contains(0) && Tree.contains(4) && Tree.contains(9));
		}
		TEST_METHOD(dftIter_create_dft_iter_EmptyTreeException)
		{
			try
			{
				BinSearchTree Tree;
				Iterator* DFT_Iter = Tree.create_dft_iterator();
			}
			catch (const char* message)
			{
				Assert::AreEqual(message, "Unable to create an iterator because the tree does not contain any elements!");
			}
		}
		TEST_METHOD(dftIter_hasNext_NoElementException)
		{
			try
			{
				BinSearchTree Tree;
				Tree.insert(3);
				Iterator* DFT_Iter = Tree.create_dft_iterator();
				DFT_Iter->next();
				DFT_Iter->next();
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "No more elements");
			}
		}
		TEST_METHOD(dftIter_hasNext_oneElement)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Iterator* DFT_Iter = Tree.create_dft_iterator();
			Assert::IsTrue(DFT_Iter->has_next());
		}
		TEST_METHOD(dftIter_next_oneElement)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Iterator* DFT_Iter = Tree.create_dft_iterator();
			Assert::AreEqual(3, DFT_Iter->next());
		}
		TEST_METHOD(dftIter_next_twoElements)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			Iterator* DFT_Iter = Tree.create_dft_iterator();
			DFT_Iter->next();
			Assert::AreEqual(2, DFT_Iter->next());
		}
		TEST_METHOD(dftIter_next_manyElements)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(0);
			Tree.insert(1);
			Tree.insert(2);
			Tree.insert(3);
			Tree.insert(6);
			Tree.insert(4);
			Tree.insert(9);
			// Tree looks like:
			//          3
			//         / \
			//        0  6
			//       /  /  \
			//      1  4    9
			//       \	  
			//        2	 
			//         \
			//          3

			// Result: 3 0 1 2 3 6 4 9

			Iterator* DFT_Iter = Tree.create_dft_iterator();
			Assert::AreEqual(3, DFT_Iter->next());
			Assert::AreEqual(0, DFT_Iter->next());
			Assert::AreEqual(1, DFT_Iter->next());
			Assert::AreEqual(2, DFT_Iter->next());
			Assert::AreEqual(3, DFT_Iter->next());
			Assert::AreEqual(6, DFT_Iter->next());
			Assert::AreEqual(4, DFT_Iter->next());
			Assert::AreEqual(9, DFT_Iter->next());
		}
		TEST_METHOD(bftIter_create_dft_iter_EmptyTreeException)
		{
			try
			{
				BinSearchTree Tree;
				Iterator* BFT_Iter = Tree.create_dft_iterator();
			}
			catch (const char* message)
			{
				Assert::AreEqual(message, "Unable to create an iterator because the tree does not contain any elements!");
			}
		}
		TEST_METHOD(bftIter_hasNext_NoElementException)
		{
			try
			{
				BinSearchTree Tree;
				Tree.insert(3);
				Iterator* BFT_Iter = Tree.create_dft_iterator();
				BFT_Iter->next();
				BFT_Iter->next();
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "No more elements");
			}
		}
		TEST_METHOD(bftIter_hasNext_oneElement)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Iterator* BFT_Iter = Tree.create_dft_iterator();
			Assert::IsTrue(BFT_Iter->has_next());
		}
		TEST_METHOD(bftIter_next_oneElement)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Iterator* BFT_Iter = Tree.create_dft_iterator();
			Assert::AreEqual(3, BFT_Iter->next());
		}
		TEST_METHOD(bftIter_next_twoElements)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(2);
			Iterator* BFT_Iter = Tree.create_dft_iterator();
			BFT_Iter->next();
			Assert::AreEqual(2, BFT_Iter->next());
		}
		TEST_METHOD(bftIter_next_manyElements)
		{
			BinSearchTree Tree;
			Tree.insert(3);
			Tree.insert(0);
			Tree.insert(1);
			Tree.insert(2);
			Tree.insert(3);
			Tree.insert(6);
			Tree.insert(4);
			Tree.insert(9);
			// Tree looks like:
			//          3
			//         / \
			//        0  6
			//       /  /  \
			//      1  4    9
			//       \	  
			//        2	 
			//         \
			//          3

			// Result: 3 0 6 1 4 9 2 3

			Iterator* BFT_Iter = Tree.create_bft_iterator();
			Assert::AreEqual(3, BFT_Iter->next());
			Assert::AreEqual(0, BFT_Iter->next());
			Assert::AreEqual(6, BFT_Iter->next());
			Assert::AreEqual(1, BFT_Iter->next());
			Assert::AreEqual(4, BFT_Iter->next());
			Assert::AreEqual(9, BFT_Iter->next());
			Assert::AreEqual(2, BFT_Iter->next());
			Assert::AreEqual(3, BFT_Iter->next());
		}
	};
}
