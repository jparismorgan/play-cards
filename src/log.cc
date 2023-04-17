#include <stdarg.h>
#include <stdio.h>

namespace cards {

void log(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  printf("\n");
  va_end(args);
}

}  // namespace cards