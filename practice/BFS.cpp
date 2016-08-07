#include <iostream>
#include <queue>
using namespace std;

void BFS(int **arr, int n, int start_node) {
		queue<int> q;
		q.push(start_node);
		
		int visited[n];
		for(int i=0;i<n;i++)
			visited[i]=0;
		visited[start_node]=1;
		while(!q.empty()) {
			int node=q.front();
			q.pop();
			cout<<node<<" ";
			
			for(int i=0; i<n;i++) {
				if(arr[node][i]==1 && visited[i]==0) {
					q.push(i);
					visited[i]=1;
				}
			}
		}

}
int main() {
	int **graph = new int*[4];
	for(int i=0;i<4;i++)
		graph[i]=new int[4];
	graph[0][1]=1;
	graph[0][3]=1;
	graph[1][2]=1;
	graph[3][2]=1;
	BFS(graph, 4, 0);
	return 0;
}
