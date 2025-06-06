#include "../csapp.h"
#define MAXARGS 128

// Evaluate a command line
void eval(char *cmdline);
// Parse the command line and build the argv array
int parseline(char *buf, char **argv);
// If first arg is a builtin command, run it and return true
int builtin_command(char **argv);

int main()
{
    char cmdline[MAXLINE];   
    while (1) {
        // Read
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);
        // Evaluate
        eval(cmdline); 
    }
    return 0;
}

void eval(char *cmdline)
{
    char *argv[MAXARGS]; // Argument list execve()
    char buf[MAXLINE];   // Holds modified command line
    int bg;              // Should the job run in bg or fg?
    pid_t pid;           // Process id

    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
    if (argv[0] == NULL)
        return; // Ingore empty lines
    
    if (!(builtin_command(argv))) {
        if ((pid = Fork()) == 0) // Child runs user job
        {
            if (execve(argv[0], argv, environ) < 0)
            {
                printf("%s Commmand not found.\n", argv[0]);
                exit(0);
            }
        }
        // Parent waits for foreground job to terminate
        if (!bg)
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: wait error");
        }
        else
            printf("%d %s", pid, cmdline);
    }
}

int parseline(char *buf, char **argv)
{
    char *delim; // Points to first space delimiter
    int argc;    // Number of args
    int bg;      // Background jobs?

    buf[strlen(buf) - 1] = ' '; // Replace trailing '\n' with space
    while (*buf && (*buf == ' ')) // Ignore leading space
        buf++;

    // Build the argv list
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        *delim = '\0';
        argv[argc++] = buf;
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;
    if (argc == 0) // Ignore blank line
        return 1;
    
    // Should the job run in the background?
    if (bg = ((*argv[argc-1]) == '&'))
    {
        argv[--argc] = NULL;
    }
    return bg;
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit")) // quit command
        exit(0);
    if (!strcmp(argv[0], "&"))    // Ignore singleton
        return 1;
    return 0; // Not a builtin command
}