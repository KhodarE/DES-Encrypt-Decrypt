// Information Security Assignment DES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include <cctype>
#include <bitset>
#include <stdio.h>
using namespace std;


//Create variables Plaintext and Key. So user can input into program

char plaintext[16], key[16], key1[16], key2[16], temp[16], tempEncrypt[16], epEncrypt[8], epEncryptA[16], keyOneEncrypt[16];
char key1A[16], key2A[16];
char s1A[4], s2A[4], s3A[4], s4A[4];

int cnt = 0;
int cntKey2 = 0;
int cntEncrypt = 0;
int i;

int IP[16] = { 3,5,10,9,16,8,7,1,14,12,2,13,4,11,6,15 };

int IP1[16] = { 8,11,1,13,2,15,7,6,4,3,14,10,12,9,16,5 };

int EP[16] = { 5,7,3,2,8,4,6,1,1,6,4,8,2,3,7,5 };

int P8[8] = { 2,6,3,1,4,5,8,7 };

int P20[16] = { 5,2,9,12,1,19,10,3,8,11,7,17,4,15,6,20 };

int P16[16] = { 11,2,13,8,9,14,6,10,16,1,5,12,3,7,15,4 };

int s1[4][4] = { {1,0,3,2},
				{3,2,1,0},
				{0,2,1,3},
				{3,1,3,2} };

int s2[4][4] = { {0,1,2,3},
				{2,0,1,3},
				{3,0,1,0},
				{2,1,0,3} };

int s3[4][4] = { {0,3,2,1},
				{1,0,3,2},
				{3,2,0,1},
				{2,3,0,1} };

int s4[4][4] = { {3,2,0,1},
				{0,3,1,2},
				{2,1,0,3},
				{1,2,3,0} };


int main()
{
	//PROGRAM CALCULATES KEY 1 and Key 2
	cout << "THIS PROGRAM WILL CALCULATE KEY 1 & KEY 2" << endl << endl;

	//Checks if the Plaintext is 16-bits
	cout << "(20-bits) Enter Key: ";
	cin >> key;
	cout << endl;

	//Applying P20
	for (i = 0; i < 16; i++)
	{
		cnt = P20[i];
		temp[i] = key[cnt - 1];
	}
	cout << "P20 key: ";
	for (i = 0; i < 16; i++)
	{
		cout << (P20[i]) << ",";
	}

	//Bits after applying P20
	cout << endl << "Apply P20 to Key: " << temp << endl << endl;

	//Calculating LS-1 on first half
	for (i = 0; i < 16; i++) 
	{
		if (i == 7)
		{
			temp[i] = temp[i];
		}
		if (i <= 6)
		{
			temp[i] = temp[i + 1];
		}
	}

	//Performing LS-1 on second half
	for (i = 8; i < 16; i++)
	{
		if (i == 15)
		{
			temp[i] = temp[9];
		}
		if (i <= 14)
		{
			temp[i] = temp[i + 1];
		}
	}
	cout << "LS-1: " << temp << endl << endl;

	//Calculating Key 1
	cout << "P16 key: ";
	for (i = 0; i < 16; i++)
	{
		cout << P16[i] << ",";
	}

	//Applying P16 to get Key 1
	for (i = 0; i < 16; i++)
	{
		cnt = P16[i];
		key1[i] = temp[cnt - 1];
	}
	cout << endl << "Key 1: " << key1 << endl << endl;

	//Calculating LS-2 on first half 
	for (i = 1; i <= 8; i++)
	{
		if (i == 6)
		{
			temp[i] = temp[0];
		}
		if (i == 7)
		{
			temp[i] = temp[3];
		}
		if (i <= 5)
		{
			temp[i] = temp[i + 2];
		}
	}

	//Performing LS-2 on second half
	for (i = 8; i < 16; i++)
	{
		if (i == 14)
		{
			temp[i] = temp[7];
		}
		if (i == 15)
		{
			temp[i] = temp[8];
		}
		if (i == 16)
		{
			temp[i] = temp[9];
		}
		if (i < 13)
		{
			temp[i] = temp[i + 2];
		}
	}
	cout << "LS-2: " << temp << endl;

	//Applying P16 to get Key 2
	for (i = 0; i < 16; i++)
	{
		cnt = P16[i];
		key2[i] = temp[cnt - 1];
	}
	cout << endl << "Key 2: " << key2 << endl << endl << endl;


//----------------------------------------------------------------------

	//START ENCRYPTION

	cout << "THIS PROGRAM WILL CALCULATE ENCRYPTION" << endl << endl;
	cout << "(16-bits) Plaintext: ";
	cin >> plaintext;
	cout << endl;

	//Applying IP
	for (i = 0; i < 16; i++)
	{
		cntEncrypt = IP[i];
		tempEncrypt[i] = plaintext[cntEncrypt - 1];
	}
	cout << "IP: ";
	for (i = 0; i < 16; i++)
	{
		cout << (IP[i]) << ",";
	}

	//Bits after applying IP
	cout << endl << "Apply IP to Plaintext: " << tempEncrypt << endl << endl;

	//Outputting E/P array
	cout << "E/P: ";
	for (i = 0; i < 16; i++)
	{
		cout << (EP[i]) << ",";
	}
	cout << endl;

	//Get the Second Half of IP and store it in E/P
	for (i = 0; i < 8; i++) 
	{
		if (i < 8)
		{
			epEncrypt[i] = tempEncrypt[i + 8];
		}
	}
	cout << "Second Half of IP: " << epEncrypt << endl;

	//Calculating E/P and storing it in KeyOneEncrypt Array
	for (i = 0; i < 16; i++)
	{
		cntEncrypt = EP[i];
		//Applying E/P to Second half of IP
		epEncryptA[i] = epEncrypt[cntEncrypt - 1];
	}
	//We get E/P
	cout << "E/P: " << epEncryptA << endl;

	cout << "(XOR) Key 1:" << key1;
	 





	////////To get Key 1 we use Key 1 from Key Generator and do XOR with (E/P or Key 1)
	//////for (i = 0; i < 16; i++) 
	//////{
	//////	if (i < 16)
	//////	{
	//////		keyOneEncrypt[i] ^ temp[i];
	//////	}
	//////}
	////////cout << "(XOR) Key 1:" << temp;






	return 0;
}

