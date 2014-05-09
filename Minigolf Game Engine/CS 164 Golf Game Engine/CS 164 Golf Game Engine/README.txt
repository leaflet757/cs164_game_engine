Computer Science 164: Game Engines

Authors: 
Leif Myer
Jonah Nobelza

Minigold game written in c++ using the Visual Studio 2012 compiler.
To run the game, either launch the game from the debug folder by clicking on "CS 164 Golf Game Engine.exe", or launch the project from visual studio.

Change log from 5.6.14
- partial level generation: levels load from files but walls are not generated
- aside from the walls, the program exits if the fileio is improper
- simple camera controls: the user is able to move the camera on a dolly but no pan or tilt
- cup and tee are now rendering
- added ball motion
- no collision detetion yet
- added physics.cpp and ticker.cpp component
- bug fixed with graphics manager and color
- fixed bug with position and scaling
- added physics properties to actor3d class