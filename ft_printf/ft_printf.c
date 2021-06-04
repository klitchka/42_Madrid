/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:51:56 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/15 19:18:20 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(t_mod *m, va_list args)
{
	if (m->c == 'p')
		m->np += c_px(m, (unsigned long int)va_arg(args, void *));
	else if ((m->c == 'd' || m->c == 'i'))
		m->np += c_di(m, va_arg(args, int));
	else if ((m->c == 'x' || m->c == 'X'))
		m->np += c_px(m, (unsigned int)va_arg(args, int));
	else if (m->c == 'c')
		m->np += c_c(m, (char)va_arg(args, int));
	else if (m->c == 's')
		m->np += c_s(m, va_arg(args, char *));
	else if (m->c == 'u')
		m->np += c_u(m, (unsigned int)va_arg(args, int));
	else if (m->c == '%')
		m->np += c_c(m, '%');
	else
		return (-1);
	return (0);
}

int	fmt_type(const char **fmt, va_list args)
{
	t_mod	*m;
	int		np;

	np = 0;
	m = m_init();
	m_flag(fmt, m);
	m_width(fmt, m, args);
	m_pre(fmt, m, args);
	m_type(fmt, m);
	if (conv(m, args) < 0)
	{
		free(m);
		return (-1);
	}
	np += m->np;
	free(m);
	return (np);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		np;
	int		ret;

	np = 0;
	ret = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			np += write(1, &*fmt++, 1);
		else if (*fmt++)
		{
			ret = fmt_type(&fmt, args);
			if (ret < 0)
				return (-1);
			np += ret;
		}
	}
	va_end(args);
	return (np);
}
