// https://www.acmicpc.net/problem/2580
#include <iostream>
using namespace std;
typedef struct blank{
	int I=0;
	int J=0;
} BLANK;
void print_sudoku();
int check_sudoku();
void solve(int);

BLANK BK[100];
int map[9][9];
int blank_count;
int garo[10][10] = { 0, }, sero[10][10] = { 0, }, nemo[10][10] = { 0, };

void print_sudoku(){
	cout << '\n';
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){cout << map[i][j] << ' ';}
		cout << '\n';
	}
}

int check_sudoku(){
	for(int i=0; i<9; i++){
		for(int j=1; j<=9; j++){
			// check if exist blank more than one 
			if(across[i][j]==0 || down[i][j]==0 || square[i][j]==0) return -1;
		}
	}
	return 1;
}

// solve's base is dfs or backtracking
void solve(int step){
	// check the sudoku is complete when step(solve's depth) is equal(or greater than) number of blank 
	if(step>=blank_count){
		if(check_sudoku()==1){
			print_sudoku();
			exit(0);
		}
		return;
	}
	// check the suitable number(1~9) 
	for(int i=1; i<=9; i++){
		// return false if num is exist in either accross, down, or square
		if(across[BK[step].I][i]==0 && down[BK[step].J][i]==0 && square[(BK[step].I/3)*3+(BK[step].J/3)][i]==0){
			map[BK[step].I][BK[step].J]=i;
			across[BK[step].I][i]=1;
			down[BK[step].J][i]=1;
			square[(BK[step].I/3)*3+(BK[step].J/3)][i]=1;
			
			solve(step+1);
			// must reset to 0
			map[BK[step].I][BK[step].J]=0;
			across[BK[step].I][i]=0;
			down[BK[step].J][i]=0;
			square[(BK[step].I/3)*3+(BK[step].J/3)][i]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	blank_count=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> map[i][j];
			if(map[i][j]==0){
				// if input data is blank, add it to BLANK 
				BK[blank_count].I=i;
				BK[blank_count].J=j;
				blank_count++;
			} else {
				// input data is not blank, check the data in across, down, and square
				across[i][map[i][j]] = 1;
				down[j][map[i][j]] = 1;
				square[(i/3)*3+(j/3)][map[i][j]] = 1;
			}
		}
	}
	// start solve
	solve(0);
	print_sudoku();
	return 0;
}
