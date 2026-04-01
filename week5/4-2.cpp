#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int i;
	for (i = 1; i <= 100; i++) {
		cout << setw(3) << i << " : " << setw(6) << i * i << endl;
	
	}


	return 0;
}
