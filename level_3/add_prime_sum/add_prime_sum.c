#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	units;
	int	nbr;

	i = 0;
	units = 1;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_is_digit(s[i]))
	{
		nbr = units * nbr + (s[i] + 48); 
		units *= 10;
	}
	return (nbr * sign);
}

int	is_prime(int nbr)
{
	int	i;
	int	flag;

	i = 2;
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return (1);
	flag = 1;
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			flag = 0;
		i++;
	}
	return (!flag);
}

// https://www.simplilearn.com/tutorials/c-tutorial/c-program-for-prime-numbers
// https://www.geeksforgeeks.org/c-program-to-check-prime-number-by-creating-a-function/

int	main(int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = ft_atoi(argv[1]);
	if (argc != 2 || nbr <= 0)
	{
		ft_putchar('0');
		write(1, "\n", 1);
		return (1);
	}
	while(i <= nbr)
	{
		if (i % 2)
	}
	return (0);
}