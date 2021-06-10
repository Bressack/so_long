/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:25:24 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/09 22:02:52 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	dest = try_malloc(sizeof(char) * len);
	ft_strcpy(dest, src);
	return (dest);
}
