#include "../includes/philo.h"

void	end_of_the_banquet(t_info *data, t_philosopher *philo, int status)
{
	int	i;

	i = status;
	i = 0;
	pthread_mutex_unlock(&(data->message));
	usleep(100);
	while (i < data->num_philo)
	{
		status = pthread_mutex_unlock(&(data->forks[i]));
		status = pthread_mutex_unlock(&(data->philosophers[i].first_kill));
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&(data->satisfaction_counter));
	while (i < data->num_philo)
	{
		//pthread_join(philo[i].t_philo, NULL);
		pthread_detach(philo[i].t_philo);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->message));
		pthread_mutex_destroy(&(data->democritus));
		i++;
	}
}

/*
static void	leaks(void)
{
	system("leaks philo");
}

atexit(leaks);
*/
int	main(int argc, char*argv[])
{
	t_info	*data;

	if (argc != 5 && argc != 6)
		return (print_instruction());
	data = (t_info *)malloc(sizeof(t_info));
	if (!data)
	{
		print_error(MALLOC_ERROR, NULL);
		return (0);
	}
	data = init_data(argc, argv, data);
	if (data == NULL)
	{
		print_error(INIT_ERROR, data);
		return (0);
	}
	return (the_banquet(data));
}
