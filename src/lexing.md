# 字句解析
字句解析器を作成していきます。

字句解析にはオートマトンを用います。

これは説明するより実装したほうが早いと思うので、簡単な字句解析器を以下に示します。

```c
#include <stdio.h>
#include <stdlib.h>

#define TK_MAX 256

static char *p;
static char *token;

int next() {
	int c;
	char *tk = (char *)malloc(sizeof(char) * TK_MAX);
	int tkc = 0;

	while (c = *p) {
		++p;

		if (c >= '0' && c <= '9') {
			tk[tkc++] = c;
			while (*p >= '0' && *p <= '9') tk[tkc++] = *p++;
			tk[tkc++] = '\0';
			
			token = tk;
			return 1;
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			tk[tkc++] = c;
			while ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) tk[tkc++] = *p++;
			tk[tkc++] = '\0';

			token = tk;
			return 1;
		}
	}

	return 0;
}

int main(int argc, char **argv) {
	if (argc < 2) return 1;

	p = argv[1];
	while (next()) {
		printf("%s\n", token);
	}
	
	return 0;
}
```