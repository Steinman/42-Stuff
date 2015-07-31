/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 09:58:15 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/16 16:47:12 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (*(argv[0] + i) != '\0')
	{
		ft_putchar(*(argv[0] + i));
		i++;
	}
	ft_putchar('\n');
	return (0);
}
