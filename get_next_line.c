#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char    *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (!(arr = (char *)malloc(sizeof(char) * ((int)size + 1))))
		return (NULL);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((res = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) != NULL)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

int get_next_line(int fd, char **line)
{
    char buf[10 + 1];
    int readed;
    char *ptr;
    int flag;
	static char *remainder;

    flag = 1;
	if (remainder)
		*line = ft_strdup(remainder);
	else
    	*line = ft_strnew(1);
    while (flag && (readed = read(fd, buf, 10)))
    {
        buf[readed] = '\0';
        if ((ptr = ft_strchr(buf, '\n')))
        {
            *ptr = '\0';
            flag = 0;
			ptr++;
			remainder = ft_strdup(ptr);
        }
        *line = ft_strjoin(*line, buf);
    }
    return (0);
}
int main()
{
    int fd;
    char *line;
    fd = open("text.txt", O_RDONLY);
		get_next_line(fd, &line);
		printf("%s", line);
		//get_next_line(fd, &line);
		//printf("%s", line);
}