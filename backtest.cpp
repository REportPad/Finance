#include<iostream>
using namespace std;

void State(double r, double invest[], int state, int lev[]) {
	invest[0] = invest[0] * (1 + state * (lev[0] * r));
	invest[1] = invest[1] * (1 - state * (lev[1] * r));
}


double rebalancing(double invest[], double param[], int num) {
	double total = 0;
	for (int i = 0; i < num; ++i) {
		total += invest[i];
	}

	for (int i = 0; i < num; ++i) {
		invest[i] = total * param[i];
	}

	return total;
}

void StatePrint(double total, double invest[], int num) {
	cout << "total: " << total << endl;
	for (int i = 0; i < num; ++i) {
		cout << "invest[" << i << "]: " << invest[i] << endl;
	}
	cout << endl;
}