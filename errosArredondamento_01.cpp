/* 	
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	04/08/2018
*/
#include <iostream>

using namespace std;

int main(){
	float val = 0;
	cout << "Multiplicar 0.0003 10000 (dez mil) vezes" << endl;

	for( int i = 0; i < 10000; i++)
		val = val + 0.0003;

	cout << val << " != 3" << endl;

	val = 0;
	cout << "Multiplicar 0.0078125 10000000 (10 milhoes) vezes" << endl;

	for( int i = 0; i < 10000000; i++)
		val = val + 0.0078125;

	cout << val << " == 78125" << endl;

	return 0;
}