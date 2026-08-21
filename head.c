#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void head(int fd, int lines) {
	int count = 0, n;

	while (count < lines && ((n = read(fd, buf, sizeof(buf))) > 0)) {
		for (int i = 0; i < n && count < lines; i++) {
			if(write(1, &buf[i], 1) != 1) {
				printf(1, "head: write error\n");
				exit();
			}

			if (buf[i] == '\n') {
				count++;
			}
		}
	}

	if (n < 0) {
		printf(1, "head: read error\n");
		exit();
	}
}

int main(int argc, char *argv[]) {
	int fd, lines = 10;

	if (argc <= 1) {
		head(0, lines);
		exit();
	}

	for (int i = 1; i < argc; i++) {
		fd = open(argv[i], 0);
    		if (fd < 0) { 
      			printf(1, "head: cannot open %s\n", argv[i]);
      			exit();
    		}
    		head(fd, lines);
    		close(fd);
  	}

	exit();
}