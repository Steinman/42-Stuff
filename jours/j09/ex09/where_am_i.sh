# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    where_am_i.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/17 11:40:40 by hcorrale          #+#    #+#              #
#    Updated: 2015/07/17 11:46:29 by hcorrale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

var=$(ifconfig | grep "inet " | cut -f2 -d " ")
if [ -n "$res" ]
then
	ifconfig | frep "inet " | cut -d " " -f2
else
	echo "Je suis perdu!"
fi
