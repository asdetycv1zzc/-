#pragma once
#include<iostream>
#include<vector>
struct InputConvertVector
{
public:
	long lines;
	std::vector<int> inputVector;
};

struct InputConvertConvolutionkernel
{
public:
	long lines;
	std::vector<int> inputVector;
};

struct InputCalculateVector
{
public:
	long lines;
	std::vector<std::vector<int>> inputVector;
};

struct InputCalculateConvolutionkernel
{
public:
	long lines;
	std::vector<std::vector<int>> inputVector;
};