/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:53:04 by eboulhou          #+#    #+#             */
/*   Updated: 2022/11/03 17:44:31 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size1 = strlen(s1);
	size2 = strlen(s2);
	str = (char *)malloc(size1 + size2 + 1);
	if (!str)
		return (0);
	strlcpy(str, s1, size1 + 1);
	strlcat(str + size1, s2, size2 + 1);
	return (str);
}

char	*reading_func(int fd, char *temp)
{
	char buff[BUFFER_SIZE+1];
	char *ret;
	int i;
	int found;

	found = 0;
	i = BUFFER_SIZE;
	printf("temp at the reading function : -%s-\n",temp);
	while(!strchr(temp, '\n') && i == BUFFER_SIZE)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = 0;
		strncat(temp, buff, BUFFER_SIZE);
		if(i < BUFFER_SIZE)
		{
			return temp;
		}
	}
	i = 0;
	// puts(temp);
	printf("the len of temp in reading function : %zu\n", strlen(temp));
	ret = malloc(strlen(temp)+1);
	while(temp[i] != '\n')
	{
		ret[i] = temp[i];
		ret[++i] = 0;
	}
	
	
	// puts(ret);
	// exit(0);
	return ret;
}


char	*get_next_line(int fd)
{
	char static stat[BUFFER_SIZE + 1];
	char *temp;
	char *ret;
	char buff[BUFFER_SIZE+1];
	int i;
	temp = ft_strjoin(temp, stat);
	i = read(fd, buff, BUFFER_SIZE);
	buff[i] = 0;
	*temp = 0;
	printf("temp in the first function is : -%s-\n" , temp);
	if(i < 1)
		return NULL;
	temp = ft_strjoin(temp, buff);
	printf("temp at begining is : -%s-\n" , temp);
	ret = reading_func(fd, temp );
	strcpy(stat, (temp + strlen(ret)+1));
	
	printf("ret at begining is : -%s-\n" , ret);
	printf("stat at begining is : -%s-\n" , stat);

	
	return ret;
}
char	*get_next_line1(int fd)
{
	char static stat[BUFFER_SIZE + 1];
	char *temp;
	char *ret;
	char buff[BUFFER_SIZE+1];
	int i;

	temp = ft_strjoin(temp, stat);
	i = read(fd, buff, BUFFER_SIZE);
	buff[i] = 0;
	printf("temp in the second function is : -%s-\n" , temp);
	exit(0);
	*temp = 0;
	if(i < 1)
		return NULL;
	temp = ft_strjoin(temp, buff);
	printf("temp at begining is : -%s-\n" , temp);
	ret = reading_func(fd, temp );
	// exit(0);
	strcpy(stat, (temp + strlen(ret)+1));
	
	printf("ret at begining is : -%s-\n" , ret);
	printf("stat at begining is : -%s-\n" , stat);

	
	return ret;
}




int main ()
{
	int fd = open("file.txt" , O_RDONLY);
	get_next_line(fd);
	puts("00000000000000000000");
	// get_next_line1(fd);
}