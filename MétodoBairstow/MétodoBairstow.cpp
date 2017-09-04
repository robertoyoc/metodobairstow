// MétodoBairstow.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void bairstow3(double a[]);

void bairstow4(double a[]);

void bairstow5(double a[]);

void divide(double *a, double raiz, double *divido, int el);
double chicharronera(double a, double b, double c, int r);


void main() {
	int grado;
	cout << "Introduce el grado de la ecuacion a resolver: " << endl;

	double coef3[4], coef4[5], coef5[6];

	coef3[0] = -22;
	coef3[1] = 32;
	coef3[2] = -11;
	coef3[3] = 1;

	coef4[0] = 24;
	coef4[1] = -50;
	coef4[2] = 35;
	coef4[3] = -10;
	coef4[4] = 1;

	coef5[0] = -120;
	coef5[1] = 274;
	coef5[2] = -225;
	coef5[3] = 85;
	coef5[4] = -15;
	coef5[5] = 1;


	cin >> grado;
	switch (grado)
	{
	case 3:
		bairstow3(coef3);
		break;
	case 4:
		bairstow4(coef4);
		break;
	case 5:
		bairstow5(coef5);
		break;
	default:
		cout << "Este grado aun no ha sido implementado." << endl;
		break;
	}

	system("pause");

}

void bairstow3(double a[]) {
	double es = 0.001;
	double b[4], c[4];
	double r = 1, s = -1;
	double dr, ds;
	double ear, eas;
	do {
		b[3] = a[3];
		b[2] = a[2] + r*b[3];

		for (int k = 1; k >= 0; k--) {
			b[k] = a[k] + r*b[k + 1] + s*b[k + 2];
		}

		c[3] = b[3];
		c[2] = b[2] + r*c[3];

		for (int k = 1; k >= 1; k--) {
			c[k] = b[k] + r*c[k + 1] + s*c[k + 2];
		}

		dr = (b[0] * c[3] - b[1] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		ds = (b[1] * c[1] - b[0] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		r = r + dr;
		s = s + ds;

		ear = abs(ds / r) * 100;
		eas = abs(ds / s) * 100;
	} while (eas > es&&ear > es);


	double r1, r2, r3;

	if ((r*r + 4 * s) >= 0) {
		r1 = (r + sqrt(r*r + 4 * s))/2;
		r2 = (r - sqrt(r*r + 4 * s)) / 2;
		cout << "Raiz 1: " << r1 << endl;
		cout << "Raiz 2: " << r2 << endl;

		double e2[3], e1[2];

		divide(a,r2, e2, 3);
		divide(e2, r1, e1, 2);
		if (e1[1] == 1) {
			cout << "Raiz 3: " << -1*e1[0] << endl;
		}
		else {
			cout << "Raiz 3: " << e1[0]/e1[1] << endl;
		}

	}
	else {
		cout << "Raiz imaginaria" << endl;
		cout << "Raiz 1: " << r/2 << "+" << sqrt(-1*(r*r + 4 * s)) / 2 << endl;
		cout << "Raiz 2: " << r/2 << "-" << sqrt(-1 * (r*r + 4 * s)) / 2 << endl;
	}





}

void bairstow4(double a[]) {
	double es = 0.001;
	double b[5], c[5];
	double r = 1, s = -1;
	double dr, ds;
	double ear, eas;
	do {
		b[4] = a[4];
		b[3] = a[3] + r*b[4];

		for (int k = 2; k >= 0; k--) {
			b[k] = a[k] + r*b[k + 1] + s*b[k + 2];
		}

		c[4] = b[4];
		c[3] = b[3] + r*c[4];

		for (int k = 2; k >= 1; k--) {
			c[k] = b[k] + r*c[k + 1] + s*c[k + 2];
		}

		dr = (b[0] * c[3] - b[1] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		ds = (b[1] * c[1] - b[0] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		r = r + dr;
		s = s + ds;

		ear = abs(ds / r) * 100;
		eas = abs(ds / s) * 100;
		
		
	} while (eas > es&&ear > es);



	double r1, r2, r3;
	r1 = (r + sqrt(r*r + 4 * s)) / 2;
	r2 = (r - sqrt(r*r + 4 * s)) / 2;
	cout << "Raiz 1: " << r1 << endl;
	cout << "Raiz 2: " << r2 << endl;

	double e3[4], e2[3];

	divide(a, r2, e3, 4);
	divide(e3, r1, e2, 3);

	cout << "Raiz 3: " << chicharronera(e2[2], e2[1], e2[0], 1) << endl;
	cout << "Raiz 4: " << chicharronera(e2[2], e2[1], e2[0], 2) << endl;



}

void bairstow5(double a[]) {
	double es = 0.001;
	double b[6], c[6];
	double r = 1, s = -1;
	double dr, ds;
	double ear, eas;
	do {
		b[5] = a[5];
		b[4] = a[4] + r*b[5];

		for (int k = 3; k >= 0; k--) {
			b[k] = a[k] + r*b[k + 1] + s*b[k + 2];
		}

		c[5] = b[5];
		c[4] = b[4] + r*c[5];

		for (int k = 3; k >= 1; k--) {
			c[k] = b[k] + r*c[k + 1] + s*c[k + 2];
		}

		dr = (b[0] * c[3] - b[1] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		ds = (b[1] * c[1] - b[0] * c[2]) / (c[2] * c[2] - c[1] * c[3]);

		r = r + dr;
		s = s + ds;

		ear = abs(ds / r) * 100;
		eas = abs(ds / s) * 100;


	} while (eas > es&&ear > es);

	double r1, r2, r3;
	r1 = (r + sqrt(r*r + 4 * s)) / 2;
	r2 = (r - sqrt(r*r + 4 * s)) / 2;
	cout << "Raiz 1: " << r1 << endl;
	cout << "Raiz 2: " << r2 << endl;

	double e4[5], e3[4];

	divide(a, r2, e4, 5);
	divide(e4, r1, e3, 4);

	bairstow3(e3);

}


void divide(double *a,double raiz, double *divido, int el) {
	int index = el - 1;
	divido[index] = a[index + 1];
	while (index > 0) {
		divido[index - 1] = raiz* divido[index] + a[index];
		index--;
	}
}
double chicharronera(double a, double b, double c, int r) {
	if(r==1)
		return (b*-1 + sqrt(b*b - 4 * a*c)) / (2 * a);
	else
		return (b*-1 - sqrt(b*b - 4 * a*c)) / (2 * a);
}
