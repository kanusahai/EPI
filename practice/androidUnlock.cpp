#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Pos {
	int x;
	int y;

	Pos() { this->x=0; this->y=0; }
	Pos(int x, int y) { this->x=x; this->y=y; }
};
class AndroidLock {
	private:
	int m;
	vector<string> patterns;
	int** keypad;

	void initKeyPad() {
		if(keypad==NULL) {
			keypad=new int*[3];
			for(int i=0;i<3;i++) {
				keypad[i]=new int[3];
			}
		}
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			keypad[i][j]=0;
	}

	static const int xDir[8];
	static const int yDir[8];
	static const int xDir_2[8];
	static const int yDir_2[8];

	
	vector<Pos> nextMove(Pos curPos) {
		vector<Pos> moves;
		
		for(int i=0;i<8;i++) {
			int x = curPos.x+xDir[i];
			int y = curPos.y+yDir[i]; 
			int x1 = curPos.x+2*xDir[i];
			int y1 = curPos.y+2*yDir[i];
			int x2 = curPos.x+xDir_2[i];	
			int y2 = curPos.y+yDir_2[i];

			if(x>=0 && x<3 && y>=0 && y<3) {
				if(keypad[x][y]==0) {
					Pos pos(x,y);
					moves.push_back(pos);
				} else if(x1>=0 && x1<3 && y1>=0 && y1<3) {
					Pos pos(x1,y1);
					moves.push_back(pos);
				}
			}
			if(x2>=0 && x2<3 && y2>=0 && y2<3 && keypad[x2][y2]==0) {
				Pos pos(x,y);
				moves.push_back(pos);
			}
		}	
		return moves;
	}

	void buildPasscode(Pos curPos, string passcode) {
		char num = '0' + ((curPos.x*3)+curPos.y+1);
		passcode.append(1,num);
		if(passcode.length()==m) {
			patterns.push_back(passcode);
			return;
		}  
		vector<Pos> moves = nextMove(curPos);
		
		for(int i=0;i<moves.size();i++) {
			keypad[moves[i].x][moves[i].y] = 1;
			buildPasscode(moves[i], passcode);			
			keypad[moves[i].x][moves[i].y] = 0;
		}
		return;
	}

	public: 

	AndroidLock() {
		initKeyPad();
	}	

	AndroidLock(int m) {
		this->m=m;
		initKeyPad();
	}

	void reset() {
		patterns.clear();
	}

	void findAllPossiblePatterns(int m) {
		this->m=m;
		reset();
		if(patterns.size()!=0) return;
		if(m<=0) return;
		Pos curPos(0,0);	
		string passcode = "";
		for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) {
			curPos.x=i;
			curPos.y=j;
			buildPasscode(curPos, passcode);
		}
	}

	void displayPatterns() {
		for(int i=0;i<patterns.size();i++) {
			cout<<patterns[i]<<"\n";
		}
	}
};

const int AndroidLock::xDir[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int AndroidLock::yDir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int AndroidLock::xDir_2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int AndroidLock::yDir_2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
	AndroidLock al;
	al.findAllPossiblePatterns(1);
	al.displayPatterns();

	return 0;
}
