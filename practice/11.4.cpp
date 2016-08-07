#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Coordinate {
	int x;
	int y;
	int z;

	Coordinate(int x, int y, int z) {
		this->x=x;
		this->y=y;
		this->z=z;
	}

	bool operator < (const Coordinate &rhs) const {
		if(sqrt(pow(x,2)+pow(y,2)+pow(z,2)) < sqrt(pow(rhs.x,2)+pow(rhs.y,2)+pow(rhs.z,2))) return true;
		return false;
	}
};

class MilkyWay {
	private:
	static const Coordinate EARTH;
	vector<Coordinate> stars;

	void printStars(vector<Coordinate> vec) {
		for(int i=0;i<vec.size();i++) {
			cout<<"("<<vec[i].x<<", "<<vec[i].y<<", "<<vec[i].z<<")\n";
		}
	}

	public:
	MilkyWay() {}
	MilkyWay(vector<Coordinate> stars) { this->stars=stars; }

	void addStar(Coordinate c) {
		stars.push_back(c);
	} 	

	void addStar(int x, int y, int z) {
		Coordinate c(x,y,z);
		addStar(c);
	}

	void printKClosest(int k) {
		if(stars.size()<=k) {
			cout<<"Less than "<<k<<" stars present in the galaxy!\n";
			printStars();
			return;
		}
		vector<Coordinate> result;
		for(int i=0;i<k;i++) {
			result.push_back(stars[i]);
		}

		make_heap(result.begin(), result.end());

		for(int i=k;i<stars.size();i++) {
			if(stars[i]<result.front()) {
				pop_heap(result.begin(), result.end());
				result.pop_back();
				result.push_back(stars[i]);
				push_heap(result.begin(), result.end());
			}	
		}	
		printStars(result);
	
	}

	void printStars() {
		printStars(stars);		
	}

};

const Coordinate MilkyWay::EARTH(0,0,0);

int main() {
	MilkyWay mw;
	mw.addStar(1,0,0);
	mw.addStar(2,0,0);
	mw.addStar(1,2,3);
	mw.addStar(0,1,0);

	mw.printKClosest(4);
	return 0;
}
