/*
 * alter the last program so that instead of showing on the screen, put the line into file.
 */
#include <stdio.h>

#define LENGTH 10000
#define NAME_LENGTH 20

void write_to_file(char str_file[], char str[], int cnt);

int main(void)
{
	int char_input;
	int cnt = 0;
	char str[LENGTH];
	char str_file[NAME_LENGTH]; 
	/* Ask the user to input file name. */
	printf("Please input a string as file name:\n");
	/* Get file name. */
	scanf("%s", str_file);

	/* Ask the user to input characters. */
	printf("Please input characters, use ENTER to write characters to the specified file, use CTRL + A to end.\n");
	/* When the user doesn't input CTRL + A, keep reading characters. */
	while ((char_input = getchar()) != 1) {
		if (char_input == 10 && cnt > 0) {
			write_to_file(str_file, str, cnt);
			cnt = 0;
			continue;
		}
		str[cnt] = char_input;
		cnt++;
	}

	/* when the current line ends with CTRL + A, should write to file */
	if (cnt > 0) {
		/* Write the current line to file. */
		write_to_file(str_file, str, cnt);
	}
	return 0;
}

void write_to_file(char str_file[], char str[], int cnt) {
	FILE* fp; /* file handle */

	/* open file */
	fp = fopen(str_file, "w");

	/* Write the current line to the file. */
	for (int i = 0; i <= cnt - 1; i++) { /* count - 1 because at first we assign cnt = 0 which means we plus one to the length */
		fputc(str[i], fp);
	}
	fputc('\n', fp);
	/* Close the file. */
	fclose(fp);
}
