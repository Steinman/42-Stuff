/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:29:53 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/26 13:59:27 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_var
{
	int				l;
	int				**tab;
	int				err;
	int				len;
	int				winx;
	int				winy;
	double			mul;
	t_point			a;
	t_point			b;
	t_point			c;
	void			*mlx;
	void			*win;
	char			*buf;
}					t_var;

t_var		*ft_open(char *file, t_var *v, int fd);
int			ft_lineerror(char **str, t_var *v);
int			ft_emptyline(char *str);
int			ft_intnb(char *str);
t_var		*ft_graph_init(t_var *v);
t_var		*ft_points_init(t_var *v, int j);
t_var		*ft_fd_error(t_var *v, int fd, char *file);

#endif
