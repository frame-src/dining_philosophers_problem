#include "../includes/philo.h"

/*==========================================================*
|						DEATH CHECK							|
*===========================================================*
*	This is the function that check for DEATHS:
*
*	if: time_last_meal - timestamp is > than the time_to_death
*	in t_info then the philo is dead;
*
*	So we should change the value so that the main process can
*	turn the mutex(&message) on
*==========================================================*/
int	check_death(t_info **data)
{
	int				i;
	long long		time;
	t_philosopher	*philo;

	i = 0;
	time = timestamp();
	while (i < (*data)->num_philo)
	{
		philo = &(*data)->philosophers[i];
		pthread_mutex_lock(&(philo->digestion));
		if (philo->dinners_done == 0 && time - \
				(*data)->start < (*data)->time_to_death)
		{
			pthread_mutex_unlock(&(philo->digestion));
			return (ALIVE);
		}
		else if (philo->full == true)
		{
			pthread_mutex_unlock(&(philo->digestion));
			return (FULL);
		}
		pthread_mutex_unlock(&(philo->digestion));
		pthread_mutex_lock(&philo->buboes);
		if (time - philo->time_last_meal >= (*data)->time_to_death)
		{
			pthread_mutex_unlock(&philo->buboes);
			return (DEAD);
		}
		pthread_mutex_unlock(&philo->buboes);
		i++;
	}
	return (ALIVE);
}

/*
static void	plague(t_info **data)
{
	int	i;

	i = 0;
	while(i < (*data)->num_philo)
	{
		(*data)->philosophers[i].dead = true;
		i++;
	}
}
*/
/*==========================================================*
|						MAIN CONTROL						|
*===========================================================*
*	This is the function called from the MAIN THREAD:
*
*	if: time_last_meal - timestamp is > than the time_to_death
*	in t_info then the philo is dead;
*
*	So we should stop the print setting the DEATH awake.
*==========================================================*/
int	main_checker(t_info **data)
{
	t_philosopher	*philo;
	int				status;
	static int		count;

	philo = (*data)->philosophers;
	while (1)
	{
		if (count == (*data)->max_dinners)
		{
			pthread_mutex_lock(&(*data)->message);
			action_print(*data, philo->num, "GOOD JOB,\
					all the philos are \tSATISFIED\n", true);
			//pthread_mutex_lock(&(*data)->message);
			return (ALIVE);
		}
		pthread_mutex_lock(&philo->first_kill);
		status = check_death(data);
		pthread_mutex_unlock(&philo->first_kill);
		if (status == DEAD)
		{
			pthread_mutex_lock(&(*data)->message);
			action_print(*data, philo->num, "is dead... \tR.I.P.\n", true);
			pthread_mutex_lock(&(*data)->message);
			//plague(data);
			return (DEAD);
		}
		else if (status == FULL)
		{
			count++;
		}
	}
	return (ALIVE);
}