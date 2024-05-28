int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);	
}

char    *ft_strrev(char *str)
{
	int		i;
	int		str_len;
	char	temp;

	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len / 2)
	{
		temp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = temp;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char str[6] = "hello";
	printf("%s\n", ft_strrev(str));
	return (0);
}