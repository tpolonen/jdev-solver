#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAP_SIZE 2000

enum DIRS {NORTH, EAST, SOUTH, WEST};

const char START = 'S';
const char END = 'E';
const char WALL = '#';

char *read_map(char *filename, char *map);
size_t solve_map(char *map);
char *step(char *seek, size_t cols);

int	main(int ac, char **av) {
	char map[MAP_SIZE + 1] = { };

	if (ac != 2) {
		printf("usage: ./solver [filename]\n");
		exit(1);
	};
	size_t steps = solve_map(read_map(av[1], map));
	printf("took %ld steps\n\ntrace:\n%s\n", steps, map);
	return (0);
}

char *read_map(char *pathname, char *map) {
	FILE *mapfile = fopen(pathname, "r");
	if (!mapfile) {
		perror("(read_map) Couldn't read file");
		exit(2);
	}
	fread(map, 1, MAP_SIZE, mapfile);
	fclose(mapfile);
	return (map);
}

size_t solve_map(char *map) {
	char *seek = map;
	size_t cols = 1; // start from 1 to take newline in to account

	while (*(seek++) != '\n') cols++;
	while (*seek != START) seek++;

	size_t steps = 0;
	while (1) {
		seek = step(seek, cols);
		steps++;
		if (*seek == END) break ;
		if (!isdigit(*seek)) *seek = '1';
		else (*seek)++;
	}

	return (steps);
}

char *step(char *s, size_t cols) {
	static enum DIRS dir;
	char *next = s;

	while (next == s) {
		switch (dir) {
			case NORTH:
			next -= cols;
			break;

			case EAST:
			next++;
			break;

			case SOUTH:
			next += cols;
			break;

			case WEST:
			next--;
			break;
		}
		if (*next == WALL) {
			next = s;
			dir = (dir + 1) % 4;
		}
	}
	return (next);
}
