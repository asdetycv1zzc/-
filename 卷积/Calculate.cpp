#include<iostream>
#include<vector>
#include "Calculate.h"
using namespace std;

//²âÊÔ´ó¾ØÕó£º2 0 8 6 9 2 4 8 3 1 2 0 6 4 2 3
//²âÊÔĞ¡¾ØÕó£º1 3 2 4

int main()
{
	vector<int> TestInput, TestInputKernel;
	int i,n,lines,temp;

	cin >> n;
	cin >> lines;

	for (i = 0 ; i < n ; i++)
	{
		cin >> temp;
		TestInput.push_back(temp);
	}

	InputVector testInput;

	testInput.inputVector = TestInput;
	testInput.lines = lines;

	cin >> n;
	cin >> lines;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		TestInputKernel.push_back(temp);
	}

	InputConvolutionkernel testInputKernel;

	testInputKernel.inputVector = TestInputKernel;
	testInputKernel.lines = lines;

	Convert(testInput, testInputKernel);
	return 0;
}