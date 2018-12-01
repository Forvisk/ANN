/*
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	30/11/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

double getA( double syx, double sy, double sx, double sx2, int n);
double getB( double sy, double sx, double a, int n);

int main(){
	double pontos[10][2];
	double syx = 0, sy = 0, sx = 0, sx2 = 0; 

	int i, j;
	int x = 0, y = 1;
	int n = 10;
	double a = 0;
	double b = 0;

	cout << "Método da Ajuste de Curvas\n";

	pontos[0][x] = 1.32;
	pontos[0][y] = 20.46;
	pontos[1][x] = 4.08;
	pontos[1][y] = 30.19;
	pontos[2][x] = 4.62;
	pontos[2][y] = 53.10;
	pontos[3][x] = 6.64;
	pontos[3][y] = 63.14;
	pontos[4][x] = 7.57;
	pontos[4][y] = 95.29;
	pontos[5][x] = 8.89;
	pontos[5][y] = 115.89;
	pontos[6][x] = 10.00;
	pontos[6][y] = 100.00;
	pontos[7][x] = 11.03;
	pontos[7][y] = 133.83;
	pontos[8][x] = 13.68;
	pontos[8][y] = 163.74;
	pontos[9][x] = 16.32;
	pontos[9][y] = 188.31;


	for(i = 0; i < n; i++){
		cout << "P(" << pontos[i][x] << ", " << pontos[i][y] << ")\n";
		syx += pontos[i][x] * pontos[i][y];
		sx += pontos[i][x];
		sy += pontos[i][y];
		sx2 += pow( pontos[i][x], 2);
	}
	cout <<  "\tS(yx) = " << syx << "; Sx = " << sx << "; Sy = " << sy << "; Sx² = " << sx2 << ".\n"; 
	
	a = getA( syx, sy, sx, sx2, n);
	b = getB( sy, sx, a, n);


	cout << "f(x) = " << b << " + " << a << "x\n";

	cout << "Residuos:" << "\n";
	for ( i = 0; i < 10; i++){
		cout << "\tr" << (i+1) << " = " << pontos[i][y] << " - " << (b + a * pontos[i][x]);
		cout << " = " <<   pontos[i][y] - (b + a * pontos[i][x]) << "\n";
	}
	return 0;
}

double getA( double syx, double sy, double sx, double sx2, int n){
	return (syx - sx * sy / n) / (sx2 - sx * sx / n);
}

double getB( double sy, double sx, double a, int n){
	return (sy / n - a * sx / n);
}