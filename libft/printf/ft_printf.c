/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:50 by mel-houd          #+#    #+#             */
/*   Updated: 2023/11/23 23:22:15 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	args;

	if (write(1, "", 0))
		return (-1);
	va_start(args, s);
	res = 0;
	res += ft_parsing(&args, s);
	va_end(args);
	return (res);
}
