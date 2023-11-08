#include <stdio.h>
#include <string.h>

struct ReviewSetting {
    FILE *file;
    char filename[256];
    char line[256];
    int commentsFound;
};

int main() {
    struct ReviewSetting file;
    char line[256];

    // Request the file name from the user
    printf("Enter a file name: ");
    scanf("%s", file.filename);

    // Initialize commentFound
    file.commentsFound = 0;

    // Open the file for reading
    FILE *fp = fopen(file.filename, "r");

    // Check if the file was opened
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Read the file line by line and look for comments
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "//") != NULL) {
            printf("Found commentary: %s", line);
            file.commentsFound = 1;
        }
    }

    // Close the file
    fclose(fp);

    // Check if comments were found
    if (file.commentsFound == 0) {
        printf("Error: No comments on the code.\n");
    }

    return 0;
}

