#include <iostream>
using namespace std;

#include "CalcMine.h"

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argc, argv);
 C->DisplayInFix();
 return 0;
}
