
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void 	print_bits(unsigned char octet)
{
	unsigned char bit;
	int	i;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

int	 main(void)
{
	unsigned char octet;

	octet = 0;
	print_bits(octet);
}