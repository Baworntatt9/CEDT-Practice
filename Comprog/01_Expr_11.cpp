#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	double pi = 3.14159265358979323846;
	long fac = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
	double L = log(9.7);
	double cube = cbrt(2.3);
	double base = pow(1.2, cube);
	double ss = sin(40 * pi / 180);
	double no2 = (7 / sqrt(71)) - ss;
	double no1 = pi - (fac / pow(8, 8)) + pow(L, no2);

	double sum = no1 / base;

	cout << sum;
}