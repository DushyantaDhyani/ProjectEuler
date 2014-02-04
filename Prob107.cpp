#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
	int weight;
	int node1,node2; 
};
class DisjointSet{
	private:
		int size;
		vector<int> X;
	public:
		DisjointSet(int N){
			size=N+1;
			X.resize(size);
			for(int i=0;i<size;i++){
				X[i]=i;
			}
		}
		int Find(int x){
			while(x!=X[x]){
				x=X[x];
			}
			return x;
		}
		void Union(int x,int y){
			x=Find(x);
			y=Find(y);
			X[x]=y;
		}
};
bool myfunc(struct edge edge1,struct edge edge2){
	if(edge1.weight<=edge2.weight){
		return true;
	}
	return false;
}
int main(){
	int N=40;
	int num;
	long weight,rweight;
	weight=rweight=0;
	DisjointSet ob(N);
	vector<struct edge> Data;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&num);
			if(num!=0){
				weight+=num;
				struct edge Temp;
				Temp.weight=num;
				Temp.node1=i;
				Temp.node2=j;
				Data.push_back(Temp);
			}
		}
	}
	sort(Data.begin(),Data.end(),myfunc);
	for(int i=0;i<Data.size();i++){
		struct edge Temp=Data[i];
		if(ob.Find(Temp.node1)!=ob.Find(Temp.node2)){
			ob.Union(Temp.node1,Temp.node2);
			rweight+=Temp.weight;
		}
	}
	cout<<(weight/2)-rweight<<endl;
	return 0;
}
