#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int main() {
    for (int i = 1; i <= 100000; i++) {
        
        if (kill(i, 0) == 0) { 
            printf("[Loop] Found valid PID: %d. Dispatching killer...\n", i);

            pid_t pid = fork();
            if (pid == 0) {
                char pid_str[10];
                sprintf(pid_str, "%d", i);
                char *args[] = {"kill", "-9", pid_str, NULL};
                execv("/bin/kill", args);
            } else {
                wait(NULL); 
            }
        }
    }
    printf("Loop complete. If I'm still alive, I didn't hit my own PID!\n");
    return 0;
}
