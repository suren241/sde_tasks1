#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int> >v[51];
long long int n;
void add(long long int st,long long int en,long long int w)
{
	v[st].push_back(make_pair(en,w));
	v[en].push_back(make_pair(st,w));
}
void prims()
{
	long long int st,uu,vv,w,i;
	priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long> > >pq; 
    vector<long long int>dis(n+1,999999999); 
    vector<long long int>par(n+1,-1);
    vector<int>visited(n+1,0); 
    pq.push(make_pair(0,1)); 
    dis[1]=0; 
    while (!pq.empty()) 
    {
        uu=pq.top().second; 
        pq.pop(); 
        visited[uu]=1;
        vector<pair<long long int,long long int> >::iterator it; 
        for(it=v[uu].begin();it!=v[uu].end();++it) 
        {
            vv=(*it).first; 
            w=(*it).second; 
            if(visited[vv]==0 && dis[vv]>w) 
            {
                dis[vv]=w; 
                pq.push(make_pair(w,vv)); 
                par[vv]=uu; 
            } 
        } 
    }
    cout<<"Edges of Minimum Spanning Tree"<<endl;
    for(i=2;i<=n;i++) 
        cout<<par[i]<<" -> "<<i<<endl; 
}
int main()
{
	long long int e,st,en,w;
	cout<<"Enter no of nodes:";
	cin>>n;
	cout<<"Enter no of edges:";
	cin>>e;
	cout<<"Enter edges numbered from 1 to n and weight:"<<endl;
	while(e--)
	{
		cin>>st>>en>>w;
		add(st,en,w);
	}
	 prims();
}
