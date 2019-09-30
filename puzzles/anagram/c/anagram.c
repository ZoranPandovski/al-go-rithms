#include <stdio.h>
#include <string.h>
#define N 1e5

int is_anagram(char a[], char b[]) {

	int size_a = strlen(a);
	int size_b = strlen(b);
	if(size_a != size_b)
		return 0;

	int count[26];
	int i;
	for(i = 0; i < 26; ++i)
		count[i] = 0;

	for(i = 0; i < size_a; ++i)
		count[a[i] - 'a']++;

	for(i = 0; i < size_b; ++i)
		count[b[i] - 'a']--;

	for(i = 0; i < 26; ++i)
		if(count[i] != 0)
			return 0;
	return 1;
}

int main() {
	char a[] = "iggam";
	char b[] = "maggi";

	printf("%d\n", is_anagram(a, b));
}