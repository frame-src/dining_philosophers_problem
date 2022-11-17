#include "../includes/philo.h"

/*==========================================================*
|						PHILO STRUCT INIT					|
*===========================================================*
*	each philo have to grab a fork,
*	each philo have an id
*	knows when he eat last time
*	knows how many time he eat			
*==========================================================*/
static bool	init_philosophers(t_info **data)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * (*data)->num_philo);
	(*data)->philosophers = philo;
	if (!philo)
		return (print_error(THREAD_ERROR, (*data)) && false);
	while (i < (*data)->num_philo)
	{
		philo[i].num = i;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % (*data)->num_philo;
		philo[i].time_last_meal = 0;
		philo[i].dinners_done = 0;
		philo[i].data = *data;
		if (pthread_mutex_init(&philo[i].first_kill, NULL) != 0)
			return (print_error(MUTEX_ERROR, *data) && false);
		if (pthread_mutex_init(&philo[i].buboes, NULL) != 0)
			return (print_error(MUTEX_ERROR, *data) && false);
		if (pthread_mutex_init(&philo[i].digestion, NULL) != 0)
			return (print_error(MUTEX_ERROR, *data) && false);
		i++;
	}
	return (true);
}

/*==========================================================*
|						MUTEX	INIT						|
*===========================================================*
*	Every Philosopher has a fork,
*	each fork is a mutex;
===========================================================*/
static bool	init_mutex(t_info **data)
{
	int	i;

	i = 0;
	(*data)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* ((*data)->num_philo));
	if (!(*data)->forks)
		return (print_error(MALLOC_ERROR, *data) && false);
	while (i < (*data)->num_philo)
	{
		if (pthread_mutex_init(&(*data)->forks[i], NULL) != 0)
			return (print_error(MUTEX_ERROR, *data) && false);
		i++;
	}
	if (pthread_mutex_init(&(*data)->democritus, NULL) != 0)
		return (print_error(MUTEX_ERROR, *data) && false);
	if (pthread_mutex_init(&(*data)->message, NULL) != 0)
		return (print_error(MUTEX_ERROR, *data) && false);
	if (pthread_mutex_init(&(*data)->satisfaction_counter, NULL) != 0)
		return (print_error(MUTEX_ERROR, *data) && false);
	return (true);
}

/*==========================================================*
|						DATA STRUCT INIT					|
*===========================================================*
*	in the data struct i store all the
*	info that come from the parsing;
*==========================================================*/
t_info	*init_data(int argc, char **argv, t_info *data)
{
	if (!check_input(&data, argc, argv))
		return (NULL);
	if (!init_philosophers(&data))
		return (NULL);
	if (!init_mutex(&data))
		return (NULL);
	return (data);
}
