#include "prog.hpp"

int	main(int argc, char **argv)
{
	myAssert(argc == 2, "Usage: [prog.exe] [file]");
	Quad	quad = readData(argv[1]);
	
	Vec2	userPoint = getUserPoint();

	if (quad.isVertex(userPoint))
		return 0;
	if(quad.isSide(userPoint))
		return 0;
	quad.isInto(userPoint);
	return 0;
}
