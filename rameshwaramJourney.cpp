#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<int>> d;

void solve(vector<vector<pair<int, int>>> &adj, int source, int places){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, source});
	vector<int> dis(places, INF);
	dis[source] = 0 ;

	while(!pq.empty()){

		int newSource = pq.top().second ;
		pq.pop();
		
		for(auto nbr : adj[newSource]){
			
			int wt = nbr.second ;
			int place = nbr.first ;
			
			if(dis[place] > dis[newSource] + wt){
				dis[place] = dis[newSource] + wt ;
				pq.push({dis[place], place});
			}
		}

	}
	vector<pair<int, int>> el;
	for(int i = 0 ; i < places ; i++)el.push_back({dis[i] , i});
	sort(el.begin(), el.end());
	
	for(auto i: el)
		d[source][i.second] = i.first ;
}

int main(){

	int places, inp ;
	cin>>inp>>places ;
	d.resize(places);

	vector<string> tour(places) ;
	tour[0] ="temple",tour[1] ="agniteertham",tour[2] = "pamban island",tour[3] = "Apj Memorial";
	tour[4]="dhanushkodhi",tour[5]="arichal munai",tour[6]="vibhishan temple",tour[7]="ramar padham";
	tour[8]="house of kalam", tour[9] = "vilodhi terrtham";
	
	for(int i = 0 ; i < places ; i++){
		d[i].resize(places) ;
	}

	vector<vector<pair<int, int>>> adjList(places) ;
	for(int i = 0; i< inp ; i++){
		int src, des, wt;
		cin>>src>>des>>wt ;
		adjList[src].push_back({des, wt}) ;
		adjList[des].push_back({src, wt}) ;
	}

	
	for(int i =  0 ; i <places ; i++)
	solve(adjList, i, places) ;
	
	vector<pair<int, int>> el;
	for(int i = 0 ; i < places ; i++){
		for(int j = 0 ; j < places ; j++)el.push_back({d[i][j] , j});
		sort(el.begin(), el.end());
	
		for(auto val : el)
			cout<<tour[val.second]<<" -> ";
		el.clear();

		cout<<"-------Next route-----------\n";
	}

	return 0 ;
}