/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_game2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:46:17 by dverbyts          #+#    #+#             */
/*   Updated: 2017/11/10 08:46:20 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*vm_read_comand(t_car *car)
{
	unsigned char tmp;

	tmp = g_vm->map[0][car->car_pos];
	if (tmp > 0 && tmp < 17)
	{
		car->comand = (int)tmp;
		car->count = vm_cycles_count((int)tmp);
		if (car->comand == 1)
			car->live = 1;
	}
	else
	{
		car->car_next_pos += 1;
		car->comand = 0;
	}
	if (car->comand > 1 && car->comand < 17 && car->comand != 9 &&
		car->comand != 12 && car->comand != 15)
		vm_parse_code_byte(car);
	return (car);
}

int		vm_cycles_count(int tmp)
{
	if (tmp == 16)
		return (2);
	else if (tmp == 2 || tmp == 3)
		return (5);
	else if (tmp >= 6 && tmp <= 8)
		return (6);
	else if (tmp == 1 || tmp == 4 || tmp == 5 || tmp == 13)
		return (10);
	else if (tmp == 9)
		return (20);
	else if (tmp == 10 || tmp == 11)
		return (25);
	else if (tmp == 14)
		return (50);
	else if (tmp == 12)
		return (800);
	else if (tmp == 15)
		return (1000);
	return (0);
}

t_car	*vm_make_move(t_car *car)
{
	// g_vm->map[2][car->car_pos] = 0;
	// if (car->comand == 1)
	// 	car = vm_com_live(car);
	// else if (car->comand == 2)
	// 	car = vm_com_ld(car);
	// else if (car->comand == 3)
	// 	car = vm_com_st(car);
	// else if (car->comand == 4)
	// 	car = vm_com_add(car);
	// else if (car->comand == 5)
	// 	car = vm_com_sub(car);
	// else if (car->comand == 6)
	// 	car = vm_com_and(car);
	// else if (car->comand == 7)
	// 	car = vm_com_or(car);
	// else if (car->comand == 8)
	// 	car = vm_com_xor(car);
	// else
	// 	car = vm_make_move2(car);
	// if (car->car_next_pos == 0) ///////////////////////////////////////////////////////////
	// 	car->car_next_pos += 1;
	return (car);
}

t_car	*vm_make_move2(t_car *car)
{
	// if (car->comand == 9)
		// vm_com_zjmp(car);
	// else if (car->comand == 10)
	// 	car = vm_com_ldi(car);
	// else if (car->comand == 11)
	// 	car = vm_com_sti(car);
	// else if (car->comand == 12)
	// 	car = vm_com_fork(car);
	// else if (car->comand == 13)
	// 	car = vm_com_lld(car);
	// else if (car->comand == 14)
	// 	car = vm_com_lldi(car);
	// else if (car->comand == 15)
	// 	car = vm_com_ifork(car);
	// else if (car->comand == 16)
	// 	car = vm_com_aff(car);
	// else
	// 	ft_putstr_fd("Some unknow error.\n\0", 2);
	return (car);
}




