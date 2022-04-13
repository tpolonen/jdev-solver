#define <stdio.h>
#define MAP_SIZE 2000

char *read_map(char *filename, char **buf);
int solve_map(char *map);

int	main(int ac, char **av) {
	char map[MAP_SIZE] = { };

	if (ac != 2) {
		printf("usage: ./solver [filename]\n");
		exit(1);
	};
	return (solve_map(read_map(av[1], &buf));
}

char *read_map(char *pathname, char **buf) {
	FILE *mapfile = fopen(pathname, "r");
	if (!mapfile) {
		perror("(read_map) Couldn't read file");
		exit(2);
	}
	char *map = NULL;
	return (map);
}

int solve_map(char *map) {
	int result = 1;
	return (result);
}
