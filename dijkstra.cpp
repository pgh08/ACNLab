#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

void doDijkstra(unordered_map<int,vector<pair<int,int>>> &adjList, vector<int> &distance, int &source){
	distance[source] = 0;
	set<pair<int,int>> distanceNode;
	distanceNode.insert(make_pair(0,source));
	
	while(!distanceNode.empty()){
		auto top = *distanceNode.begin();
		distanceNode.erase(distanceNode.begin());
		
		int nodeDistance = top.first;
		int node = top.second;
		
		for(auto neighbours : adjList[node]){
			if(nodeDistance + neighbours.second < distance[neighbours.first]){
				auto record = distanceNode.find(make_pair(distance[neighbours.first], neighbours.first));
				
				if(record != distanceNode.end()){
					distanceNode.erase(record);
				}
				
				distance[neighbours.first] = nodeDistance + neighbours.second;
				
				distanceNode.insert(make_pair(distance[neighbours.first], neighbours.first));
			}
		}
	}
}

int main()
{
	int v, e;
	cout<<"Enter the number of vertices and edges"<<endl;
	cin>>v>>e;
	
	unordered_map<int,vector<pair<int,int>>> adjList;
	cout<<"Enter the value of node1, node2 and respective weight"<<endl;
	for(int i=0; i<e; i++){
		int u,v,w;
		cin>>u>>v>>w;
		
		adjList[u].push_back({v,w});
		adjList[v].push_back({u,w});
	}
	
	vector<int> distance(v, INT_MAX);
	
	int source;
	cout<<"Enter the value of source node from which you want to measure distance from : "<<endl;
	cin>>source;
	
	doDijkstra(adjList, distance, source);
	
	for(int i=0; i<v; i++){
		cout<<source<<" --> "<<distance[i]<<endl;
	}
	
	return 0;
}
