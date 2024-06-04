#include <stdio.h>
#include <stdlib.h>

void pr_stdio(const char*, FILE*);
int is_unbuffered(FILE*);
int is_linebuffered(FILE*);
int buffer_size(FILE*);

int main(void)
{
    FILE* fp;

    fputs("enter any character\n", stdout);
    if (getchar() == EOF)
    {
        perror("getchar error");
        exit(1);
    }
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);
    if ((fp = fopen("/etc/passwd", "r")) == NULL)
    {
        perror("fopen error");
        exit(1);
    }
    if (getc(fp) == EOF)
    {
        perror("getc error");
        exit(1);
    }
    pr_stdio("/etc/passwd", fp);
    fclose(fp);
    exit(0);
}

void pr_stdio(const char* name, FILE* fp)
{
    printf("stream = %s, ", name);
    if (is_unbuffered(fp))
    {
        printf("unbuffered");
    }
    else if (is_linebuffered(fp))
    {
        printf("line buffered");
    }
    else /* if neither of above */
    {
        printf("fully buffered");
    }
    printf(", buffer size = %d\n", buffer_size(fp));
}

int is_unbuffered(FILE* fp)
{
    return fp->_flags & _IONBF;
}

int is_linebuffered(FILE* fp)
{
    return fp->_flags & _IOLBF;
}

int buffer_size(FILE* fp)
{
    return fp->_IO_buf_end - fp->_IO_buf_base;
}
