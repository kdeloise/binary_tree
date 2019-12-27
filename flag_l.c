/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:49:06 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/24 16:49:38 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long	totaltotal(char *name, t_trpointers *tp, t_signs *fl)
{
	struct stat		stbuf;
	struct dirent	*infdir;
	DIR				*dp;
	long long		tot;
	char			*tmp;

	tp->lenc.total = 0;
	dp = opendir(name);
	while((infdir = readdir(dp)))
	{
		if ((infdir->d_name[0] == '.' && !(fl->a) && !(fl->abig)) || (infdir->d_name[0] == '.' && infdir->d_name[1] == '.' && fl->abig))
			continue;
		tmp = ft_strjoinp(name, infdir->d_name);
		if (lstat(tmp, &stbuf) != -1)
			tp->lenc.total = tp->lenc.total + stbuf.st_blocks;
		free(tmp);
	}
	closedir(dp);
	tot = tp->lenc.total;
	return (tot);
}

t_lc	zerostruct(t_lc	len)
{
	len.c2 = 0;
	len.c3 = 0;
	len.c4 = 0;
	len.cmajor = 0;
	len.cminor = 0;
	len.c5 = 0;
	len.total = 0;
	return(len);
}

t_lc	total(char *name, t_lc len, t_trpointers *tp)
{
	struct stat		stbuf;

	if (lstat(name, &stbuf) != -1)
	{
		if (len.c2 < ft_lennbr((int) stbuf.st_nlink))
			len.c2 = ft_lennbr((int) stbuf.st_nlink);
		if (len.c3 < ft_strlen(getpwuid(stbuf.st_uid)->pw_name))
			len.c3 = ft_strlen(getpwuid(stbuf.st_uid)->pw_name);
		if (len.c4 < ft_strlen(getgrgid(stbuf.st_gid)->gr_name))
			len.c4 = ft_strlen(getgrgid(stbuf.st_gid)->gr_name);
		if (len.cmajor < ft_lennbr((int) major(stbuf.st_rdev)) && (S_ISCHR(stbuf.st_mode) || S_ISBLK(stbuf.st_mode)))
			len.cmajor = ft_lennbr((int) major(stbuf.st_rdev));
		if (len.cminor < ft_lennbr((int) minor(stbuf.st_rdev)))
			len.cminor = ft_lennbr((int) minor(stbuf.st_rdev));
		if (len.c5 < ft_lennbr((int) stbuf.st_size))
			len.c5 = ft_lennbr((int) stbuf.st_size);
	}
	return (len);
}

void	chtime(char *time)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (i != 16)
		time[j++] = time[i++];
	time[j] = '\0';
}

char	*drwx(int mode)
{
	char	*chmod;
	char	*str;
	int		i;

	chmod = "drwxrwxrwx";
	i = (int)ft_strlen(chmod) + 1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		exit(0);
	if (S_ISDIR(mode))
		str[0] = 'd';
	else if (S_ISLNK(mode))
		str[0] = 'l';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISFIFO(mode))
		str[0] = 'p';
	else if (S_ISSOCK(mode))
		str[0] = 's';
	else
		str[0] = '-';
	str[--i] = '\0';
	while (i-- > 1)
	{
		str[i] = (char)(mode % 2 + '0');
		if (str[i] == '1')
			str[i] = chmod[i];
		else
			str[i] = '-';
		mode = mode / 2;
	}
	return (str);
}