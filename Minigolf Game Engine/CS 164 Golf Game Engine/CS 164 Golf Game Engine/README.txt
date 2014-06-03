Computer Science 164: Game Engines

Authors: 
Leif Myer
Jonah Nobelza

Minigold game written in c++ using the Visual Studio 2012 compiler.
To run the game, either launch the game from the debug folder by clicking on "CS 164 Golf Game Engine.exe", or launch the project from visual studio.

Change log from 6.2.14
- HUD Suppport work in progress
	- The data structures are still being established to work in the c++ language
- Refactoring of main to be less dependant
	- code was move to their respective components
	- still in progress of refactoring ball class
	- most of ball collision test code should be moved to physics
- ball movement and direction added
	- user can control direction and power of shot with the ball
- ball collision with cup added
	- message will apear in terminal if ball collides with cup
- level management added
	- the 'n' and 'b' keys control next level and previous level
	- only two levels are currently being loaded however
- User can now change camera position with 1,2,3 buttons
- User can strafe camera with a and d buttons
- User can zoom camera with w and s buttons
- Bugs found with shader code
- Bugs found with force code, it has been left out of this version

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