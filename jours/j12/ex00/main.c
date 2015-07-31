/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 10:37:21 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/24 15:51:54 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(*str++);
}

int		ft_display_file(char *filename)
{
	int		fd;
	int		len;
	char	buf[4097];
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	len = read(fd, buf, 4096);
	buf[len] = '\0';
	ft_putstr(buf);
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc == 2)
	{
		if (ft_display_file(argv[1]) == 1)
		{
			ft_putstr("Error.\n");
			return (0);
		}
		return (0);
	}
}
