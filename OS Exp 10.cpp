#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;

    if (fork() == 0) {
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from child process!");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Child: Message sent.\n");
    } else {
        sleep(1);
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Parent: Received message: %s\n", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
