#include "cli.h"
#include <windows.h>
#include <dirent.h>
#include "../core/Core.h"
#include "stdio.h"
#include "stdlib.h"

#define COMMIT_ID_SIZE 9
#define TITLE_SIZE 60
#define DESCRIPTION_SIZE 120

void initCli();

void statusCli();

void selectCli(String filename);

void unSelectCli(String filename);

void commitCli(String title, String description);

void logCli();

void resetCli(String commitId);

void stashCli(String commitId);

void help();

void runCli(int argc, String *argv) {
    String mainCommand = argv[1];
    print("%s", mainCommand);
    if (strcmp(mainCommand, "init") == 0) {
        initCli();

    } else if (strcmp(mainCommand, "status") == 0) {
        statusCli();

    } else if (strcmp(mainCommand, "select") == 0) {
        String commitId = malloc(COMMIT_ID_SIZE * sizeof(char));
        scanf("%s ", commitId);
        selectCli(commitId);
    } else if (strcmp(mainCommand, "unselect") == 0) {
        String commitId = malloc(COMMIT_ID_SIZE * sizeof(char));
        scanf("%s ", commitId);
        unSelectCli(commitId);
    } else if (strcmp(mainCommand, "commit") == 0) {
        String title = malloc(TITLE_SIZE * sizeof(char));
        String description = malloc(DESCRIPTION_SIZE * sizeof(char));
        scanf("%s %s", title, description);
        commitCli(title, description);
    } else if (strcmp(mainCommand, "log") == 0) {
        logCli();
    } else if (strcmp(mainCommand, "reset") == 0) {
        String commitId = malloc(COMMIT_ID_SIZE * sizeof(char));
        scanf("%s ", commitId);
        resetCli(commitId);
    } else if (strcmp(mainCommand, "stash") == 0) {
        String commitId = malloc(COMMIT_ID_SIZE * sizeof(char));
        scanf("%s ", commitId);
        stashCli(commitId);
    } else {
        // anything else , use need help
        help();
    }

}

void initCli() {

}

void statusCli() {

}

void selectCli(String filename) {

}

void unSelectCli(String filename) {

}

void commitCli(String title, String description) {

}

void logCli() {

}

void resetCli(String commitId) {

}

void stashCli(String commitId) {

}

void help() {
    print("\n\n");
    printColored("help: \n", COLOR_BLOCK_GREEN);
    print("\n");

    printColored(" status ", COLOR_BLOCK_BLUE);
    printColored("  -show status of the files in workspace\n", COLOR_YELLOW);
    print("\n");

    printColored(" select [filename] ", COLOR_BLOCK_BLUE);
    printColored("  -add file to current commit\n", COLOR_YELLOW);
    printColored("filename can has relative or absolute path\n", COLOR_YELLOW);
    print("\n");

    printColored(" unselect ", COLOR_BLOCK_BLUE);
    printColored("  -remove file from current commit\n", COLOR_YELLOW);
    printColored("filename can has relative or absolute path\n", COLOR_YELLOW);
    print("\n");

    printColored(" commit [title, description] ", COLOR_BLOCK_BLUE);
    printColored("  -commit all changes and gives commit id in the format of hashcode\n", COLOR_YELLOW);
    printColored("commit id is first 8 chars of hashcode\n", COLOR_YELLOW);
    print("\n");

    printColored(" log ", COLOR_BLOCK_BLUE);
    printColored("  -show all commits with their commitId in the format of hashcode \n", COLOR_YELLOW);
    printColored("commit id is first 8 chars of hashcode\n", COLOR_YELLOW);
    print("\n");

    printColored(" reset ", COLOR_BLOCK_BLUE);
    printColored("  -go to commit with the help of commit id  \n", COLOR_YELLOW);
    printColored("Note : if you have stash you lose your data, to keep your stash you can use stash method\n",
                 COLOR_BLOCK_RED);
    print("\n");

    printColored(" stash [ commit id ] ", COLOR_BLOCK_BLUE);
    printColored("  -go to commit with the help of commit id without lose your stash \n", COLOR_YELLOW);
    printColored("commit id is first 8 chars of hashcode\n", COLOR_YELLOW);
    print("\n");

    printColored(" stash pop ", COLOR_BLOCK_BLUE);
    printColored("  -go back to your current workspace without lose any data in stash \n", COLOR_YELLOW);


}


/**
 * Changes cmd font color
 * @param colorCode
 */
void changeConsoleColor(int colorCode) {
    // color code between 0 to 255
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}


void printColored(String content, int colorCode) {
    changeConsoleColor(COLOR_WHITE);
    changeConsoleColor(colorCode);
    print("%s", content);
    changeConsoleColor(COLOR_WHITE);
}
