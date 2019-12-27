/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:57:43 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/09 00:12:47 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *ft_name(char *name)
{
	int i;
	int	j;
	char *n;

	j = 0;
	i = (int)ft_strlen(name) - 1;
	while (name[i--] != '/')
		j++;
	j++;
	n = (char *)malloc(sizeof(char) * j);
	n[j - 1] = '\0';
	i += j;
	j = 0;
	while (name[i] != '/')
	{
		n[j] = name[i];
		j++;
		i--;
	}
	n = ft_strrev(n);
	return (n);
}
