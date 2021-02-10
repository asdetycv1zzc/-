#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
#include<exception>

/**
 * @brief ͨ����������������������ά��
 * @param inputConvertVector    �������飬�������ң����ϵ��²�ɢ����
 * @param inputConvertConvolutionkernel    ����������������������������������Ƿ�����
 *
 * @return ����˵��
 *     ���ɹ�������true
 */


bool Convert(InputConvertVector inputVector,InputConvertConvolutionkernel inputConvolutionkernel, InputCalculateVector& outputVector, InputCalculateConvolutionkernel& outputConvolutionkernel)
{

	try
	{
		InputCalculateConvolutionkernel FormatedInputConvolutionkernel;
		InputCalculateVector FormatedInputVector;

		//������ʼ��С����ʱ
		FormatedInputConvolutionkernel.Vector.resize(100);
		FormatedInputVector.Vector.resize(100);

		//������ά����ĳ�ʼ��С����ͬ
		for (long i = 0; i < 100; i++)
		{
			FormatedInputConvolutionkernel.Vector[i].resize(100);
		}

		for (long i = 0; i < 100; i++)
		{
			FormatedInputVector.Vector[i].resize(100);
		}

		int VectorNumberEveryLine;//����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1
		int ConvolutionkernelNumberEveryLine;//�����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1

		TryTimes CalculateTimes;//��������Ҫ����Ĵ���

		//���ÿ�о�������˵ĳ���
		VectorNumberEveryLine = inputVector.Vector.size() / inputVector.lines;
		ConvolutionkernelNumberEveryLine = inputConvolutionkernel.Vector.size() / inputConvolutionkernel.lines;

		//�����Ϊ2���Ҹ���Ϊ����ʱ������������Ҫ��1
		if (inputVector.lines == 2 && inputVector.Vector.size() % 2 == 1)
		{
			VectorNumberEveryLine += 1;
		}
		if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.Vector.size() % 2 == 1)
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
		std::cout << "��ת�����������˴���" << e;
		return false;
	}
}
