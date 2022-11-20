/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:47 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/20 20:45:43 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSTRUCT_H
# define PSTRUCT_H

# include "philo.h"

# define FULL 0
# define DEAD 1
# define ALIVE 2

typedef struct s_info			t_info;
typedef struct s_philosopher	t_philosopher;
typedef struct s_death			t_death;
typedef struct s_purgatory		t_purgatory;

/*==========================================================*
|						STRUCT PHILO						|
*==========================================================*/
typedef struct s_philosopher
{
	pthread_t			t_philo;
	int					num;
	long long			time_last_meal;
	int					l_fork;
	int					r_fork;
	int					dinners_done;
	bool				dead;
	bool				full;
	pthread_mutex_t		first_kill;
	pthread_mutex_t		buboes;
	pthread_mutex_t		digestion;
	t_info				*data;
}						t_philosopher;

/*==========================================================*
|						STRUCT INFO							|
*==========================================================*/

typedef struct s_info
{
	int					num_philo;
	int					time_to_death;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_dinners;
	int					num_dinners;
	int					n_philos_sated;
	bool				all_ready;
	bool				first_dinner_done;
	bool				last_christmas;
	long long			start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		democritus;
	pthread_mutex_t		message;
	pthread_mutex_t		condition;
	t_philosopher		*philosophers;
}						t_info;

#endif
