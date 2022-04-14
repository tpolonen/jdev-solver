#include <stdio.h>
#include <stdlib.h>
#define MAP_SIZE 2000

const int DIRS[4][2] = {
	{ 1, 0 }, // Right
	{ 0, 1 }, // Down
	{ -1, 0 },// Left
	{ 0, -1 } // up
};

char **read_map(char *filename, char **map);
int solve_map(char *map);

int	main(int ac, char **av) {
	char map[MAP_SIZE] = { };

	if (ac != 2) {
		printf("usage: ./solver [filename]\n");
		exit(1);
	};
	return (solve_map(read_map(av[1], (char **)&map)));
}

char **read_map(char *pathname, char **map) {
	FILE *mapfile = fopen(pathname, "r");
	if (!mapfile) {
		perror("(read_map) Couldn't read file");
		exit(2);
	}
	fread((void *)*map, 1, MAP_SIZE, mapfile);
	fclose(mapfile);
	return (map);
}

int solve_map(char *map) {
	int result = 1;
	size_t cols = 0;

	return (result);
}
