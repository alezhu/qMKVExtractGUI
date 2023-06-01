#include "Application.h"
#include <exception>

int main(int argc, char *argv[])
{
	try
	{
		return Application::start(argc, argv);
	}
	catch (const std::exception &e)
	{
		//        e.what()
		return 1;
	}
}
