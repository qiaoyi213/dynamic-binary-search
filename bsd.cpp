#include<bits/stdc++.h>
#include "binarySearchDynamic.h"
using namespace std;

int main(int argc, char* argv[]){
	int N = 0;
	string sN = string(argv[1]);
	for(int i=0;i<sN.length();i++){
		N *= 10;
		N += sN[i] - '0';
	}
	DBinarySearch s = DBinarySearch();
	double start, end;
	start = clock();
	for(int i=0;i<=N;i++){
		s.insert(i);
	}
	end = clock();
	cout<<(end-start)/CLOCKS_PER_SEC<<" ";
	
	start = clock();
	for(int i=0;i<=N;i++){
		s.find(i);
	}
	end = clock();
	cout<<(end-start)/CLOCKS_PER_SEC<<" ";
	
	start = clock();
	for(int i=0;i<=N;i++){
		s.remove(i);
	}
	end = clock();
	cout<<(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
