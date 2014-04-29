#include "IOManager.h"


IOManager::IOManager()
{
}


IOManager::~IOManager()
{
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

std::vector<Level>* IOManager::loadLevels(int argc, char **argv)
{
	std::vector<Level>* levels = new std::vector<Level>();

	for (int i = 1; i < argc; i++)
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

		std::string str = "";
		str.append((char *)argv[i]);

		// open the file
		fileName.open(str);

		//Check if file name is passed into arguments.
		if (!fileName)
		{
			std::cout << "Unable to open file";
			exit(-1);
		}

		for (std::string line; std::getline(fileName, line);)   //read stream line by line
		{
			std::istringstream in(line);      //make a stream for the line itself

			std::string type;
			in >> type;                  //and read the first whitespace-separated token

			if (type == "Tile" || type == "tile")       //and check its value
			{
				numTiles = numTiles + 1;
				Tile newTile = Tile();
				tilesStore.push_back(newTile);
				Wall newWall = Wall();
				wallsStore.push_back(newWall);
				std::string stringID = std::string();
				std::string stringEdges = std::string();

				in >> stringID >> stringEdges; //store in ID and Edges strings

				// checks if id is a positive integer
				if(is_number(stringID))
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

				// checks if edges is a positive integer
				if(is_number(stringEdges))
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

				//stores into tiles if it passes the checks
				tilesStore[tilesStore.size()-1].tileID = atoi(stringID.c_str());
				tilesStore[tilesStore.size()-1].edges = atoi(stringEdges.c_str());


				counterCoordsAndNeigh = tilesStore[tilesStore.size() - 1].edges; //stores a counter for the next for loop.
				float tempX = 0.0; // temporary variables to store in.
				float tempY = 0.0;
				float tempZ = 0.0;
				int tempNeigh = 0;
				for (counter = 0; counter <= counterCoordsAndNeigh - 1; counter++){ // checks white spaces for the next three values and stores into x, y, z temps.
					in >> tempX >> tempY >> tempZ;
					tilesStore[tilesStore.size() - 1].x.push_back(tempX); //Puts x, y, and z in.
					tilesStore[tilesStore.size() - 1].y.push_back(tempY);
					tilesStore[tilesStore.size() - 1].z.push_back(tempZ);
				}
				for(counter = 0; counter <= counterCoordsAndNeigh-1; counter++){ // stores each number afterward within the neighbor resize
					in >> tempNeigh;
					tilesStore[tilesStore.size()-1].neighbors.push_back(tempNeigh); // push neighbor onto vector

					// If this is 0 and less than the size of edges, we store a pair of coordinates
					if (tempNeigh == 0 && tilesStore[tilesStore.size()-1].neighbors.size() < counterCoordsAndNeigh){ 
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);

						// Stores second coordinate
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[counter+1]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[counter+1]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[counter+1]);

					} 
					//If neighbor is 0 and we're at the last number, we get the current coordinates and the coordinates in the first slot.
					else if (tempNeigh == 0 && tilesStore[tilesStore.size()-1].neighbors.size() == counterCoordsAndNeigh){ 
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);
						// Stores second coordinate.
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[0]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[0]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[0]);
					}
				}
			}
			else if (type == "Tee" || type == "tee"){ //If it's a tee, read in the tee's id.
				in >> teeStore.tID;
				if (teeStore.tID < 0)
				{
					std::cout << "Tee id cannot be a negative number.";
					exit(-1);
				}
				in >> teeStore.x >> teeStore.y >> teeStore.z; // read the whitespace-separated floats + store.
			}
			else if (type == "Cup" || type == "cup")
			{
				in >> cupStore.cupID; //If it's a cup, read in the cup's id.
				if (cupStore.cupID < 0)
				{
					std::cout << " Cup id cannot be a negative number.";
					exit(-1);
				}
				in >> cupStore.x >> cupStore.y >> cupStore.z;
			}
			else {
				std::cout << "Invalid entry or invalid length.";
				exit(-1);
			}
			if (numTiles == 0){
				std::cout << "You need at least one tile.";
				exit(-1);
			}
		}
		Level level(tilesStore, wallsStore, cupStore, teeStore);
		levels->push_back(level);
	}

	return levels;
}