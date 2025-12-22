*This project has been created as part of the 42 curriculum by semebrah.*

# get_next_line #

## Description ##
This project's aim is to build up on write(unistd.h) and read up to a new line, hence invoking this functions would give you a new line or it will return NULL if it reached the end of a file or any kind of errors occures.

The bonus part of this project can handle multiple files, reading a new line from where it left off.

### Artifacts ###
`` char	*get_next_line(int fd); ``

This is the ultimate artifact of this project -- returns a new line on invocation or NULL on EOF or error.

### Algorithmic Approach ###
We have a buffer where we can read into and a temporary empty string. We start off by reading from the fd and then check if the buffer has newline('\n'), if it does it concatenates the buffer(up to and including the '\n') with the temporary string and returns the temporary string, else it concatenates the entire contents of the buffer with a temporary string and keeps doing this process all over again.

## Instructions ##
An example of usage of the program is as the following.

```

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>

void	display_files(int count, char **f_names)
{
	char	*res;
	int		fd_count;
	int		*fds;

	fd_count = count;
	fds = malloc(sizeof(int) * count);
	if (!fds)
		return ;
	for (int i = 0; i < count; i++)
	{
		fds[i] = open(f_names[i], O_RDONLY);
		if (fds[i] == -1)
		{
			dprintf(1, "Can't open %s\n", f_names[i]);
			fd_count--;
		}
	}
	while (fd_count > 0)
	{
		for (int i = 0; i < count; i++)
			if (fds[i] > 0)
			{
				if ((res = get_next_line(fds[i])))
				{
					dprintf(1, "%s", res);
					free(res);
				}
				else
				{
					close(fds[i]);
					fds[i] = -1;
					fd_count--;
				}
			}
	}
	free(fds);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_display_file(0);
	else
		display_files(argc - 1, &argv[1]);
}

```

## Resources ##
mainly manual page of `read (3)`

There was a moderate AI usage when developing this project, mainly on the library `sys/select.h` and on the `static` keyword.