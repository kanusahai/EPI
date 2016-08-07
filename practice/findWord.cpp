#include <iostream>
#include<string>
#include<stack>
#include<utility>

using namespace std;

struct Coord {
	int x;
	int y;
};

bool DFS(Coord coord, string sample, char **matrix, int n, isVisited) {
	stack<pair<Coord, int>> dfsStack;
	
	int marker=0;
	if(sample[0] != matrix[coord.x][coord.y])
		return false;
	else {
		dfsStack.push(make_pair(coord, marker));
		isVisited[coord.x][coord.y]=1;
	}	
	while(!dfsStack.empty()) {
		coord = dfsStack.top().first;
		marker= dfsStack.top().second;
		dfsStack.pop();
		if(coord.x-1>=0) {
			if(isVisited[coord.x-1][coord.y]!=1 && matrix[coord.x-1][coord.y]==sample[marker+1]) {
				isVisited[coord.x-1][coord.y]=1;
				Coord newCoord = (coord.x-1, coord.y);
				dfsStack.push(make_pair(newCoord, marker+1));
			}
			
			if(coord.y-1>=0) {
				if(isVisited[coord.x-1][coord.y-1]!=1 && matrix[coord.x-1][coord.y-1]==sample[marker+1]) {
					isVisited[coord.x-1][coord.y-1]=1;
					Coord newCoord = (coord.x-1, coord.y-1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
				
				if(isVisited[coord.x][coord.y-1]!=1 && matrix[coord.x][coord.y-1]==sample[marker+1]) {
					isVisited[coord.x][coord.y-1]=1;
					Coord newCoord = (coord.x, coord.y-1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
			}
			
			if(coord.y+1 <n) {
				if(isVisited[coord.x-1][coord.y+1]!=1 && matrix[coord.x-1][coord.y+1]==sample[marker+1]) {
					isVisited[coord.x-1][coord.y+1]=1;
					Coord newCoord = (coord.x-1, coord.y+1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
				
				if(isVisited[coord.x][coord.y+1]!=1 && matrix[coord.x][coord.y+1]==sample[marker+1]) {
					isVisited[coord.x][coord.y+1]=1;
					Coord newCoord = (coord.x, coord.y+1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
			}
			
		}
		
		if(coord.x+1 <n) {
				if(coord.y-1>=0 && isVisited[coord.x+1][coord.y-1]!=1 && matrix[coord.x+1][coord.y-1]==sample[marker+1]) {
					isVisited[coord.x+1][coord.y-1]=1;
					Coord newCoord = (coord.x+1, coord.y-1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
				
				if(isVisited[coord.x+1][coord.y]!=1 && matrix[coord.x+1][coord.y]==sample[marker+1]) {
					isVisited[coord.x+1][coord.y]=1;
					Coord newCoord = (coord.x+1, coord.y);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
				
				if(coord.y+1<n && isVisited[coord.x+1][coord.y+1]!=1 && matrix[coord.x+1][coord.y+1]==sample[marker+1]) {
					isVisited[coord.x+1][coord.y+1]=1;
					Coord newCoord = (coord.x+1, coord.y+1);
					dfsStack.push(make_pair(newCoord, marker+1));
				}
		}
		
	}
	
	
}

Coord findString(char **matrix, int n, string sample) {
	int **isVisited = new int*[n];
	for(int i=0;i<n;i++) {
		isVisited[i]= new int[n];
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) {
		isVisited[i][j]=0;
	}
	
	bool isFound = false;
	for(int i=0; i<n;i++)
	for(int j=0;j<n;j++) {
		Coord coord=(i,j);
		isFound = DFS(coord, sample, matrix, n, isVisited);
		if(isFound)
			return coord;
	}
	
	return NULL;
}

int main() {
	// your code goes here
	return 0;
}
