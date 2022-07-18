#include "test.h"

#include "easy_tools.h"

void test_ini() {
	et_ini_file ini;
	et_ini_handle handle("../test/test_data/test.ini");
	handle.read(ini);
	auto ret = ini.get_val("section1", "name1");
	printf("ret=%s", ret.c_str());
	ret = ini.get_val("section1", "name2");
	printf("ret=%s", ret.c_str());
	ret = ini.get_val("section0", "name1");
	printf("ret=%s", ret.c_str());
}