/*
Class: CPSC 122-02 
Team Member 1: Tanner Franz 
Team Member 2: Wesley Muehlhausen
Submitted By: Tanner Franz 
GU Username: tfranz 
File Name:proj8.cpp, proj8Tst.cpp
List3 class functions to manipualte a linked list
To Build: g++ proj8.cpp proj8Tst.cpp
To Execute: ./a.out
*/

#include "CalcMine.h"
#include <iostream>

	Calc::Calc(int argcIn, char* argvIn[])
	{	
		inFix = new char[strlen(argvIn[1])];
		length = strlen(argvIn[1]);
		int i = 0;
		while(i < length)
			{			
				inFix[i] = argvIn[1][i];
				i++;
			}
			inFix[i] = '\0';
			int a = 0;
			for(int c = 2; c < argcIn; c++)
				{
					values[a] = argvIn[c];
					a++;
				}
		Parse();
	}

void Calc::DisplayInFix()
	{ 
		for(int i = 0; i < length; i++)
			cout << inFix[i];
		cout << endl;
		return;
	}

void Calc::Parse()
	{ 
		BuildHash();
		if(CheckTokens()&&CheckParens())
			cout << "Valid Expression" << endl;
		else
			cout << "Invalid expression" << endl;
		return;
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
		int paren = 0;
		for(int i = 0; inFix[i]!= '\0'; i++)
			{
				if(inFix[i] == '(')
					{
					paren++;
					//stk->Push()
					}
				else if (inFix[i] ==')')
					{
					//stk->Pop();
					paren--;
					}
			}
		if(paren == 0)//stk->IsEmpty())
			{
				cout << "Even parens" << endl;
				return true;
			}
		cout << "Uneven parens" << paren << endl;
		return false;
	}


void Calc::InFixToPostFix()
	{
		int j = 0;
		int CP = 0;
		postFix = new char [strlen(inFix)];
		//infix read in;
		for(int i = 0; i < length; i++)
			{
				if(inFix[i] == '+' ||inFix[i] == '-' || inFix[i] == '*' ||inFix[i] == '/'||inFix[i] == ')'||inFix[i] == '(')
				{
					stk->Push(inFix[i]);
				}
				else
					{
					postFix[j] = inFix[i];
					j++;
					}


				if(stk->Peek() == ')')
					{
					stk->Pop();
					postFix[j] == stk->Peek();
					stk->Pop(); 
					j++;
					}
			}
		postlength = j;
	}



















void Calc::BuildHash()
	{
		hashTble = new int[26];
		FillHash();
		return;
	}


void Calc::FillHash()
	{
		int j = 0;
		for(int i =0; i < length; i++)
			{
				if(inFix[i] >= 65 && inFix[i] <=90)
					{
						hashTble[inFix[i]%65] = atoi(values[j]);//num;
						j++;
					}
				}
		return;
	}


void Calc::PutHash(int value, char letter)
	{
		int hashPlace;
		hashPlace = letter%65;
		hashTble[hashPlace] = value;
	}


int Calc::GetHash(char letter)
	{
		int num = 0;
		int hashPlace = 0;
		hashPlace = letter%65;
		num = hashTble[hashPlace];
		return num;
	}
void Calc::PrintHash()
	{
		for (int i = 0; i< 27; i++)
			cout << hashTble[i];
	}
	
