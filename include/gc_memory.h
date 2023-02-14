/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:50:11 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/14 23:44:20 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_MEMORY_H
# define GC_MEMORY_H

# include <stdlib.h>
# include <unistd.h>
# include <stab.h>

# define CLEAN_ALL 1 << 0x1
# define CLEAN_TMP 1 << 0x2
# define CLEAN_OVR 1 << 0x5
# define ADD_TMP 1 << 0x3
# define ADD_OVR 1 << 0x4

/**
 * @brief The flag use for indicate the mode of CG : (ADD_TMP | ADD_OVR | CLEAN_ALL | CLEAN_TMP | CLEAN_OVR).
 * @typedef unsigned long > gc_flag.
 */

typedef unsigned long gc_flag;

typedef struct s_dustbin
{
	void				*address;
	struct s_dustbin	*next;
}						t_dustbin;

/**
 * @struct of GC_MEMORY.
 * @brief init the uses function.
 * @param overall pointer to the head of overall_list.
 * @param temporary pointer to the head of temporary_list.
 */

typedef struct s_gc
{
	t_dustbin			*overall;
	t_dustbin			*temporary;
	struct s_gc 		*(*gc_adding_adress)(struct s_gc *, void *, gc_flag);
	void				*(*gc_strainer)(struct s_gc *, void *, gc_flag);
	void				(*gc_clean_dustbin)(struct s_dustbin **);
	int					(*gc_purifying)(struct s_gc **, gc_flag);
}						t_gc;

/**
 * @brief init the GC_MEMORY.
 * @param nothing.
 * @return t_gc*.
 */

t_gc	*gc_init(void);

/**
 * @brief 
 * 
 * @param gc pointer to the GC_MEMORY.
 * @param address the new address return by familiarity of malloc 
 * @param flag the gc flag : if (FLAG & ADD_TMP) ==> the newaddress should be add in temporary_list.
 * 							 if (FLAG & ADD_OVR) ==> the newaddress should be add in overall_list.
 * @return t_gc* 
 */

t_gc	*gc_adding_adress(t_gc *gc, void *address, gc_flag flag);

/**
 * @brief 
 * 
 * @param gc pointer to the GC_MEMORY.
 * @param newaddress The pointer should be store in (temporary_list or overall_list) by flag.
 * @param flag 
 * @return void* the address of new address 
 */

void	*gc_strainer(t_gc *gc, void *newaddress, gc_flag flag);

/**
 * @brief clear a list by passing the head of the target list
 * 
 * @param dustbin the head of target list
 */

void	gc_clean_dustbin(t_dustbin **dustbin);

/**
 * @brief clear the list by the FLAG
 * 
 * @param gc pointer to the GC_MEMORY.
 * @param flag 
 * @return int (return EXIT_SUCCESS else return EXIT_FAILURE).
 */

int		gc_purifying(t_gc **gc, gc_flag flag);

#endif