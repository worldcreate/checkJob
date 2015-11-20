#ifndef _JOBTABLE_H_
#define _JOBTABLE_H_

#include "Job.h"
#include "SettingTable.h"
#include <vector>
#include <string>

using namespace std;

class JobTable{
public:
	JobTable();
	~JobTable();
	void addMachine(char[]);
	void input();
	void print();
	bool check(const Job&,const Job&);
	bool checkTechnicalOrder(int);
	void checkTechnicalOrder();
	bool checkJob(int);
	void checkJob();
	bool checkMachine(int);
	void checkMachine();
private:
	vector<vector<Job> > table;
	SettingTable *settingTable;
};

#endif