#include <iostream>
using namespace std;

int main (){
	
	int score;
	cin >> score;
	
	int cost = 0,factor = 0, meme;
	
	while (score != 1){
		
		for (int i = 2;i <= score/2;i++){
			if (score%i == 0){
				factor = i;
				break;
			}
		}
		if (factor == 0){
			factor = 1;
			score -=1;
			cost += score;
			factor = 0;
			continue;
		}
		
		meme = score/factor;
		score -= meme;
		cost += score/meme;

		factor = 0;
	}
	cout << cost;
	
	
}
