#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "elf.h"

char *read_file(int fd)
{
    char *res;
    struct stat file_info;

    if (fstat(fd, &file_info))
    {
        perror("stat :");
        return NULL;
    }
    size_t file_size = file_info.st_size;
    res = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (res == MAP_FAILED)
    {
        perror("mmap :");
        return NULL;
    }
    return res;
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "Error in nb argument \n",22);
        return 0;
    }
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open :");
        return -1;
    }
    char *res = read_file(fd);
    printf("%s\n", res);
    return 0;
}