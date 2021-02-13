#include<iostream>
#include<vector>
#include "Convert.h"
#include "InputFormat.h"
#include "Calculate.h"
using namespace std;

//≤‚ ‘¥Ûæÿ’Û£∫2 0 8 6 9 2 4 8 3 1 2 0 6 4 2 3
//≤‚ ‘–°æÿ’Û£∫1 3 2 4

void test();

int main()
{
	test();
	return 0;
}
void test()
{
	vector<int> TestInput, TestInputKernel;
	int i, n, lines, temp;

	cin >> n;
	cin >> lines;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		TestInput.push_back(temp);
	}

	InputConvertVector testInput;

	testInput.Vector = TestInput;
	testInput.lines = lines;

	cin >> n;
	cin >> lines;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		TestInputKernel.push_back(temp);
	}

	InputConvertVector testInputKernel;

	testInputKernel.Vector = TestInputKernel;
	testInputKernel.lines = lines;

	InputCalculateVector testOutput;
	InputCalculateVector testOutputKernel;
	Convert(testInput, testOutput);
	Convert(testInputKernel, testOutputKernel);
	InputCalculateConvolutionkernel OutputKernel;
	OutputKernel.lines = testOutputKernel.lines;
	OutputKernel.Vector = testOutputKernel.Vector;
	OutputKernel.VectorNumberEveryLine = testOutputKernel.VectorNumberEveryLine;
	ConvolutionCalculate(testOutput, OutputKernel);
}