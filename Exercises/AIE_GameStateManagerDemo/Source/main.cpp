#include "raylib.h"
#define RAYGUY_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "Application.h"

#include <iostream>


int main(int argc, char** argv)
{
	{
		Application app(1600, 900);
		app.Run();
	}
	return 0;
}



//TODO:

//fix hard coded "60" value representing the radius of nearby nodes to connect
// ( getters and setters)

//add variables to customise the graph2Deditor's node 
//- node color
//- line color
//- node radius 
//- node outline

//can you do a hovor color on nodes (prevent nodes from being placed on top of each other) ...tip -  get nearbynode function 
