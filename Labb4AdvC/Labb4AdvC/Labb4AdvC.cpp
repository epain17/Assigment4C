// Labb4AdvC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>


void PrintVector(std::vector<int> vector);
void PrintArray(int array[], int size);
std::vector<int> RemoveEven(std::vector<int> vector);


int main()
{
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


template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end)
{

}