#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	auto i{ 0x0E58 };
	string x{ " TFuocro" };
	while (i--) next_permutation(x.begin(), x.end());
	cout << x;
	cin.get();
}
