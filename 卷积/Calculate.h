#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
struct TryTimes
{
public:
	int horizontalTimes;//������Ҫ����Ĵ���
	int verticalTimes;//������Ҫ����Ĵ���
};
/**
 * @brief ͨ����������������������ά��
 * @param inputVector    �������飬�������ң����ϵ��²�ɢ����
 * @param inputConvolutionkernel    ����������������������������������Ƿ�����
 *
 * @return ����˵��
 *     ����һ������
 */

std::vector<int> Calculate(InputVector& inputVector,InputConvolutionkernel& inputConvolutionkernel)
{
	std::vector<int> FormatedInputVector, FormatedInputConvolutionkernel;

	int VectorNumberEveryLine;//����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1
	int ConvolutionkernelNumberEveryLine;//�����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1

	TryTimes CalculateTimes;//��������Ҫ����Ĵ���

	//���ÿ�о�������˵ĳ���
	VectorNumberEveryLine = inputVector.InputVector.size() / 2;
	ConvolutionkernelNumberEveryLine = inputConvolutionkernel.InputVector.size() / 2;

	//�����Ϊ2���Ҹ���Ϊ����ʱ������������Ҫ��1
	if (inputVector.lines == 2 && inputVector.InputVector.size() % 2 == 1)
	{
		VectorNumberEveryLine += 1;
	}
	if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.InputVector.size() % 2 == 1)
	{
		ConvolutionkernelNumberEveryLine += 1;
	}

	//���������������Ҫ����Ĵ���
	CalculateTimes.horizontalTimes = VectorNumberEveryLine - ConvolutionkernelNumberEveryLine + 1;
	CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;

	//�����������˵��ܴ�С
	int VectorTotalNumber = VectorNumberEveryLine * inputVector.lines;
	int ConvolutionkernelTotalNumber = ConvolutionkernelNumberEveryLine * inputConvolutionkernel.lines;

	//����תΪ��ά���鲢����
	for (long i = 0; i < inputVector.lines;i++)
	{
		for (long j = 0; i < VectorNumberEveryLine; i++)
		{
			FormatedInputVector[i][j] = inputVector.InputVector[]
		}
	}
}
