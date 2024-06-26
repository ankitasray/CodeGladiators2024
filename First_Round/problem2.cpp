/* Read input from STDIN. Print your output to STDOUT*/
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int solve(int n,int w[]){
	unordered_map<int,int>weights_counts;

	for(int i=0;i<n;i++){
		weights_counts[w[i]]++;
	}
	int maxt=0;
	for(int i=2;i<=2*n;i++){
		int teams=0;
		auto use_cnt = weights_counts;
		for(int j=1;j<=(i+1)/2;j++){
			if(use_cnt.count(i-j)== use_cnt.count(j)){
				if(j == (i-j)){
					teams+= use_cnt[j]/2;
				}
				else{
					int p_teams= min(use_cnt[j],use_cnt[i-j]);
					teams += p_teams;
					use_cnt[j] -= p_teams;
					use_cnt[i-j] -=p_teams;
				}
			}
		}
		maxt = max(maxt , teams);
	}
	return maxt;
}
int main(int argc, char *a[])
{
	//Write code here
	int n;
	cin>>n;
	int w[n];
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	cout<<solve(n,w)<<endl;
}
