/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:57 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/17 21:23:53 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*==========================================================*
|						ACTION PRINT						|
*===========================================================*
*	print OUT the action the philosopher is doing,
*	in doing that is important to check that no one is dead.
*	if someone is dead: we don't print anymore;		
*==========================================================*/
void	action_print(t_info *data, int who, char *message, bool	last_print)
{
	long long int	time;
	static bool		condition;

	if (condition == true)
		return ;
	time = time_frame(data->start, timestamp());
	printf("%lli\t%i\t%s", time, who, message);
	if (last_print == true)
		condition = true;
	pthread_mutex_unlock(&(data->message));
	
}

static void	philo_taking_fork(t_philosopher **philo, t_info **data)
{
	pthread_mutex_lock(&((*data)->forks[(*philo)->l_fork]));
	pthread_mutex_lock(&((*data)->message));
	action_print(*data, (*philo)->num, "Has taken a fork... \t--E\n", false);
	pthread_mutex_lock(&((*data)->forks[(*philo)->r_fork]));
	pthread_mutex_lock(&((*data)->message));
	action_print(*data, (*philo)->num, "Has taken a fork... \t--E\n", false);
}

static void	philo_leaving_fork(t_philosopher **philo, t_info **data)
{
	pthread_mutex_unlock(&((*data)->forks[(*philo)->l_fork]));
	pthread_mutex_unlock(&((*data)->forks[(*philo)->r_fork]));
}

static void	digestion(t_philosopher **philo, t_info **data)
{
	pthread_mutex_lock(&(*philo)->digestion);
	((*philo)->dinners_done)++;
	if ((*data)->max_dinners >= 0 && (*philo)->dinners_done == \
				(*data)->max_dinners)
		(*philo)->full = true;
	pthread_mutex_unlock(&(*philo)->digestion);
}

void	eating(t_philosopher **philo)
{
	t_info	*data;

	data = (*philo)->data;
	philo_taking_fork(philo, &data);
	pthread_mutex_lock(&(*philo)->buboes);
	(*philo)->time_last_meal = timestamp();
	pthread_mutex_unlock(&(*philo)->buboes);
	pthread_mutex_lock(&(data->message));
	action_print(data, (*philo)->num, "Is eating... \t\t*nyam nyam nyam*\n", false);
	waiting(data->time_to_eat, &data);
	philo_leaving_fork(philo, &data);
	digestion(philo, &data);
}