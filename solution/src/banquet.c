/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banquet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:10:02 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/20 19:53:50 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*==========================================================*
|						ROUTINE								|
*===========================================================*
*	threads ROUTINES:
*
*	As you can see i start dining with only the
*	!even philosophers
*
*	sent to "usleep" the even philo, so they will start later
*==========================================================*/
static void	*dining(void *philosopher)
{
	t_info			*data;
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	data = philo->data;
	pthread_mutex_lock(&(data->democritus));
	if (data->all_ready == true)
		pthread_mutex_unlock(&(data->democritus));
	if (philo->num % 2)
		usleep(100);
	while (philo->dead == false)
	{
		eating(&philo);
		if ((data->max_dinners >= 0 && \
			philo->dinners_done == data->max_dinners) || philo->dead == true)
			break ;
		action_print(data, philo->num, "Is sleeping... \t\t*zzzz*\n", false);
		waiting(data->time_to_sleep);
		if (philo->dead == false)
			action_print(data, philo->num, \
				"Is thinking... \t\t*mumble mumble*\n", false);
		if ((data->max_dinners >= 0 && \
			philo->dinners_done == data->max_dinners) || philo->dead == true)
			break ;
	}
	return (NULL);
}

static void	sinc(t_info **data)
{
	(*data)->all_ready = true;
	usleep(100);
	(*data)->start = timestamp();
	printf("START %lld\n", (*data)->start);
	printf("food %d\n", (*data)->max_dinners);
	pthread_mutex_unlock(&(*data)->democritus);
}

/*==========================================================*
|						PHILO BIRTH CONTROL					|
*===========================================================*
*	Here I create the THREADS:
*	I use democritus for stopping them from doing something
*	before the program has finished to create all of them;
*	then them all are sent to routine and in the main_process
* 	we	can run meanwhile a loop that check when Philo dies;
*==========================================================*/
int	the_banquet(t_info *data)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = data->philosophers;
	pthread_mutex_lock(&(data->democritus));
	while (i < data->num_philo)
	{
		if (pthread_create(&(philo[i].t_philo), NULL, dining, &(philo[i])) != 0)
		{
			print_error(THREAD_ERROR, data);
			return (1);
		}
		i++;
		if (i == data->num_philo)
			sinc(&data);
	}
	if (main_checker(&data) == ALIVE)
		end_of_the_banquet(data, philo, ALIVE);
	else
		end_of_the_banquet(data, philo, DEAD);
	return (0);
}
