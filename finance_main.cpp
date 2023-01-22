#include <iostream>
#include"backtest.h"

using namespace std;

#define N 3//the number of stock

/*void State(double r, double invest[], int state, int lev[]);
double rebalancing(double invest[], double param[], int num);
void StatePrint(double total, double invest[], int num);
*/

int main(){
	//initial value setting
	double total = 3100;
	double param[N] = {0.5, 1./6., 1. / 3.};//stock, inverse, cash
	double invest[N] = {0,};
	int lev[2] = {1,2};//leverage
	for (int i = 0; i < N; ++i) {
		invest[i] = total * param[i];
	}

	//state printe
	StatePrint(total, invest, N);

	//1. increase +x%
	double r = 0.1; //+10%
	State(r, invest, 1, lev);//1: increase, -1: decrease
	total = rebalancing(invest, param, N);	//rebalancing
	StatePrint(total, invest, N);	//result print

	//2. decrease -x%
	State(r, invest, -1, lev);//1: increase, -1: decrease
	total = rebalancing(invest, param, N);
	StatePrint(total, invest, N);

	return 0;
}

/*
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
}*/