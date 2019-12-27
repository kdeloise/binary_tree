/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 08:01:27 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/25 08:03:08 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*ft_dirt(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;
	struct stat				stbuf;

	tp->lenc = zerostruct(tp->lenc);
	if ((di = opendir(name)) == NULL)
	{
		fl->terd = 1;
		tr_trees = ft_errd(tr_trees, strerror(errno), name, fl);
		tr_trees->fofreetd = tr_trees;
		tr_trees->fft = 1;
		if (fl->rec && fl->fir)
			ft_printf("\n%s:\n", name);
		else if (fl->ac > 2)
			ft_printf("\n%s:\n", name);
		fl->fir = 1;
		treeprint(tr_trees, fl, tp);
		return (tr_trees);
	}
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
						tp->tmp = ft_strjoinp(name, dp->d_name);
						if (lstat(tp->tmp, &stbuf) != -1)
							tp->tsec = stbuf.st_ctime;
						free(tp->tmp);
						if (td->sec < tp->tsec)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name, tp);
								break;
							}
							else
								td = td->left;
						}
						if (td->sec >= tp->tsec)
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

t_ree_dir	*ft_dirrt(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;
	struct stat				stbuf;

	tp->lenc = zerostruct(tp->lenc);
	if ((di = opendir(name)) == NULL)
	{
		fl->terd = 1;
		tr_trees = ft_errd(tr_trees, strerror(errno), name, fl);
		tr_trees->fofreetd = tr_trees;
		tr_trees->fft = 1;
		if (fl->rec && fl->fir)
			ft_printf("\n%s:\n", name);
		else if (fl->ac > 2)
			ft_printf("\n%s:\n", name);
		fl->fir = 1;
		treeprint(tr_trees, fl, tp);
		return (tr_trees);
	}
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
						tp->tmp = ft_strjoinp(name, dp->d_name);
						if (lstat(tp->tmp, &stbuf) != -1)
							tp->tsec = stbuf.st_ctime;
						free(tp->tmp);
						if (td->sec >= tp->tsec)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name, tp);
								break;
							}
							else
								td = td->left;
						}
						if (td->sec < tp->tsec)
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
	fl->tds = 0;
	treeprint(tr_trees, fl, tp);
	return (tr_trees);
}