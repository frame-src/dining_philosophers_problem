/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:12:24 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/21 23:07:28 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*==========================================================*
|						TIMESTAMP							|
*===========================================================*
*	this function convert the time of the day in millisec:
*		t.tv_sec	is in second
*		t.tv_usec	is in microsecond
*	so the conversion should summ the 2 value converted in ms
*==========================================================*/
long long	timestamp(void)
{
	struct timeval	time;
	long long		value;

	gettimeofday(&time, NULL);
	value = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (value);
}

/*==========================================================*
|						TIME FRAME							|
*===========================================================*
*	this function is just returning a Δt back given start 
*	and end;
*					time ended - time prev
*==========================================================*/
long long	time_frame(long long start, long long end)
{
	return (end - start);
}

/*==========================================================*
|						WAITING FUNC						|
*===========================================================*
*	It is a better usleep but:
*	this is also checking in the meantime if a philo is dead;
*==========================================================*/
bool	waiting(long int time)
{
	long long	i;

	i = timestamp();
	while (1)
	{
		if (time_frame(i, timestamp()) >= time)
			return (true);
		usleep(100);
	}
	return (false);
}
