#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Meeting {
  private:
  int startTime;
  int endTime;

  public:
  Meeting(int start, int end) {
    this->startTime=start;
    this->endTime=end;
  }

  int getStart() {
    return startTime;
  }

  int getEnd() {
    return endTime;
  }
};


class HiCal {
  private:
  vector<Meeting> meetings;
  vector<Meeting> condenseMeetings() { 
    return meetings;
  }

  public:
  void addMeeting(Meeting &meet) {
    meetings.push_back(meet);
  }

  void removeMeeting(Meeting &meet) {
    vector<Meeting>::iterator it = meetings.begin();
    while(it!=meetings.end()) {
      if(it->getStart()==meet.getStart() && it->getEnd()==meet.getEnd()) {
        break;
      }
      it++;
    }
    if(it!=meetings.end()) {
      meetings.erase(it);
    }
  }
  
  void freeSlots() {
    vector<Meeting> condensedMeetings = condenseMeetings();
    vector<Meeting>::iterator it;
    for(it=condensedMeetings.begin();it<condensedMeetings.end()-1;it++) {
      cout<<"("<<(*it).getEnd()<<","<<(*(it+1)).getStart()<<") ";
    }
    cout<<"\n";
  }  
};

int main() {

  HiCal calendar;
  Meeting m1(0,1), m2(3,5), m3(4,8), m4(10,12), m5(9,10);

  calendar.addMeeting(m1);
  calendar.addMeeting(m2);
  calendar.addMeeting(m3);
  calendar.addMeeting(m4);
  calendar.addMeeting(m5);
  
  calendar.freeSlots();
  return 0;
}
