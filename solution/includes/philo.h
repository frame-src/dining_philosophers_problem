#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <errno.h>
# include <unistd.h>
# include "pstruct.h"
# include "errors.h"

/*==========================================================*
|						STRUCTs								|
*==========================================================*/
typedef struct s_info			t_info;
typedef struct s_philosopher	t_philosopher;
typedef struct s_death			t_death;

/*==========================================================*
|						FT_ATOI								|
*==========================================================*/
int			ft_atoi(char *string);
/*==========================================================*
|						ACTIONS								|
*==========================================================*/
void		eating(t_philosopher **philo);
bool		waiting(int time, t_info **data);
void		end_of_the_banquet(t_info *data, \
				t_philosopher *philo, int status);
/*==========================================================*
|						GENERAL UTILS						|
*==========================================================*/
long long	timestamp(void);
long long	time_frame(long long start, long long end);
void		action_print(t_info *data, int who, char *message,\
				bool last_print);
int			print_instruction(void);
/*==========================================================*
|						INPUT UTILS							|
*==========================================================*/
bool		check_input(t_info **data, int argc, char **argv);
/*==========================================================*
|						INIT STRUCTS						|
*==========================================================*/
t_info		*init_data(int argc, char **argv, t_info *data);
/*==========================================================*
|						ERRORS								|
*==========================================================*/
void		*print_error(char *message, t_info *data);
/*==========================================================*
|						PHILO BIRTH CONTROL					|
*==========================================================*/
int			the_banquet(t_info *data);
/*==========================================================*
|						DEATH CHECK							|
*==========================================================*/
int			check_death(t_info **data);
int			main_checker(t_info **data);

#endif 