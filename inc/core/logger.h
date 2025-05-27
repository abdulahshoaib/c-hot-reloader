// logging utilities
#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void logger_init(void);
void log_info(const char *fmt, ...);
void log_error(const char *fmt, ...);
void logger_cleanup(void);

#endif // !LOGGER_H
