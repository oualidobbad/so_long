/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:37 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/01 10:51:59 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int n)
{
	char	q;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	q = (n % 10 + '0');
	count += write(1, &q, 1);
	return (count);
}

int	ft_putnbr_uns(unsigned int n)
{
	char	q;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	q = (n % 10 + '0');
	count += write(1, &q, 1);
	return (count);
}
