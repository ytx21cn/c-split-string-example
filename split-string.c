#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** splitStr(const char* str) {
	
	// split the string by white spaces, and add NULL at the end
	
	const char* delims = " \n\t\v\f\r";
	
	char* sdup = strdup(str);
	void* sdup_orig = sdup;
	
	unsigned int numTokens = 0;
	char** resultArr = NULL;
	
	char* found = NULL;
	
	do {
		found = strsep(&sdup, delims);
		
		if ((found == NULL) || (strcmp(found, "") != 0)) {
			++numTokens;
			resultArr = (char**)realloc(resultArr, numTokens * sizeof(char*));
			
			if (!resultArr) { // on error
				free(found);
				free(sdup_orig);
				free(resultArr);
				exit(-1);
			}
			
			resultArr[numTokens-1] = found;
		}
		
	} while (found != NULL);
	
	
	// print out, for testing only
	for (unsigned int i = 0; i < numTokens; ++i) {
		char* resultStr = resultArr[i];
		if (resultStr != NULL) {
			printf("%s\n", resultStr);
		}
		else {
			printf("[NULL]\n");
		}
	}
	
	free(found);
	free(sdup_orig);
	free(resultArr);
	
	return resultArr;
}


int main () {
	char str[] = "   This is a string  ";
	splitStr(str);
	return 0;
}

