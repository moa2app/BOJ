// https://www.acmicpc.net/problem/1213
#include <iostream>
#include <string>
using namespace std;
int alpha[26]={0};
string S;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> S;
	int odd_count=0, odd_index=0;
	for(int i=0; i<S.length(); i++){
		alpha[S[i]-'A']++;
	}
	for(int i=0; i<26; i++){
		if(alpha[i]%2==1){
			odd_count++;
			odd_index=i;
		} if(odd_count>1){			//	if odd number of alphabet is more than two, exit program
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
	for(int i=0; i<26; i++){
		for(int j=0; j<alpha[i]/2; j++) cout << char('A'+i);
	}
	if(odd_count>0){
		cout << char('A'+odd_index);
	}
	for(int i=25; i>=0; i--){
		for(int j=0; j<alpha[i]/2; j++) cout << char('A'+i);
	}
	return 0;
}
