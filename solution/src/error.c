/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:11:22 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/20 19:50:32 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*print_error(char *message, t_info *data)
{
	printf("%s", message);
	free(data);
	data = NULL;
	return (NULL);
}

/*==========================================================*
|						PRINT INSTRUCTION					|
*==========================================================*/
int	print_instruction(void)
{
	printf("\nINSTRUCTION:\tplease insert: \n\n");
	printf("[argc1] = int:\tnum philosophers \n");
	printf("[argc2] = int:\ttime to death \n");
	printf("[argc3] = int:\ttime to eat \n");
	printf("[argc4] = int:\ttime to sleep \n");
	printf("[argc5] = int:\tnumber of dinners; \n\n");
	return (1);
}
