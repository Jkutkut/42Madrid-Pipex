#include <stdlib.h>
#include <string.h>

static void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (*(array + i))
		free(*(array + i++));
	free(array);
}

int	main(void)
{
	char	**array;

	array = malloc(sizeof(char *) * 3);
	array[0] = malloc(sizeof(char) * 5);
	strncpy(array[0], "test", 5);
	array[1] = malloc(sizeof(char) * 5);
	strncpy(array[1], "test", 5);
	array[2] = NULL;

	int		**array2;

	array2 = malloc(sizeof(int *) * 3);
	array2[0] = malloc(sizeof(int) * 2);
	array2[0][0] = 1;
	array2[0][1] = 2;
	array2[1] = malloc(sizeof(int) * 2);
	array2[1][0] = 3;
	array2[1][1] = 4;
	array2[2] = NULL;

	free_array((void *)array);
	free_array((void *)array2);
	return (0);
}