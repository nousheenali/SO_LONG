/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:20:03 by nali              #+#    #+#             */
/*   Updated: 2021/11/18 09:46:25 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	const char	*mems;
	char		*memd;

	mems = src;
	memd = dst;
	if (memd == mems)
		return (memd);
	if (mems < memd)
	{
		while (len)
		{
			memd[len - 1] = mems[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(memd, mems, len);
	return (dst);
}
