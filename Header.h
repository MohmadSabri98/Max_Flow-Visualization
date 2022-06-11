#include<vector>
#include<iostream>
using namespace std;
class MaxFlow
{
private:
    int **AdjacencyMatrix;//Matrix that conrain every edge with the capacity before the maxflow
	int **NewFlow; // the new array that contain every edge with the capacity after the maxflow
	int NumOfNodes, NumOfEdges, Source, Sink, MaxFlowValue;
	vector<pair<int,vector<int> > >  Allpathes;//to store all pathes during the flow
	int *parent;// temporary array to save every node and it's parent when run backtrack
public:
	void BackTrack(int , vector<int>& );// to store the path
	bool GetPath();// return true if there is a path and save it
	int FindFlowAndReduceit(vector<int>);// find the minimum cut in the given path
	void GetMaxFlow();// calculate the maxflow
	MaxFlow();//constractor to read the input
};

