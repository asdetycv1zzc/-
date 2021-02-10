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

bool Convert(InputVector& inputVector,InputConvolutionkernel& inputConvolutionkernel)
{
	try
	{
		std::vector<std::vector<int>> FormatedInputVector, FormatedInputConvolutionkernel;

		//������ʼ��С����ʱ
		FormatedInputConvolutionkernel.resize(100);
		FormatedInputVector.resize(100);

		//������ά����ĳ�ʼ��С����ͬ
		for (long i = 0; i < 100; i++)
		{
			FormatedInputConvolutionkernel[i].resize(100);
		}

		for (long i = 0; i < 100; i++)
		{
			FormatedInputVector[i].resize(100);
		}

		int VectorNumberEveryLine;//����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1
		int ConvolutionkernelNumberEveryLine;//�����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1

		TryTimes CalculateTimes;//��������Ҫ����Ĵ���

		//���ÿ�о�������˵ĳ���
		VectorNumberEveryLine = inputVector.inputVector.size() / inputVector.lines;
		ConvolutionkernelNumberEveryLine = inputConvolutionkernel.inputVector.size() / inputConvolutionkernel.lines;

		//�����Ϊ2���Ҹ���Ϊ����ʱ������������Ҫ��1
		if (inputVector.lines == 2 && inputVector.inputVector.size() % 2 == 1)
		{
			VectorNumberEveryLine += 1;
		}
		if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.inputVector.size() % 2 == 1)
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
		std::cout << "��ת�����������˴���" << e.what;
		return false;
	}
}
