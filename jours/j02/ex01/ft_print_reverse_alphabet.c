/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 11:42:44 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/10 23:36:31 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	int begin;
	int end;

	begin = 'z';
	end = 'a';
	while (begin >= end)
	{
		ft_putchar(begin);
		begin--;
	}
}
