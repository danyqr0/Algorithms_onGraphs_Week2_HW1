//=================================================================================================================================================
// Name        : Algorithms_onGraphs_Week2_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week2
// Description : A Computer Science curriculum specifies the prerequisites for each course as a list of courses that should be taken before taking
//this course. You would like to perform a consistency check of the curriculum, that is, to check that there are no cyclic dependencies.
//For this, you construct the following directed graph: vertices correspond to courses, there is a directed edge (u, v) is the course u should be
//taken before the course v. Then, it is enough to check whether the resulting graph contains a cycle.
//
//=================================================================================================================================================

#include <iostream>
#include <vector>

using namespace std;

using std::vector;

//prototypes:
void explore(vector<vector<int> > &adj, vector<bool> &adj_v, int x);
int acyclic(vector<vector<int> > &adj);
void processed(vector<int> &v_processing);

//global variables
size_t n, m,num_cycle=0;
bool cycle,sink;

void processed(vector<int> &vector_set){
	vector<int>::iterator it;
	for(it=vector_set.begin();it!=vector_set.end();++it)
		cout<<" *it="<<*it<<endl;
}

void explore(vector<vector<int> > &adj, vector<int> &v_processing, vector<int> &v_visited,int x){
	vector<int>::iterator it;
	v_processing[x]=x;
	sink=(adj[x].empty()) ? true:false;
	if(sink){
	     v_visited[x]=x;
	     v_processing[x]=-1;
	}
	else{
	  for(it=adj[x].begin();it!=adj[x].end();it++){
	     cycle=(v_processing[*it]==*it) ? true:false;
         if(!cycle && v_visited[*it]!=*it){
	  	      explore(adj,v_processing,v_visited,*it);
         }
         else if (cycle) num_cycle++;
	     v_processing[x]=-1;
	  	 v_visited[x]=x;
	  }
   }
}

int acyclic(vector<vector<int> > &adj) {
	vector<int> v_visited(n,-1);
	vector<int> v_processing(n,-1);
    for(int i=0;i<n;i++){
	   if(v_visited[i]!=i)
		   explore(adj,v_processing, v_visited, i);
	}
    if(num_cycle>0)
    	return 1;
    return 0;
}

int main() {
	  cin >> n >> m;
	  if( (n>=1 && n<=1e3) && (m>=0 && m<=1e3) ){
		  vector<vector<int> > adj(n, vector<int>());
		  for (size_t i = 0; i < m; i++) {
			  int x, y;
			  cin >> x >> y;
			  adj[x - 1].push_back(y - 1);
		  }
		  cout << acyclic(adj);
	  }
	  else
		  cout << 0;
	  return 0;
}
