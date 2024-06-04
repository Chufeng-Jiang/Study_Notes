#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>


void delete_files() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            // ����ļ����Ƿ��� hw3_foo ��ͷ���� .txt ��β
            if (strncmp(dir->d_name, "hw3_foo", 7) == 0 && strstr(dir->d_name, ".txt")) {
                if (unlink(dir->d_name) == -1) {
                    perror("unlink");
                } else {
                    printf("Deleted: %s\n", dir->d_name);
                }
            }
        }
        closedir(d);
    } else {
        perror("opendir");
    }
}

int main() {

    // ɾ���ļ�
    delete_files();

    return 0;
}
