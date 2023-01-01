#include <bits/stdc++.h>
using namespace std;
#include <list>
#include <map>
#include <set>
template <typename T>
class graph{
	public:
	map<T,list<pair<T,int>>> adjlist;
	void addedge(T u, T v, int dist, bool direc=1){
		
		adjlist[u].push_back(make_pair(v,dist));
		if (direc){
			adjlist[v].push_back(make_pair(u,dist));
		}
		
	}
	void print(){
		for (auto it : adjlist){
			cout<< it.first<<" ";
			for (auto cwa : it.second){
				cout<<cwa.first<<" wt -> "<<cwa.second;
			}
			cout<<endl;
		}
	}
	void bfs(T u){
		map<T,bool> visited;
		queue <T> q;
		q.push(u);
		while(!q.empty()){
			T front_element=q.front();
			q.pop();
			if (!visited[front_element]){
				cout <<front_element<<" -> ";
				visited[front_element]	=true;
			}
			for(auto it: adjlist[front_element]){
				if (!visited[it.first]){q.push(it.first);}
			}
		}

	}
	void dfs(T u,map<T, bool> &visited ){
		visited[u]=true;
		cout<<u<<"-> ";
		for(auto it: adjlist[u]){
			if(!visited[it.first]){
				dfs(it.first,visited);
			}
		}
	}
	void dfs_start(T u){
		map<T,bool> visited;
		dfs(u,visited);
	}
};
int main(){
	graph<char> g;
	g.addedge('1','2',4,1);
	g.addedge('2','4',3,1);
	g.addedge('0','1',1,1);
	g.addedge('3','2',6,1);
	g.addedge('6','2',5,1);
	g.addedge('5','4',2,1);
	g.dfs_start('0');

	//g.print();
}