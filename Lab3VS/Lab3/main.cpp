#include "functions/lib/binary_search_tree.hpp"

#include <stdexcept>
using namespace std;

int main() 
{   
    try
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

        Iterator *DFT_Iter = Tree.create_dft_iterator();         
        while(DFT_Iter->has_next()){cout << DFT_Iter->next() << " ";}

        cout << "\n";

        Iterator *BFT_Iter = Tree.create_bft_iterator();
        while(BFT_Iter->has_next()){cout << BFT_Iter->next() << " ";}
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
    return 0;
}