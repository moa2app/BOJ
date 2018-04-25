// https://www.acmicpc.net/problem/2580
// this code is Time Limit Exceeded
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct blank{
	int I=0;
	int J=0;
	int room=0;
	int can_count=0;
	int can[10]={0,};
} BLANK;
bool comp (BLANK, BLANK);
void print_sudoku();
int check_room(int, int);
void get_can(int);
int check_sudoku();
void solve(int);

BLANK BK[100];
int map[9][9];
int blank_count, blank_just_one;
int complete_sudoku=0;

bool comp (BLANK a, BLANK b){
    return a.can_count < b.can_count;
}
void print_sudoku(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
int check_room(int i, int j){
	if(i<3){
		if(j<3) return 1;
		else if(j<6) return 2;
		else return 3;
	} else if(i<6){
		if(j<3) return 4;
		else if(j<6) return 5;
		else return 6;
	} else {
		if(j<3) return 7;
		else if(j<6) return 8;
		else return 9;
	}
}

void get_can(int start){
	int input[10];
	for(int i=start; i<blank_count; i++){
		fill_n(input, 10, 0);
		// check the across 
		for(int j=0; j<9; j++){
			input[map[BK[i].I][j]]=1;
		}
		// check the down
		for(int j=0; j<9; j++){
			input[map[j][BK[i].J]]=1;
		}
		// check the square
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				input[map[((BK[i].room-1)/3)*3+j][((BK[i].room-1)%3)*3+k]]=1;
			}
		}
		// fill can array  
		BK[i].can_count=0;
		for(int j=1; j<10; j++){
			if(input[j]==0){
				BK[i].can[BK[i].can_count++]=j;
			}
		}
	}
}
int check_sudoku(){
	int temp[10];
	for(int i=0; i<9; i++){
		fill_n(temp, 10, 0);
		for(int j=0; j<9; j++){
			if(temp[map[i][j]]>0) return -1;
			else temp[map[i][j]]=1;
		}
	}
	for(int i=0; i<9; i++){
		fill_n(temp, 10, 0);
		for(int j=0; j<9; j++){
			if(temp[map[j][i]]>0) return -1;
			else temp[map[j][i]]=1;
		}
	}
	for(int i=1; i<=9; i++){
		fill_n(temp, 10, 0);
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(temp[map[((i-1)/3)*3+j][((i-1)%3)*3+k]]>0) return -1;
				else temp[map[((i-1)/3)*3+j][((i-1)%3)*3+k]]=1;
			}
		}
	}
	return 1;
}

int check_in(int step, int num){
	for(int j=0; j<9; j++){
		if(num==map[BK[step].I][j]) return -1;
		if(num==map[j][BK[step].J]) return -1;
	}
	for(int j=0; j<3; j++){
		for(int k=0; k<3; k++){
			if(num==map[((BK[step].room-1)/3)*3+j][((BK[step].room-1)%3)*3+k]) return -1;
		}
	}
	return 1;
}
void solve(int step){
	if(step>=blank_count){
		if(check_sudoku()==1){
			print_sudoku();
			exit(0);
		}
		return;
	}
	for(int i=0; i<BK[step].can_count; i++){
		if(check_in(step, BK[step].can[i])==1){
			map[BK[step].I][BK[step].J]=BK[step].can[i];
			solve(step+1);
			map[BK[step].I][BK[step].J]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	blank_count=blank_just_one=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> map[i][j];
			if(map[i][j]==0){
				BK[blank_count].I=i;
				BK[blank_count].J=j;
				BK[blank_count].room = check_room(i, j);
				blank_count++;
			}
		}
	}
	
	get_can(0);
	sort(BK,BK+blank_count,comp);
	for(int i=0; i<blank_count; i++){
		blank_just_one=i;
		if(BK[i].can_count==1){
			map[BK[i].I][BK[i].J]=BK[i].can[0];
		} else break;
	}
	solve(blank_just_one);
	print_sudoku();
	return 0;
}
