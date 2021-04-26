/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:39:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/26 09:43:33 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_result(int x, int y)
{
  if (x == y)
  {
    printf("\e[32m[YEAH] \e[0m\n\n");
    return (1);
  }
  else
  {
    printf("\e[91m[LOOSER] \e[0m \e[32m system: %d \e[0m \e[91m yours: %d \e[0m \n\n", x-15, y-15);
    return (0);
  }
}
void print_total(int total, int index)
{
  if (total == index - 1)
    printf("\e[32m TOTAL: %d/%d --- GOOD JOB!\e[0m\n\n", total, index - 1);
  else
    printf("\e[91m TOTAL: %d/%d --- TRY AGAIN\e[0m\n\n", total, index - 1);
}
int main(void)
{
    int x, y, index, total;
    index = 1;
    total = 0;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%20.10x|\n", -0x123abcdu);
    y = ft_printf("mine    -> |%20.10x|\n", -0x123abcdu);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%20.x|\n", 0x123abcdu);
    y = ft_printf("mine    -> |%20.x|\n", 0x123abcdu);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%*.*X %*.*X|\n", 1, 50, 5000, 1, 0, 10);
    y = ft_printf("mine    -> |%*.*X %*.*X|\n", 1, 50, 5000, 1, 0, 10);
    total += print_result(x, y); index++;
\
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%--194.54x|\n", 3852169892u);
    y = ft_printf("mine    -> |%--194.54x|\n", 3852169892u);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%--180.61x|\n", 1396814909u);
    y = ft_printf("mine    -> |%--180.61x|\n", 1396814909u);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-8.5x|\n", 42);
    y = ft_printf("mine    -> |%-8.5x|\n", 42);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%0-8.5x|\n", 42);
    y = ft_printf("mine    -> |%0-8.5x|\n", 42);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%08.5x|\n", 42);
    y = ft_printf("mine    -> |%08.5x|\n", 42);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-8.3x|\n", 4242);
    y = ft_printf("mine    -> |%-8.3x|\n", 4242);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%10c%0036.99%|\n", 9);
    y = ft_printf("mine    -> |%10c%0036.99%|\n", 9);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%--91.*x|\n", -192,3542796524u);
    y = ft_printf("mine    -> |%--91.*x|\n", -192,3542796524u);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-153.x|\n", 822360617u);
    y = ft_printf("mine    -> |%-153.x|\n", 822360617u);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-5.0x|\n", 0);
    y = ft_printf("mine    -> |%-5.0x|\n", 0);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |p22 %.0x|\n", 100);
    y = ft_printf("mine    -> |p22 %.0x|\n", 100);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%.0x|\n", 0);
    y = ft_printf("mine    -> |%.0x|\n", 0);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%8.4x|\n", 424242424);
    y = ft_printf("mine    -> |%8.4x|\n", 424242424);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%*.*x|\n", 4, -1, 8);
    y = ft_printf("mine    -> |%*.*x|\n", 4, -1, 8);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-*.20x|\n", 94,1446072230u);
    y = ft_printf("mine    -> |%-*.20x|\n", 94,1446072230u);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-*.*x|\n", 4, 0, 0);
    y = ft_printf("mine    -> |%-*.*x|\n", 4, 0, 0);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-*.*x|\n", 4, 0, 8);
    y = ft_printf("mine    -> |%-*.*x|\n", 4, 0, 8);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%0*x|\n", 0, 8);
    y = ft_printf("mine    -> |%0*x|\n", 0, 8);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-*x|\n", 2, 8);
    y = ft_printf("mine    -> |%-*x|\n", 2, 8);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%-*x|\n", 2, 0);
    y = ft_printf("mine    -> |%-*x|\n", 2, 0);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%*.*x|\n", 0, 0, 0);
    y = ft_printf("mine    -> |%*.*x|\n", 0, 0, 0);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%*.x|\n", 0, -100);
    y = ft_printf("mine    -> |%*.x|\n", 0, -100);
    total += print_result(x, y); index++;
    printf("--- test %d ---\n", index);
    x = printf("system  -> |%*.x|\n", -4, 1);
    y = ft_printf("mine    -> |%*.x|\n", -4, 1);
    total += print_result(x, y); index++;
    print_total(total, index);
    return (0);
}
