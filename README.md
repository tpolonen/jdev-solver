# jdev-solver
Quick program thrown together to solve a specific pre-application assignment.

Given a map which consists of walls (character #), floors (character .), starting position (letter S) and ending position (letter E), count how many steps robot needs to take to reach the ending position from the starting position.

Robot has following rules for movement:
* Starting direction is always up.
* If the robot is about to hit an obstacle, it should turn right before it and move forward.
* If the robot enters into S character after the start, treat S as a dot, so count it as a step.
* (E) character is counted as step.
