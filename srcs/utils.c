#include "../includes/map_editor.h"

void	help()
{
	write(1, "help\n", 5);
}

void	zero(t_app *app)
{
	int i;
	int j;

	j = 0;
	while (j < MY)
	{
		i = 0;
		while (i < MX)
		{
			app->map[j][i] = 7;
			i++;
		}
		j++;
	}
}

void	aff(int map[MY][MX])
{
	int 	i;
	int 	j;
	char 	c[1];

	printf("asdf\n");
	j = 0;
	while (j < MY)
	{
		i = 0;
		while (i < MX)
		{
			c[0] = map[j][i] + '0';
			write(1, &c, 1);
			// printf("%c,", 'c');
			i++;
		}
		c[0] = '\n';
		write(1, &c, 1);
		j++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	void *beg;

	beg = b;
	while (len--)
	{
		*((char *)b) = (unsigned char)c;
		b++;
	}
	return (beg);
}
