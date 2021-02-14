#pragma once
#include<iostream>
#include<vector>
std::vector<int> RandomGenerator(long Geshu)
{
	std::vector<int> rand_num;
	rand_num.resize(Geshu);
	std::vector<int> result;
	for (int x = 0; x < Geshu; x++)
	{
		rand_num.push_back(rand() % 100);
	}
	return result;
}
