#pragma once
#include <iostream>

#include <vector> // For array
#include <ctime> // For random
#include <chrono> // For timer

using namespace std;
using namespace std::chrono;

class timer
{
private:
	using clock_t = high_resolution_clock;
	using second_t = duration<long double, ratio<1>>;

	time_point<clock_t> m_beg;

public:
	// Start timer when creating class object
	timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	// Returns the time that has passed since the timer was created
	long double elapsed() const
	{
		return duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void arrayRandomFill(vector<int>& array, size_t size);

void arrayRandomFill(vector<char>& array, size_t size);

void print(const vector<int>& array);

void print(const vector<char>& array);

void swap(int* a, int* b);

bool checkSort(const vector<int>& array);

int binarySearch(vector<int>& array, const int key);

int partition(vector<int>& array, int left, int right);

void quickSort(vector<int>& array, int left, int right);

void insertionSort(vector<int>& array);

void bogoSort(vector<int>& array);

void countSort(vector<char>& array);