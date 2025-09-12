#include <stdio.h>
#include <string.h>

#define MAX 100

char directory[MAX][50];
int file_count = 0;

void createFile(char* filename) {
    strcpy(directory[file_count++], filename);
    printf("File '%s' created.\n", filename);
}

void displayFiles() {
    printf("\nFiles in Directory:\n");
    for (int i = 0; i < file_count; i++)
        printf("%s\n", directory[i]);
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");
    displayFiles();
    return 0;
}
