#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
int main() {
    char oldname[260];
    char newname[260];

    printf("Game to install: ");
    scanf("%259s", oldname);

    const char *ext = strrchr(oldname, '.');
    if (!ext || strcmp(ext, ".cinstall") != 0) {
        MessageBoxW(NULL, "The file selected is not in cinstall (not supported by cloudgamer)", "ERROR", MB_OK | MB_ICONERROR);
        return 1;
    }

    strcpy(newname, oldname);
    char *dot = strrchr(newname, '.');
    strcpy(dot, ".html");

    if (rename(oldname, newname) == 0) {
        printf("Fichier renommé en : %s\n", newname);
        char command[300];
        snprintf(command, sizeof(command), "start %s", newname);
        system(command);
    } else {
        perror("Erreur lors du renommage");
    }

    return 0;
}
