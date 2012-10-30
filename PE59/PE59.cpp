/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 59
 * Cracking XOR Encryption
 */

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>

//Frequency of letters a-z in the english language
const double frequency[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228,
							2.015, 6.094, 6.966, 0.153, 0.772, 4.025,
							2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
							6.327, 9.056, 2.758, 0.978, 2.360, 0.150,
							1.974, 0.074};

struct Cipher
{
	double variance;
	int cipher[3];
};

int main()
{
	bool asciiPossible;
	int result = 0;
	char curValue[3];
	double testFrequency[26];
	double testVariance = 0.0;
	std::vector<int> asciiList;
	std::vector<Cipher> cipherList;
	Cipher tempCipher;

	//Open cipher1.txt
	std::fstream inFile;
	inFile.open("cipher1.txt", std::fstream::in);

	//Take in ascii values
	while(inFile.getline(curValue, 3, ','))
	{
		asciiList.push_back(boost::lexical_cast<int>(curValue));	
	}

	//Create all 3-letter lower-case permutations
	//Lower-case letters have an ASCII value range from 97-122
	for(int i = 97, count = 0; i < 123; ++i)
	{
		for(int j = 97; j < 123; ++j)
		{
			for(int k = 97; k < 123; ++k, ++count)
			{
				tempCipher.cipher[0] = i;
				tempCipher.cipher[1] = j;
				tempCipher.cipher[2] = k;
				tempCipher.variance = 0;
				cipherList.push_back(tempCipher);
			}
		}
	}

	int endASCII = asciiList.size();
	int endCipher = cipherList.size();
	for(int i = 0; i < 10; ++i)
	{
		//Reset previous frequency numbers
		testVariance = 0.0;
		asciiPossible = true;
		for(int j = 0; j < 26; ++j)
		{
			testFrequency[j] = 0.0;
		}

		//First XOR pass
		for(int j = 0; j < endASCII; j += 3)
		{
			for(int k = 0; k < 3; ++k)
			{
				asciiList[j+k] ^= cipherList[i].cipher[k];
			}
		}

		//Frequency analysis
		for(int j = 0; j < endASCII; ++j)
		{
			if((asciiList[j] < 97) || (asciiList[j] > 122))
			{
				asciiPossible = false;
				break;
			}
			testFrequency[asciiList[j] - 97]++;	
		}
		if(asciiPossible)
		{
			for(int j = 0; j < 26; ++j)
			{
				testVariance += abs((testFrequency[j] / static_cast<double>(endASCII)) - frequency[j]);
			}
			cipherList[i].variance = testVariance;
		}
		else
		{
			cipherList[i].variance = 1000000.0;
		}
		std::cout << testVariance << std::endl;

		//Second XOR pass to reset
		for(int j = 0; j < endASCII; j += 3)
		{
			for(int k = 0; k < 3; ++k)
			{
				asciiList[j+k] ^= cipherList[i].cipher[k];
			}
		}
	}

	//Find ASCII values with the lowest variance
	testVariance = 10000000.0;
	for(int i = 0; i < endCipher; ++i)
	{
		if(cipherList[i].variance < testVariance)
		{
			result = i;
		}
	}

	std::cout << cipherList[result].cipher[0] << std::endl;
	std::cout << cipherList[result].cipher[1] << std::endl;
	std::cout << cipherList[result].cipher[2] << std::endl;

	inFile.close();
	return EXIT_SUCCESS;
}
