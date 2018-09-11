/*
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	10/09/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

double funcao( float x);
double derfuncao( float x);

int main(){
	float fe = M_E;
	float fx1 = -0.7;
	float fx2 = 0;

	double func_finit;
	int itmax = 10, it = 0;

	cout << "Newton-Raphson" << "\n";
	cout << "Precisão e=-8" << "\n";
	cout << "f(x) = x^3 + sen(x^2) - x^4/e" << "\n";

	func_finit = funcao(fx1);

	cout << "f(" << fx1 << ") = " << func_finit << "\n";

	do{
		fx2 = fx1 - funcao(fx1) / derfuncao(fx1);
		if (abs(fx2 - fx1) < pow(10,-8) || abs(funcao( fx2)) < pow(10,-8)){
			cout << "break iteracao " << it << "\n";
			break;
		} else {
			fx1 = fx2;
		}
		it++;
	} while(it < itmax);


	if ( abs( func_finit) < abs( funcao(fx2))){
		cout << "A função diverge, método não eficiente para o caso" << "\n";
	}
	cout << "final f (" << fx2 << ") = " << funcao(fx2) << "\n";
	return 0;
}

double funcao( float x){
	float fe = M_E;
	return pow( x, 3) + sin( pow(x,2)) - pow(x,4)/fe;
}

double derfuncao( float x){
	float fe = M_E;
	return 3*pow( x, 2) + cos( pow(x,2))* 2*x -4*pow(x,3)/fe;
}