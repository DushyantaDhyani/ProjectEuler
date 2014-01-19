#define maxsize 1001
#define Last 1002001
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	vector< vector<long> > Data(maxsize);
	int i=0,j,k;
	int step=1;//No of steps in each direction
	bool flag=false;//To check number of iterations of n steps -- There should be 2
	bool exitflag=false;
	int dir=1;//To specify the direction of movement
	long value=1;
	while(i<maxsize){
		Data[i].resize(maxsize);
		i++;
	}
	i=maxsize/2;j=maxsize/2;
	while(true){
		switch(dir){
			case 1: k=1;
				while(k<=step){
					Data[i][j++]=value++;
					if(value>Last){
						k=step;
						exitflag=true;
					}
					k++;
				}
				dir=2;
				if(!flag){
					flag=true;
				}
				else{
					step++;
					flag=false;
				}
				break;
			case 2:k=1;
				while(k<=step){
					Data[i++][j]=value++;
					if(value>Last){
						k=step;
						exitflag=true;
					}
					k++;
				}
				dir=3;
				if(!flag){
					flag=true;
				}
				else{
					step++;
					flag=false;
				}
				break;
			case 3:k=1;
				while(k<=step){
					Data[i][j--]=value++;
					if(value>Last){
						k=step;
						exitflag=true;
					}
					k++;
				}
				dir=4;
				if(!flag){
					flag=true;
				}
				else{
					step++;
					flag=false;
				}
				break;
			case 4:k=1;
				while(k<=step){
					Data[i--][j]=value++;
					if(value>Last){
						k=step;
						exitflag=true;
					}
					k++;
				}
				dir=1;
				if(!flag){
					flag=true;
				}
				else{
					step++;
					flag=false;
				}
				break;
		}
		if(exitflag){
			break;
		}
	}
	long total=0;
	for(i=0;i<maxsize;i++){
		for(j=0;j<maxsize;j++){
			if((i==j) || ((i+j)==(maxsize-1))){
				total+=Data[i][j];
			}
		}
	}
	cout<<total<<endl;
	return 0;
}
