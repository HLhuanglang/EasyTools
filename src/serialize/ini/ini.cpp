#include "ini.h"

et_ini_handle::et_ini_handle(const char *file_path) :file_name_(file_path) {
	this->parser_ = new et_ini_parser();
}

et_ini_handle::~et_ini_handle() {
	if (!this->parser_) {
		delete this->parser_;
	}
	if (!this->fp_) {
		fclose(fp_);
	}
}

bool et_ini_handle::read(et_ini_file &ini) {
	this->file_name_ = file_name_;
	this->fp_ = fopen(file_name_, "r");
	if (!this->fp_) {
		et_trace_error("open file failed!");
		return false;
	}
	et_trace_debug("open file %s succeed!", file_name_);
	char buf[1024] = { 0 };
	std::string section;
	parse_data_t parse_data;
	while (!feof(this->fp_)) {
		fgets(buf, 1024, this->fp_);
		size_t len = strlen(buf);
		auto parse_ret = this->parser_->parse_line(buf, parse_data);
		if (parse_ret == et_ini_data_type_e::ET_DATA_SECTION) {
			section = parse_data.first;
			ini.data_[section];
		}
		if (parse_ret == et_ini_data_type_e::ET_DATA_KEY_VAL) {
			ini.data_[section][parse_data.first] = parse_data.second;
		}
	}
	return true;
}

bool et_ini_handle::write(et_ini_file &data)const {
	return true;
}

bool et_ini_handle::gengerate(et_ini_file &data)const {
	return true;
}

std::string et_ini_file::get_val(const char *section, const char *key) {
	return data_[section][key];
}