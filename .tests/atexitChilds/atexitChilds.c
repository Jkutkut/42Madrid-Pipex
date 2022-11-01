#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void	print(char *s)
{
	printf("%s", s);
	fflush(stdin);
}

void	fn(void)
{
	print("Atexit called\n");
}

void	fn_child(void)
{
	print("child atexit called\n");
}

int	child(void)
{
	int	pid;

	pid = fork();
	if (pid)
		return pid;
	atexit(fn_child);
	print("child\n");
	exit(0); // Otherwise, the parent code is also run
	return (-1);
}


int	main(void) {
	int	pid;
	
	atexit(fn);
	pid = child();

	print("childs created\n");
	waitpid(pid, NULL, 0);
	print("parent end\n");
	return (0);
}
