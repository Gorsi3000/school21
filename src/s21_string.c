#include "s21_string.h"

   
size_t s21_strlen(const char *str) {
	int i = 0;
	while (str[i])
		i++;
	return (i);
} 

int s21_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char* s21_strcpy(char *dest, const char *src) {
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char* s21_strcat(char *dest, const char *src) {
	char	*ptr;

	ptr = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}

char* s21_strchr(const char* src, int to_find) {
    return src;
}

char* s21_strstr(const char* str, const char* to_find) {
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return ((void *)0);
}

char* s21_strtok(char* str, const char* delimiters ) {}
