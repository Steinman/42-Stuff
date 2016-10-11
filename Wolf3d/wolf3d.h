/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:29:10 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/11 11:54:00 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*add;
	int				bpp;
	int				line;
	int				line_nb;
	int				endian;
	int				win_w;
	int				win_h;
	int				err;
	double			posx;
	double			posy;
	char			**map;
}					t_var;

int					ft_open(t_var *v, char *file, int fd);
int					ft_key_hook(int keycode, t_var *v);
void				ft_find_player(t_var *v);
void				ft_raycast(t_var *v);
void				ft_pixel_put(t_var *v, int x, int y, int color);

#endif
