/* 	
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	10/09/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float fe = M_E;
	float fx1 = 2; // f(2) > 0
	float fx2 = 3.5; // f(3.5) < 0
	float fxr = 0;
	float frsp = 0;
	int nitmax, nit;

	cout << "Bissecção" << "\n";
	cout << "Precisão e=-8" << "\n";
	cout << "f(x) = x^3 + sen(x^2) - x^4/e" << "\n";

	nitmax = 6;

	cout << nitmax << " vezes\n";
	nit = 0;
	cout << "x1 = " << fx1 << ".\tx2 = " << fx2 << ".\n";
	while (nit < nitmax){
		fxr = abs(fx1 - fx2)/2 + fx1;
		frsp = pow( fxr, 3) + sin( pow(fxr,2)) - pow(fxr,4)/fe;
		if (frsp < 0){
			fx1 = fxr;
		}else if (frsp > 0){
			fx2 = fxr;
		}else{
			break;
		}
		cout << nit+1 << ": x1 = " << fx1 << ".\tx2 = " << fx2 << ".\n";
		nit++;
	}

	return 0;
}