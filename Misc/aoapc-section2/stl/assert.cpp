#include <bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));
	double random = rand() * 1.0 / RAND_MAX;
	int tarand = floor(random * 100);
	cout << tarand;
}