#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void childTask() {
    char name[30];

    printf("Enter your wife's  name: ");
    fgets(name, 30, stdin);
    printf("My wife  name is %s", name);
    exit(0);}
void parentTask() {
    printf("Waiting for child process to finish...\n");
    wait(NULL);
    printf("Job is done.\n");}
int main(void) {
    for(int i = 0; i < 4; i++) {
        int pid = fork();
        if(pid == 0) {
            childTask(); }
        else {
            parentTask(); } }
    return 0;
}
