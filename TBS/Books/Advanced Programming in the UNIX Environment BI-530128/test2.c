#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "Geeks \t\nfor \t\nHeros";

	printf("%s\n\n", str);

	// Returns first token
	int len = strlen(str);
	char *token = strtok(str, " \t\n");
	char **string;
	int cnt = 0, i, j;

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " \t\n");
		++cnt;
	}

	string = (char**) malloc(sizeof(char*) * cnt);

	printf("%d %d\n", len, cnt);

	for (int i = 0; i < len; i++)
		printf("%d\n", str[i]);

	string[j = 0] = str;

	for (i = 0; i < len; i++)
		if (str[i] == '\0' && j < cnt)
			string[++j] = &str[++i];

	for (int i = 0; i < cnt; i++)
		printf("%s", string[i]);

	return 0;
}
