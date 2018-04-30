// https://www.acmicpc.net/problem/1620
// I was failed when I use cin and cout
// And success when I change scanf and printf from cin and couot
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<int, string>> S, S2;
bool cmp(const pair<int,string> &A, const pair<int,string> &B){
   return A.second.compare(B.second)<0;
}
int main(){
	int N, M;
	char tempchar[22];
	string temp;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", tempchar);
		temp = tempchar;
		S.push_back(make_pair(i+1, temp));
	}
	S2=S;
	// sort by string(pokemon's name)
	sort(S2.begin(), S2.end(), cmp);
	
	for(int i=0; i<M; i++){
		scanf("%s", tempchar);
		temp=tempchar;
		if(temp[0]>='0' && temp[0]<='9'){
			// Indexing
			int num = stoi(temp);
			printf("%s\n", S[num-1].second.c_str());
		} else {
			// Binary Search
			int start=0, end=N-1;
			while(start<=end){
				int mid = (start+end)/2;
				int res = S2[mid].second.compare(temp);
				if(res<0){
					start = mid+1;
				} else if (res>0){
					end = mid-1;
				} else {
					printf("%d\n", S2[mid].first);
					break;
				}			
			}			
		}
	}
	return 0;
}
