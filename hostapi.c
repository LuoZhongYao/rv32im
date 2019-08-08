#include "hostapi.h"
#include <stdarg.h>

extern int (*hostapi_entry)(unsigned req, ...);

int hostapi_open(const char *file, int flags, ...)
{
	va_list ap;
	va_start(ap, flags);
	return hostapi_entry(HOSTAPI_OPEN, (unsigned)file, flags, va_arg(ap, int));
}

int hostapi_write(int fd, const void *buf, unsigned size)
{
	return hostapi_entry(HOSTAPI_WRITE, fd, (unsigned)buf, size);
}

int hostapi_read(int fd, void *buf, unsigned size)
{
	return hostapi_entry(HOSTAPI_WRITE, fd, (unsigned)buf, size);
}

int hostapi_close(int fd)
{
	return hostapi_entry(HOSTAPI_CLOSE, fd);
}

int hostapi_lseek(int fd, int offset, int whence)
{
	return hostapi_entry(HOSTAPI_SEEK, fd, offset, whence);
}
