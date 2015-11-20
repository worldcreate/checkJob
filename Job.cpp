#include "Job.h"

ostream& operator<<(ostream& os,const Job& job){
	os<<job.toString();
	return os;
}
