// int	ft_atoi(char *str)
// {
// 	int	sign;
// 	int nbr;
// 	int i;

// 	if (!str)
// 		return (0);
// 	sign = 1;
// 	nbr = 0;
// 	i = 0;
// 	if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	while (str[i] && ft_isdigt(str[i]))
// 	{
// 		nbr = 10 * nbr + (str[i] - 48);
// 		i++;
// 	}
// 	return (nbr * sign);
// }


int	ft_isdigt(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_uppercase_q(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	get_idx(char c)
{
	char *hex_base_chars;
	int	i;

	i = 0;
	hex_base_chars = "0123456789abcdef";
	while (hex_base_chars[i])
	{
		if (hex_base_chars[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_includes_q(char c, int str_base)
{
	int	i;
	char *hex_base_chars;

	hex_base_chars = "0123456789abcdef";
	i = 0;
	while (i <= str_base)
	{
		if (c == hex_base_chars[i])
			return (1);
		i++;
	}
	return (0);
}

int	valid_string(char *str, int str_base)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (get_idx(str[i]) >= str_base)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isalphanum(char c)
{
	if (is_uppercase_q(c) || (c >= 'a' && c <= 'z')
		|| ft_isdigt(c))
		return (1);
	return (0);
}


int	ft_atoi_base(const char *str, int str_base)
{

	int	sign;
	int nbr;
	int i;

	if (!valid_string((char *)str, str_base))
		return (0);
	if (!str || !str_base)
		return (0);
	sign = 1;
	nbr = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isalphanum(str[i]))
	{
		if (is_uppercase_q(str[i]))
			nbr = str_base * nbr + (get_idx(str[i] + 32));
		else
			nbr = str_base * nbr + (get_idx(str[i]));
		i++;
	}
	return (nbr * sign);

}

#include <stdio.h>
#include <limits.h>
int	main(void)
{
	printf("%d\n", ft_atoi_base("-12FDB3", 16));
	return (0);
}