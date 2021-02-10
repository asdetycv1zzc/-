#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
struct TryTimes
{
public:
	int horizontalTimes;//横向需要计算的次数
	int verticalTimes;//纵向需要计算的次数
};
/**
 * @brief 通过数组卷积来计算向量（二维）
 * @param inputVector    输入数组，从左至右，从上到下拆散排列
 * @param inputConvolutionkernel    输入数组的行数（向量的行数），无论是否整除
 *
 * @return 返回说明
 *     返回一个数组
 */

bool Convert(InputVector& inputVector,InputConvolutionkernel& inputConvolutionkernel)
{
	try
	{
		std::vector<std::vector<int>> FormatedInputVector, FormatedInputConvolutionkernel;

		//调整初始大小（临时
		FormatedInputConvolutionkernel.resize(100);
		FormatedInputVector.resize(100);

		//调整二维数组的初始大小，下同
		for (long i = 0; i < 100; i++)
		{
			FormatedInputConvolutionkernel[i].resize(100);
		}

		for (long i = 0; i < 100; i++)
		{
			FormatedInputVector[i].resize(100);
		}

		int VectorNumberEveryLine;//向量每行的长度 当为2行且个数为奇数时在整除后需要加1
		int ConvolutionkernelNumberEveryLine;//卷积核每行的长度 当为2行且个数为奇数时在整除后需要加1

		TryTimes CalculateTimes;//横纵向需要计算的次数

		//算出每行卷积与卷积核的长度
		VectorNumberEveryLine = inputVector.inputVector.size() / inputVector.lines;
		ConvolutionkernelNumberEveryLine = inputConvolutionkernel.inputVector.size() / inputConvolutionkernel.lines;

		//当卷积为2行且个数为奇数时，在整除后需要加1
		if (inputVector.lines == 2 && inputVector.inputVector.size() % 2 == 1)
		{
			VectorNumberEveryLine += 1;
		}
		if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.inputVector.size() % 2 == 1)
		{
			ConvolutionkernelNumberEveryLine += 1;
		}

		//算出横向纵向所需要卷积的次数
		CalculateTimes.horizontalTimes = VectorNumberEveryLine - ConvolutionkernelNumberEveryLine + 1;
		CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;

		//算出卷积与卷积核的总大小
		int VectorTotalNumber = VectorNumberEveryLine * inputVector.lines;
		int ConvolutionkernelTotalNumber = ConvolutionkernelNumberEveryLine * inputConvolutionkernel.lines;

		//重新转为二维数组并补零
		for (long i = 0; i < inputVector.lines; i++)
		{
			for (long j = 0; j < VectorNumberEveryLine; j++)
			{
				if ((i * VectorNumberEveryLine + j) > (inputVector.inputVector.size() - 1))
				{
					FormatedInputVector[i][j] = 0;
				}
				FormatedInputVector[i][j] = inputVector.inputVector[i * VectorNumberEveryLine + j];
			}
		}
		for (long i = 0; i < inputConvolutionkernel.lines; i++)
		{
			for (long j = 0; j < ConvolutionkernelNumberEveryLine; j++)
			{
				if ((i * ConvolutionkernelNumberEveryLine + j) > (inputConvolutionkernel.inputVector.size() - 1))
				{
					FormatedInputConvolutionkernel[i][j] = 0;
				}
				FormatedInputConvolutionkernel[i][j] = inputConvolutionkernel.inputVector[i * ConvolutionkernelNumberEveryLine + j];
			}
		}
		return true;
	}

	catch (exception e)
	{
		std::cout << "在转换向量出现了错误：" << e.what;
		return false;
	}
}
