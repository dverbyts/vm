/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:20:18 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/24 14:20:22 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int i, char **arg)
{
	t_vm *vm;

	if (i < 2)
		return(vm_usage(NULL));
	vm = vm_init();
	vm_read(vm, i, arg);
	if (vm->error != -1)
		return (vm_error(vm->error));
}


t_vm	*vm_init(void)
{
	t_vm *mem;

	if (!(mem = (t_vm *)malloc(sizeof(t_vm) * 1)))
		return (NULL);
	ft_bzero(mem, sizeof(t_vm));
	mem->error = -1;
	return (mem);
}



int		vm_error(int error)
{
	if (error == 1)
		return(vm_usage("Invalid argument.\n\0"));
	else if (error == 2)
		ft_putstr("Invalid or empty file.\n\0");
	else if (error == 3)
		ft_putstr("Wrong MAGIC.\n\0");
	else
		ft_putstr("Some unknow error.\n\0");
	return (0);
}

int		vm_usage(char *re)
{
	if (re != NULL)
		ft_putstr(re);
	ft_putstr("Usage:\n./corewar [-flags] <champion1.cor> <...>\n\0");
	return (0);
}

/*
** error management.
**
** error = 1 - invalid argument""
** error = 2 - invalid of empty file;
** error = 3 - wrong MAGIC;
** error = 4 - 
** error = 5 - 
*/

/*
** int f - флаг какой ти данных проверяю.
**
** f = 1 - 4 байта - меджик число
** f = 2 - 132 байта - имя
** f = 3 - 4 байта - значение размера программы
** f = 4 - 2052 байта - коммент
** f = 5 - (значение из f3) байт - размер программы
*/