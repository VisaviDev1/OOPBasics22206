#include "Module1.h"
#include "Module2.h"
#include "my_module.h"
#include <iostream>
using std::cout;

int main(void)
{
	cout << "Hello, world!" << '\n';
	
	cout << Module1::getMyName() << '\n';
	cout << Module2::getMyName() << '\n';

	using namespace Module1;
	cout << getMyName() << '\n';//(A)
	cout << Module2::getMyName() << '\n';
	
	//using namespace Module2;//(B)
	//cout << getMyName() << '\n'; //COMPIL.ERROR
	using Module2::getMyName;
	cout << getMyName() << '\n'; // (D)

	//Work with my_module.h
	cout << MyModule::getMyName() << '\n';

	return 0;
}