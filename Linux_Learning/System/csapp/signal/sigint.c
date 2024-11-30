#include "../csapp.h"

void signt_handler(int sig)
{
    printf("Caught SIGINT\n");
    exit(0);
}

int main()
{
    // Install the SIGINT handler
    if (signal(SIGINT, signt_handler) == SIG_ERR)
        unix_error("signal error");
    Pause();
    return 0;
}