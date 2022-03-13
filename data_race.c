/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:12:51 by mac               #+#    #+#             */
/*   Updated: 2022/03/13 17:20:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int total_meals_eaten(t_philo *philo)
{
    int i = 0;
    int sum = 0;
    int total;
    
    total = philo[0].n_p * philo[0].meals;
    while(i < philo[0].n_p && philo[0].meals > 0)
    {
        sum += philo[i].meals_eaten;
        i++;
    }
    if (sum > total)
        return 1;
    return 0;
}