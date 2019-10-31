/* Hacker Earth Practice BFS
mail@fahimabrar.com
lazyfahim
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define pb push_back 
#define M 1000000
using  namespace std;
#define what_is(n) cerr<<#n<<" is "<<n<<endl;
string debug;
class bfs
{
public:
	int _node;
	vector<int> *nodes;
	int *level;
	bool *visited;
	queue<int> q;
	set<int>_nodecount;
	bfs(int node)
	{
		_node = node;
		nodes = new vector<int> [node+1];
		level = new int[M];
		visited = new bool[M];
	}
	void push(int a,int b)
	{
		nodes[a].pb(b);
		nodes[b].pb(a);
		_nodecount.insert(a);
		_nodecount.insert(b);
	}

	void dobfs(int start)
	{
		for(int i=0;i<1000;i++)
		{
			level[i] = -1;
			visited[i] = false;
		}
		q.push(start);
		level[start] = 1;
		visited[start] = true;
		while(!q.empty())
		{
			int latest_node = q.front();
			what_is(latest_node)
			q.pop();
			for(int i=0;i<nodes[latest_node].size();i++)
			{
				int to_be_visited = nodes[latest_node][i];
				what_is(to_be_visited)
				what_is(visited[to_be_visited])
				if(visited[to_be_visited]==false)
				{
					visited[to_be_visited]=true;
					q.push(to_be_visited);
					level[to_be_visited]= level[latest_node]+1;
					what_is(level[to_be_visited])
				}
			}
		}
	}
	
};
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	bfs p(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		p.push(a,b);
	}
	p.dobfs(1);
	int query;
	cin>>query;
	set<int>::iterator it;
	int count=0;
	for(it=p._nodecount.begin();it!=p._nodecount.end();it++)
	{
		if(p.level[*it] ==query)
			count++;
	}
	cout<<count<<endl;
}