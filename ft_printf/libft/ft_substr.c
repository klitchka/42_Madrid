/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:30:12 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/12 12:17:13 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Reserva memoria (con malloc(3)) y devuelve la
** cadena de caracteres que proviene de la cadena
** pasada como argumento.
** Esta nueva cadena comienza en el índice ’start’ y
** tiene como tamaño máximo ’len’
**
** Parámetros:
** #1. La cadena de la que se extrae la nueva cadena
** #2. El índice del principio de la nueva cadena
** #3. El tamaño máximo de la nueva cadena.
**
** Retorno:
** La nueva cadena de caracteres. NULL si falla la
** reserva de memoria.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;
	size_t	s_len;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
