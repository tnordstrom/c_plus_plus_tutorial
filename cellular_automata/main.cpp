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
 - Command j reads rules from a json file, using json library from https://json.nlohmann.me/
 - Refactored out unchanged 3rd state in rules
 - Grid is now bool not char
 - Converts to char only on print
 - Command p prints out the rules
 Version 0.4
 - Command z sets rules to random
 - Command s saves rules to json
 - Command d sets rules to default
 - Command e edits rules manually
 */

#include <iostream>
#include <fstream>
#include <random>
#include "json.hpp"

using json = nlohmann::json;

const std::string version { "0.3" };
const char empty { ' ' };
const char full { '#' };
const int grid_length { 20 };
const int grid_width { 80 };
bool grid[grid_length][grid_width];
int neigh[grid_length][grid_width];
bool full_cell_rules[9] =
{ 0, 0, 1, 1, 0, 0, 0, 0, 0 };
bool empty_cell_rules[9] =
{ 0, 0, 0, 1, 0, 0, 0, 0, 0 };

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
		if (grid[x-1][y-1] == true)
		{
			retval++;
		}
	}
	if (on_edge_y == false)
	{
		if (grid[x][y-1] == true)
		{
			retval++;
		}
	}
	if ((on_edge_xx == false) && (on_edge_y == false))
	{
		if (grid[x+1][y-1] == true)
		{
			retval++;
		}
	}
	if (on_edge_x == false)
	{
		if (grid[x-1][y] == true)
		{
			retval++;
		}
	}
	if (on_edge_xx == false)
	{
		if (grid[x+1][y] == true)
		{
			retval++;
		}
	}
	if ((on_edge_x == false) && (on_edge_yy == false))
	{
		if (grid[x-1][y+1] == true)
		{
			retval++;
		}
	}
	if (on_edge_yy == false)
	{
		if (grid[x][y+1] == true)
		{
			retval++;
		}
	}
	if ((on_edge_xx == false) && (on_edge_yy == false))
	{
		if (grid[x+1][y+1] == true)
		{
			retval++;
		}
	}
	
	return retval;
}

/* Apply the neighbour rules to the cell */
void apply_rules(int x, int y)
{
	if (grid[x][y] == true)
	{
		grid[x][y] = full_cell_rules[neigh[x][y]];
	}
	else if (grid[x][y] == false)
	{
		grid[x][y] = empty_cell_rules[neigh[x][y]];
	}
	
	return;
}

/* Read rule set from json file */
void get_json(void)
{

	std::ifstream i("rules.json");
	auto j = json::parse(i);
	std::cout << j.dump(2) << '\n';

	int index { 0 };
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		std::cout << it.key() << ": " << it.value() << '\n';
		if (index < 9)
		{
			empty_cell_rules[index] = it.value();
		}
		else
		{
			full_cell_rules[index-9] = it.value();
		}
		index++;
	}	
	return;
}

/* Print the current rules */
void print_rules(void)
{
	std::cout << "empty_cell_rules: ";
	for (int i { 0 }; i <= 8; i++)
	{
		std::cout << empty_cell_rules[i] << ", ";
	}
	std::cout << '\n';
	
	std::cout << "full_cell_rules: ";
	for (int i { 0 }; i <= 8; i++)
	{
		std::cout << full_cell_rules[i] << ", ";
	}
	std::cout << '\n';
	
	return;
}

int main ( void )
{
	
	/* Fill the grid with random empty / full characters */
	for (int i { 0 }; i < grid_length; i++)
	{
		for (int j { 0 }; j < grid_width; j++)
		{
			grid[i][j] = rand() % 2 ? false : true;
		}
	}
	
	while (true)
	{
		/* Print the grid */
		for (int i { 0 }; i < grid_length; i++)
		{
			for (int j { 0 }; j < grid_width; j++)
			{
				std::cout << (grid[i][j] ? full : empty);
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
				std::cout << "q - quit, r - run, h/? - help, a - about, j - load rules from json, p - print rules\n";
				break;
			case 'a':
				std::cout << "Cellular automata version " << version << " by Tony Nordstrom\n";
				break;
			case 'j':
				std::cout << "Reload rules from json file\n";
				get_json();
				break;
			case 'p':
				print_rules();
				break;
			default:
				break;
		}
	}
	
exit:

	return 0;
}

