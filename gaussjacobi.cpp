/* 	
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	23/10/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

void printMatriz3x3( double M[3][3]);
void printMatriz3x1( double M[3]);
bool criterioParada( double X0[3], double X1[3], double ed);

int main(){

	const int n = 3;
	const double ed = 0.000001; // 10^-6
	int i, j;
	int k = 3;

	double A[3][3];
	double L[3];
	double D[3];
	double U[3];
	double b[3];
	double X_k1[3]; // x k+1
	double X_k[3];	// x k

	cout << "Método de Gauss-Jacobi\n";

	cout << "Utilizaremos a seguinte matriz matriz:" << "\n";
	cout << "A = \t|  3  4  5 |\n" << "\t|  6  7  8 |\n" << "\t|  9 10 11 |\n";
	cout << "E utilizaremos:\n" << "b = \t| 12 |\n" << "\t| 13 |\n" << "\t| 14 |\n";

	cout << "Chite inicial sera:\n";
	cout << "x[0] =\t|  3/12 |\n" << "\t|  6/13 |\n" << "\t| 11/14 |\n";

	/* Alimenta matriz A*/
	for( i = 0; i < 3; i++)
		for( j = 0; j < 3; j++){
			A[i][j] = k;
			k++;
		}
	/* Alimenta matrizes b, o x0 e D*/
	for( i = 0; i < 3; i++){
		b[i] = k;
		X_k[i] = A[i][i]/b[i];

		X_k1[i] = X_k[i];
		D[i] = A[i][i];
		k++;
	}

	/* Alimenta L e U*/
	L[0] = A[0][1];
	L[1] = A[1][0];
	L[2] = A[2][0];
	U[0] = A[0][2];
	U[1] = A[1][2];
	U[2] = A[2][1];

	printMatriz3x3(A);
	printMatriz3x1(X_k);
/*	//Teste da função
	if ( criterioParada( X_k, X_k1, ed))
		cout << "ok";
	else
		cout << "not ok";
*/
	k = 0;
	cout << "\n------- Iniciando Iterações -------\n";
	//while( k < 3){	// teste 3 iterações
	do{
		for( i = 0; i < 3; i++)
			X_k[i] = X_k1[i];
		
		for( i = 0; i < 3; i++){
			X_k1[i] = b[i];
			if ( i != 0)
				X_k1[i] -= L[i]*X_k[0];
			else
				X_k1[i] -= L[i]*X_k[1];

			if ( i != 2)
				X_k1[i] -= U[i]*X_k[2];
			else
				X_k1[i] -= U[i]*X_k[1];

			X_k1[i] = X_k1[i]/D[i];
		}
		cout << " k = " << k << "\n";
		cout << "Matriz X(k+1)\n";
		printMatriz3x1(X_k1);
		k++;
	/*
	if ( criterioParada( X_k, X_k1, ed))
		cout << "ok";
	else
		cout << "not ok";*/
	}while ( (!criterioParada( X_k, X_k1, ed)) && (k < 100));
	cout << "\n------- Finalizando Iterações na "<< k << "-esima iteração -------\n";
	return 0;
}

void printMatriz3x3( double M[3][3]){
	int i, j;

	cout << "\nImprimindo Matriz\n" << "M = ";
	for( i = 0; i < 3; i++){
		cout << "\t| ";
		for( j = 0; j < 3; j++){
			printf("%02lf ", M[i][j]);
		}
		cout << "|\n";
	}
}


void printMatriz3x1( double M[3]){ 
	int j;

	cout << "\nImprimindo Matriz\n" << "M = ";
	for( j = 0; j < 3; j++){
		printf("\t| %lf |\n", M[j]);
	}
}

bool criterioParada( double X0[3], double X1[3], double ed){
	double max = 0, aux = 0;
	int i = 0;

	for ( i = 0; i < 3; i++){
		aux = abs( X1[i] - X0[i]);
		if ( aux > max){
			max = aux;
		}
	}

	return ( max < ed);
}