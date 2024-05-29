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

void	define_temp(int x, int y, t_point *temp)
{
	(*temp).x = x;
	(*temp).y = y;
}

void  derived_flood_fill(char **tab, t_point size, t_point begin,
							char replace_char)
{
	t_point	orig = begin;
	t_point temp;

	tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
	// Horizontal Fill
	begin.x++;
	while (begin.x * 2 - 2 <= size.x * 2 - 2)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
		{
			define_temp(begin.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.x++;
	}
	begin.x = orig.x;
	begin.x--;
	while (begin.x * 2 - 2 >= 0)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
		{
			define_temp(begin.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.x--;
	}

	// Vertical Fill
	// Downwards
	begin.y--;
	while (size.y - begin.y <= size.y - 1)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
		{
			define_temp(orig.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.y--;
	}
	// Upwards
	begin.y = orig.y;
	begin.y++;
	while (size.y - begin.y >= 0)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
		{
			define_temp(orig.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.y++;
	}

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char replace_char = get_begin_char(tab, size, begin);
	t_point	orig = begin;
	t_point temp;

	tab[size.y - begin.y][begin.x * 2 - 2] = 'F';
	// Horizontal Fill
	begin.x++;
	while (begin.x * 2 - 2 <= size.x * 2 - 2)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
		{
			define_temp(begin.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.x++;
	}
	begin.x = orig.x;
	begin.x--;
	while (begin.x * 2 - 2 >= 0)
	{
		if (tab[size.y - begin.y][begin.x * 2 - 2] == replace_char)
		{
			define_temp(begin.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.x--;
	}

	// begin.x will perhaps have been altered. Thus use of orig.x.
	// Possible refactor: simply reset begin.x with orig.x and
	// use begin.x downbelow.

	// Vertical Fill
	// Downwards
	begin.y--;
	while (size.y - begin.y <= size.y - 1)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
		{
			define_temp(orig.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.y--;
	}
	// Upwards
	begin.y = orig.y;
	begin.y++;
	while (size.y - begin.y >= 0)
	{
		if (tab[size.y - begin.y][orig.x * 2 - 2] == replace_char)
		{
			define_temp(orig.x, begin.y, &temp);
			derived_flood_fill(tab, size, temp, replace_char);
		}
		else
			break;
		begin.y++;
	}

}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *new_str;
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (!new_str)
		return(NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}


int	main(void)
{
	char **area;
	// char *zone[] = {
	// 	"1 1 1 1 1 1 1 1",
	// 	"1 0 0 0 1 0 0 1",
	// 	"1 0 0 1 0 0 0 1",
	// 	"1 0 1 1 0 0 0 1",
	// 	"1 1 1 0 0 0 0 1",
	// };
	int n = 4;
	int	i = 0;
	area = (char **)malloc(5 * sizeof(char *));
	area[0] = ft_strdup("1 1 1 1 1 1 1 1");
	area[1] = ft_strdup("1 0 0 0 1 0 0 1");
	area[2] = ft_strdup("1 0 0 1 0 0 0 1");
	area[3] = ft_strdup("1 0 1 1 0 0 0 1");
	area[4] = ft_strdup("1 1 1 0 0 0 0 1");
	t_point size = {8, 5};
	t_point begin = {2, 2};
	// printf("%d\n", get_actual_begin_idx(begin));
	// printf("%c\n", get_begin_char(zone, size, begin));
	// printf("%c\n", zone[2][18]);
	flood_fill(area, size, begin);

	while (i <= 4)
		printf("%s\n", area[i++]);

	while (n >= 0)
		free(area[n--]);
	free(area);
	return (0);
}

// Better solution:

// // Recursive function to flood fill an area of a 2D character array
// void fill(char **tab, t_point size, char target, int row, int col)
// {
//     // Check if current row and column values are out of bounds
//     if (row < 0 || col < 0 || row >= size.y || col >= size.x)
//         return;
    
//     // Check if current cell has already been filled or does not match the target character
//     if (tab[row][col] == 'F' || tab[row][col] != target)
//         return;

//     // Mark current cell as filled
//     tab[row][col] = 'F';

//     // Recursively fill neighboring cells
//     fill(tab, size, target, row -1, col); // fill cell above
//     fill(tab, size, target, row +1, col); // fill cell below
//     fill(tab, size, target, row, col - 1); // fill cell to the left
//     fill(tab, size, target, row, col + 1); // fill cell to the right
// }

// // Function to initiate flood fill from a specified point
// void flood_fill(char **tab, t_point size, t_point begin)
// {
//     char target = tab[begin.y][begin.x]; // Get the character to fill around
//     fill(tab, size, target, begin.y, begin.x); // Start the flood fill from the specified point
// }
