/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:50:16 by dait-atm          #+#    #+#             */
/*   Updated: 2020/10/12 13:50:17 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_editor.h"

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
	while (*str >= '0' && *str <= '9')
		res = ((res * 10) + (*str++ - '0'));
	return ((int)(neg * res));
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
