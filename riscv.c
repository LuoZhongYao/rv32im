extern int hostapi_write(int fd, const void *buf, unsigned size);

int main(void)
{
	hostapi_write(1, "hello world\n", 12);

	while (1) ;
	return 0;
}
