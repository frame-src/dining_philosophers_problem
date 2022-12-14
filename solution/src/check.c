/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:10:34 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/22 17:40:10 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static bool	death_status(t_philosopher *philo, int i, t_info **data)
{
	long long	time;

	pthread_mutex_lock(&philo->buboes);
	time = timestamp();
	if (time - philo->time_last_meal > (*data)->time_to_death)
	{
		action_print(*data, i, "is dead... \tR.I.P.\n", true);
		pthread_mutex_unlock(&philo->buboes);
		return (true);
	}
	pthread_mutex_unlock(&philo->buboes);
	return (false);
}

int	check_death(t_info **data, long long time)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	while (i < (*data)->num_philo)
	{
		philo = &(*data)->philosophers[i];
		pthread_mutex_lock(&(philo->digestion));
		if (philo->dinners_done == 0 && (*data) && time - \
				(*data)->start <= (*data)->time_to_death)
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
		if (death_status(philo, i, data) == true)
			return (DEAD);
		i++;
	}
	return (ALIVE);
}

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
	long long		time;
	static int		count;

	philo = (*data)->philosophers;
	while (1)
	{
		if (count == (*data)->max_dinners)
			return (FULL);
		pthread_mutex_lock(&philo->first_kill);
		time = timestamp();
		status = check_death(data, time);
		pthread_mutex_unlock(&philo->first_kill);
		if (status == DEAD)
			return (DEAD);
		else if (status == FULL)
			count++;
	}
	return (ALIVE);
}
