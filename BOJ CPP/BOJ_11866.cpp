// https://www.acmicpc.net/problem/11866
// Josephus Problem
#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int N, M;
	queue<int> Q;
	cin >> N >> M;
	for(int i=1; i<=N; i++) Q.push(i);
	cout<<'<';
	while(!Q.empty()){
		for(int i=1; i<M; i++){
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front();
		Q.pop();
		if(Q.empty()) break;
		cout<<", ";
	}
	cout<<'>';
	return 0;
}
