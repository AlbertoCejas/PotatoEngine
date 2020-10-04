#include <PotatoEngine/Core/Plugin.h>
#include <iostream>


int main(int argc, char** argv)
{
	potato::Plugin plugin("test", 1);

	const char* name = plugin.getName();

	std::cout << "Plugin name: " << name << std::endl;

	return 0;
}