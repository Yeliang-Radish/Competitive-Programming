#include <iostream>
#include <string.h>
using namespace std;

/*
void strrev (char *s){
	
	char cpy[100005];
	strcpy (cpy,s);	
	int i = strlen(s)-1,j=0;
	
	while (i != -1){
		s[j] = cpy[i];
		i--;
		j++;
	}
	
}
*/


int main (){
	
	int n;

	scanf ("%d",&n);
	
	
	int flow = 0, end = 0,i;
	char temp[100005];
	int neg = 0,big;
	
	for (int j = 0;j < n;j++){
		
		char eq[2][100005];
		char sol[100005];
		scanf ("%s",eq[0]);
		scanf ("%s",eq[1]);
		
		//if both positive
		if (eq[0][0] != '-' && eq[1][0] != '-'){
			strrev (eq[0]);
			strrev (eq[1]);
			for (i = 0;i < 100005;i++){
				if (eq[0][i] == 0 && eq[1][i] == 0)
					break;
				if (eq[0][i] == 0 && end == 2)
					break;
				else if (eq[0][i] == 0)
					end = 1;
				if (eq[1][i] == 0 && end == 1)
					break;
				else if (eq[1][i] == 0)
					end = 2;
				if (end == 1)
					eq[0][i] = '0';
				else if (end == 2)
					eq[1][i] = '0';
			
				sol[i] = ((eq[0][i] -'0')+(eq[1][i] -'0') + flow) + '0';
				if (sol[i]-'0' >= 10){
					flow = 1;
					sol[i] -=10;
				} 
				else if (sol[i]-'0' < 10)
					flow = 0;
			}
			if (flow == 1){
				sol[i] = 1 + '0';
				i++;
				sol[i] = 0;
			}
			sol[i] = 0;
			//reset
			flow = 0;
			end = 0;
			strrev(sol);
		}
		//if double negatives
		else if (eq[0][0] == '-' && eq[1][0] == '-'){
		
			strrev (eq[0]);
			strrev (eq[1]);
			for (i = 0;i < 100005;i++){
				if (eq[0][i] == '-' && eq[1][i] == '-')
					break;
				if (eq[0][i] == '-' && end == 2)
					break;
				else if (eq[0][i] == '-')
					end = 1;
				if (eq[1][i] == '-' && end == 1)
					break;
				else if (eq[1][i] == '-')
					end = 2;
				if (end == 1)
					eq[0][i] = '0';
				else if (end == 2)
					eq[1][i] = '0';
			
				sol[i] = ((eq[0][i] -'0')+(eq[1][i] -'0') + flow) + '0';
				if (sol[i]-'0' >= 10){
					flow = 1;
					sol[i] -=10;
				} 
				else if (sol[i]-'0' < 10)
					flow = 0;
			}
			if (flow == 1){
				sol[i] = 1 + '0';
				i++;
			}
			sol[i] = '-';
			i++;
			sol[i] = 0;	
			
			//reset
			flow = 0;
			end = 0;
			strrev(sol);
		}
		// if one is negative
		else if ((eq[0][0] == '-' && eq[1][0] != '-') || (eq[0][0] != '-' && eq[1][0] == '-')){
			
			if (eq[0][0] == '-'){
				neg = 1;
				strrev(eq[0]);
				eq[0][strlen (eq[0])-1] = 0;
				strrev(eq[0]);
			}
			else if (eq[1][0] == '-'){
				neg = 2;
				strrev (eq[1]);
				eq[1][strlen(eq[1])-1] = 0;	
				strrev (eq[1]);
			}
			if (strcmp (eq[0],eq[1]) == 0){
				sol[0] = '0';
				sol[1] = 0;
			}
			else{
				if (strlen(eq[1]) > strlen(eq[0])){
					strcpy(temp,eq[1]);
					strcpy(eq[1],eq[0]);
					strcpy(eq[0], temp);
					big = 2;
				}
				else if (strlen(eq[1]) < strlen(eq[0]))
					big = 1;
				else if (strlen(eq[1]) == strlen(eq[0])){
					if (strcmp(eq[0],eq[1]) < 0){
						strcpy(temp,eq[1]);
						strcpy(eq[1],eq[0]);
						strcpy(eq[0], temp);
						big = 2;	
					} else 
						big = 1;
				}
			
				strrev(eq[0]);
				strrev(eq[1]);

				for (i = 0;i < 100005;i++){
					if (eq[0][i] == 0)
						break;
					if (eq[1][i] == 0)
						end = 1;
					if (end == 1)
						eq[1][i] = '0';
					
					sol[i] = eq[0][i]-eq[1][i]+'0'+flow;
					
					if (sol[i] < '0'){
						sol[i] += 10;
						flow = -1;
					}
					else if (sol[i] >= '0')
						flow = 0;
				}	

				for (i -= 1;sol[i] == '0';i--);
				i++;
				if (big == neg){
					sol[i] = '-';
					i++;
				}
				sol[i] = 0;

				big = 0;
				neg = 0;
				flow = 0;
				end = 0;
				
				strrev (sol);
			}
		}
		cout << sol << endl;
	}	
	//END
	
	
}
