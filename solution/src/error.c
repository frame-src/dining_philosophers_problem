#include "../includes/philo.h"

void	*print_error(char *message, t_info *data)
{
	printf("%s", message);
	if (data->philosophers)
		free(data->philosophers);
	if (data->forks)
		free(data->forks);
	free(data);
	return (NULL);
}

/*==========================================================*
|						PRINT INSTRUCTION					|
*==========================================================*/
int	print_instruction(void)
{
	printf("\nINSTRUCTION:\tplease insert: \n\n");
	printf("[argc1] = int:\tnum philosophers \n");
	printf("[argc2] = int:\ttime to death \n");
	printf("[argc3] = int:\ttime to eat \n");
	printf("[argc4] = int:\ttime to sleep \n");
	printf("[argc5] = int:\tnumber of dinners; \n\n");
	return (1);
}

//you should call with macro __func__
// void *failure(int flag,char *str)
// {
// 	int err_value;

// 	if (flag == 1)
// 	err_value = errno;
//     printf("%s failed\n", str);
//     if (err_value == ...){ ... }
// } 
