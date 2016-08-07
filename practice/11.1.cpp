#include<iostream>
#include<set>
#include<vector>

using namespace std;

class SortUnion {
	private:
	set<vector<int> > sortedSeq;

	struct HeapPoint {
			vector<int>::const_iterator curIt;
			vector<int>::const_iterator endIt;
	};
	
	void build_heap(vector<HeapPoint> &heap) {
		for(int i=heap.size()/2; i>=0; i--) {
			heapify(heap, i);
		}
	}

	void heapify(vector<HeapPoint> &heap, int index) {
		if(!(index>=0) && !(index<heap.size())) return;
		int leftChild = (2*index+1<heap.size())? 2*index+1 : -1;
		int rightChild = (2*index+2<heap.size())? 2+index+2 : -1;
		
		int replaceCode=0;
		int minVal = *(heap[index].curIt); 
		if(leftChild>0 && minVal>*(heap[leftChild].curIt)) {
			replaceCode=-1;
			minVal=*(heap[leftChild].curIt);
		}

		if(rightChild>0 && minVal>*(heap[rightChild].curIt)) {
			replaceCode=1;
			minVal=*(heap[rightChild].curIt);
		}

		HeapPoint hp=heap[index];
		switch(replaceCode) {
			default:
			case 0:
				break;

			case -1:
				
				heap[index]=heap[leftChild];
				heap[leftChild]=hp;
				heapify(heap, leftChild);
				break;
			case 1:
				heap[index]=heap[rightChild];
				heap[rightChild]=hp;
				heapify(heap, rightChild);
				break;
		}
		
	}

	public:
	SortUnion() {

	}

	SortUnion(const set<vector<int> > &myset) {
		sortedSeq=myset;
	}
	
	vector<int> unionOfSeq() {	
		vector<HeapPoint> heap;
		set<vector<int> >::iterator setIt;
		vector<int> vec;
		for(setIt=sortedSeq.begin(); setIt!=sortedSeq.end(); setIt++) {
			//vector<int>::iterator vecIt =(*setIt).begin();
			HeapPoint hp={(*setIt).begin(), (*setIt).end()};
			//hp.curIt=vecIt;
			//hp.endIt=(*setIt).end();
			heap.push_back(hp);
		}
		build_heap(heap);
		
		while(heap.size()>0) {
			vec.push_back(*(heap[0].curIt));
			heap[0].curIt++;
			if(heap[0].curIt==heap[0].endIt) {
				heap[0]=heap[heap.size()-1];
				heap.pop_back();
			}
			heapify(heap, 0);
		}
		return vec;
	}
};

int main() {
	set<vector<int> > inputSet;
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(3);

	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	
	inputSet.insert(vec1);
	inputSet.insert(vec2);

	SortUnion su(inputSet);

	
	vector<int> result = su.unionOfSeq();

	for(int i=0; i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<"\n";
	return 0;
}
