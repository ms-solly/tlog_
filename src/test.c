#include "../include/tlog.h"
#include<stddef.h>
int main(void){
	tlog_logger* log = tlog_create(NULL);
	tlog_log(log, TLOG_DEBUG, "debug1\n");
	tlog_set_level(log, TLOG_DEBUG);
	tlog_log(log, TLOG_DEBUG, "debug2\n");
//	tlog_log(log, TLOG_INFO, "hello %d\n", 42);
	tlog_destroy(log);

	return 0;
}
