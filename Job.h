#ifndef _JOB_H_
#define _JOB_H_

#include "Util.h"
#include <string>
#include <iostream>

using namespace std;

class Job{
public:
	Job():endTime(0),makeTime(0),machine(-1){}
	Job(const string& end,const string& make){
		endTime=Util::stoi(end);
		makeTime=Util::stoi(make);
	}
	const string toString() const{
		ostringstream s;
		s<<endTime<<","<<makeTime;
		return s.str();
	}
	friend ostream& operator<<(ostream& os,const Job& job);
	int makeTime;
	int endTime;
	int machine;
	Job& operator=(const Job& src){
		this->endTime=src.endTime;
		this->makeTime=src.makeTime;
		this->machine=src.machine;
		return (*this);
	}
	bool operator <(const Job& dst) const{
		return endTime<dst.endTime;
	}
};


#endif