#include "sh21.h"
#include "builtins.h"

int				btin_exit(int status)
{
	ft_putendl_fd("exit", 1);
	destruct_globals();
	exit(status);
}
