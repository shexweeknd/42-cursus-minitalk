#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	send_char_to_server(unsigned char c)
{
	unsigned char	bit;
	unsigned char	res;

	bit = 0b10000000;
	while (bit)
	{
		printf("bit is: %x\n", bit);
		res = bit & c;
		printf("res is: %x\n", res);
		bit >>= 1;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Err args too short");
		exit(1);
	}
	while (*argv[1])
	{
		send_char_to_server(*argv[1]);
		argv[1]++;
	}
	return (0);
}