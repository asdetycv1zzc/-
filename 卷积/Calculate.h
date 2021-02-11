#pragma once
#include<iostream>
#include<exception>
#include<vector>
#include "InputFormat.h"
#include "OutputFormat.h"

CalculatedVector ConvolutionCalculate(InputCalculateVector inputVector, InputCalculateConvolutionkernel inputConvolutionkernel)
{
	TryTimes CalculateTimes;//横纵向需要计算的次数

	CalculateTimes.horizontalTimes = inputVector.VectorNumberEveryLine - inputVector.VectorNumberEveryLine + 1;
	CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;

	//初始化结果
	CalculatedVector result;
	result.HorizontalLength = CalculateTimes.horizontalTimes;
	result.VerticalLength = CalculateTimes.verticalTimes;
	
	//开辟Vector的纵向空间
	result.Vector.resize(result.VerticalLength);

	//开辟Vector的横向空间
	for (long i = 0;i < result.VerticalLength;i++)
	{
		result.Vector[i].resize(result.HorizontalLength);
	}

	//开始进行横向卷积计算
	for (long i = 0;i < CalculateTimes.horizontalTimes;i++)
	{
		
	}
	return result;
}
