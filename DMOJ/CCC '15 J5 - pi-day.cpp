#include <stdio.h>
#include <stdlib.h>

int visited [251][251][250];

int counter ( int n,int k,int min){
	
	if (visited[n][k][min] ==0){
		if (n == k || k == 1){
			visited [n][k][min] = 1;
		}
		else{
			for(int i = min;i <= n/k;i++){
				visited [n][k][min] += counter (n-i,k-1,i);
			}
		}
	}
	return visited [n][k][min];
}

int main (){
	
	int n, k;
	
	scanf ("%d",&n);
	scanf ("%d",&k);
	
	//int visited [n][k+1][n/k+1];
	
	for (int i = 1;i < n+1;i++)
		for ( int j = 1; j < k+1;j++)
			for (int f = 1;f < n;f++)
				visited[i][k][f] = 0; 
				
	printf ("%d",counter (n,k,1));

	
	
}


