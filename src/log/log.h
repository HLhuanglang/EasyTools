#ifndef __ET_LOG_H
#define __ET_LOG_H

#include <memory>
#include <mutex>
#include <string>
#include <atomic>

#include "log_prefix.h"

__et_extern_c_enter

using logger_t = struct __et_logger;

class __et_export et_log {
	friend class et_sigleton<et_log>;
public:
	void logger_init();
	void logger_print(log_level_e log_level, const char *fmt, ...);
	void logger_set_log_target(log_target_e targert);
	void logger_set_filepath(const std::string &file_path);
	void logger_set_logfile_name(const std::string &file_name);
	void logger_set_level(log_level_e log_level);
	void logger_set_filesize(size_t file_size);
	void logger_write(const char *buf, size_t size);
	void logger_enable_fsync(bool flag);

public:
	et_log();
	~et_log();
private:
	logger_t *logger_;
	std::once_flag once_;
};

/***************************************************************
 * 供用户使用的宏
 **************************************************************/

 //日志初始化
#define log_init() et_sigleton<et_log>::get_instance()->logger_init()

//设置日志信息输出地,若设置为仅输出到终端,则后续宏不起作用
#define log_set_target(target) \
  et_sigleton<et_log>::get_instance()->logger_set_log_target(target)

//设置日志文件存放地点,不设置绝对路径,则存放在当前程序运行路径下
#define log_set_filepath(filepath) \
  et_sigleton<et_log>::get_instance()->logger_set_filepath(filepath)

//设置日志级别 [DEBUG,INFO,WARN,ERROR,FATAL]
#define log_set_log_level(level) \
  et_sigleton<et_log>::get_instance()->logger_set_level(level)

//设置日志文件的大小,超过限制则清理,默认16MB
#define log_set_filesize(filesize) \
  et_sigleton<et_log>::get_instance()->logger_set_filesize(filesize)

// 日志信息
#define log_debug(fmt, ...)                                            \
  et_sigleton<et_log>::get_instance()->logger_print(                                   \
      log_level_e::LOG_LEVEL_DEBUG, "[%s:%d][%s]" fmt __et_newline, __et_filename, __et_line, \
      __FUNCTION__, ##__VA_ARGS__)

#define log_info(fmt, ...)                                            \
  et_sigleton<et_log>::get_instance()->logger_print(                                  \
      log_level_e::LOG_LEVEL_INFO, "[%s:%d][%s]" fmt __et_newline, __et_filename, __et_line, \
      __FUNCTION__, ##__VA_ARGS__)

#define log_warn(fmt, ...)                                            \
  et_sigleton<et_log>::get_instance()->logger_print(                                  \
      log_level_e::LOG_LEVEL_WARN, "[%s:%d][%s]" fmt __et_newline, __et_filename, __et_line, \
      __FUNCTION__, ##__VA_ARGS__)

#define log_error(fmt, ...)                                            \
  et_sigleton<et_log>::get_instance()->logger_print(                                   \
      log_level_e::LOG_LEVEL_ERROR, "[%s:%d][%s]" fmt __et_newline, __et_filename, __et_line, \
      __FUNCTION__, ##__VA_ARGS__)

#define log_fatal(fmt, ...)                                            \
  et_sigleton<et_log>::get_instance()->logger_print(                                   \
      log_level_e::LOG_LEVEL_FATAL, "[%s:%d][%s]" fmt __et_newline, __et_filename, __et_line, \
      __FUNCTION__, ##__VA_ARGS__)

// 别名
#define LOG_DEBUG	log_debug
#define LOG_INFO	log_info
#define LOG_WARN	log_warn
#define LOG_ERROR	log_error
#define LOG_FATAL	log_fatal

__et_extern_c_leave

#endif __ET_LOG_H
