#include "defaults.c"
#include "cmd_init.c"
#include "cmd_load.c"
#include "cmd_ls.c"
#include "cmd_mkdir.c"
#include "cmd_create.c"
#include "cmd_unlink.c"
#include "cmd_write.c"
#include "cmd_read.c"
#include "cmd_append.c"

void prompt(char* destination, char* prompt)
{
    printf("\n");
    printf("%s", prompt);
    scanf("%s", destination);
    printf("\n");
}

void main()
{
    // Clear the screen

    system("clear");

    // Show title

    printf("PandaSystem V1.0\n");
    printf("Created by Rafael Copstein and João Pedro Pianta\n");

    // Prompt the user

    char input[78662]; 
    char buffer[] = "root/main";

    while (strcmp(input, "exit") != 0)
    {
        prompt(input, "> ");

             if (strcmp(input, "exit") == 0) {}
        else if (strcmp(input, "init") == 0) cmd_init(FILENAME);
        else if (strcmp(input, "load") == 0) cmd_load(FILENAME);
        else if (strcmp(input, "ls") == 0) { scanf("%s", buffer); cmd_ls(buffer); }
        else if (strcmp(input, "mkdir") == 0) { scanf("%s", buffer); cmd_mkdir(buffer); }
        else if (strcmp(input, "create") == 0) { scanf("%s", buffer); cmd_create(buffer); }
        else if (strcmp(input, "unlink") == 0) { scanf("%s", buffer); cmd_unlink(buffer); }
        else if (strcmp(input, "write") == 0) { fgets(buffer, 78662, stdin); cmd_write(buffer); }
        else if (strcmp(input, "read") == 0) { scanf("%s", buffer); cmd_read(buffer); }
        else if (strcmp(input, "append") == 0) { fgets(buffer, 78662, stdin); cmd_append(buffer); }
        else printf("Command \"%s\" not found\n", input);

    }

}

/*

    Boot Block -> 1 Cluster
    FAT -> 4096 entradas de 2 bytes = 8 Clusters = 8192 Bytes
    root -> 1 Cluster (32 entradas de diretórios)
    data clusters -> 4086 Clusters

*/