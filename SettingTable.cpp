#include "SettingTable.h"
#include "FileReader.h"
#include "Util.h"

SettingTable::SettingTable(char filename[]){
	FileReader fr(filename);
	table.resize(fr.getLineNum());
	for(int i=0;i<fr.getLineNum();i++){
		vector<string> job=Util::split(fr.getLine(i),':');
		for(int j=0;j<job.size();j++){
			vector<string> param=Util::split(job[j],',');
			table[i].push_back(Util::stoi(param[0]));
		}
	}
}