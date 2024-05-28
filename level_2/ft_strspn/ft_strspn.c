#include <string.h>

int	any_q(char c, const char *charset)
{
	int	i;

	i = 0;
	if (!c || !charset)
		return (0);
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t strspn(const char *s, const char *charset)
{
	int	i;

	i = 0;
	while (s[i] && any_q(s[i], charset))
		i++;
	return (i);
}

#include <stdio.h>
int	main(void)
{
	printf("%ld\n", strspn("hello", "hello"));
	return (0);
}