#include "../include/tlog.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<time.h>
struct tlog_logger{
	FILE* out ;
	int owns_file; // 1 ? fopen: fclose
	tlog_level level;
};
tlog_logger* tlog_create(const char* filepath){
	tlog_logger* logger = malloc(sizeof(struct tlog_logger));
	logger->level = TLOG_INFO;
	if(!logger){
		return NULL;
	}
	
	if (filepath == NULL){
		logger->out = stdout;
		logger->owns_file = 0;
	}else{
		logger->out = fopen(filepath, "a");
		if(!logger->out){
			free(logger);
			return NULL;
		}
		logger->owns_file = 1;
	} 
	return logger;
}
void tlog_set_level(tlog_logger* logger, tlog_level level){
	if(!logger) return;
	logger->level = level;
}
void tlog_destroy(tlog_logger* logger){
	if(logger == NULL){
		return ;
	}
	if(logger->owns_file && logger->out ){
		fclose(logger->out);
	}
	free(logger);	
}
static const char* level_to_string(tlog_level level){
	switch(level){
		case TLOG_DEBUG : return "DEBUG";
		case TLOG_INFO  : return "INFO";
		case TLOG_WARN  : return "WARM";
		case TLOG_ERROR : return "ERROR";
		default         : return "UNKNOWN";
	}
}

void tlog_log(
		tlog_logger* logger,
		tlog_level level,
		const char* fmt,
		...
		){
	if(logger == NULL){
		return;
	}
	if(level < logger->level){
		return;
	}
	if(fmt == NULL){
		return;
	}
	if(logger->out == NULL){
		return;
	}
	const char* level_str = level_to_string(level);
	time_t now = time(NULL);
	struct tm* tm_info = localtime(&now);

	char time_buf[20];
	strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
	fprintf(logger->out, "[%s] [%s]", time_buf, level_str);
	va_list args;
	va_start(args, fmt);
	vfprintf(logger->out, fmt, args);
	va_end(args);
}
