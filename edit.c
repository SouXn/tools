#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void listFilesAndDirectories(const char* path) {
    DIR* dir;
    struct dirent* entry;
    struct stat fileStat;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    printf("Listing files and directories in: %s\n", path);

    while ((entry = readdir(dir)) != NULL) {
        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);

        if (stat(filePath, &fileStat) < 0) {
            printf("Unable to get file/directory information for: %s\n", filePath);
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            printf("Directory: %s\n", entry->d_name);
            listFilesAndDirectories(filePath);
        } else {
            printf("File: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    const char* path = "."; // Change this to the directory path you want to list

    listFilesAndDirectories(path);

    return 0;
}