#include <iostream>
using namespace std;

#include "Calc.h"

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argc, argv);
 C->DisplayInFix();
 //C->Parse();

 return 0;
}
