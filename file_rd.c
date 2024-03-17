#import <stdio.h>
#import <fcntl.h>
#import <unistd.h>
#import <sys/stat.h>

struct database_header {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    struct database_header header = {0};
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("read");
        close(fd);
        return -1;
    }

    struct stat dbstat = {0};
    if (fstat(fd, &dbstat) == -1) {
        perror("fstat");
        close(fd);
        return -1;
    }

    printf ("DB file size (reported by fstat): %lld\n", dbstat.st_size);
    if (header.filesize != dbstat.st_size) {
        printf("HACKER DETECTED!\n");
        close(fd);
        return -1;
    }

    printf("DB version: %u\n", header.version);
    printf("DB number of employees: %u\n", header.employees);
    printf("DB file size: %u\n", header.filesize);

    close(fd);
    return 0;
}
