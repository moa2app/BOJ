// https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> A;
int main(){
	ios_base::sync_with_stdio(false);
	int N, x, y;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x >> y;
		A.push_back(make_pair(x, y));
	}
	sort(A.begin(), A.end());
	for(int i=0; i<N; i++) cout << A[i].first << " " << A[i].second << "\n";	
	return 0;
}
