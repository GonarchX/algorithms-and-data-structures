#include "functions/lib/sort.hpp"

using namespace std;

int main()
{
    vector<int> array{ 1, 2, 3, 4,4,4,4,4,4, 5,6 };
    cout << "array[" << binarySearch(array, 5) << "] = " << array.at(binarySearch(array, 5));
    return 0;
}