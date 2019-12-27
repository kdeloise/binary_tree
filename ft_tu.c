/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedirs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 07:38:54 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/27 06:17:24 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir *ft_treedirs(char *name, t_signs *fl, t_trpointers *tp)
{
	t_ree_dir		*t;
	if (fl->r)
	{
		if (fl->t)
			t = ft_dirrt(name, fl, t, tp);
		else
			t = ft_dirr(name, fl, t, tp);
	}
	else if (fl->t)
	{
		if (fl->r)
			t = ft_dirrt(name, fl, t, tp);
		else
			t = ft_dirt(name, fl, t, tp);
	}
	else
		t = ft_dir(name, fl, t, tp);
		fl->tdr = 1;
		return (t);
}
