/*
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	10/09/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

bool pivotacaoGaus( double A[3][3], double b[3], int n);
void printMatriz3x3( double M[3][3]);
void printMatriz3x1( double M[3]);

int main(){
	double mA[3][3];
	double b[3];
	int n = 3;
	int i, j;
	int k = 3;
	// Ax = b

	cout << "Método da Pivotação de Gaus\n";

	cout << "Utilizaremos a seguinte matriz matriz:" << "\n";
	cout << "A = \t|  3  4  5 |\n" << "\t|  6  7  8 |\n" << "\t|  9 10 11 |\n";
	cout << "E utilizaremos:\n" << "b = \t| 12 |\n" << "\t| 13 |\n" << "\t| 14 |\n";

	/* Alimenta matriz A*/
	for( i = 0; i < 3; i++)
		for( j = 0; j < 3; j++){
			mA[i][j] = k;
			k++;
		}
	/*	Alimenta Matriz b 	*/
	for( i = 0; i < 3; i++){
		b[i] = k;
		k++;
	}

	pivotacaoGaus( mA, b, n);
	return 0;
}

bool pivotacaoGaus( double A[3][3], double b[3], int n){
	bool ret = true;
	int i, j;
	double L[3][3], U[3][3];
	double div1, div2, div3;

	double y[3], x[3];

	printMatriz3x3(A);
	printMatriz3x1(b);

	/* Pivotacao */
	div1 = A[1][0] / A[0][0];
	div2 = A[2][0] / A[0][0];
	for ( i = 0; i < 3; i++){
		A[1][i] -= A[0][i] * div1;
		A[2][i] -= A[0][i] * div2;
	}
	/*
	cout << "A 1 Pivotado" << "\n";
	printMatriz3x3(A);
	*/
	div3 = A[2][1] / A[1][1];
	for ( i = 1; i < 3; i++){
		A[2][i] -= A[0][i] * div3;
	}

	cout << "Div1 = " << div1 << "; Div2 = " << div2 << "; Div3 = " << div3 << ".\n"; 

	A[1][0] = div1;
	A[2][1] = div3;
	A[2][0] = div2;

	cout << "A Pivotado" << "\n";
	printMatriz3x3(A);

	for ( i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			L[i][j] = 0;
			U[i][j] = 0;
		}

	for (i = 0; i < 3; i ++){
		for (j = 0; j <= i; j++)
			if (i != j)
				L[i][j] = A[i][j];
			else
				L[i][j] = 1;
	}
	for (i = 0; i < 3; i ++){
		for (j = i; j < 3; j++)
			U[i][j] = A[i][j];
	}
	
	cout << "Lower" << "\n";
	printMatriz3x3(L);

	cout << "Upper Pivotado" << "\n";
	printMatriz3x3(U);

	/*	Ly = b 	*/
	y[0] = b[0];
	y[1] = b[1] - L[1][0] * y[0];
	y[2] = b[2] - L[2][0] * y[0] - L[2][1] * y[1];

	cout << "Vetor Y";
	printMatriz3x1(y);

	/*	Ux = y	*/
	x[2] = y[2] / U[2][2];
	x[1] = ( y[1] - x[2] * U[1][2]) / U[1][1];
	x[0] = ( y[0] - x[2] * U[0][2] - x[1] * U[0][1]) / U[0][0];
	
	cout << "Vetor X";
	printMatriz3x1(x);

	return ret;
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
	cout << "\n";
}


void printMatriz3x1( double M[3]){ 
	int j;

	cout << "\nImprimindo Matriz\n" << "M = ";
	for( j = 0; j < 3; j++){
		printf("\t| %lf |\n", M[j]);
	}
	cout << "\n";
}