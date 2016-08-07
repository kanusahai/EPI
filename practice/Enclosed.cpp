#include<iostream>
#include<stack>
#include<cstring>
#include<cstdlib>

using namespace std;

struct Coordinates {
  int x;
  int y;
};

void DFS(char **matrix, Coordinates cn) {
  stack<Coordinates> dfsStack;
  int numCols = strlen(matrix[0]);
  int numRows = numCols;

  matrix[cn.x][cn.y]='G';
  dfsStack.push(cn);

  while(!dfsStack.empty()) {
    Coordinates coord = dfsStack.top();
    dfsStack.pop();
    if((coord.x)-1>=0 && matrix[coord.x-1][coord.y]=='W') {
      Coordinates newCn;
      newCn.x=coord.x-1;
      newCn.y=coord.y;
      matrix[newCn.x][newCn.y]='G';
      dfsStack.push(newCn);  
    }

    if((coord.x)+1<numRows && matrix[coord.x+1][coord.y]=='W') {
      Coordinates newCn;
      newCn.x=coord.x+1;
      newCn.y=coord.y;
      matrix[newCn.x][newCn.y]='G';
      dfsStack.push(newCn); 
    }

    if((coord.y)-1>=0 && matrix[coord.x][coord.y-1]=='W') {
      Coordinates newCn;
      newCn.x=coord.x;
      newCn.y=coord.y-1;
      matrix[newCn.x][newCn.y]='G';
      dfsStack.push(newCn); 
    }

    if((coord.y)+1<numCols && matrix[coord.x][coord.y+1]=='W') {
      Coordinates newCn;
      newCn.x=coord.x;
      newCn.y=coord.y+1;
      matrix[newCn.x][newCn.y]='G';
      dfsStack.push(newCn); 
    } 
  }
}

void paintEnclosed(char **matrix) {
  int numCols = strlen(matrix[0]);
  int numRows = numCols;

  for(int j=0;j<numCols;j++) {
    if(matrix[0][j] == 'W') {
      Coordinates cn;
      cn.x=0;
      cn.y=j;
      DFS(matrix, cn);
    }
  }

  for(int j=0;j<numCols;j++) {
    if(matrix[numRows-1][j] == 'W') {
      Coordinates cn;
      cn.x=numRows-1;
      cn.y=j;
      DFS(matrix, cn);
    }
  }

  for(int i=0;i<numRows;i++) {
    if(matrix[i][0] == 'W') {
      Coordinates cn;
      cn.x=i;
      cn.y=0;
      DFS(matrix, cn);
    }
  }

  for(int i=0;i<numRows;i++) {
    if(matrix[i][numCols-1] == 'W') {
      Coordinates cn;
      cn.x=i;
      cn.y=numCols-1;
      DFS(matrix, cn);
    }
  }

  for(int i=0;i<numRows;i++) {
    for(int j=0;j<numCols;j++) {
      if(matrix[i][j]=='W') {
        matrix[i][j]='B';
      }
    }
  }

  for(int i=0;i<numRows;i++) {
    for(int j=0;j<numCols;j++) {
      if(matrix[i][j]=='G') {
        matrix[i][j]='W';
      }
    }
  }
}

void printMatrix(char **matrix) {
  int numCols = strlen(matrix[0]);
  int numRows = numCols;
  
  for(int i=0;i<numRows;i++) {
    for(int j=0;j<numCols;j++) {
      cout<<matrix[i][j]<<" ";  
    }
    cout<<"\n";
  }  
}

int main() {
  char **matrix=new char*[4];
  for(int i=0;i<4;i++) {
    matrix[i]=new char[4];
  }

  for(int i=0;i<4;i++) 
  for(int j=0;j<4;j++) {
    int random = rand();
    matrix[i][j]=(random%4==0)?'W':'B';
  }  

  printMatrix(matrix);
  paintEnclosed(matrix);
  cout<<"\n\n";
  printMatrix(matrix);

  return 0;
}
