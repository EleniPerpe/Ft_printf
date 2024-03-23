/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hex_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:32:38 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/23 13:56:26 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_calc(unsigned int n, int *counter, char c)
{
	char	*res;
	int		hex_len;
	int		i;

	i = 0;
	hex_len = check_null_hex(n);
	(*counter) += hex_len;
	res = malloc(hex_len + 1 * sizeof(char));
	if (!res)
		return (NULL);
	while (i < hex_len)
	{
		if (n % 16 > 9)
		{
			if (c == 'X')
				res[hex_len - i - 1] = ((n % 16) + 55);
			else
				res[hex_len - i - 1] = ((n % 16) + 87);
		}
		else
			res[hex_len - i - 1] = ((n % 16) + 48);
		n = n / 16;
		i++;
	}
	print_hex(res, hex_len);
	return (res);
}

void print_hex(char *res, int hex_len) 
{
    int i = 0;

    while (i < hex_len) {
        write(1, &res[i], 1);
        i++;
    }
    free(res);
}

int	check_null_hex(unsigned long n)
{
	int	hex_len;

	hex_len = 0;
	if (n == 0)
		hex_len = 1;
	else
	{
		while (n > 0)
		{
			n /= 16;
			hex_len++;
		}
	}
	return (hex_len);
}
