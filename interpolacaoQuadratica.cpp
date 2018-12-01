/* 	
	by Adriano Zanella Junior
	ANN - CCT - UDESC
	30/11/2018
*/
#include <iostream>
#include <cmath>

using namespace std;

void printMatriz3x3( double M[3][3]);
void printMatriz3x1( double M[3]);

int main(){
	double A[3][3];
	double b[3];

	double pontos[3][2];
	double an[3];

	int x = 0;
	int y = 1;
	double v;

	int i, j;
	
	cout << "Interpolação Quadrática\n";

	pontos[0][x] = 1;
	pontos[0][y] = 1;
	pontos[1][x] = 5;
	pontos[1][y] = 15;
	pontos[2][x] = 7;
	pontos[2][y] = 16;
	

	/*
	pontos[0][0] = 20;
	pontos[0][1] = 1.013;
	pontos[1][0] = 30;
	pontos[1][1] = 1.122;
	pontos[2][0] = 40;
	pontos[2][1] = 1.213;
	*/
	for(i = 0; i < 3; i++){
		cout << "P(" << pontos[i][x] << ", " << pontos[i][y] << ")\n";
		b[i] = pontos[i][y];
	}

	for ( i =0 ; i < 3; i++){
		for ( j = 0; j < 3; j++){
			A[i][j] = pow( pontos[i][x], j);
		}
	}

	printMatriz3x3(A);
	printMatriz3x1(b);

	for( i = 0; i < 3; i++){
		A[1][i] -= A[0][i];
		A[2][i] -= A[0][i]; 
	}
	b[1] -= b[0];
	b[2] -= b[0];

	//printMatriz3x3(A);
	//printMatriz3x1(b);

	v = A[2][1] / A[1][1];
	for ( i = 1; i < 3; i++)
		A[2][i] -= v * A[1][i];
	b[2] -= v * b[1];
	
	cout << " ---------- Pos Pivotacao ---------- " << "\n";
	
	printMatriz3x3(A);
	printMatriz3x1(b);

	an[2] = b[2] / A[2][2];
	an[1] = (b[1] - an[2] * A[1][2]) / A[1][1];
	an[0] = (b[0] - an[2] * A[0][2] - an[1] * A[0][1]) / A[0][0];

	cout << "Vetor a" << "\n";
	printMatriz3x1(an);

	cout << "F(x) = " << an[0] << " + " << an[1] << "x + " << an[2] << "x²";

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