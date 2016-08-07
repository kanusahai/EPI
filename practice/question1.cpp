#include<iostream>
#include<list>
using namespace std;

class Tree {
 private:
 int startFertile;
 int endFertile;
 int deathAge;
 int units;
 

 public: 
 Tree(int startFertile, int endFertile, int dA, int units) {
   this->startFertile=startFertile;
   this->endFertile=endFertile;
   this->deathAge=dA;
   this->units=units;
   this->curAge=0;
 }

 int curAge;
 int getStartFer() {
   return startFertile;
 }

 int getEndFertile() {
   return endFertile;
 }

 int getDA() {
  return deathAge;
 }

 int getUnits() {
    return units;
 }

 int getCurAge() {
    return curAge;
 }
};

class AppleTree : public Tree {
  public:
  AppleTree(): Tree(3,6,15,10) {
       
  } 
};

class PearTree : public Tree {
  public:
  PearTree(): Tree(2,4,12,5) {
  }
};

enum Season {
  SPRING,
  FALL,
  WINTER,
  SUMMER,
  END
};

class Orchard {
  private:
  list<Tree> trees;    
  int numOfTrees;

  Season curSeason;
  public:
 
  Orchard() {
    numOfTrees=0;
    curSeason=FALL;
  } 
  int changeSeason() {
    int numOfFruits=0;
    curSeason=(curSeason+1);
    if(curSeason==END)
      curSeason=SPRING;
    if(curSeason==FALL) {
      list<Tree>::iterator it=trees.begin();

      while(it!=trees.end()) {
        it->curAge+=1;
        if(it->curAge>=it->getStartFer() && it->curAge<=it->getEndFertile())  {
          numOfFruits+=it->getUnits();
        }
        it++;
      }
      return numOfFruits;
    } else {
      return 0;
    }
  }

  void plantTree(Tree tr) {
    trees.push_back(tr);
  }
};


int main() {
  Orchard orch;
  AppleTree at;
  PearTree pt;

  orch.plantTree(at); 
  orch.plantTree(pt);
}

