/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:49:37 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:28:16 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	lenint(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*convert(int len, long nb, char *ptr)
{
	ptr[len] = '\0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	len--;
	while (nb > 0)
	{
		ptr[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*ptr;

	nb = (long)n;
	len = lenint(nb);
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	return (convert(len, nb, ptr));
}
// int main()
// {
// 	printf("%s",ft_itoa(12343));
// }
