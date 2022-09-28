#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int num_case, m, n;
	ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);
	input >> num_case;
	cout << num_case;
	while(num_case!=0){
		input >> m >> n;
		float A[m][n];
		float A_t[n][m];
		float temp_A[n][n];
		float U[m][m];
		float D[m][n];
		float V[n][n];
		
		for(int i = 0; i < m; ++i){//initialize A AT D
			for(int j = 0; j < n; ++j){
				input >> A[i][j];
				A_t[j][i] = A[i][j];
				D[i][j] = 0;
			}
		}
		for(int i = 0; i < m; ++i){//initialize U
			for(int j = 0; j < m; ++j){
				U[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i){//initialize V & ATA
			for(int j = 0; j < n; ++j){
				V[i][j] = 0;
				temp_A[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n; ++i){//find ATA
        	for(int j = 0; j < n; ++j){
            	for(int k = 0; k < m; ++k){
                	temp_A[i][j] += A_t[i][k] * A[k][j];
            	}
        	}
    	}
    	
    	

		
		
		--num_case;
	}

	return 0;
}
