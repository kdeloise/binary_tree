/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:35:54 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/27 17:48:19 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char *start;
	char *finish;
	char *end;
	char c;

	start = str;
	finish = str;
	while (*str)
		str++;
	str--;
	end = str;
	while (start < end)
	{
		c = *start;
		*start = *end;
		*end = c;
		end--;
		start++;
	}
	return (finish);
}
