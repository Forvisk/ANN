/* 	
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	28/08/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float val, tval = 0;
	float e = M_E;
	float x = 3;
	double n = 1;
	cout << "Serie de McLaurin com f(x) = (cos(x) + e^x) e x = 3" << endl;

	val = 2; // cos(0) = 1, e^0 = 1
	for( int i = 1; i < 15; i++){
		n = n*i;
		//cout << n << ", " << pow(x,i) << "\n";
		switch(i % 4){ // e^0 = 1
			case 1:
				val += (pow(x,i))/n; // sin(0) = 0
				break;
			case 2:
				val += 0; // -cos(0) = -1
				break;
			case 3:
				val += (pow(x,i))/n; // -sin(0) = 0
				break;
			default:
				val += (pow(x,i))/n; // cos(0) = 1
				break;
		}
	}
	tval = cos(x*M_PI/180) + pow(e,3);

	cout << "Valor calculado pela série: "<< val << ". Valor calculado pela função cos(x)+e³ : "<< tval << "." <<  endl;

	return 0;
}