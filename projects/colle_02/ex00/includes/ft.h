/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:11:03 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/26 22:34:06 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_print(int num, int x, int y);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *s1, char *s2);
char	*colle00(int x, int y);
char	*colle01(int x, int y);
char	*colle02(int x, int y);
char	*colle03(int x, int y);
char	*colle04(int x, int y);
int		ft_colle00(int x, int y, char *buf);
int		ft_colle01(int x, int y, char *buf);
int		ft_colle02(int x, int y, char *buf);
int		ft_colle03(int x, int y, char *buf);
int		ft_colle04(int x, int y, char *buf);

#endif
