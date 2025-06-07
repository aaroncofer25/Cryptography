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
        for (int val : s) {
                cout << val << " , ";
        }
}

int main() {
        unsigned long long int n = 0;

        while (true) {
                cout << "Input 0 to exit \n";
                cout << "Input the number to b factored: ";
                cin >> n;
                if (n == 0)
                        break;
                factor(n);
        }
        cout << "Thanks for Playing \n";
        return 0;
}
