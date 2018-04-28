// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(false);
	int N, X;
	string com;		// for input command 
	cin >> N;
	while(N--){
		cin >> com;
		if(com=="push"){				// push 
			cin >> X;
			stk.push(X);
		} else if(com=="pop") {		// pop
			if(stk.empty()) cout << "-1\n";	
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
		} else if(com=="size"){		// size
			cout << stk.size() << "\n";
		} else if(com=="empty"){	// empty
		
			if(stk.empty()) cout << "1\n";
			else cout << "0\n";
		} else {							// top
			if(stk.empty()) cout << "-1\n";
			else cout << stk.top() << "\n";
		}
	}
	return 0;
}
