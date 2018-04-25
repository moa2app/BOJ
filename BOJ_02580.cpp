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
			if(garo[i][j]==0 || sero[i][j]==0 || nemo[i][j]==0) return -1;
		}
	}
	return 1;
}

int check_in(int step, int num){
	if(garo[BK[step].I][num]==1) return -1;
	if(sero[BK[step].J][num]==1) return -1;
	if(nemo[(BK[step].I/3)*3+(BK[step].J/3)][num]==1) return -1;
	return 1;
}
void solve(int step){
	if(step>=blank_count){
		if(check_sudoku()==1){
			print_sudoku();
			//exit(0);
		}
		return;
	}
	for(int i=1; i<=9; i++){
		if(garo[BK[step].I][i]==0 && sero[BK[step].J][i]==0 && nemo[(BK[step].I/3)*3+(BK[step].J/3)][i]==0){
			map[BK[step].I][BK[step].J]=i;
			garo[BK[step].I][i]=1;
			sero[BK[step].J][i]=1;
			nemo[(BK[step].I/3)*3+(BK[step].J/3)][i]=1;
			
			solve(step+1);
			map[BK[step].I][BK[step].J]=0;
			garo[BK[step].I][i]=0;
			sero[BK[step].J][i]=0;
			nemo[(BK[step].I/3)*3+(BK[step].J/3)][i]=0;
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
				BK[blank_count].I=i;
				BK[blank_count].J=j;
				blank_count++;
			} else {
				garo[i][map[i][j]] = 1;
				sero[j][map[i][j]] = 1;
				nemo[(i/3)*3+(j/3)][map[i][j]] = 1;
			}
		}
	}
	solve(0);
	print_sudoku();
	return 0;
}
