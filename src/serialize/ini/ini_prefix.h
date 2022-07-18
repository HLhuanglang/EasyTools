#ifndef __ET_INI_PREFIX_H
#define __ET_INI_PREFIX_H

#include "../../prefix/prefix.h"
#include "../../utils/debug.h"

#include <map>
#include <string>

__et_extern_c_enter

const std::string MODULE_INI = "et_ini";
const char *const k_whitespace_delimiters = " \t\n\r\f\v";

using parse_data_t = std::pair<std::string, std::string>;		//ini: key-value
using kv_t = std::map<std::string, std::string>;
using ini_containder_t = std::map<std::string, kv_t>;	//ini: section-kv

enum class et_ini_data_type_e {
	ET_DATA_NONE,
	ET_DATA_COMMENT,
	ET_DATA_SECTION,
	ET_DATA_KEY_VAL,
	ET_DATA_UNKNOWN
};

__et_extern_c_leave

#endif // !__ET_INI_PREFIX_H
