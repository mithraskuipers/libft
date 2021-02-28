/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 19:41:18 by mikuiper      #+#    #+#                 */
/*   Updated: 2020/12/25 12:24:25 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		n_words;

	n_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			n_words++;
		}
		i++;
	}
	return (n_words);
}

static int		word_len(char const *s, char c)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		n_words++;
	}
	return (n_words);
}

static void		*leak(char **sen, int n_words)
{
	int	i;

	i = 0;
	while (i < n_words)
	{
		free(sen[i]);
		i++;
	}
	free(sen);
	return (NULL);
}

static char		**sen_filler(char const *s, int n_words, char c, char **sen)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < n_words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		if (!(sen[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(sen, i));
		j = 0;
		while (j < len)
			sen[i][j++] = *s++;
		sen[i][j] = '\0';
		i++;
	}
	sen[i] = NULL;
	return (sen);
}

char			**ft_split(char	const *s, char c)
{
	char	**sen;
	int		n_words;

	if (!s)
	{
		return (NULL);
	}
	n_words = count_words(s, c);
	if (!(sen = (char **)malloc(sizeof(char *) * (n_words + 1))))
	{
		return (NULL);
	}
	sen = sen_filler(s, n_words, c, sen);
	return (sen);
}

/*
** #include <stdio.h>
**
** int 	main(int argc, char **argv)
** {
** 	char	sen[] = "Hello there! My name is Mithras";
** 	char 	**splitted_sen;
**
** 	splitted_sen = ft_split(sen, 'M');
** 	printf("%s\n", splitted_sen[0]); //should print "Hello there!"
** 	printf("%s\n", splitted_sen[1]); //should print "y name is "
** 	printf("%s\n", splitted_sen[2]); //should print "ithras"
** 	return (0);
** }
*/
