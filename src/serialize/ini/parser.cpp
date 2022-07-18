#include "parser.h"
#include <map>

et_ini_data_type_e et_ini_parser::parse_line(std::string line, parse_data_t &data) {
	line.erase(line.find_last_not_of(k_whitespace_delimiters) + 1);
	line.erase(0, line.find_first_not_of(k_whitespace_delimiters));
	data.first.clear();
	data.second.clear();
	if (line.empty()) {
		return et_ini_data_type_e::ET_DATA_NONE;
	}
	char first_ch = line[0];
	if (first_ch == ';') {
		return et_ini_data_type_e::ET_DATA_COMMENT;
	}
	if (first_ch == '[') {
		auto comment_idx = line.find_first_of('; ');
		if (comment_idx != std::string::npos) {
			line = line.substr(0, comment_idx);
		}
		auto close_bracket_idx = line.find_last_of(']');
		if (close_bracket_idx != line.npos) {
			auto section = line.substr(1, close_bracket_idx - 1);
			data.first = section;
			return et_ini_data_type_e::ET_DATA_SECTION;
		}
	}
	auto equals_idx = line.find_first_of('=');
	if (equals_idx != line.npos) {
		auto key = line.substr(0, equals_idx);
		auto value = line.substr(equals_idx + 1);
		data.first = key;
		data.second = value;
		return et_ini_data_type_e::ET_DATA_KEY_VAL;
	}
	return et_ini_data_type_e::ET_DATA_UNKNOWN;
}