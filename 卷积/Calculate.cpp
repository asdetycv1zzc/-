#include<iostream>
#include<vector>
#include "Convert.h"
#include "InputFormat.h"
using namespace std;

//���Դ����2 0 8 6 9 2 4 8 3 1 2 0 6 4 2 3
//����С����1 3 2 4

int main()
{
	
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

	testInput.inputVector = TestInput;
	testInput.lines = lines;

	cin >> n;
	cin >> lines;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		TestInputKernel.push_back(temp);
	}

	InputConvertConvolutionkernel testInputKernel;

	testInputKernel.inputVector = TestInputKernel;
	testInputKernel.lines = lines;

	Convert(testInput, testInputKernel);
}