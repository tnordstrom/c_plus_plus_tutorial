/* Tony Nordstrom */
/* November 28 02024 */
/* 
 * Cellular Automata Version 0.1
 - Fill grid with random characters
 - Print the grid
 - Calculate the number of neighbouring full cells for each cell
 - Print the neighbour grid
 Version 0.2
 - Update the grid with rules for each cell
 These are Conway's Game of Life rules:
 Any alive cell that is touching less than two alive neighbours dies.
 Any alive cell touching four or more alive neighbours dies.
 Any alive cell touching two or three alive neighbours does nothing.
 Any dead cell touching exactly three alive neighbours becomes alive.
 - Accepts commands
 - Runs in a loop
 - Prints version / about string
 Version 0.3
 - Read rules from a json file
 - Apply changes by j command
 */

#include <iostream>
#include <random>

const std::string version { "0.2" };
const char empty { ' ' };
const char full { '#' };
const char unchanged { '-' };
const int grid_length { 20 };
const int grid_width { 80 };
char grid[grid_length][grid_width];
int neigh[grid_length][grid_width];
char full_cell_rules[9] =
{ empty, empty, unchanged, unchanged, empty, empty, empty, empty, empty };
char empty_cell_rules[9] =
{ unchanged, unchanged, unchanged, full, unchanged, unchanged, unchanged, unchanged, unchanged };
	
/* Calculate the number of neighbouring full cells */
int neighbours (int x, int y)
{
	int retval { 0 };
	bool on_edge_x { false };
	bool on_edge_y { false };
	bool on_edge_xx { false };
	bool on_edge_yy { false };
	
	/* Edge detection */
	if (x == 0)
		on_edge_x = true;
	if (y == 0)
		on_edge_y = true;
	if (x == grid_length)
		on_edge_xx = true;
	if (y == grid_width)
		on_edge_yy = true;
		
	if ((on_edge_x == false) && (on_edge_y == false))
	{
		if (grid[x-1][y-1] == full)
		{
			retval++;
		}
	}
	if (on_edge_y == false)
	{
		if (grid[x][y-1] == full)
		{
			retval++;
		}
	}
	if ((on_edge_xx == false) && (on_edge_y == false))
	{
		if (grid[x+1][y-1] == full)
		{
			retval++;
		}
	}
	if (on_edge_x == false)
	{
		if (grid[x-1][y] == full)
		{
			retval++;
		}
	}
	if (on_edge_xx == false)
	{
		if (grid[x+1][y] == full)
		{
			retval++;
		}
	}
	if ((on_edge_x == false) && (on_edge_yy == false))
	{
		if (grid[x-1][y+1] == full)
		{
			retval++;
		}
	}
	if (on_edge_yy == false)
	{
		if (grid[x][y+1] == full)
		{
			retval++;
		}
	}
	if ((on_edge_xx == false) && (on_edge_yy == false))
	{
		if (grid[x+1][y+1] == full)
		{
			retval++;
		}
	}
	
	return retval;
}

/* Apply the neighbour rules to the cell */
void apply_rules(int x, int y)
{
	if (grid[x][y] == full)
	{
		if (full_cell_rules[neigh[x][y]] != unchanged)
		{
			grid[x][y] = full_cell_rules[neigh[x][y]];
		}
	}
	else if (grid[x][y] == empty)
	{
		if (empty_cell_rules[neigh[x][y]] != unchanged)
		{
			grid[x][y] = empty_cell_rules[neigh[x][y]];
		}
	}
	
	return;
}

int main ( void )
{
	
	/* Fill the grid with random empty / full characters */
	for (int i { 0 }; i < grid_length; i++)
	{
		for (int j { 0 }; j < grid_width; j++)
		{
			grid[i][j] = rand() % 2 ? empty : full;
		}
	}
	
	while (true)
	{
		/* Print the grid */
		for (int i { 0 }; i < grid_length; i++)
		{
			for (int j { 0 }; j < grid_width; j++)
			{
				std::cout << grid[i][j];
			}
			
			std::cout << '\n';
		}
	
		/* Calculate the neighbours, store in int array */
		for (int i { 0 }; i < grid_length; i++)
		{
			for (int j { 0 }; j < grid_width; j++)
			{
				neigh[i][j] = neighbours(i, j);
			}
		}
	
		/* Print the neighbour info */
		for (int i { 0 }; i < grid_length; i++)
		{
			for (int j { 0 }; j < grid_width; j++)
			{
				std::cout << neigh[i][j];
			}
		
			std::cout << '\n';
		}
	
		/* Apply the rules to the grid */
		for (int i { 0 }; i < grid_length; i++)
		{
			for (int j { 0 }; j < grid_width; j++)
			{
				apply_rules(i, j);
			}
		}
		
		/* Get a command from the user */
		char command { 0 };
		std::cin >> command;
		switch (command)
		{
			case 'q':
				goto exit;
			case 'r':
				continue; /* Doesn't do anything that any other non-q command does */
			case 'h':
			case '?':
				std::cout << "q - quit, r - run, h/? - help, a - about, j - reload json\n";
				break;
			case 'a':
				std::cout << "Cellular automata version " << version << " by Tony Nordstrom\n";
				break;
			case 'j':
				std::cout << "Reload rules from json file (TBD)\n";
				break;
			default:
				break;
		}
	}
	
exit:

	return 0;
}

