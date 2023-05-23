#include <iostream>
#include <bitset>
using namespace std;
int a = 15, b = 6, c = 3;
short v;

int main() {
	b = (a % 3 == 0 && a % 10 == 5) ? 1 : 0;
	cout << b;
}