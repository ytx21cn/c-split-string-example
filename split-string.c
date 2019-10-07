#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** splitStr(char* str, unsigned int* tokensCounter) {

	// split the string by white spaces, and add NULL at the end
	// NOTE: the memory allocated for resultArr must be freed afterwards

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
	char str[] = " This is a sample string   ";
	unsigned int tokens = 0;
	char** result = splitStr(str, &tokens);

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

	free(result);

	return 0;
}
