#include <iostream>
#include"backtest.h"

using namespace std;

#define N 3//the number of stock

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
