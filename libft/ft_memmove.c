/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:22:40 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/09 09:54:31 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src1 < dest1)
	{
		dest1 += n - 1;
		src1 += n - 1;
		while (n--)
			*dest1-- = *src1--;
	}
	else
		dest1 = ft_memcpy(dest1, src1, n);
	return (dest1);
}
