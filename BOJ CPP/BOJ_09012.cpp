// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		bool check = true;
		string S;
		stack<int> stk;
		cin >> S;
		for(int i=0; i<S.length(); i++){
			// push the index when S[i] is '('
			if(S[i]=='(') stk.push(i);
			else {
				// print "NO" when S[i] is ')' and stack is empty
				if(stk.empty()){
					check=false;
					break;
				} else {
					// pop stack when S[i] is ')' and stack is non-empty
					// because complete '(' + ')' , remove one pair "()"
					stk.pop();
				}
			}
		}
		// stack is still non-empty or number of ')' is more than number of '(' 
		if(!stk.empty() || !check) cout << "NO\n";
		// search the string at all index and stack is empty
		else cout << "YES\n";
	}
	return 0;
}
