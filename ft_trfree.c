/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:17:33 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/12 03:24:35 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freedirs(t_dirs *dirs)
{
	t_dirs *buff;

	while (dirs)
	{
		free(dirs->name);
		buff = dirs->next;
		free(dirs);
		dirs = buff;
	}
}

void 	freememdir(t_ree_dir *td, t_signs *fl, t_trpointers *tp)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (td == NULL)
		return ;
	freememdir(td->left, fl, tp);
	freememdir(td->right, fl, tp);
	if (td->path)
	{
		i = 1;
		free(td->path);
		td->path = NULL;
	}
	if (td->dname)
	{
		free(td->dname);
		td->dname = NULL;
	}
	if (td->s)
	{
		free(td->s);
		td->s = NULL;
		j = 1;
	}
	if ((fl->l || fl->t) && i && !j && td->gg)
	{
		free(td->time);
		if (fl->l)
		{
			free(td->uid);
			free(td->gid);
			free(td->rwx);
			if (td->buff)
				free(td->buff);
		}
	}
		if (td->fft)
			free(td->fofreetd);
		else
			free(td);
}
