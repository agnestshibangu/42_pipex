#include "pipex.h"

void child(char **av, int *p_fd)
{
    int fd;

    // Open the input file for reading
    fd = open_file(av[1], 0);
    // Redirect stdin to the input file
    dup2(fd, 0);
    // Redirect stdout to the pipe write end
    dup2(p_fd[1], 1);
    // Close unused pipe file descriptors
    close(p_fd[0]);
    close(p_fd[1]);
    // Close the file descriptor
    close(fd);

    // Execute the command with the argument
    execlp(av[2], av[2], (char *)NULL);
    perror("execlp"); // If execlp fails
    exit(1);
}

void parent(char **av, int *p_fd)
{
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    // Open the output file for writing
    fd = open_file(av[3], 1);
    // Close the unused write end of the pipe
    close(p_fd[1]);

    // Read from the pipe and write to the output file
    while ((bytes_read = read(p_fd[0], buffer, sizeof(buffer))) > 0)
    {
        write(fd, buffer, bytes_read);
    }

    // Close the pipe and output file descriptors
    close(p_fd[0]);
    close(fd);

    // Wait for the child process to finish
    wait(NULL);
}

int main(int ac, char **av)
{
    pid_t pid;
    int p_fd[2];

    if (ac != 4)
        return (0);
    if (pipe(p_fd) == -1)
        return (0);
    pid = fork();
    if (pid == -1)
        return (0);
    else if (pid == 0)
        child(av, p_fd);
    else
        parent(av, p_fd);

    return (0);
}