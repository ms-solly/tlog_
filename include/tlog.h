#pragma once

typedef enum{
	TLOG_DEBUG,
	TLOG_INFO,
	TLOG_WARN,
	TLOG_ERROR
}tlog_level;

typedef struct tlog_logger tlog_logger;

tlog_logger* tlog_create(const char* filepath);
void tlog_set_level(tlog_logger* logger, tlog_level level);
void tlog_destroy(tlog_logger* logger);


void tlog_log(
		tlog_logger* logger,
		tlog_level level,
		const char* fmt,
		...
		);

