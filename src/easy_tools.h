#ifndef __EASY_TOOLS_H
#define __EASY_TOOLS_H

#include "prefix/prefix.h"
#include "log/log.h"
#include "singleton/sigleton.h"
#include "serialize/ini/ini.h"

__et_extern_c_enter

__et_export bool et_init();
__et_export bool et_exit();

__et_extern_c_leave

#endif // !__EASY_TOOLS_H
