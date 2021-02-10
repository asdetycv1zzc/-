#pragma once
#include<iostream>
#include<exception>
#include<vector>
#include "InputFormat.h"

std::vector<std::vector<int>> ConvolutionCalculate(InputCalculateVector inputVector, InputCalculateConvolutionkernel inputConvolutionkernel)
{
	TryTimes CalculateTimes;//横纵向需要计算的次数

	CalculateTimes.horizontalTimes = inputVector.VectorNumberEveryLine - inputVector.VectorNumberEveryLine + 1;
	CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;


	return NULL;
}
