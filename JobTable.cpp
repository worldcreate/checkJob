#include "JobTable.h"
#include "Util.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <algorithm>

JobTable::JobTable(){
}

JobTable::~JobTable(){
	delete settingTable;
}

void JobTable::addMachine(char line[]){
	string str(line);
	vector<string> job=Util::split(str,' ');
	vector<Job> machine;

	for(int i=1;i<job.size();i++){
		if(job[i]=="")
			continue;
		vector<string> param=Util::split(job[i],',');
		machine.push_back(Job(param[0],param[1]));
	}
	table.push_back(machine);
}

void JobTable::input(){
	int m,j;
	char filename[256];
	scanf("%s",filename);
	settingTable=new SettingTable(filename);
	scanf("%d*%d\n",&j,&m);
	for(int i=0;i<m;i++){
		char line[1024];
		gets(line);
		addMachine(line);
	}
}

void JobTable::print(){
	for(int i=0;i<table.size();i++){
		cout<<i<<": ";
		for(int j=0;j<table[i].size();j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
}

void JobTable::checkTechnicalOrder(){
	cout<<"============== TechnicalOrder check start =============="<<endl;
	for(int i=0;i<table[0].size();i++){
		cout<<i<<":"<<checkTechnicalOrder(i)<<endl;
	}
}

bool JobTable::checkTechnicalOrder(int job){
	vector<Job> line;
	for(int i=0;i<table.size();i++){
		line.push_back(table[i][job]);
		line[i].machine=i;
	}
	sort(line.begin(),line.end());
	bool isMatch=true;
	for(int i=0;i<line.size();i++){
		if(line[i].machine!=settingTable->table[job][i])
			isMatch=false;
	}
	return !isMatch;
}

void JobTable::checkJob(){
	cout<<"============== job check start =============="<<endl;
	for(int i=0;i<table[0].size();i++){
		cout<<i<<":"<<checkJob(i)<<endl;
	}
}

bool JobTable::checkJob(int job){
	bool ret=false;
	for(int i=0;i<table.size();i++){
		for(int j=0;j<table.size();j++){
			if(i==j)
				continue;
			bool r=false;
			r=check(table[i][job],table[j][job]);
			if(r)
				cout<<"machine:"<<i<<":"<<j<<endl;
			ret|=r;
		}
	}
	return ret;
}

void JobTable::checkMachine(){
	cout<<"============== machine check start =============="<<endl;
	for(int i=0;i<table.size();i++){
		cout<<i<<":"<<checkMachine(i)<<endl;
	}
}

bool JobTable::checkMachine(int machine){
	bool ret=false;
	for(int i=0;i<table[machine].size();i++){
		for(int j=0;j<table[machine].size();j++){
			if(i==j)
				continue;
			bool r=false;
			r=check(table[machine][i],table[machine][j]);
			if(r)
				cout<<"job:"<<i<<":"<<j<<endl;
			ret|=r;
		}
	}
	return ret;
}

bool JobTable::check(const Job& left,const Job& right){
	Job shortJob;
	Job longJob;
	shortJob=left.makeTime<right.makeTime?left:right;
	longJob=left.makeTime>right.makeTime?left:right;
	int start=longJob.endTime-longJob.makeTime;
	int end=longJob.endTime;
	bool ret=false;

	if(start<shortJob.endTime-shortJob.makeTime && shortJob.endTime-shortJob.makeTime<end){
		ret=true;
	}
	if(start<shortJob.endTime && shortJob.endTime<end){
		ret=true;
	}
	return ret;
}