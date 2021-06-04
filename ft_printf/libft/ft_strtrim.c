/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:30:05 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/11 19:33:05 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reserva memoria (con malloc(3)) y devuelve la
** cadena de caracteres que es una copia de ’s1’, sin
** los caracteres indicados en el ’set’ al principio y
** al final de la cadena de caracteres.
** char	*ft_strtrim(char const *s1, char const *set)
**
** Retorno:
** La cadena de caracteres depurada. NULL si falla la
** reserva de memoria.
*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(&s1[i]);
	if (j)
		while (j && ft_strchr(set, s1[i + j - 1]))
			j--;
	r = ft_substr(s1, i, j);
	return (r);
}
