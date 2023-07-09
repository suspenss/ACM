#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main () {
	set<i64> s;
	s.insert(1);
	set<i64>::iterator it = s.begin();
	for (int i = 0; i < 1500; i++) {
		i64 x = *it;
		s.insert(x * 2);
		s.insert(x * 3);
		s.insert(x * 5);
		it++;
	}
	it--;
	cout << "The 1500'th ugly number is " << *it << "." << endl;
}