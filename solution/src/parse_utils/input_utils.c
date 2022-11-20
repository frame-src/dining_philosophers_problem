/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:09 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/20 19:46:41 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/*==================================================================*
|						PRINT PARSING ERROR							|
*===================================================================*
*	it prints the error message
*==================================================================*/
static bool	print_parsing_error(char *string)
{
	printf("%s\n", string);
	return (false);
}

/*==================================================================*
|						CHECK ARGS									|
*===================================================================*
*	it check if the parsing has weird
*	numbers
*==================================================================*/
static bool	check_arguments(char **argv, int argc)
{
	if (ft_atoi(argv[1]) <= 0)
		return (print_parsing_error(\
			"there's no one	in the table"));
	if (ft_atoi(argv[1]) > 200)
		return (print_parsing_error(\
			"chill, you can test with less"));
	if (ft_atoi(argv[2]) < 60)
		return (print_parsing_error(\
			"parsing error, try bigger value for death_time"));
	if (ft_atoi(argv[3]) < 60)
		return (print_parsing_error("parsing error"));
	if (ft_atoi(argv[4]) < 60)
		return (print_parsing_error("parsing error"));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (print_parsing_error("no food in the table"));
	}
	return (true);
}

/*==================================================================*
|						FT_CALLOC									|
*==================================================================*/
void	*ft_calloc(size_t size, size_t num_of_elements)
{
	void		*rtn_ptr;
	size_t		i;

	rtn_ptr = malloc(size * num_of_elements);
	if (!rtn_ptr)
		return ((void *)0);
	else
	{
		i = 0;
		while (i < num_of_elements)
		{
			((int *)rtn_ptr)[i] = 0;
			i++;
		}
	}
	return ((void *)rtn_ptr);
}

/*==================================================================*
|						DATA FILL									|
*===================================================================*
*	fill the data structure				
*	DATA->DEAD -1; (Because of Philo 0)*
*==================================================================*/
static void	fill_data(char **argv, t_info **data)
{
	(*data)->num_philo = ft_atoi(argv[1]);
	(*data)->time_to_death = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);
	(*data)->n_philos_sated = 0;
}

/*==================================================================*
|						CHECK INPUT									|
*===================================================================*
*	it checks with check_args,
*	and if no error
*	it fills the data structure;
*	DATA->MAX_DINNERS = -1 if no arg;
*==================================================================*/
bool	check_input(t_info **data, int argc, char **argv)
{
	(*data)->max_dinners = -1;
	if (check_arguments(argv, argc) == false)
		return (false);
	else
	{
		if (argc == 6)
		{
			fill_data(argv, data);
			(*data)->max_dinners = ft_atoi(argv[5]);
		}
		else
			fill_data(argv, data);
	}	
	return (true);
}
