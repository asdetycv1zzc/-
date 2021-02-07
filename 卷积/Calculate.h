#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
/**
 * @brief 通过数组卷积来计算向量（二维）
 * @param inputVector    输入数组，从左至右，从上到下拆散排列
 * @param inputConvolutionkernel    输入数组的行数（向量的行数），无论是否整除
 *
 * @return 返回说明
 *     返回一个数组
 */
std::vector<int> Calculate(InputVector inputVector,InputConvolutionkernel inputConvolutionkernel)
{
	std::vector<int> FormatedInputVector, FormatedInputConvolutionkernel;
	for (long i = 0; i < (inputVector.lines - 1);i++)
	{

	}
}
