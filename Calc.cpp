#include "Calc.h"
#include <iostream>

	Calc::Calc(int argcIn, char* argvIn[])
	{
		length = strlen(argvIn[1]);
		inFix = argvIn[1];
		int i = 0;
		while(i < length)
			{			
				inFix[i] = argvIn[1][i];
				i++;
			}
			inFix[i] = '\0';
			argVG = argvIn;
	}

void Calc::DisplayInFix()
	{ 
		for(int i = 0; i < length; i++
			cout << inFix[i];
	cout << endl;
	return;
	}

void Calc::Parse(char* cmdLineInp[], int num_cmd_line_args)
	{
		CheckTokens();
		CheckParens();
		BuildHash()
	}

bool Calc::CheckTokens() 
	{
		int i = 0;
		while (i<length) 
			{
				if (inFix[i]== ')'||inFix[i] == '(' || inFix[i] == '+' ||inFix[i] == '-' || inFix[i] == '*' ||inFix[i] == '/' || inFix[i] >= 65|| inFix[i] <= 90)
				i++;
				else
					{
						cout << "Invlaid character in pos: " << i << endl;
						return false;
					}
			}
		return true;	
	}

bool Calc::CheckParens()
	{

		for(int i = 0; inFix[i] != NULL; i++)
			{
				if(inFix[i] == '(')
					stk->Push(inFix[i]);
				else if (inFix[i] ==')')
					stk->Pop();
			}
		if(stk->IsEmpty)
			{
				cout << "even";
				return true;
			}
		return false;
	}

void Calc::BuildHash(char* argvIn[])
	{
		hashTble = new int[26];
		
int j = 2;
		for(int i =0; i<length; i++)
			{
				if(argvIn[i] >= 65 || express[i] <=90)
					{
						int num = atoi(args[j]);
						hashTble[express[i]%65] = num;
						j++;
					}
				}
	
		return;
	}

void Calc::FillHash()
	{
		int j = 2;
		for(int i =0; express[i]!= NULL; i++)
			{
				if(express[i] >= 65 || express[i] <=90)
					{
						int num = atoi(args[j]);
						hashTble[express[i]%65] = num;
						j++;
					}
				}
		return;
	}


void Calc::PutHash(int value, int letter)
	{
		int hashPlace =0;
		hashPlace = letter%65;
		hashTble[hashPlac\g++] =value;
	}
int Calc::GetHash(char letter)
	{
		int num = 0;
		int hashPlace = 0;
		hashPlace = letter%65;
		num = hashTble[hashPlace];
		return num;
	}
	*/
