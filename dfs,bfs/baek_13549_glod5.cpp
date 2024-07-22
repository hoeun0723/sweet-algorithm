#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
bool visit[100005];

int main(){
	int N,K;
	
	scanf("%d %d",&N,&K);
	
	pq.push(make_pair(0,N));
	
	while(!pq.empty()){
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		
		visit[x] = 1;
		
		if(x==K){
			printf("%d",time);
			break;
		}
		
		if(x-1>=0 && !visit[x-1])
			pq.push(make_pair(time+1,x-1));
		if(x+1<=100000 && !visit[x+1])
			pq.push(make_pair(time+1,x+1));
		if(x*2<=100000 && !visit[x*2])
			pq.push(make_pair(time,x*2));
	}
	
	return 0;
}