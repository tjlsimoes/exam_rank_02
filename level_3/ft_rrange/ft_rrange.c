
#include <stdlib.h>

int		get_nbr_elements(int start, int end)
{
	int i;

	i = 0;
	if (start == end)
		return (1);
	else if (end > start)
	{
		while (start + i <= end)
			i++;
	}
	else
	{
		while (end + i <= start)
			i++;	
	}
	return (i);
}

int     *ft_rrange(int start, int end)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)malloc(get_nbr_elements(start, end) * sizeof(int));
	if (!array)
		return (0);
	if (start == end)
		array[i] = start;
	else if (end > start)
	{
		while (end >= start)
		{
			array[i] = end--;
			i++;
		}
	}
	else
	{
		while (end + i <= start)
		{
			array[i] = end + i;
			i++;	
		}
	}
	return (array);
}

#include <stdio.h>
int	main(void)
{
	int	*array;
	int	i;
	
	// printf("%d\n", get_nbr_elements(0, -3));
	i = 0;
	array = ft_rrange(1, 3);
	while (i < get_nbr_elements(1, 3))
	{
		printf("%d\n", array[i]);
		i++;
	}
	// while (i--)
	// 	free(array[i]);
	// free(array);
	return (0);
}