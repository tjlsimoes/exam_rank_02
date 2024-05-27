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
	if (!s)
		return (-444);
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
		i++;
	}
	return (nbr * sign);
}

void	ft_putnbr(int nbr)
{
	long nbr_long;
	char c;

	nbr_long = (long) nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_long *= -1;
	}
	if (nbr_long < 9)
	{
		c = nbr_long - 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr_long / 10);
		ft_putnbr(nbr_long % 10);
	}
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
	if (flag)
		return (0);
	return (1);
}

// https://www.simplilearn.com/tutorials/c-tutorial/c-program-for-prime-numbers
// https://www.geeksforgeeks.org/c-program-to-check-prime-number-by-creating-a-function/

void error(void)
{
	ft_putchar('0');
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nbr;
	int	sum;

	i = 0;
	sum = 0;
	nbr = ft_atoi(argv[1]);
	if (argc != 2 || nbr == -444)
	{
		error();
		return (1);
	}
	while(i <= nbr)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
	return (0);
}