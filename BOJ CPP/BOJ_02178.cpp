// https://www.acmicpc.net/problem/2178
#include <cstdio>
#include <queue>
using namespace std;
int N,M;
int map[101][101]={0,}, temp[101][101]={0,};
const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};
queue<int> Q;
void prt();

void bfs(){
	temp[0][0]=1;
	Q.push(0);
	Q.push(0);
	
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		int y = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0 || nx>=N || ny<0 || ny>M) continue;
			if(map[nx][ny]==1 && temp[nx][ny]==0){
				temp[nx][ny] = temp[x][y]+1;
				Q.push(nx);
				Q.push(ny);
			}			
		}
	}
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &map[i][j]);
	bfs();
	printf("%d", temp[N-1][M-1]);
	return 0;
}
