#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

static int perms_parse(char *perms_arr) {
    int bits = 0;
    for(int i = 0; i < strlen(perms_arr); i++) {
        if(perms_arr[i] != '-') {
            bits |= 1 << (8 - i);
        }
    }
    return bits;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Less arguments are provided. %s [FILE] [PERMISSIONS]\n\nEx. %s test.txt r\n", argv[0], argv[0]);
        return 0;
    }

    if(!open(argv[1], O_WRONLY | O_CREAT, 0)) {
        printf("An error occurred on file creation\n");
        return 0;
    }
    if(chmod(argv[1], perms_parse(strlen(argv[2]) > 10 ? 0 : argv[2])) != 0) { // Permissions are bits read https://man7.org/linux/man-pages/man2/chmod.2.html
        printf("An error occurred on setting permissions to file\n");
        return 0;
    }
    printf("Task completed\n");
    return 0;
}
