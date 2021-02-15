#pragma once
#include<iostream>
#include<vector>
#include "InputFormat.h"
#include<exception>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include<fstream>

/**
 * @brief ͨ����������������������ά��
 * @param inputConvertVector    �������飬�������ң����ϵ��²�ɢ����
 * @param inputConvertConvolutionkernel    ����������������������������������Ƿ�����
 *
 * @return ����˵��
 *     ���ɹ�������true
 */


bool Convert1Dto2D(InputConvertVector inputVector, InputCalculateVector& outputVector)
{

	try
	{
		//InputCalculateVector FormatedInputConvolutionkernel;
		InputCalculateVector FormatedInputVector;

		
		int VectorNumberEveryLine;//����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1
		//int ConvolutionkernelNumberEveryLine;//�����ÿ�еĳ��� ��Ϊ2���Ҹ���Ϊ����ʱ����������Ҫ��1

		//TryTimes CalculateTimes;//��������Ҫ����Ĵ���

		//���ÿ�о�������˵ĳ���
		VectorNumberEveryLine = inputVector.Vector.size() / inputVector.lines;
		//ConvolutionkernelNumberEveryLine = inputConvolutionkernel.Vector.size() / inputConvolutionkernel.lines;

		//�����Ϊ2���Ҹ���Ϊ����ʱ������������Ҫ��1
		if (inputVector.lines == 2 && inputVector.Vector.size() % 2 == 1)
		{
			VectorNumberEveryLine += 1;
		}
		/*
		if (inputConvolutionkernel.lines == 2 && inputConvolutionkernel.Vector.size() % 2 == 1)
		{
			ConvolutionkernelNumberEveryLine += 1;
		}
		*/
		//������ʼ��С����ʱ
		//FormatedInputConvolutionkernel.Vector.resize(inputVector.lines);
		FormatedInputVector.Vector.resize(inputVector.lines);

		//������ά����ĳ�ʼ��С����ͬ
		/*
		for (long i = 0; i < 100; i++)
		{
			FormatedInputConvolutionkernel.Vector[i].resize(100);
		}
		*/

		for (long i = 0; i < inputVector.lines; i++)
		{
			FormatedInputVector.Vector[i].resize(VectorNumberEveryLine);
		}


		//���������������Ҫ����Ĵ���
		//CalculateTimes.horizontalTimes = VectorNumberEveryLine - ConvolutionkernelNumberEveryLine + 1;
		//CalculateTimes.verticalTimes = inputVector.lines - inputConvolutionkernel.lines + 1;

		//�����������˵��ܴ�С
		int VectorTotalNumber = VectorNumberEveryLine * inputVector.lines;
		//int ConvolutionkernelTotalNumber = ConvolutionkernelNumberEveryLine * inputConvolutionkernel.lines;

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
		/*
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
		*/

		//FormatedInputConvolutionkernel.VectorNumberEveryLine = ConvolutionkernelNumberEveryLine;
		FormatedInputVector.VectorNumberEveryLine = VectorNumberEveryLine;

		//FormatedInputConvolutionkernel.lines = inputConvolutionkernel.lines;
		FormatedInputVector.lines = inputVector.lines;

		//outputConvolutionkernel = FormatedInputConvolutionkernel;
		outputVector = FormatedInputVector;

		return true;
	}

	catch (const char* e)
	{
		std::cout << "��ת�����������˴���" << e;
		return false;
	}
}

bool ConvertImagetoVector(const cv::String PictureAddress)
{
	auto VectorData = cv::imread(PictureAddress);
	std::ofstream out;
	out.open("./Data.txt");
	out << VectorData << std::endl;
	return true;
}
template<typename _Tp>
cv::Mat Vector2Mat(std::vector<_Tp> v, int channels, int rows)
{
	cv::Mat mat = cv::Mat(v);//��vector��ɵ��е�mat
	cv::Mat dest = mat.reshape(channels, rows).clone();//PS������clone()һ�ݣ����򷵻س���
	return dest;
}


template<typename _Tp>
std::vector<_Tp> Mat2Vector(const cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//ͨ�������䣬����תΪһ��
}