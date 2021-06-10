/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:04:44 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:00:13 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_strfind_ls_char(char *s, char *to_find)
{
	int		i;

	if (!s || !to_find)
		return (0);
	i = 0;
	while (s[i])
	{
		if (ft_strfind(to_find, s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strfind_c(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_strfind(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
