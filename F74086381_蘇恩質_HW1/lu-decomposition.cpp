#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstdio>
using namespace std;
int main(){
	int i, j, k, count;
	float pivot_row;
	bool check_P = true;
	int m, n;
	int num_case;
	
	ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);

	input >> num_case;
	output << num_case << endl;
	while(num_case != 0){
		input >> m >> n;
		float P[m][m];
		float L[m][m];
		float U[m][n];
		for(i = 0; i < m; i++){//initial U by A
			for(j = 0; j < n; j++){
				input >> U[i][j];
			}
		}
		
		for(i = 0; i < m; i++){//initial P, L
			for(j = 0; j < m; j++){	
				(i == j)?P[i][j] = 1:P[i][j] = 0;
				(i == j)?L[i][j] = 1:L[i][j] = 0;
			}
		}

		for(i = 0; i < m-1; i++){//creat L and U
			for(j = i+1; j < m; j++){
			    pivot_row = U[j][i]/U[i][i];
				for(k = i; k < n; k++){
					L[j][i] = pivot_row;
					U[j][k] = U[j][k] + U[i][k]*pivot_row*(-1);
				}
			}
			if(i < m-2 && U[i+1][i+1] == 0){//check if A = PLU, creat P, adjust L and U
				check_P = false;
				for(j = i+2; i < m; j++){
					if(U[j][i+1] != 0){
						for(k = i+1; k < n; k++){
							int temp_U[k];
							temp_U[k] = U[i+1][k];
							U[i+1][k] = U[j][k];
							U[j][k] = temp_U[k];
							int temp_P[k];
							temp_P[k] = P[i+1][k];
							P[i+1][k] = P[j][k];
							P[j][k] = temp_P[k];
						}
						int temp_L;
						temp_L = L[j][i];
						L[j][i] = L[i+1][i];
						L[i+1][i] = temp_L;
					}
					break;
				}
			}
		}
		
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				
			}
		}
				
		if(check_P == true){//print
			output << "True" << endl << m << " " << m << endl;
			for(i = 0; i < m; i++){
				for(j = 0;j < m; j++){
					output << fixed << setprecision(2) << L[i][j] << " ";
				}
				output << endl;
			}
			output << m << " " << n << endl;
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					output << fixed << setprecision(2)  << U[i][j] << " ";
				}
				output << endl;
			}
		}
		
		if(check_P == false){
			output  << "False" << endl << m << " " << m << endl;
			for(i = 0; i < m; i++){
				for(j = 0; j < m; j++){
					output << fixed << setprecision(2) << P[i][j] << " ";
				}
				output << endl;
			}
			output << m << " " << m << endl;
			for(i = 0; i < m; i++){
				for(j = 0; j < m; j++){
					output << fixed << setprecision(2) << L[i][j] << " ";
				}
				output << endl;
			}
			output << m << " " << n << endl;
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					output << fixed << setprecision(2) << U[i][j] << " ";
				}
				output << endl;
			}
		}
		
		check_P = true;
		--num_case;
	}
	
	system("pause");
	return 0;
} 
