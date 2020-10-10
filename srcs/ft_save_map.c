#include "../includes/map_editor.h"

static void	set_save_map_file(t_app *app, int *fd)
{
	int i;

	if ((i = app->pts) < 1)
	{
		*fd = -1;
		return ;
	}
	app->sfile[i] = '.';
	app->sfile[++i] = 'c';
	app->sfile[++i] = 'u';
	app->sfile[++i] = 'b';
	if ((*fd = open(app->sfile, O_CREAT | O_WRONLY | O_EXCL)) < 0)
	{
		print(YEL "Can't save in " CYN);
		print(app->sfile);
		print(RST"\n");
	}
}

static char	nerf_akuma_plz(char c)
{
	if (c >= 0 && c <= 2)
		return (c + '0');
	else if (c == 3)
		return ('N');
	else if (c == 4)
		return ('S');
	else if (c == 5)
		return ('E');
	else if (c == 6)
		return ('W');
	return (' ');
}

void		ft_save_map(t_app *app)
{
	int		i;
	int		j;
	int		fd;
	char	c[1];

	set_save_map_file(app, &fd);
	if (fd < 0)
		return ;
	printf("ye\n");
	j = 0;
	while (j < app->sy)
	{
		i = 0;
		while (i < app->sx)
		{
			c[0] = nerf_akuma_plz((char)app->map[j][i]);
			write(fd, &c, 1);
			i++;
		}
		j++;
		write(fd, "\n", 1);
	}
	close(fd);
}
