#ifndef __ET_INI_PARSER_H
#define __ET_INI_PARSER_H

#include "ini_prefix.h"

class et_ini_parser {
public:
	et_ini_data_type_e parse_line(std::string line, parse_data_t &data);
};

#endif // !__ET_INI_PARSER_H
