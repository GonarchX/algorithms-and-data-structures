#include "../lib/sort.hpp"

using namespace std;

#define MAX_VALUE_IN_ARRAY_INT 10
#define MAX_VALUE_IN_ARRAY_CHAR 256

void arrayRandomFill(vector<int>& array, size_t size)
{
    // We set the starting value for generating random numbers 
    // based on the current time on the user's computer
    // only one time while program works
    static bool useOneTime = false;
    if (!useOneTime) {
        srand(static_cast<unsigned int>(time(0)));
        useOneTime = true;
    }
    if (array.size()) array.clear();
    for (int i = 0; i < size; i++) array.push_back((rand() % (2 * MAX_VALUE_IN_ARRAY_INT)) - MAX_VALUE_IN_ARRAY_INT);
}

void arrayRandomFill(vector<char>& array, size_t size)
{
    // We set the starting value for generating random numbers 
    // based on the current time on the user's computer
    // only one time while program works
    static bool useOneTime = false;
    if (!useOneTime) {
        srand(static_cast<unsigned int>(time(0)));
        useOneTime = true;
    }
    if (array.size()) array.clear();
    for (int i = 0; i < size; i++) array.push_back(static_cast<char>(rand()));
}

void print(const vector<int>& array)
{
    for (auto const& element : array)
        std::cout << element << ' ';
    cout << "\n";
}

void print(const vector<char>& array)
{
    for (auto const& element : array)
        std::cout << element << " ";
    cout << "\n";
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool checkSort(const vector<int>& array)
{
    bool check = true;
    if (!array.size()) return check;

    for (int i = 0; i < array.size() - 1; i++)
        if (array.at(i) > array.at(i + 1)) check = false;
    return check;
}

int binarySearch(vector<int>& array, const int key)
{
    if (!array.size()) throw invalid_argument("You tried to find element in empty list!");

    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        // Don't use "(left + right) / 2", 
        // because on large arrays this can cause variable overflow
        int mid = (right - left) / 2 + left;

        if (key == array.at(mid)) {
            return mid;
        }
        if (key < array[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1; //If we don't have element with this value in array
}

int partition(vector<int>& array, int left, int right)
{
    int pivot = array[right]; // pivot  
    int i = (left - 1); // Index of smaller element  

    for (int j = left; j <= right - 1; j++)
    {
        // If current element is smaller than the pivot  
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

void quickSort(vector<int>& array, int left, int right)
{
    if (!array.size()) throw invalid_argument("You tried to sort an empty list!");

    if (left < right)
    {
        // pi is partitioning index, array[p] is now  
        // at right place 
        int pi = partition(array, left, right);

        // Separately sort elements before partition
        quickSort(array, left, pi - 1);
        // and after partition
        quickSort(array, pi + 1, right);
    }
}

void insertionSort(vector<int>& array)
{
    if (!array.size()) throw invalid_argument("You tried to sort an empty list!");

    for (size_t i = 1; i < array.size(); i++) {
        // At every step of the loop, 
        // we move current element in left
        // until an element smaller than the current one is found
        for (size_t j = i; j > 0 && array.at(j - 1) > array.at(j); j--) {
            swap(&array[j - 1], &array[j]);
        }
    }
}

void bogoSort(vector<int>& array)
{
    if (!array.size()) throw invalid_argument("You tried to sort an empty list!");

    size_t i = 1;
    while (i < array.size())
    {
        if (array.at(i - 1) <= array.at(i)) {
            i++;
        }
        else {
            // If we find an unsorted element in the array, 
            // then we return to the previous element
            swap(&array[i - 1], &array[i]);
            if (i > 1) i--;
        }
    }
}

void countSort(vector<char>& array)
{
    vector<int> countArray;
    // Create array for 255 elements
    countArray.resize(MAX_VALUE_IN_ARRAY_CHAR);

    for (int i = 0; i < array.size(); i++)
        // Counting the number of characters in a given array
        countArray[static_cast<int>(array.at(i))]++;
    for (int i = 0; i < countArray.size() - 1; i++) countArray[i + 1] += countArray[i];

    vector<char> outArray;
    outArray.resize(array.size());

    for (int i = 0; i < array.size(); i++) {
        outArray[countArray[array[i]] - 1] = array[i];
        --countArray[array[i]];
    }
    array = outArray;
}