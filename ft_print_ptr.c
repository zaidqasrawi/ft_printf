/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulja <zabdulja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 03:01:16 by zabdulja          #+#    #+#             */
/*   Updated: 2026/10/10 03:01:16 by zabdulja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long ptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
		ft_put_ptr(ptr / 16);
	write(1, &hex[ptr % 16], 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	write(1, "0x", 2);
	count += 2;
	ft_put_ptr(ptr);
	count += ft_ptr_len(ptr);
	return (count);
}
