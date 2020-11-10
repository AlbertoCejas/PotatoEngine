#include <PotatoApp/PotatoApp.h>
#include <iostream>


int main(int argc, char** argv)
{
	PotatoApp app("PotatoApp");

	app.init();

	while (app.isShuttingDown() == false)
	{
		app.update();
	}

	return 0;
}