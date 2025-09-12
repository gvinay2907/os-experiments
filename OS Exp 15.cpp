#include <stdio.h>
#include <string.h>

#define MAX 10

struct SubDirectory {
    char filename[50];
};

struct Directory {
    char dirname[50];
    struct SubDirectory files[MAX];
    int file_count;
};

struct Directory mainDir[MAX];
int dir_count = 0;

void createDirectory(char* dirname) {
    strcpy(mainDir[dir_count].dirname, dirname);
    mainDir[dir_count].file_count = 0;
    dir_count++;
    printf("Directory '%s' created.\n", dirname);
}

void createFile(char* dirname, char* filename) {
    for (int i = 0; i < dir_count; i++) {
        if (strcmp(mainDir[i].dirname, dirname) == 0) {
            strcpy(mainDir[i].files[mainDir[i].file_count++].filename, filename);
            printf("File '%s' created in Directory '%s'.\n", filename, dirname);
            return;
        }
    }
}

void displayStructure() {
    printf("\nDirectory Structure:\n");
    for (int i = 0; i < dir_count; i++) {
        printf("Directory: %s\n", mainDir[i].dirname);
        for (int j = 0; j < mainDir[i].file_count; j++)
            printf("\t%s\n", mainDir[i].files[j].filename);
    }
}

int main() {
    createDirectory("Documents");
    createDirectory("Downloads");

    createFile("Documents", "doc1.txt");
    createFile("Downloads", "image1.png");

    displayStructure();
    return 0;
}
