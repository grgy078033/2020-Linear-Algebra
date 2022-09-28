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
	output << num_case << endl;
	while(num_case != 0){
		input >> m >> n;
		int count;
		float a[m][n];
		float A[m][n];
		float Q[m][n];
		float R[n][n];
		float temp_A = 0;
		float temp_qa = 0;
		float temp_arr[m][1];
		float temp_R;
		for(int i = 0; i < m; ++i){
			temp_arr[m][0] = 0;
		}
		for(int i = 0; i < m; ++i){//initial A & Q
			for(int j = 0; j < n; ++j){
				input >> a[i][j];
				Q[i][j] = 0;
				A[i][j] = 0; 
			} 
		}
		for(int i = 0; i < n; ++i){//initial R
			for(int j = 0; j < n; ++j){
				R[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n; ++i){
			count = i;
			temp_A = 0;
			while(count > 0){
				for(int l = 0; l < m; ++l){
					temp_qa += Q[l][i-count] * a[l][i];
				}
				for(int k = 0; k < m; ++k){
					temp_arr[k][0] += temp_qa * Q[k][i-count];
				}
				temp_qa = 0;
				--count;
			}
			for(int j = 0; j < m; ++j){
				A[j][i] = a[j][i] - temp_arr[j][0];
			}
			for(int j = 0; j < m; ++j){
				temp_A += A[j][i] * A[j][i];
			}
			for(int j = 0; j < m; ++j){
				Q[j][i] = A[j][i] / sqrt(temp_A);
			}
			for(int j = 0; j < m; ++j){
				temp_arr[j][0] = 0;
			}
		}
		count = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < count; ++j){
				for(int k = 0; k < m; ++k){
					R[j][i] += Q[k][j] * a[k][i];
				}
			}
			++count;
		}
		output << m << " " << n << endl;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				output << fixed << setprecision(2) <<  Q[i][j] << " "; 
			}
			output << endl;
		}
		output << n << " " << n << endl;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				output << fixed << setprecision(2) << R[i][j] << " ";
			}
			output << endl;
		}
		num_case--;
	}
	return 0;
} 
