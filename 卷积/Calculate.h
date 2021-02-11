#pragma once
#include<iostream>
#include<exception>
#include<vector>
#include "InputFormat.h"
#include "OutputFormat.h"

CalculatedVector ConvolutionCalculate(InputCalculateVector inputVector, InputCalculateConvolutionkernel inputConvolutionkernel)
{
	TryTimes CalculateTimes;//��������Ҫ����Ĵ���

	CalculateTimes.horizontalTimes = inputVector.VectorNumberEveryLine - inputVector.VectorNumberEveryLine + 1;
	CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;

	//��ʼ�����
	CalculatedVector result;
	result.HorizontalLength = CalculateTimes.horizontalTimes;
	result.VerticalLength = CalculateTimes.verticalTimes;
	
	//����Vector������ռ�
	result.Vector.resize(result.VerticalLength);

	//����Vector�ĺ���ռ�
	for (long i = 0;i < result.VerticalLength;i++)
	{
		result.Vector[i].resize(result.HorizontalLength);
	}

	//��ʼ���к���������
	for (long i = 0;i < CalculateTimes.horizontalTimes;i++)
	{
		
	}
	return result;
}
