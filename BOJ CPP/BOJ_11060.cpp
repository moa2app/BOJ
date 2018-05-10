// https://www.acmicpc.net/problem/11060
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int A[1201];
vector<int> dp[1201];
int main(){
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
		dp[i].push_back(99999);			// push in max value 
	}
	for(int i=0; i<N; i++){
		for(int j=1; j<=A[i]; j++){
			dp[i+j].push_back(i);
		}
	}
	dp[0][0]=0;
	for(int i=0; i<N; i++){
		for(int j=1; j<dp[i].size(); j++){
			if(dp[i][0] > dp[dp[i][j]][0]+1)
				dp[i][0] = dp[dp[i][j]][0]+1;
		}
	}
	if(dp[N-1][0]==99999) cout << "-1";	// if can't reach end point, print "-1"
	else 	cout << dp[N-1][0];				// of print minimun step
	return 0;
}
