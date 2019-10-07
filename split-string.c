#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 512

char** splitStr(char* str, unsigned int* tokensCounter) {

	/* split the string by white spaces, and add NULL at the end
		return an array of tokens (dynamically allocated)
		tokensCounter is updated at the end to save the number of tokens

		e.g.
			Input: "  This is a sample string   "
			Output: {"This", "is", "a", "sample", "string", NULL}
	*/
	// NOTE: the memory allocated for resultArr must be freed afterwards
	// using free() manually in subsequent code

	const char* delims = " \n\t\v\f\r";

	unsigned int numTokens = 0;
	char** resultArr = NULL;
	char* found = NULL;
	do {
		found = strsep(&str, delims);
		if ((found == NULL) || (strcmp(found, "") != 0)) {
			++numTokens;
			resultArr = (char**)realloc(resultArr, numTokens * sizeof(char*));
			if (!resultArr) { // on error
				free(found);
				free(resultArr);
				exit(-1);
			}
			resultArr[numTokens-1] = found;
		}
	} while (found != NULL);

	*tokensCounter = numTokens;

	free(found);

	return resultArr;
}


int main () {
	char str[MAX_INPUT_SIZE];
	size_t n = MAX_INPUT_SIZE;
	printf("Please type in your string: $ ");
	fgets(str, n, stdin);

	char* sdup = strdup(str);
	// make a copy of str, and pass it into splitStr
	// this copy has its own memory space, and must be freed afterwards

	unsigned int tokens = 0;
	char** result = splitStr(sdup, &tokens);

	// print out, for testing only
	printf("Tokens: %d\n", tokens);
	for (unsigned int i = 0; i < tokens; ++i) {
		char* resultStr = result[i];
		if (resultStr) {
			printf("%s\n", resultStr);
		}
		else {
			printf("[NULL]\n");
		}
	}

	printf("Original: %s\n", str); // str is unchanged

	free(sdup);
	free(result);

	return 0;
}
