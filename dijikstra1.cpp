#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int> >v[51];
long long int n;
void add(long long int st,long long int en,long long int w)
{
	v[st].push_back(make_pair(en,w));
	v[en].push_back(make_pair(st,w));
}
void dijk(long long int s)
{
	long long int st,uu,vv,w,i;
	priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long> > >pq; 
    vector<long long int>dis(n+1,999999999);  
    pq.push(make_pair(0,s)); 
    dis[s]=0; 
    while (!pq.empty()) 
    {
        uu=pq.top().second; 
        pq.pop(); 
        vector<pair<long long int,long long int> >::iterator it; 
        for(it=v[uu].begin();it!=v[uu].end();++it) 
        {
            vv=(*it).first; 
            w=(*it).second; 
            if(dis[uu]+w<dis[vv]) 
            { 
                dis[vv]=dis[uu]+w; 
                pq.push(make_pair(dis[vv],vv)); 
            }
        } 
    }
    cout<<"vertex and distance from source:"<<endl;
    for(i=1;i<=n;i++) 
        cout<<i<<" "<<dis[i]<<endl; 
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
    cout<<"enter source vertex:";
    cin>>st;
	dijk(st);
}
