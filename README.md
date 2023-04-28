# Pipex
The pipex project is a program that simulates the functionality of the shell pipeline by redirecting the output of one
command as the input of another command. The project is part of the curriculum at 42 School.

## Getting Started
To use the pipex program, simply clone the repository to your local machine.
The program comes with a Makefile that includes the following rules:

- `all`: compiles the pipex program
- `bonus`: compiles the program to allow multiple pipes
- `clean`: removes all object files
- `fclean`: removes all object files and the pipex program
- `re`: recompiles the pipex program

To compile the program, run:

```bash
make all
```
This will generate a pipex executable that you can run.

## Using the Program
For example, the following command will run the ls command and then the wc command using pipex:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

## Bonus
The pipex project has a bonus part where you can use multiple pipes.
To use this functionality, provide the program with the additional commands and files as arguments.
For example, the following command will run `ls | grep test | wc -l` using pipex:

```bash
./pipex infile "ls" "grep test" "wc -l" outfile
```

## Conclusion
The pipex program is a useful tool for any student at 42 because it helps to understand the functionality of the shell pipeline and improves problem-solving skills. By implementing this project, you gain a deeper understanding of Unix system calls and how to use them in a practical application.
