#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {
	int a = 2;
	a >>= 1;
	cout << a;
}


/*
	vector<int> a(10);
	iota(a.begin(), a.end(), 1);
	for (auto i : a) cout << i << " ";
	// 1 2 3 4 5 6 7 8 9 10
	cout << endl;
	rotate(a.begin() + 1, a.begin() + 3, a.begin() + 5);
	for (auto i : a) cout << i << " ";
*/