/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:23:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:43:02 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	eprint(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

int	ft_strlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
