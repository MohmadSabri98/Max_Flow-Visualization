#include"Header.h"
/*
the test case ely el doctor menazelaha :D

0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 5 4
4 3 7
3 5 20
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



*/
MaxFlow::MaxFlow()
{
	MaxFlowValue = 0;
	cout << "Enter Number Of Nodes" << endl;
	cin >> NumOfNodes;
	cout << "Enter Number Of Edges" << endl;
	cin >> NumOfEdges;
	AdjacencyMatrix = new int*[NumOfNodes];
	NewFlow = new int*[NumOfNodes];
	for (int i = 0; i < NumOfNodes; i++)
	{
        AdjacencyMatrix[i] = new int[NumOfN0odes];
		NewFlow[i] = new int[NumOfNodes];
	}
	for (int i = 0; i < NumOfNodes; i++)
		for (int j = 0; j < NumOfNodes; j++)
		{
          AdjacencyMatrix[i][j] = 0;
		  NewFlow[i][j] = 0;
		}
	parent = new int[NumOfNodes];
	cout << "Enter " << NumOfEdges << " " << "Edges , Ex : From -> to then tha capacity :" << endl;
	int u, v, cap;
	for (int i = 0; i < NumOfEdges; i++)
	{
		cin >> u >> v >> cap;
		AdjacencyMatrix[u][v] = cap;
	}
	cout << "Enter your Source Node :"; cin >> Source;
	cout << "Enter your Sink Node :"; cin >> Sink;
	cout << endl;
}
bool MaxFlow::GetPath()
{
	queue<int> q;
	vector<bool> vis(NumOfNodes);
	for (int i = 0; i < NumOfNodes; i++)parent[i] = -1,vis[i]=0;
	vis[Source] = 1;
	q.push(Source);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < NumOfNodes;i++`)
			if (i != cur && AdjacencyMatrix[cur][i]>0 && !vis[i])
			{
				parent[i] = cur;
				vis[i] = 1;
				q.push(i);
			}
		if (cur == Sink)
			break;
	}
	if (parent[Sink] == -1)
		return 0;
	else
		return 1;
}
void MaxFlow::BackTrack(int u, vector<int>& path)
{
	if (parent[u] == -1)
	{
		return;
	}
	BackTrack(parent[u], path);
	path.push_back(u);
}
int MaxFlow::FindFlowAndReduceit(vector<int> path)
{
	int minn = 1e9;
	for (int i = 0; i < path.size() - 1; i++)
	{
		minn = min(AdjacencyMatrix[path[i]][path[i + 1]], minn);
	}
	for (int i = 0; i < path.size() - 1; i++)
	{
		AdjacencyMatrix[path[i]][path[i + 1]] -= minn;
		NewFlow[path[i]][path[i + 1]] += minn;
	}
	return minn;
}
void MaxFlow::GetMaxFlow()
{
	vector<int> Path;
	while (GetPath())
	{
		Path.clear();
		Path.push_back(Source);
		BackTrack(Sink, Path);
		int minn = FindFlowAndReduceit(Path);
		Allpathes.push_back({ minn,Path });
		for (int i = 0; i < Path.size(); i++)
		{
			cout << Path[i];
			if (i != Path.size() - 1)
				cout << "->";
			else
				cout << "   : This Path With Flow =" << minn << endl;
		}
		MaxFlowValue += minn;
	}
	if (Allpathes.size() == 0)
	{
		cout << "There is no Pathes from" << Source << " To " << Sink << endl;
	}
	else
	cout <<endl<< "Max Flow is :" << MaxFlowValue << endl;
}
