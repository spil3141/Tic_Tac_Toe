#include "CustomServer.h"

#ifdef T_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	CustomServer server("127.0.0.1",60000);
	server.Start();

	while (1)
	{
		server.Update(-1, true);
	}

	return 1;
}

#else
#error Only Support Windows
#endif
