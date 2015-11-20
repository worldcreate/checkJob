#include "Util.h"
#include <stdio.h>

vector<string> Util::split(const string &str, char delim){
	istringstream iss(str); string tmp; vector<string> res;
	while(getline(iss, tmp, delim)) res.push_back(tmp);
	return res;
}

int Util::stoi(const string& src){
	int a;
	stringstream ss;
	ss<<src;
	ss>>a;
	return a;
}

void Util::blankRead(){
	while(getchar() != '\n');
}