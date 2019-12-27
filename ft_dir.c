/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:09:56 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/26 00:10:17 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*ft_dir(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;

	tp->lenc = zerostruct(tp->lenc);
	if ((di = opendir(name)) == NULL)
		return (ft_direrr(name, fl, tr_trees, tp));
	if ((dp = readdir(di)) != NULL)
	{
		if (!fl->tds && fl->a)
		{
			fl->tds = 1;
			tr_trees = filltd(tr_trees, dp->d_name, name, tp);
			td = tr_trees;
			td_root = td;
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
		while ((dp = readdir(di)) != NULL)
		{
			if ((dp->d_name[0] == '.' && !(fl->a) && !(fl->abig)) || (dp->d_name[0] == '.' && dp->d_name[1] == '.' && fl->abig))
				;
			else
			{
				if (!fl->tds)
				{
					fl->tds = 1;
					tr_trees = filltd(tr_trees, dp->d_name, name, tp);
					td = tr_trees;
					td_root = td;
					tr_trees->fofreetd = tr_trees;
					tr_trees->fft = 1;
				}
				else
				{
					td = td_root;
					while (1)
					{
						if (ft_strcmp(td->dname, dp->d_name) >= 0)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name, tp);
								break;
							}
							else
								td = td->left;
						}
						if (ft_strcmp(td->dname, dp->d_name) < 0)
						{
							if (td->right == NULL)
							{
								td->right = filltd(td, dp->d_name, name, tp);
								break;
							}
							else
								td = td->right;
						}
					}
				}
			}
		}
		closedir(di);
		if (fl->tds == 0)
		{
			tr_trees = fillemp(tr_trees);
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
	}
	if (fl->rec && fl->fir)
		ft_printf("\n%s:\n", name);
	else if (fl->ac > 2)
	{
		if(tp->i >= 1 && !tp->ifile)
		{
			ft_printf("%s:\n", name);
			tp->i = 0;
		}
		else
			ft_printf("\n%s:\n", name);
	}
	if (fl->tds && fl->l)
		ft_printf("total %lld\n", totaltotal(name, tp, fl));
	fl->fir = 1;
	if (fl->tds)
		treeprint(tr_trees, fl, tp);
	fl->tds = 0;
	return (tr_trees);
}