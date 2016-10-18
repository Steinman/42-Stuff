/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:29:10 by hcorrale          #+#    #+#             */
/*   Updated: 2016/10/18 14:08:11 by hcorrale         ###   ########.fr       */
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

typedef struct		s_w3d
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camx;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			spd;
	double			rtspd;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}					t_w3d;

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
	char			**map;
	t_w3d			*w;
}					t_var;

int					ft_open(t_var *v, char *file, int fd);
int					ft_key_hook(int keycode, t_var *v);
int					ft_linelen(char *str, int i);
int					ft_find_player(t_var *v);
void				ft_raycast(t_var *v);
void				ft_pixel_put(t_var *v, int x, int y, int color);
int					ft_draw(t_var *v);

#endif
