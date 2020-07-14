#include "printfn.h"

#include <stdarg.h>
#include <stdio.h>

int printfn(const char * restrict fmt, ...) {
    va_list args;
    int res, res2;

    va_start(args, fmt);
    /* can't malloc because that would break %n specifiers */
    res = vprintf(fmt, args);
    if (res >= 0) {
        res2 = printf("\n");
        if (res2 < 0) {
            res = res2;
        } else {
            res += res2;
        }
    }
    va_end(args);
    return res;
}
