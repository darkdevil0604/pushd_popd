#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 100

// Global stack to store directories
char dirStack[MAX_DIRS][256];
int top = -1;

void pushd(const char* dirname) {
    if (top == MAX_DIRS - 1) {
        printf("Stack is full. Cannot push more directories.\n");
        return;
    }
    strcpy(dirStack[++top], dirname);
    printf("Pushed directory: %s\n", dirname);
}

void popd() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop any directory.\n");
        return;
    }
    printf("Popped directory: %s\n", dirStack[top--]);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [directory]\n", argv[0]);
        return 1;
    }

    const char* command = argv[1];
    if (strcmp(command, "pushd") == 0) {
        if (argc != 3) {
            printf("Usage: %s pushd <directory>\n", argv[0]);
            return 1;
        }
        pushd(argv[2]);
    } else if (strcmp(command, "popd") == 0) {
        popd();
    } else {
        printf("Invalid command. Use 'pushd' or 'popd'.\n");
        return 1;
    }

    return 0;
}
