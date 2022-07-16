#include <iostream>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;

void factor(unsigned long long int n) {
	int a, d;
	a = 2;
	d = 0;
	set <int> s;

	for (int i = 1; i < 100000; i++) {
		a = (a ^ i) % n;
		d = std::gcd(a - 1, n);
		if (d > 1 && d < n)
			s.insert(d);
			
	}
	for (int i = 0; i = s.size(); i++) {
		cout << s.[i] << " , ";
	}
}

int main() {
	unsigned long long int n = 1;

	while (n != 0) {
		cout << "Input 0 to exit \n";
		cout << "Input the number to b factored: ";
		cin >> n;
		factor(n);
	}
	cout << "Thanks for Playing \n";
	return 0;
}