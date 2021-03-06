/*
Class: CPSC 122-01
Paul De Palma
GU Username: depalma
Submitted By: Paul De Palma
GU Username: depalma
File Name: proj10.h
To Execute: ./calc "(A+B) 7 12
*/

#ifndef CALC_H
#define CALC_H

#include<cstring>
#include <iostream>
#include "stack2.h"

using namespace std;

class Calc 
{ 
  public: 
  /* 
  pre: none 
  post: instance of calculator created. valid in-fix expression stored in 
        inFix. symbolTlble create
        symbolTble created 
  */
  Calc(int agrcIn, char* argvIn[]);

  /*
  pre: instance of calculator exists. 
  post: displays the infix expression
 */
  void DisplayInFix();
 
  /*
  pre: instance of calculator exists and infix expression has been transformed
       to postfix 
  post: postfix exression displayed 
 */
  void DisplayPostFix();
 
  /*
  pre: instance of calculator exists. 
  post: infix expression transformed to postfix and stored in memory pointed to by the member variable postfix
 */
  void InFixToPostFix();

  /*
  pre: instance of calculator exists. valid postfix expr. has been created
  post: post fix expression has been evaluated and displayed on the screen
 */
  void Evaluate();

 private:

	/*
	
	*/
	void BuildHash();

	void FillHash();
	int GetHash(char letter);
	void PutHash(int value, char letter);
	void PrintHash();

  /*
  pre:  invoked from constructor
  post: 1) command line input has been a) checked for balanced parentheses
        b) checked for valid input. 2) symbolTble has been constructed  
	3) inFix holds a valid in fix expression
  */
	void Parse();
  

  /*
  pre:  instance of calculator exists
  post: return true if all characters in the infix expression are legal,
        false otherwise  Legal characters are ')', '(', '+','-','*','/',
        'A' ... 'Z'   
  */
  bool CheckTokens(); 

  /*
   pre:  instance of calculator exists and all input tokens are legal
   post: Using the technique discussed in class, returns true if parentheses
         are balanced, false otherwise 
  */
  bool CheckParens();
 
 int postlength;
	int length;			//length of argv[1] expression
	int numArgs;		// added to have class access to argc
  Stack* stk;
  char*  inFix;    //null-terminated string that holds infix expression  
  char*  postFix;  //null-terminated string that holds the post-fix
  int*   hashTble; //pointer to symbolTable holding expression values
	char* values[];
};
#endif 

