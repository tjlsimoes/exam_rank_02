#include "flood_fill.h"

char	get_begin_char(char **tab, t_point size, t_point begin)
{
	return (tab[size.y - begin.y][get_actual_begin_idx(begin)]);
}

char	get_char(char **tab, t_point size, t_point begin)
{
	return (tab[size.y - begin.y][get_actual_begin_idx(begin)]);
}

int		get_actual_begin_idx(t_point begin)
{
	int	i;
	int	x;

	i = 0;
	x = begin.x;
	while (x > 1)
	{
		i += 2;
		x--;
	}
	return (i);
}

void  derived_flood_fill(char **tab, t_point size, t_point begin,
							char replace_char)
{
	t_point	orig = begin;

	tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
	// Horizontal Fill
	while (begin.x * 2 - 2 <= size.x * 2 - 2)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
		else
			break;
		begin.x++;
	}
	while (begin.x * 2 - 2 >= 0)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
		else
			break;
		begin.x--;
	}

	// Vertical Fill
	// Downwards
	while (size.y - begin.y <= size.y - 1)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][orig.x * 2 - 2] = 'F';
		else
			break;
		begin.y--;
	}
	// Upwards
	while (size.y - begin.y >= 0)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][orig.x * 2 - 2] = 'F';
		else
			break;
		begin.y++;
	}

}

t_point	define_temp(int x, int y, t_point *temp)
{
	(*temp).x = x;
	(*temp).y = y;
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char replace_char = get_begin_char(tab, size, begin);
	t_point	orig = begin;
	t_point temp;

	tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
	// Horizontal Fill
	while (begin.x * 2 - 2 <= size.x * 2 - 2)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
		// {
		// 	define_temp(begin.x, size.y, &temp);
		// 	derived_flood_fill(tab, size, temp, replace_char);
		// }
		tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
		else
			break;
		begin.x++;
	}
	while (begin.x * 2 - 2 >= 0)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
		else
			break;
		begin.x--;
	}

	// Vertical Fill
	// Downwards
	while (size.y - begin.y <= size.y - 1)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][orig.x * 2 - 2] = 'F';
		else
			break;
		begin.y--;
	}
	// Upwards
	while (size.y - begin.y >= 0)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
			tab[size.y - begin.y][orig.x * 2 - 2] = 'F';
		else
			break;
		begin.y++;
	}

}

int	main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	// t_point size = {8, 5};
	// t_point begin = {2, 2};
	// printf("%d\n", get_actual_begin_idx(begin));
	// printf("%c\n", get_begin_char(zone, size, begin));
	printf("%c\n", zone[2][18]);
	return (0);
}