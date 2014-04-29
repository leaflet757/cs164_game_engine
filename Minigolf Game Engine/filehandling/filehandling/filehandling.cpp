// filehandling.cpp : Defines the entry point for the console application.
//
//
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <stdio.h>
#include <ctype.h>

struct Tile
{
public:
	int id;
	int edges;
	std::vector<float> x;
	std::vector<float> y;
	std::vector<float> z;
	std::vector<int> neighbors;
	Tile()
	{
		x = std::vector<float>();
		y = std::vector<float>();
		z = std::vector<float>();
		neighbors = std::vector<int>();
	}
};

struct Wall
{
public:
	std::vector<float> x1;
	std::vector<float> y1;
	std::vector<float> z1;
	std::vector<float> x2;
	std::vector<float> y2;
	std::vector<float> z2;
	Wall()
	{
		x1 = std::vector<float>();
		y1 = std::vector<float>();
		z1 = std::vector<float>();
		x2 = std::vector<float>();
		y2 = std::vector<float>();
		z2 = std::vector<float>();
	}
};

struct Tee
{
public:
	int id;
	float x;
	float y;
	float z;
};

struct Cup
{
public:
	int id;
	float x;
	float y;
	float z;
};

std::vector<Tile> returnTile(std::vector<Tile> &a)
{
	return a;
};

Cup returnCup(Cup a)
{
	return a;
};

Tee returnTee(Tee a)
{
	return a;
};

bool is_int(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool is_float(const std::string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

//Checks - make sure no illegal characters, check if int is negative

int main(int argc, char** argv)
{
	//Storage for Tiles/Cups/Tee
	std::vector<Tile> tilesStore = std::vector<Tile>();
	std::vector<Wall> wallsStore = std::vector<Wall>();
	Cup cupStore = Cup();
	Tee teeStore = Tee();
	//Counter for counting number of Tiles, Cups, and Tees.
	int numTiles = 0;
	int numCup = 0;
	int numTee = 0;
	//Counters to assist with adding to vectors.
	int counterTotalTiles = 0;
	//These get cleared every time it reads in Tiles/Cups/Tees.
	int counter = 0;
	int counterTiles = 0;
	int counterCoordsAndNeigh = 0;
	int counterCup = 0;
	int counterTee = 0;

	std::ifstream fileName;

	fileName.open((char *)argv[1]);

	//Check if file name is passed into arguments.
	if(!fileName)
	{
		std::cout << "Unable to open file";
		exit(-1);
	}

	for(std::string line; std::getline(fileName, line); )   //read stream line by line
	{
		std::istringstream in(line);      //make a stream for the line itself

		std::string type;
		in >> type;                  //and read the first whitespace-separated token

		if(type == "Tile" || type == "tile")       //and check its value
		{
			numTiles = numTiles + 1;
			Tile newTile = Tile();
			tilesStore.push_back(newTile);
			Wall newWall = Wall();
			wallsStore.push_back(newWall);
			std::string stringID = std::string();
			std::string stringEdges = std::string();

			//in >> tilesStore[tilesStore.size()-1].id >> tilesStore[tilesStore.size()-1].edges; //stores next two numbers into id and edges.
			in >> stringID >> stringEdges;
			if(is_int(stringID))
			{
				if(atoi(stringID.c_str()) < 0)
				{
					std::cout << "Tile id cannot be a negative number.";
					exit(-1);
				}
			} else {
				std::cout << "Tile id has unknown characters.";
				exit(-1);
			}

			if(is_int(stringEdges))
			{
				if(atoi(stringEdges.c_str()) < 1)
				{
					std::cout << "Tile edges cannot be 0 or a negative number.";
					exit(-1);
				}
			} else {
				std::cout << "Tile edges have unknown character(s) in it.";
				exit(-1);
			}
			
			//atoi(stringEdges.c_str());

			tilesStore[tilesStore.size()-1].id = atoi(stringID.c_str());
			tilesStore[tilesStore.size()-1].edges = atoi(stringEdges.c_str());
			
			counterCoordsAndNeigh = tilesStore[tilesStore.size()-1].edges; //stores a counter for the next for loop.
			
			std::string stringX = std::string(); // temporary variables to store in.
			std::string stringY = std::string();
			std::string stringZ = std::string();
			std::string stringNeigh = std::string();
			/*float tempX = 0.0; 
			float tempY = 0.0;
			float tempZ = 0.0;
			int tempNeigh = 0;*/


			for(counter = 0; counter <= counterCoordsAndNeigh-1; counter++){ // checks white spaces for the next three values and stores into x, y, z temps.
				in >> stringX >> stringY >> stringZ;
				if(is_float(stringX) && is_float(stringY) && is_float(stringZ)){
					tilesStore[tilesStore.size()-1].x.push_back(atof(stringX.c_str())); //Puts x, y, and z in.
					tilesStore[tilesStore.size()-1].y.push_back(atof(stringY.c_str()));
					tilesStore[tilesStore.size()-1].z.push_back(atof(stringZ.c_str()));
				} else {
					std::cout << "xyz points contain unknown characters.";
					exit(-1);
				}
			}
			int wallCounter = 0;
			for(counter = 0; counter <= counterCoordsAndNeigh-1; counter++){ // stores each number afterward within the neighbor resize
				in >> stringNeigh;
				if(is_int(stringNeigh)){
					tilesStore[tilesStore.size()-1].neighbors.push_back(atoi(stringNeigh.c_str())); // push neighbor onto vector
				} else {
					std::cout << "Invalid character in neighbors.";
					exit(-1);
				}
				if (atoi(stringNeigh.c_str()) == 0 && tilesStore[tilesStore.size()-1].neighbors.size() < counterCoordsAndNeigh){ // If this is 0 and less than the size of edges, we store a pair of coordinates
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);
						std::cout << wallsStore[wallsStore.size() - 1].x1[wallCounter] << " " << wallsStore[wallsStore.size() - 1].y1[wallCounter] << " " << wallsStore[wallsStore.size() - 1].z1[wallCounter] << " | ";
						
						// Stores second coordinate
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[counter+1]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[counter+1]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[counter+1]);
						std::cout << wallsStore[wallsStore.size() - 1].x2[wallCounter] << " " << wallsStore[wallsStore.size() - 1].y2[wallCounter] << " " << wallsStore[wallsStore.size() - 1].z2[wallCounter] << "\n";
						wallCounter+=1;
					} else if (atoi(stringNeigh.c_str()) == 0 && tilesStore[tilesStore.size()-1].neighbors.size() == counterCoordsAndNeigh){ //If neighbor is 0 and we're at the last number, we get the current coordinates and the coordinates in the first slot.
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);
						std::cout << wallsStore[wallsStore.size() - 1].x1[wallCounter] << " " << wallsStore[wallsStore.size() - 1].y1[wallCounter] << " " << wallsStore[wallsStore.size() - 1].z1[wallCounter] << " | ";
						// Stores second coordinate.
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[0]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[0]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[0]);
						std::cout << wallsStore[wallsStore.size() - 1].x2[wallCounter] << " " << wallsStore[wallsStore.size() - 1].y2[wallCounter] << " " << wallsStore[wallsStore.size() - 1].z2[wallCounter] << "\n";
						wallCounter+=1;
					}
			}
			wallCounter = 0;
		}
		else if(type == "Tee" || type == "tee"){ //If it's a tee, read in the tee's id.
			in >> teeStore.id;
			if(teeStore.id < 0) 
			{
				std::cout << "Tee id cannot be a negative number.";
				exit(-1);
			}
			in >> teeStore.x >> teeStore.y >> teeStore.z; // read the whitespace-separated floats + store.
		}
		else if(type == "Cup" || type == "cup")
		{
			in >> cupStore.id; //If it's a cup, read in the cup's id.
			if(cupStore.id < 0) 
			{
				std::cout << "Cup id cannot be a negative number.";
				exit(-1);
			}
			in >> cupStore.x >> cupStore.y >> cupStore.z;
		} else {
			std::cout << "Invalid entry or invalid length.";
			exit(-1);
		}
		if(numTiles == 0){
			std::cout << "You need at least one tile.";
			exit(-1);
		}
	}

	
	//For Debug purposes
	for(counter = 0; counter <= tilesStore.size()-1; counter++){
			std::cout << tilesStore[counter].id << " " << tilesStore[counter].edges << " ";
			for (int i = 0; i <= tilesStore[counter].x.size()-1; i++){
				std::cout << tilesStore[counter].x[i] << " " << tilesStore[counter].y[i] << " " << tilesStore[counter].z[i];
			}
			std::cout << std::endl;
		}
	std::cout << cupStore.id << " " << cupStore.x << " " << cupStore.y << " " << cupStore.z;
	std::cout << std::endl;
	std::cout << teeStore.id << " " << teeStore.x << " " << teeStore.y << " " << teeStore.z;
	std::cout << std::endl;
	/*for(counter = 0; counter <= wallsStore.size()-1; counter++){
			for (int i = 0; i <= wallsStore[counter].x.size()-1; i++){
				if(wallsStore[counter].x[i] != NULL){
					std::cout << wallsStore[counter].x[i] << " " << wallsStore[counter].y[i] << " " << wallsStore[counter].z[i];
				}
			}
			std::cout << std::endl;
		}*/

	return 0;
}

