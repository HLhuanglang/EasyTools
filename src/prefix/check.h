#ifndef __ET_CHECK_H
#define __ET_CHECK_H

// check
#define et_check_return(x)                              do { if (!(x)) return ; } while (0)
#define et_check_return_val(x, v)                       do { if (!(x)) return (v); } while (0)

#endif // !__ET_CHECK_H
