/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:12:06 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:54 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	ft_convert(const char *str, int i, int sign, unsigned long res)
{
	int final;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807 && sign == -1)
			return ('0');
		else if (res > 9223372036854775807)
			return ('0');
		res = res * 10 + (str[i++] - '0');
	}
	final = res * sign;
	return ('1');
}

char	ft_atoi(const char *str)
{
	unsigned long			res;
	int						sign;
	int						count;
	int						i;

	res = 0;
	count = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		count++;
	}
	if (count > 1)
		return ('0');
	return (ft_convert(str, i, sign, res));
}