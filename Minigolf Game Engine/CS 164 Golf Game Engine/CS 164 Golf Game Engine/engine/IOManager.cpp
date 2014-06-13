#include "IOManager.h"


IOManager::IOManager()
{
}


IOManager::~IOManager()
{
}

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

std::vector<Level>* IOManager::loadLevels(int argc, char **argv)
{
	std::vector<Level>* levels = new std::vector<Level>();

	std::ifstream fileName;

	std::string courseName = "";
	int numberOfHoles = 0;

	std::string str = "./levels/"; //may or may not need/want
	str.append((char *)argv[1]);

	// open the file
	fileName.open(str);

	//read stream line by line
	for (std::string line; std::getline(fileName, line);)   {
		std::istringstream in(line);      //make a stream for the line itself

		std::string type;
		in >> type;

		if(type == "course"){
			
			std::string token = "";

			while(!in.eof()){
				in >> token;

				if(!is_int(token)) {
					courseName.append(token);
				} else {
					numberOfHoles = atoi(token.c_str());
				}
			}
			std::cout << courseName << " " << numberOfHoles << std::endl;
		}

		else if(type == "begin_hole"){
			// call load level if "begin_hole".
			levels->push_back(loadLevel(fileName));
		}
	}

	/*for (int i = 1; i < argc; i++)
	{
		std::ifstream fileName;

		std::string str = "./levels/";
		str.append((char *)argv[i]);

		// open the file
		fileName.open(str);

		//Check if file name is passed into arguments.
		if (!fileName)
		{
			std::cout << "Unable to open file";
			exit(-1);
		}
		levels->push_back(loadLevel(fileName));
	}*/

	return levels;
}

//
Level IOManager::loadLevel(std::ifstream &fileName){
	//Storage for Tiles/Cups/Tee
		std::vector<Tile> tilesStore = std::vector<Tile>();
		std::vector<Wall> wallsStore = std::vector<Wall>();
		Cup cupStore = Cup();
		Tee teeStore = Tee();
		int parNum = 0;
		std::string name = "";

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
		//for Course checking.
		int courseNum = 0;

	for (std::string line; std::getline(fileName, line);)   //read stream line by line
		{
			std::istringstream in(line);      //make a stream for the line itself

			std::string type;
			in >> type;                  //and read the first whitespace-separated token

			if(type == "end_hole"){ //if end_hole, break out of for loop.
				break;
			}

			else if(type == "par"){ // Gets par and stores par number.
				std::string parStr = std::string();
				in >> parStr;
				if(is_int(parStr)){
					parNum = atoi(parStr.c_str());
				} else {
					std::cout << "Par is not a number.";
					exit(-1);
				}
			}
			
			else if(type == "name"){ // Stores name.
				std::getline(in, name);
				//std::cout << name << std::endl;
			}
			
			// Checks for course.
			else if (type == "Tile" || type == "tile")       //and check its value
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
				if(is_int(stringID))
				{
					if(atoi(stringID.c_str()) < 1)
					{
						std::cout << "Tile id cannot be 0 or a negative number.";
						exit(-1);
					}
				} else {
					std::cout << "Tile id has unknown characters.";
					exit(-1);
				}

				// checks if edges is a positive integer
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

				//stores into tiles if it passes the checks
				tilesStore[tilesStore.size()-1].tileID = atoi(stringID.c_str());
				tilesStore[tilesStore.size()-1].edges = atoi(stringEdges.c_str());


				counterCoordsAndNeigh = tilesStore[tilesStore.size() - 1].edges; //stores a counter for the next for loop.

				std::string stringX = std::string(); // temporary variables to store in.
				std::string stringY = std::string();
				std::string stringZ = std::string();
				std::string stringNeigh = std::string();

				for (counter = 0; counter <= counterCoordsAndNeigh - 1; counter++){ // checks white spaces for the next three values and stores into x, y, z temps.
					in >> stringX >> stringY >> stringZ;
					if(is_float(stringX) && is_float(stringY) && is_float(stringZ)){ //Checks if they're floats before storing
						tilesStore[tilesStore.size()-1].x.push_back(atof(stringX.c_str())); //Puts x, y, and z in.
						tilesStore[tilesStore.size()-1].y.push_back(atof(stringY.c_str()));
						tilesStore[tilesStore.size()-1].z.push_back(atof(stringZ.c_str()));
						tilesStore[tilesStore.size()-1].xyz.push_back(glm::vec3(atof(stringX.c_str()), atof(stringY.c_str()), atof(stringZ.c_str()))); //just in case
						tilesStore[tilesStore.size()-1].addVert(atof(stringX.c_str()), atof(stringY.c_str()), atof(stringZ.c_str())); //using addVert
					} else {
						std::cout << "xyz points contain unknown characters.";
						exit(-1);
					}
				}
				for(counter = 0; counter <= counterCoordsAndNeigh-1; counter++){ // stores each number afterward within the neighbor resize
					in >> stringNeigh;
					if(is_int(stringNeigh)){ //Checks if positive integer.
						tilesStore[tilesStore.size()-1].neighborID.push_back(atoi(stringNeigh.c_str())); // push neighbor onto vector
					} else {
						std::cout << "Invalid character in neighborID.";
						exit(-1);
					}
					// If this is 0 and less than the size of edges, we store a pair of coordinates
					if (atoi(stringNeigh.c_str()) == 0 && tilesStore[tilesStore.size()-1].neighborID.size() < counterCoordsAndNeigh){ 
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);
						wallsStore[wallsStore.size() - 1].xyz_1.push_back(glm::vec3(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter], tilesStore[tilesStore.size() - 1].z[counter]));
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter], tilesStore[tilesStore.size() - 1].z[counter]);
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter]+0.1, tilesStore[tilesStore.size() - 1].z[counter]);
						// Stores second coordinate
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[counter+1]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[counter+1]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[counter+1]);
						wallsStore[wallsStore.size() - 1].xyz_2.push_back(glm::vec3(tilesStore[tilesStore.size() - 1].x[counter+1], tilesStore[tilesStore.size() - 1].y[counter+1], tilesStore[tilesStore.size() - 1].z[counter+1]));
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter+1], tilesStore[tilesStore.size() - 1].y[counter+1]+0.1, tilesStore[tilesStore.size() - 1].z[counter+1]);
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter+1], tilesStore[tilesStore.size() - 1].y[counter+1], tilesStore[tilesStore.size() - 1].z[counter+1]);
					} 
					//If neighbor is 0 and we're at the last number, we get the current coordinates and the coordinates in the first slot.
					else if (atoi(stringNeigh.c_str()) == 0 && tilesStore[tilesStore.size()-1].neighborID.size() == counterCoordsAndNeigh){ 
						// Stores first coordinate
						wallsStore[wallsStore.size() - 1].x1.push_back(tilesStore[tilesStore.size() - 1].x[counter]);
						wallsStore[wallsStore.size() - 1].y1.push_back(tilesStore[tilesStore.size() - 1].y[counter]);
						wallsStore[wallsStore.size() - 1].z1.push_back(tilesStore[tilesStore.size() - 1].z[counter]);
						wallsStore[wallsStore.size() - 1].xyz_1.push_back(glm::vec3(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter], tilesStore[tilesStore.size() - 1].z[counter]));
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter], tilesStore[tilesStore.size() - 1].z[counter]);
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[counter], tilesStore[tilesStore.size() - 1].y[counter]+0.1, tilesStore[tilesStore.size() - 1].z[counter]);
						// Stores second coordinate.
						wallsStore[wallsStore.size() - 1].x2.push_back(tilesStore[tilesStore.size() - 1].x[0]);
						wallsStore[wallsStore.size() - 1].y2.push_back(tilesStore[tilesStore.size() - 1].y[0]);
						wallsStore[wallsStore.size() - 1].z2.push_back(tilesStore[tilesStore.size() - 1].z[0]);
						wallsStore[wallsStore.size() - 1].xyz_2.push_back(glm::vec3(tilesStore[tilesStore.size() - 1].x[0], tilesStore[tilesStore.size() - 1].y[0], tilesStore[tilesStore.size() - 1].z[0]));
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[0], tilesStore[tilesStore.size() - 1].y[0]+0.1, tilesStore[tilesStore.size() - 1].z[0]);
						wallsStore[wallsStore.size() - 1].addVert(tilesStore[tilesStore.size() - 1].x[0], tilesStore[tilesStore.size() - 1].y[0], tilesStore[tilesStore.size() - 1].z[0]);
					}
				}
			}
			else if (type == "Tee" || type == "tee"){ //If it's a tee, read in the tee's id.
				numTee = numTee + 1;
				std::string teeID = std::string(); // temporary variables
				std::string teeX = std::string();
				std::string teeY = std::string();
				std::string teeZ = std::string();

				//read in first.
				in >> teeID;

				if(is_int(teeID)){ //if it's a positive integer, store it.
					teeStore.tID = atoi(teeID.c_str());
					if(teeStore.tID < 1) //if the ID is 0 or less, error.
					{
						std::cout << "Tee id cannot be 0 or a negative number.";
						exit(-1);
					}
				} else {
					std::cout << "Tee id contains invalid characters.";
					exit(-1);
				}
				in >> teeX >> teeY >> teeZ; // read the whitespace-separated floats + store.
				if(is_float(teeX) && is_float(teeY) && is_float(teeZ)){ // checks if they're all valid floats and stores them
					teeStore.x = atof(teeX.c_str());
					teeStore.y = atof(teeY.c_str());
					teeStore.z = atof(teeZ.c_str());
					teeStore.addVert(atof(teeX.c_str()), atof(teeY.c_str()), atof(teeZ.c_str()));
				} else {
					std::cout << "Tee coordinates contain invalid characters.";
					exit(-1);
				}
			}
			else if (type == "Cup" || type == "cup")
			{
				numCup = numCup + 1;
				std::string cupID = std::string(); //temporary cup variables
				std::string cupX = std::string();
				std::string cupY = std::string();
				std::string cupZ = std::string();

				in >> cupID;

				if(is_int(cupID)){ //if it's a positive integer, we store it. else, error.
					cupStore.cupID = atoi(cupID.c_str());
					if(cupStore.cupID < 1)  //cup id cannot be 0 or negative.
					{
						std::cout << "Cup id cannot be 0 or a negative number.";
						exit(-1);
					}
				} else {
					std::cout << "Cup id contains invalid characters.";
					exit(-1);
				}
				in >> cupX >> cupY >> cupZ; // read the whitespace-separated floats + store.
				if(is_float(cupX) && is_float(cupY) && is_float(cupZ)){ //checks if they're all floats. If so, store.
					cupStore.x = atof(cupX.c_str());
					cupStore.y = atof(cupY.c_str());
					cupStore.z = atof(cupZ.c_str());
					cupStore.addVert(atof(cupX.c_str()), atof(cupY.c_str()), atof(cupZ.c_str()));
				} else {
					std::cout << "Cup coordinates contain invalid characters.";
					exit(-1);
				}
			}
			else {
				std::cout << "Invalid entry or invalid length.";
				exit(-1);
			}
		}
		if (numTiles == 0){ //if there are no tiles, error.
			std::cout << "You need at least one tile.";
			exit(-1);
		}
		if (numTee > 1){
			std::cout << "You cannot have more than one tee.";
			exit(-1);
		}
		if (numCup > 1) {
			std::cout << "You cannot have more than one cup.";
			exit(-1);
		}
		if (numTee == 0){
			std::cout << "You need one tee.";
			exit(-1);
		}
		if (numCup == 0) {
			std::cout << "You need one cup.";
			exit(-1);
		}
		// O(n^3) SWAGGGGG
		for (Tile & t : tilesStore)
		{
			for (int id : t.neighborID)
			{
				for (Tile & n : tilesStore)
				{
					if (id == n.tileID && (&t != &n))
					{
						t.neighbors.push_back(&n);
					}
				}
			}
		}
		Level level(tilesStore, wallsStore, cupStore, teeStore);
		level.setPar(parNum);
		level.setName(name);
		return level;
}