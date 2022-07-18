#ifndef __ET_INI_H
#define __ET_INI_H

#include "parser.h"
#include "ini_prefix.h"

__et_extern_c_enter

class __et_export et_ini_file {
	friend class et_ini_handle;
public:
	std::string get_val(const char *section, const char *key);
public:
	et_ini_file() = default;
	~et_ini_file() = default;
private:
	ini_containder_t data_;
};

class __et_export et_ini_handle {
public:
	bool read(et_ini_file &data);
	bool write(et_ini_file &data) const;
	bool gengerate(et_ini_file &data) const;
public:
	explicit et_ini_handle(const char *file_name);
	~et_ini_handle();
private:
	et_ini_parser *parser_ = nullptr;
	const char *file_name_ = nullptr;
	FILE *fp_ = nullptr;
};

__et_extern_c_leave

#endif // !__ET_INI_H
