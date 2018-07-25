#include <iostream>
using namespace std;

int main (){
	
	long long int a,b,x;
	
	cin >> a;
	cin >> b;
	cin >> x;	
	
	long long int count =1;
	
	long long int i = 1,j = 1, gcf = 0;
	
	while (j <= x || i <= x){
		
		if (i > j)
			j += b;
		else 
			i += a;

		if (j == i){
			gcf = i-1;
			count += (x-1)/gcf; 
			break;
		}
		
	}
	cout << count;
	
}
