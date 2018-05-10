// https://www.acmicpc.net/problem/10809
#include <iostream>
#include <string>
using namespace std;
string S;
int al[26];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> S;
	for(int i=0; i<26; i++) al[i]=-1;
	for(int i=0; i<S.length(); i++){
		if(al[S[i]-'a']==-1) al[S[i]-'a']=i;
	}
	for(int i=0; i<26; i++) cout << al[i] << " ";
	return 0;
}
