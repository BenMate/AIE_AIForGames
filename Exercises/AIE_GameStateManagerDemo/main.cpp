
#include "raylib.h"
#include "raygui.h"

#include "Application.h"


#include <iostream>





int main(int argc, char** argv)
{
	{
		Application app(800, 450, "GameAI");
		app.Run();
	}
	return 0;
}
