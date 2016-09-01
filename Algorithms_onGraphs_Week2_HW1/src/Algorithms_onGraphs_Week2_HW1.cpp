//============================================================================
// Name        : Algorithms_onGraphs_Week2_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week2
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

using std::vector;
using std::pair;

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  return 0;
}

int main() {
	  size_t n, m;
	  std::cin >> n >> m;
	  vector<vector<int> > adj(n, vector<int>());
	  for (size_t i = 0; i < m; i++) {
	    int x, y;
	    std::cin >> x >> y;
	    adj[x - 1].push_back(y - 1);
	  }
	  std::cout << acyclic(adj);

	  return 0;
}
