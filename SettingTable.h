#ifndef _SETTINGTABLE_H_
#define _SETTINGTABLE_H_

#include "Job.h"
#include <vector>

using namespace std;

class SettingTable{
public:
	SettingTable(char []);
private:
	vector<vector<int> >table;
};

#endif