/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:56 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/24 16:46:43 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	int			fd;
	int			**tab;
	char 		*line;
	char		*buf;
	char		**stock;
	int			i;

	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
		i++;
	}
	close(fd);
	printf("%s\n", buf);
	stock = ft_strsplit(buf, '\n');
	tab = ft_inttabtab(stock, i);
	return (0);
}
