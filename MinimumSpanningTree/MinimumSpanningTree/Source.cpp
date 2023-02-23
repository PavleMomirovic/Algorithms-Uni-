#include<iostream>
using namespace std;

//maximum number of nodes in this programs
constexpr auto NN = 30;

int parent[30];

// Find set of vertex i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskalMST(int cost[][NN], int n)
{
	int mincost = 0; // Cost of min MST.

	// Initialize sets of disjoint sets.
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < n - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	//printf("\n Minimum cost= %d \n", mincost);
}
int minKey(int key[], bool mstSet[])
{
	int min = 100000, min_index;

	for (int v = 0; v < NN; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[NN][NN],int n)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[NN][NN],int n)
{
	int parent[NN];
	int key[NN];
	bool mstSet[NN];

	// Initialize all keys as INFINITE
	for (int i = 0; i < NN; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	for (int count = 0; count < NN - 1; count++)
	{
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < NN; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph,n);
}


int main()
{

	int graph[NN][NN];
	std::fill((int*)graph, (int*)graph + sizeof(graph) / sizeof(int), 50000);

	//reading the input
	int n;
	cin >> n;
	string nodeNames[NN];
	for (int i = 0;i < n;i++) {
		cin >> nodeNames[i];
	}
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x][y] = z;
		graph[y][x] = z;
	}



	/* Graph printing used for debugging
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << "by using prim's algorithm:" << endl;
	primMST(graph,n);
	cout << "by using Kruskal's algorithm:" << endl;
	kruskalMST(graph,n);

	return 0;
}

/*
8 
0 
1
2
3
4
5
6
7
10 
0 1 5 
0 2 6
1 3 8
1 5 4
2 7 2
3 6 7
3 4 3
4 5 3
4 6 1
7 5 9
*/