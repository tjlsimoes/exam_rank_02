#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (argv[1][i] && ft_isspace(argv[1][i]))
		i++;
	while(argv[1][i] && !ft_isspace(argv[1][i]))
	{
		ft_putchar(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

// Solution

// #include <unistd.h>

// int main(int argc, char *av[])
// {
//     /* checking the number of arguments
//      */
//     if (argc == 2)
//     {
//         unsigned int i;
        
//         i = 0;
//         /* looping over the string to remove the possible starting
//          * spaces (32) and tabulations (9)
//          */
//         while (av[1][i] == 32 || av[1][i] == 9)
//             i++;
//         /* then start printing the characters from the string
//          * until we find either a space, a tabulation, or a \0
//          */
//         while ((av[1][i] != 32 && av[1][i] != 9) && av[1][i])
//             write(1, &av[1][i++], 1);
//     }
//     /* writing a \n at the end, because in every case we have to put a 
//      * \n at then end, either when we wrote something or not
//      */
//     write(1, "\n", 1);
//     return (0);
// }

// Spaces or tabs are taken at their face value.