// Labb4AdvC.cpp : Defines the entry point for the console application.
//

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <forward_list>
#include <list>
#include <iterator>




template<typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt Merge(InputIt1 first1,
	InputIt1 end1,
	InputIt2 first2,
	InputIt2 end2,
	OutputIt out)
{
	while (first1 != end1) {
		if (first2 == end2)
			return std::copy(first1, end1, out);

		if (*first2 < *first1) {
			*out = *first2;
			++first2;
		}
		else {
			*out = *first1;
			++first1;
		}
		++out;
	}

	return std::copy(first2, end2, out);
}

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{
	
	size_t n = std::distance(begin, end);
	if (n < 2)
		return;
	ForwardIterator mid = begin;

	std::advance(mid, n / 2);
	
	std::vector<typename ForwardIterator::value_type> res;
	ForwardSort(begin, mid);
	ForwardSort(mid, end);
	Merge(begin, mid, mid, end, std::back_inserter(res));
	std::copy(res.begin(), res.end(), begin);
}

void PrintVector(std::vector<int> vector);
void PrintArray(int array[], int size);
std::vector<int> RemoveEven(std::vector<int> vector);
std::forward_list<int> flist = { 22, 13, 5, 34, 1, 6, 7 };




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const int max = 10;
	std::vector<int> testVector;
	int testArray[max];

	srand((unsigned)time(NULL));

	for (size_t i = 0; i < max; i++)
	{
		testVector.push_back(rand());
		testArray[i] = rand();

	}

	PrintVector(testVector);
	std::cout << ' ' << "vector before" << std::endl;
	std::cout << ' ' << std::endl;

	PrintArray(testArray, max);
	std::cout << ' ' << "array before" << std::endl;
	std::cout << ' ' << std::endl;

	std::sort(testVector.begin(), testVector.end());
	PrintVector(testVector);
	std::cout << ' ' << "vector after sort" << std::endl;
	std::cout << ' ' << std::endl;

	std::sort(testArray, testArray + max);
	PrintArray(testArray, max);
	std::cout << ' ' << "array after sort" << std::endl;
	std::cout << ' ' << std::endl;

	std::sort(testVector.rbegin(), testVector.rend());
	PrintVector(testVector);
	std::cout << ' ' << "vector after reversesort" << std::endl;
	std::cout << ' ' << std::endl;

	std::sort(testArray, testArray + max, [](int a, int b) {return a > b; });
	PrintArray(testArray, max);
	std::cout << ' ' << "array after reversesort" << std::endl;
	std::cout << ' ' << std::endl;

	testVector = RemoveEven(testVector);
	PrintVector(testVector);
	//Printa ut listan före och efter

	ForwardSort(flist.begin(), flist.end());
	return 0;
}
//Gör om så att den använder templates
void PrintVector(std::vector<int> vector)
{
	for (std::vector<int>::const_iterator i = vector.begin(); i != vector.end(); ++i)
	{
		std::cout << *i << ' ';
	}
}

//Gör om så att den använder templates
void PrintArray(int array[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
}

//Gör om så att den använder templates
std::vector<int> RemoveEven(std::vector<int> vector)
{
	for (const auto &i : vector) std::cout << i << " ";
	std::cout << std::endl;

	vector.erase(std::remove_if(vector.begin(), vector.end(), [](int i)
	{ return (i % 2) == 0; }), vector.end());

	return vector;
}



//template<typname ForwardIterator, class StrictWeakOrdering>
