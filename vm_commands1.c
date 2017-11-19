/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:07:20 by dverbyts          #+#    #+#             */
/*   Updated: 2017/11/13 15:07:24 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_com_live(t_car *car)/////////////////////
{
	int 			champ_namber;

	car->c_byte[0] = 2;
	vm_get_reg_dir(car, 0, 1);
	champ_namber = car->com_args[0] * -1;
	if (champ_namber > 0 && champ_namber <= g_vm->champs_nmbr)
	{
		g_vm->champs[champ_namber]->live += 1;
		g_vm->champs[champ_namber]->last_live = g_vm->cycle;
		g_vm->map3[car->car_pos] = 1;
		g_vm->live_checks++;
		if (g_vm->flag_say_alive == 1 && g_vm->flag_visualize != 1)
			vm_com_live2(champ_namber);
	}
	car->car_next_pos = vm_find_next_pos(car);
	car->live += 1;
	vm_car_clean(car);
}

void	vm_com_live2(int champ_namber)
{
	ft_putstr("Player \0");
	ft_putnbr(champ_namber);
	write(1, " (", 2);
	ft_putstr(g_vm->champs[champ_namber]->name);
	write(1, ") ", 2);
	ft_putstr("is said to be alive\n\0");	
}

void		vm_com_add(t_car *car)
{
	car->carry = FALSE;
	if (car->c_byte[0] == 1 && car->c_byte[1] == 1 && car->c_byte[2] == 1)
	{
		vm_get_reg_dir(car, 0, 2);
		vm_get_reg_dir(car, 1, 3);
		vm_get_reg_dir(car, 2, 4);
		if ((car->com_args[0] >= 0 && car->com_args[0] < 16) &&
			(car->com_args[1] >= 0 && car->com_args[1] < 16) && 
			(car->com_args[2] >= 0 && car->com_args[2] < 16))
		{
			car->car_reg[car->com_args[2]] = car->car_reg[car->com_args[0]] + 
			car->car_reg[car->com_args[1]];
			(car->car_reg[car->com_args[2]] == 0) ? (car->carry = TRUE) : 0;
		}
	}
	car->car_next_pos = vm_find_next_pos(car);
	vm_car_clean(car);
}

void		vm_com_sub(t_car *car)
{
	car->carry = FALSE;
	if (car->c_byte[0] == 1 && car->c_byte[1] == 1 && car->c_byte[2] == 1)
	{
		vm_get_reg_dir(car, 0, 2);
		vm_get_reg_dir(car, 1, 3);
		vm_get_reg_dir(car, 2, 4);
		if ((car->com_args[0] >= 0 && car->com_args[0] < 16) &&
			(car->com_args[1] >= 0 && car->com_args[1] < 16) && 
			(car->com_args[2] >= 0 && car->com_args[2] < 16))
		{
			car->car_reg[car->com_args[2]] = car->car_reg[car->com_args[0]] - 
			car->car_reg[car->com_args[1]];
			(car->car_reg[car->com_args[2]] == 0) ? (car->carry = TRUE) : 0;
		}
	}
	car->car_next_pos = vm_find_next_pos(car);
	vm_car_clean(car);
}

void	vm_com_zjmp(t_car *car)
{
	car->car_next_pos = 3;
	if (car->carry == FALSE)
	{
		vm_car_clean(car);
		return ;
	}
	car->c_byte[0] = 2;
	vm_get_reg_dir(car, 0, 1);
	car->car_next_pos = (short int)car->com_args[0];
	vm_car_clean(car);
}
