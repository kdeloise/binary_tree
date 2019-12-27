/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 22:02:09 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 22:10:20 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *forlen)
{
	int len;

	if (!forlen)
		return (0);
	len = 1;
	while (forlen->next)
	{
		forlen = forlen->next;
		len++;
	}
	return (len);
}
