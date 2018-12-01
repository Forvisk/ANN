/*
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	30/11/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

double getNT( double b, double a);
double func( double x);

int main(){
	double b = 1, a = 0;
	double n = getNT(b, a); // numero recomendado de Trapézios
	double h = (b - a) / n;
	double sumFx = 0, resp = 0;;
	int i;

	cout << "Método dos Trapézios Compostos\n";

	cout << "\n\tFunção utilizada: f(x) = e^(x^3) - x^3" << "\n";
	cout << "\tDerivada segunda: f''(x) = 6 * x * e^(x^3) + 9 * x^4 * e^(x^3) -6 * x" << "\n";
	cout << "\tIntervalo [ 0, 1]" << "\n";
	cout << "\tErro de 10^-6" << "\n";
	cout << "\tNumero de trapézios recomendado: " << n << "\n";
	cout << "\th =  " << h << "\n";

	sumFx += func( a);
	for( i = 1; i < n-1; i ++){
		sumFx += 2 *func(a + i * h);
	}
	sumFx += func(b);
	resp = sumFx * (h / 2);

	cout << "Resultado: " << resp << "\n\n";


	cout << "\tNumero de trapézios: " << 1 << "\n";
	n = 1;
	h = (b - a);
	cout << "\th =  " << h << "\n";
	sumFx = 0;
	sumFx += func( a);
	
	for( i = 1; i < n-1; i ++){
		sumFx += ( 2 *func(a + i * h));
		cout << "---";
	}
	sumFx += func(b);
	resp = sumFx * (h / 2);

	cout << "Resultado: " << resp << "\n";
	
	return 0;
}


double getNT( double b, double a){
	double fe = M_E;
	double maxF = 6* fe + 9 * fe - 6;
	double n;
	cout << "máximo de f''(x) com x entre [ 0,1] é com x = 1 "<< "\n";
	cout << "max f''(x) com x entre [0, 1] é 1,7182818" << "\n";

	n = sqrt( maxF * pow(b-a, 3) * pow(10, 6) / 12);
	return round(n) + 1;
}

double func( double x){
	double fe = M_E;
	return ( pow(fe, pow( x, 3)) - pow( x, 3));
}