#include <iostream>
#include"Header.h"

using namespace std;

int main()
{
	Stack stack;
	std::string str = "1+(2+3)*4";
	std::string str1 = stack.postfix(str);
	int eva = stack.evaluation(str1);
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;
	std::cout << eva;
}


