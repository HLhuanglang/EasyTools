#include "test.h"

#include "easy_tools.h"

void test_ini() {
	et_ini_file ini;
#if defined(__GNUC__)
	et_ini_handle handle("./test_data/test.ini");
#else
	et_ini_handle handle("../test/test_data/test.ini");
#endif
	handle.read(ini);
	auto ret = ini.get_val("section1", "name1");
	printf("ret=%s\n", ret.c_str());
	ret = ini.get_val("section1", "name2");
	printf("ret=%s\n", ret.c_str());
	ret = ini.get_val("section0", "name1");
	printf("ret=%s\n", ret.c_str());
}