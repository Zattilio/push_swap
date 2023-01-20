/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:47 by jlanza            #+#    #+#             */
/*   Updated: 2022/11/20 16:42:56 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;
	char	cc;

	cc = (char)c;
	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			last = (char *)&s[i];
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (last);
}
