#include <stdio.h>
#include <stdlib.h>

int main()
{

	DIR* proc = opendir("/proc");
	struct dirent* ent;
	long tgid;

	if(proc == NULL) {
		perror("opendir(/proc)");
		return 1;
	}

	while(ent = readdir(proc)) {
		if(!isdigit(*ent->d_name))
			continue;

		tgid = strtol(ent->d_name, NULL, 10);

		print_status(tgid);
	}

	closedir(proc);
	return 0;
}
