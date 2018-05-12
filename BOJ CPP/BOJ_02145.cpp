// https://www.acmicpc.net/problem/2145
#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int N;
	while(1){
		cin >> N;
		if(N==0) break;
		while(N>=10){
			int temp=N;
			N=0;
			while(temp>0){
				N+=temp%10;
				temp/=10;
			}
		}
		cout << N << "\n";
	}
	return 0;
}
