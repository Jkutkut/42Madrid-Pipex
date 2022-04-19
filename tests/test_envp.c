#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	printf("---------------------------------\n");
	while (envp[i])
		printf("%s\n", envp[i++]);
	printf("---------------------------------\n");
	return (0);
}