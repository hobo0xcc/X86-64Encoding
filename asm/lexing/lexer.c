#define TK_MAX 256

static char *p = "abc 123 de45fg";
static char *token;

int next() {
	int c;
	char tk[TK_MAX];
	int tkc = 0;

	while (c = *p) {
		++p;

		if (c >= '0' && c <= '9') {
			tk[tkc++] = c;
			while (*p >= '0' && *p <= '9') tk[tkc++] = *p++;
			tk[tkc++] = '\0';
			
			token = tk;
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			tk[tkc++] = c;
			while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) tk[tkc++] = *p++;
			tk[tkc++] = '\0';

			token = tk;
		}
	}
}
