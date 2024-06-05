#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int				i;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + 48;
		write(1, &bit, 1);
		i--;
	}
}

int	power(int base, int exponent)
{
	int	i;
	int	nbr;

	if (exponent == 0)
		return (1);
	nbr = base;
	i = 0;
	while (i < exponent)
	{
		nbr = nbr * base; 
		i++;
	}
	return (nbr);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;
	int				new;

	bit = 0;
	i = 7;
	new = 0;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1);
		printf("Bit: %d\n", bit);
		new = new + bit * power(2, 7 - i); 
		printf("New: %d\n", new);
		i--;
	}
	return ((char)new);
}

int main(void)
{
	unsigned char *octet;

	octet = (unsigned char *)malloc(sizeof(unsigned char));
	*octet = 5;
	print_bits(*octet);
	write(1, "\n", 1);

	print_bits(reverse_bits(*octet));
	write(1, "\n", 1);
	free(octet);
	return (0);
}