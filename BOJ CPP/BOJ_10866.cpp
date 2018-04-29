// https://www.acmicpc.net/problem/10866
#include <iostream>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int N, X;
	string com;
	deque<int> DQ;
	cin >> N;
	while(N--){
		cin>>com;
		if(com=="push_front"){
			cin >> X;
			DQ.push_front(X);
		} else if(com=="push_back"){
			cin >> X;
			DQ.push_back(X);
		} else if(com=="pop_front"){
			if(DQ.empty()) cout << "-1\n";
			else {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
		} else if(com=="pop_back"){
			if(DQ.empty()) cout << "-1\n";
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		} else if(com=="size"){
			cout << DQ.size() << "\n";
		} else if(com=="empty"){
			if(DQ.empty()) cout << "1\n";
			else cout << "0\n";
		} else if(com=="front"){
			if(DQ.empty()) cout << "-1\n";
			else cout << DQ.front() << "\n";
		} else if(com=="back"){
			if(DQ.empty()) cout << "-1\n";
			else cout << DQ.back() << "\n";
		} else {
			continue;
		}		
	}
	return 0;
}
