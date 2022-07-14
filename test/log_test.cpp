#include "easy_tools.h"

void test_log() {
	log_init();
	LOG_DEBUG("hello,world!");
	LOG_INFO("hello,world!");
	LOG_WARN("hello,world!");
	LOG_ERROR("hello,world!");
	LOG_FATAL("hello,world!");
}