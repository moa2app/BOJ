// https://www.acmicpc.net/problem/10845
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int N, X;
	string com;
	queue<int> q;
	cin >> N;
	while(N--){
		cin >> com;
		if(com=="push"){
			cin >> X;
			q.push(X);
		} else if (com=="pop"){
			if(q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		} else if (com=="size"){
			cout << q.size() << "\n";
		} else if (com=="empty"){
			if(q.empty()) cout << "1\n";
			else cout << "0\n";
		} else if (com=="front"){
			if(q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		} else if (com=="back"){
			if(q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		} else {
			continue;
		}	
	}
	return 0;
}
