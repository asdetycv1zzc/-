#pragma once
#include<iostream>
#include<vector>
std::vector<int> RandomGenerator(long Geshu)
{
	std::vector<int> rand_num;
	rand_num.resize(Geshu);
	for (int x = 0; x < Geshu; x++)
	{
		rand_num[x] = rand() % 1000;
	}
	return rand_num;
}
