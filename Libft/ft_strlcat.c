/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:22:15 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/25 15:22:17 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;

	dlen = 0;
	while (dst[dlen] && dlen < size)
		dlen++;
	i = dlen;
	while (src[dlen - i] && (dlen + 1) < size)
	{
		dst[dlen] = src[dlen - i];
		dlen++;
	}
	if (i < size)
		dst[dlen] = '\0';
	return (i + ft_strlen(src));
}
