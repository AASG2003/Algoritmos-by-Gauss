#include <iostream>
#include <deque>
using namespace std;
	int C[100000];
	deque <int> G[100000];
	bool dfs(int u,int p){
		bool ans=true;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v!=p){
				int cadj=1-C[u];
				if(C[v]==-1){
					C[v]=cadj;
					ans=ans and dfs(v,u);
				}else{
					if(C[v]==C[u]){
						return false;
					}
				}
			}
		}
		return ans;
	}
int main() {
   bool esb=true;
   int N,a,b,c;
   cin>>N,a;
   for(int i=0;i<N;i++){
   	C[i]=-1;
   }
   for(int i=0;i<N;i++){
   	cin>>b>>c;
   b--;c--;
   	G[b].push_back(c);
   }
   for(int i=0;i<N;i++){
   	if(C[i]==-1){
   		C[i]=0;
   		esb=esb and dfs(i,-1);
   	}
   }
   for(int i=0;i<N;i++){
   	cout<<i<<": ";
   	cout<<C[i]<<endl;
   }
	return 0;
}
