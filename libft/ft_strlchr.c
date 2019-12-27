/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 06:12:20 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 19:49:55 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlchr(const char *s, int c, int i)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)s;
	while (str[j] != c && j <= i)
	{
		if (str[j] == '\0')
			return (NULL);
		j++;
	}
	return (str + j);
}
