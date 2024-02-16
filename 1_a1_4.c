#include <stdio.h>

int main() 
{
    FILE *file;
    char filename[100];
    char character;
    
    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the character to find frequency: ");
    scanf(" %c", &character); 

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    int frequency = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) 
    {
        if (ch == character)
            frequency++;
    }

    printf("Frequency of '%c' in the file: %d\n", character, frequency);

    fclose(file);
    return 0;
}