/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:12:01 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/20 20:07:33 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	end_of_the_banquet(t_info *data, t_philosopher *philo, int status)
{
	int	i;

	i = status;
	i = -1;
	while (++i < data->num_philo)
		pthread_join(philo[i].t_philo, NULL);
	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->philosophers[i].buboes));
		pthread_mutex_destroy(&(data->philosophers[i].digestion));	
		pthread_mutex_destroy(&(data->philosophers[i].first_kill));	
	}
	pthread_mutex_destroy(&(data->message));
	pthread_mutex_destroy(&(data->condition));
	pthread_mutex_destroy(&(data->democritus));
	free(data->philosophers);
	free(data->forks);
}

static void	leaks(void)
{
	system("leaks philo");
}
/*

*/
int	main(int argc, char*argv[])
{
	atexit(leaks);
	t_info	*data;

	if (argc != 5 && argc != 6)
		return (print_instruction());
	data = (t_info *)malloc(sizeof(t_info));
	if (!data)
	{
		print_error(MALLOC_ERROR, NULL);
		return (1);
	}
	data = init_data(argc, argv, data);
	if (data == NULL)
	{
		print_error(INIT_ERROR, data);
		return (1);
	}
	return (the_banquet(data));
}
