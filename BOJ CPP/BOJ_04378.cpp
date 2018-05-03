// https://www.acmicpc.net/problem/4378
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S;
string T = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
	ios_base::sync_with_stdio(false);
	while(getline(cin, S)){			// check End Of File
		for(int i=0; i<S.length(); i++){
			if(S[i]==' ') cout << " ";
			else {
				for(int j=0; j<T.length(); j++){
					if(T[j]==S[i]){
						cout << T[j-1];
						break;
					}
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
