/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:20:50 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/28 12:33:51 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoinp(char *s1, char const *s2)
{
	char	*fresh;
	char	*finish;
	int		len;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = (int)(ft_strlen(s1) + (int)ft_strlen(s2)) + 2;
	fresh = (char *)malloc(sizeof(char) * len);
	if (fresh == 0)
		return (NULL);
	finish = fresh;
	while (s1[++i])
		fresh[i] = s1[i];
	fresh[i++] = '/';
	while (*s2)
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (finish);
}
