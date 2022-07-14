#ifndef __ET_LOG_PREFIX_H
#define __ET_LOG_PREFIX_H

#ifdef _WIN32
#define DIR_SEPARATOR '\\'
#define DIR_SEPARATOR_STR "\\"
#else
#define DIR_SEPARATOR '/'
#define DIR_SEPARATOR_STR "/"
#endif

#ifndef __FILENAME__
#define __FILENAME__                                                       \
  (strrchr(__FILE__, DIR_SEPARATOR) ? strrchr(__FILE__, DIR_SEPARATOR) + 1 \
                                    : __FILE__)
#endif

// some default macro
#define DEFAULT_LOG_FILE_PATH "./"
#define DEFAULT_LOG_FILE_NAME "et_log.log"
#define DEFAULT_LOG_LEVEL log_level_e::LOG_LEVEL_DEBUG
#define DEFAULT_LOG_TARGERT log_target_e::TERMINAL
#define DEFAULT_LOG_MAX_BUFSIZE (1 << 14)   // 16k
#define DEFAULT_LOG_MAX_FILESIZE (1 << 24)  // 16M

enum class log_level_e {
	LOG_LEVEL_DEBUG = 0,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARN,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,
};

enum class log_target_e {
	FILE = 0,          //输出到文件
	TERMINAL,          //输出到终端
	FILE_AND_TERMINAL  //文件和终端
};

#endif // !__ET_LOG_PREFIX_H
