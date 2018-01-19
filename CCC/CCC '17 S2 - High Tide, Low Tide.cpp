#include <iostream>
using namespace std;

int sort (int *tide,int lo,int hi){

	if (lo >= hi)
		return 0;
		
	int pivot = tide[lo];
	int j =lo, temp; 
	for (int i = lo;i <= hi;i++){
		if (tide[i] <= pivot){
			temp = tide [i];
			tide[i] = tide[j];
			tide[j] = temp;
			j++;
		}
	}
	temp = tide[j-1];
	tide[j-1] = tide[lo];
	tide[lo] = temp;
	
	sort(tide,lo,j-2);
	sort(tide,j,hi);
	
}




int main (){
	
	int n;
	cin >>n;
	
	int tide[n];
	for (int i = 0;i < n;i++)
		cin >> tide[i];
	
	int hi = n-1, lo=0;
	
	sort (tide,lo,hi);

	for (int i = 0; i < n/2+1;i++){
		if ((n-1)/2-i == -1)
			break;
		printf ("%d ",tide[(n-1)/2-i]);
		if ((n-1)/2+i+1 == n)
			break;
		printf ("%d ",tide[(n-1)/2+i+1]);	
		
	}
	
	
	
}
