#include <iostream>
using namespace std;

int main (){
	
	long long int n,k;
	//n is # rabbit girls, k is group size
	cin >> n;
	cin >> k;
	
	long long int r = n%k;
	
	if (k > n)
		cout << k-n;
	else{
		if (k-r >= r)
			cout <<r;
		else
			cout <<k-r;
	}

	
}
