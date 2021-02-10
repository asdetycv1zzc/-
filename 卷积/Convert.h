#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
#include<exception>

/**
 * @brief 通过数组卷积来计算向量（二维）
 * @param inputConvertVector    输入数组，从左至右，从上到下拆散排列
 * @param inputConvertConvolutionkernel    输入数组的行数（向量的行数），无论是否整除
 *
 * @return 返回说明
 *     若成功，返回true
 */


bool Convert(InputConvertVector inputVector,InputConvertConvolutionkernel inputConvolutionkernel, InputCalculateVector& outputVector, InputCalculateConvolutionkernel& outputConvolutionkernel)
{

	try
	{
		InputCalculateConvolutionkernel FormatedInputConvolutionkernel;
		InputCalculateVector FormatedInputVector;

		//调整初始大小（临时
		FormatedInputConvolutionkernel.Vector.resize(100);
		FormatedInputVector.Vector.resize(100);

		//调整二维数组的初始大小，下同
		for (long i = 0; i < 100; i++)
		{
			FormatedInputConvolutionkernel.Vector[i].resize(100);
		}

		for (long i = 0; i < 100; i++)
		{
			FormatedInputVector.Vector[i].resize(100);
		}

		int VectorNumberEveryLine;//向量每行的长度 当为2行且个数为奇数时在整除后需要加1
		int ConvolutionkernelNumberEveryLine;//卷积核每行的长度 当为2行且个数为奇数时在整除后需要加1

		TryTimes CalculateTimes;//横纵向需要计算的次数

		//算出每行卷积与卷积核的长度
		VectorNumberEveryLine = inputVector.Vector.size() / inputVector.lines;
		ConvolutionkernelNumberEveryLine = inputConvolutionkernel.Vector.size() / inputConvolutionkernel.lines;

		//当卷积为2行且个数为奇数时，在整除后需要加1
		if (inputVector.lines == 2 && inputVector.Vector.size() % 2 == 1)
		{
			VectorNumberEveryLine += 1;
		}
		if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.Vector.size() % 2 == 1)
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
				if ((i * VectorNumberEveryLine + j) > (inputVector.Vector.size() - 1))
				{
					FormatedInputVector.Vector[i][j] = 0;
				}
				FormatedInputVector.Vector[i][j] = inputVector.Vector[i * VectorNumberEveryLine + j];
			}
		}
		for (long i = 0; i < inputConvolutionkernel.lines; i++)
		{
			for (long j = 0; j < ConvolutionkernelNumberEveryLine; j++)
			{
				if ((i * ConvolutionkernelNumberEveryLine + j) > (inputConvolutionkernel.Vector.size() - 1))
				{
					FormatedInputConvolutionkernel.Vector[i][j] = 0;
				}
				FormatedInputConvolutionkernel.Vector[i][j] = inputConvolutionkernel.Vector[i * ConvolutionkernelNumberEveryLine + j];
			}
		}

		FormatedInputConvolutionkernel.VectorNumberEveryLine = ConvolutionkernelNumberEveryLine;
		FormatedInputVector.VectorNumberEveryLine = VectorNumberEveryLine;

		outputConvolutionkernel = FormatedInputConvolutionkernel;
		outputVector = FormatedInputVector;

		return true;
	}

	catch (const char* e)
	{
		std::cout << "在转换向量出现了错误：" << e;
		return false;
	}
}
