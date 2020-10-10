#include "../includes/map_editor.h"

void	help()
{
	write(1, "help\n", 5);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	print(char *s)
{
	write(1, s, ft_strlen(s));
}

void	zero(t_app *app)
{
	int i;
	int j;

	j = 0;
	while (j < app->sy)
	{
		i = 0;
		while (i < app->sx)
		{
			app->map[j][i] = 7;
			i++;
		}
		j++;
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
		res = ((res * 10) + (*str++ - '0'));
	return ((int)(neg * res));
}

void	aff(t_app *app)
{
	int 	i;
	int 	j;
	char 	c[1];

	j = 0;
	while (j < app->sy)
	{
		i = 0;
		while (i < app->sx)
		{
			c[0] = app->map[j][i] + '0';
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
