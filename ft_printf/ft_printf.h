/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:52:02 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/15 18:42:31 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_mod
{
	char		sign;
	char		adj;
	char		padd;
	int			width;
	int			pre;
	char		c;
	int			np;
}				t_mod;

t_mod			*m_init(void);
void			m_flag(const char **fmt, t_mod *m);
void			m_width(const char **fmt, t_mod *m, va_list args);
void			m_pre(const char **fmt, t_mod *m, va_list args);
void			m_type(const char **fmt, t_mod *m);
int				fmt_str(t_mod *m, char *s);
int				ft_printf(const char *str, ...);
int				c_c(t_mod *m, char c);
int				c_u(t_mod *m, unsigned long long int num);
int				c_di(t_mod *m, long long int num);
int				c_px(t_mod *m, unsigned long long int num);
int				c_s(t_mod *m, char *s);
#endif
