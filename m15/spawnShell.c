#include <unistd.h>
#include <string.h>

#define DEFAULTSHELL "/bin/bash"
#define MAXSHELLPATHLENGTH 50

int main(int argc, char** argv) {

	char shellName[MAXSHELLPATHLENGTH];
	char* shellNameP = (char*)shellName;

	if (argc <= 1) {
		strcpy(shellName, DEFAULTSHELL);
	} else {
		shellNameP = argv[1];
	}

	char *pargv[2];
	pargv[0] = shellNameP;
	pargv[1] = NULL;
	execve(pargv[0], pargv, NULL);
}
