/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:32:04 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:11 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_uppercase(char **str)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] -= 32;
}
