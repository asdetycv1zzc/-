#include<iostream>
#include<vector>
#include "Convert.h"
#include "InputFormat.h"
#include "Calculate.h"
#include "Random.h"
using namespace std;

//²âÊÔ´ó¾ØÕó£º2 0 8 6 9 2 4 8 3 1 2 0 6 4 2 3
//²âÊÔÐ¡¾ØÕó£º1 3 2 4

void test();
void testRandom(long Geshu);
int main()
{
	long Geshu;
	cin >> Geshu;
	//testRandom(Geshu);
	test();
	return 0;
}
void test()
{
	vector<int> TestInput, TestInputKernel;
	long i, n, lines, temp;

	cin >> n;
	cin >> lines;

	TestInput.resize(n);
	for (i = 0; i < n; i++)
	{
		cin >> TestInput[i];
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
	auto temp1 = ConvolutionCalculate(testOutput, OutputKernel);
	for (long j = 0; j < temp1.Vector.size(); j++)
	{
		for (long k = 0; k < temp1.Vector.size(); k++)
		{
			cout << temp1.Vector[j][k] << " ";
		}
		cout << endl;
	}
}
void testRandom(long Geshu)
{
	auto temp = RandomGenerator(Geshu);
	for (long i = 0;i < temp.size();i++)
	{
		cout << temp[i] << " ";
	}
}