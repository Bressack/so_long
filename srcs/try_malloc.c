/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:20:55 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:55:58 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < len)
	{
		((char *)b)[bytes] = (unsigned char)c;
		bytes++;
	}
	return (b);
}

void	*try_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
	{
		write(2, "error: unable to allocate region\n", 33);
		exit(-1);
	}
	ft_memset(new, 0, size);
	return (new);
}
