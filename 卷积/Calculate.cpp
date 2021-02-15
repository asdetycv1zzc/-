#include<iostream>
#include<vector>
#include "Convert.h"
#include "InputFormat.h"
#include "Calculate.h"
#include "Random.h"
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace std;

//≤‚ ‘¥Ûæÿ’Û£∫2 0 8 6 9 2 4 8 3 1 2 0 6 4 2 3
//≤‚ ‘–°æÿ’Û£∫1 3 2 4

void test();
void testRandom(long Geshu);
void testImageConvert(cv::String Address);
int main()
{
	//long Geshu;
	//cin >> Geshu;
	//testRandom(Geshu);
	//test();
	//ConvertImagetoVector("C:\\Users\\Dashan\\Desktop\\≥ı»˝÷ÿ“™“Ù∆µ\\navy.jpg");
	testImageConvert("C:\\Users\\Dashan\\Desktop\\≥ı»˝÷ÿ“™“Ù∆µ\\navy.jpg");
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
	Convert1Dto2D(testInput, testOutput);
	Convert1Dto2D(testInputKernel, testOutputKernel);
	InputCalculateVector OutputKernel;
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
void testImageConvert(cv::String Address)
{
	vector<int> TestInput, TestInputKernel;
	long i, n, lines, temp;

	cin >> n;
	cin >> lines;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		TestInputKernel.push_back(temp);
	}
	InputCalculateVector input, outputKernel;
	InputConvertVector inputKernel;

	inputKernel.Vector = TestInputKernel;
	inputKernel.lines = lines;

	Convert1Dto2D(inputKernel, outputKernel);

	auto image = cv::imread(Address);
	input.VectorNumberEveryLine = image.cols;
	input.lines = image.rows;
	input.Vector = Mat2Vector<vector<int>>(image);

	ConvolutionCalculate(input, outputKernel);
}
