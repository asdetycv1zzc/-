#pragma once
#include<iostream>
#include<vector>

struct TryTimes
{
public:
	int horizontalTimes;//横向需要计算的次数
	int verticalTimes;//纵向需要计算的次数
};

struct InputConvertVector
{
public:
	long lines;
	std::vector<int> Vector;
};

struct InputConvertConvolutionkernel
{
public:
	long lines;
	std::vector<int> Vector;
};

struct InputCalculateVector
{
public:
	long lines;
	std::vector<std::vector<int>> Vector;
	long VectorNumberEveryLine;
};

struct InputCalculateConvolutionkernel
{
public:
	long lines;
	std::vector<std::vector<int>> Vector;
	long VectorNumberEveryLine;
};