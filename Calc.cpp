/*
Class: CPSC 122-02 
Team Member 1: Tanner Franz 
Team Member 2: Wesley Muehlhausen
Submitted By: Tanner Franz 
GU Username: tfranz 
File Name:
List3 class functions to manipualte a linked list
To Build: g++ Calc.cpp, CalcTst.cpp list1.cpp stack2.cpp
To Execute: ./a.out " <equation<" <value> <value>
*/

#include "CalcMine.h"
#include <iostream>

	Calc::Calc(int argcIn, char* argvIn[])
	{	cout << "construct" << endl;
		int i = 0;
		length = strlen(argvIn[1]);
		inFix = new char[strlen(argvIn[1])+1];
		while(i < length)
			{			
				inFix[i] = argvIn[1][i];
				i++;
			}
			inFix[i] = '\0';
			int a = 0;
cout << argcIn << endl;
	for(int c = 2; c < argcIn; c++)
				{
					cout << "for loop" << c << endl;
					values[a] = atoi(argvIn[c]);
					a++;
					cout << "bottom of for" << c << endl;
				}
		Parse();
		numArgs = argcIn;
	}


void Calc::DisplayInFix()
	{ cout << "Infix called" << endl;
		for(int i = 0; i < length; i++)
			cout << inFix[i];
		cout << endl;
		return;
	}

void Calc::Parse()
	{ cout << "called Parse()" << endl;
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
		int paren = 20;
		for(int i = 0; i < length; i++)
			{
				if(inFix[i] == '(')
					{
						paren ++;
						//stk->Push(inFix[i]);
					}
				else if (inFix[i] ==')')
					{
						//stk->Pop();
						paren--;
					}
			}
		
		if(paren == 20)
			{
				cout << "Even parens" << endl;
				return true;
			}
		cout << "Uneven parens" << paren << endl;
		return false;
	}


void Calc::InFixToPostFix()
	{cout << "infix called" << endl;
		int j = 0;
		int CP = 0;
    char operand;
		postFix = new char [length];
		for(int i = 0; i < length; i++)
			{ cout << "for loop " << i << endl;
				int priority = 0;
				if(inFix[i] == '+' ||inFix[i] == '-' || inFix[i] == '*' ||inFix[i] == '/'||inFix[i] == ')'||inFix[i] == '(')
				{
cout << " first if " << endl;
					stk->Push(inFix[i]);
	cout << "back in if" << endl;
				}
				else
					{
cout << "I made" << endl;
						postFix[j] = inFix[i];
						cout << "2";
						j++;
					}
cout << "B4 while" << endl;
cout << "Peek " <<stk->Peek();
			if(i>0)
				{
					int temp = PEMDAS(stk->Peek());
cout << "After PEMDAS CALL 1" << endl;
				while(temp > priority)
					{
cout << "in while" << endl;
						postFix[j]=	stk->Peek();
cout << "after peek";
						stk->Pop();
cout << "after pop";
					}
				}
cout << "eofor" << endl;
			}
				/*if(stk->Peek() == ')')
					{cout << "if2";
					stk->Pop();
					postFix[j] == stk->Peek();
					stk->Pop(); 
					j++;
					}*/
						}

	
	



void Calc::BuildHash()
	{
		hashTble = new int[26];
		FillHash();
		return;
	}


void Calc::FillHash()
	{ int letter;
		int j = 0;
		for(int i =0; i < length; i++)
			{
				if(inFix[i] >= 65 && inFix[i] <=90)
					{PutHash(values[j], inFix[i]);
						//letter  = (inFix[i]%65);
						//hashTble[letter] = values[j];
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
	
void Calc:: DisplayPostFix()
	{
		cout << "\n POSTFIX\n";
		for(int r = 0; r < length; r++)
			{
				cout << postFix[r];
			}
	}
void Calc:: Evaluate()
	{	
		for(int i = 0; i < length; i++)
			{
	
			
			}
	
}

int Calc:: PEMDAS(char ch)	
	{
cout << "PEMDAS CALLED" << endl;
		int priority;
		if(ch == '+' ||ch == '-')
			priority = 1;
		else if(ch == '/'||ch == '*')
			priority = 2;
		else if(ch == '('||ch ==')')
			priority = 0;
		else
			priority = 0;
		return priority;
	}

		











