#include "apue.h"

char *path_alloc(size_t *size) {
    char *p = NULL;
    if (size == NULL) {
        return NULL;
    }
    *size = pathconf("/", _PC_PATH_MAX);
    if (*size <= 0) {
        *size = 4096;  // Ä¬ÈÏ´óÐ¡
    }
    p = malloc(*size);
    return p;
}


int main(void)
{
    char* ptr;
    size_t size;

    if (chdir("/home/beza/CS510-APUE") < 0)
    {
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);  /* our own function */
    if (getcwd(ptr, size) == NULL)
    {
        err_sys("getcwd failed");
    }

    printf("cwd = %s\n", ptr);
    exit(0);
}
