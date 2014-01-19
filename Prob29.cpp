#define EPS 1e-9
#define Limit 100
#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	int i,j,k;
	vector<double> Data;
	i=2;
	double num;
	while(i<=Limit){
		j=2;
		while(j<=Limit){
			num=i*log(j);
			k=0;
			while(k<Data.size()){
				if(abs(Data[k]-num)<=EPS){
					break;
				}
				k++;
			}
			if(k==Data.size()){
				Data.push_back(num);
			}
			j++;
		}
		i++;
	}
	cout<<Data.size()<<endl;
	return 0;
}
