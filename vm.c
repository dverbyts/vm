/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:20:18 by dverbyts          #+#    #+#             */
/*   Updated: 2017/11/20 09:22:22 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm		*g_vm;

int		main(int i, char **arg)
{
	if (i < 2)
		return (vm_usage(NULL));
	if (!(g_vm = (t_vm *)malloc(sizeof(t_vm))))
		return (0);
	vm_init(0);
	vm_read1(i, arg, 0, 0);
	if (g_vm->error != -1)
		return (vm_error(g_vm->error));
	vm_split_champs();
	if (g_vm->error != -1)
		return (vm_error(g_vm->error));
	vm_init_champs();
//	if (g_vm->flag_visualize == 1)
//		g_vm->sleep = ncurses(g_vm->sleep);
	vm_make_game(NULL);
	return (0);
}

/*
** Проверяем, что у нас есть хоть что-то
** малочим память под главную структуру
** забиваем память структуры нужными данными
** читаем аргументы, которые зашли
** парсим чемпионов, закидываем их код на карту
** выводим нулевой ход, если включена визуализация, на экран
** запускаем игру
** если на любомэта возникает ошибка - завершаем.
*/