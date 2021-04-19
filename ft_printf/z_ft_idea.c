/*if (*(*conv).str)
	{
		ft_write(conv->str, 1);
		free((*conv).str);
		ft_cln(conv);
	}

if(!((*conv).str = ft_conv_d(va_arg(arg, int))))
			return (0);
			printf("\nminus = %d\n", conv.minus);
			printf("zero = %d\n", conv.zero);
			printf("width = %d\n", conv.width);
			printf("dot = %d\n", conv.dot);
			printf("precision = %d\n", conv.precision);
			printf("type = %d\n", conv.type);
			printf("str = %s\n", conv.str);*/




/*				printf("\nminus = %d\n", conv->minus);
			printf("zero = %d\n", conv->zero);
			printf("width = %d\n", conv->width);
			printf("dot = %d\n", conv->dot);
			printf("precision = %d\n", conv->precision);
			printf("type = %d\n", conv->type);
			printf("size = %d\n", conv->size);*/

			/*	printf("\nminus = %d\n", conv->minus);
			printf("zero = %d\n", conv->zero);
			printf("width = %d\n", conv->width);
			printf("dot = %d\n", conv->dot);
			printf("precision = %d\n", conv->precision);
			printf("type = %d\n", conv->type);
			printf("size = %d\n", conv->size);
			printf("i = %d\n", i);*/

		/*while (str[i] || i == 0)
		{
			if (str[i] == 0 && i == 0)
			{
				write(1, 0, 1);
			}
			write(1, &str[i], 1);
			ret++;
			i++;
		}*/

		/*	conv->size = ft_strlen_nb(i);
	if (i < 0)
		conv->size--;
	if (conv->dot == 1 && (conv->precision > conv->size))
		conv->precision = conv->precision - conv->size;
	if (conv->width > (conv->size + conv->precision))
	{
		conv->width = (conv->width - (conv->size + conv->precision));
		if (i < 0)
			conv->width--;
		if (conv->minus == 1)
		{
			if (i < 0 && conv->precision != 0)
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
			while (conv->width-- != 0)
				ft_write(' ', 1);
		}
		else if (conv->zero == 1 && conv->dot == 0)
		{
			if (i < 0 )
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while (conv->width-- != 0)
				ft_write('0', 1);
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
		}
		else
		{
			while (conv->width-- != 0)
				ft_write(' ', 1);
			if (i < 0 && conv->precision != 0)
			{
				ft_write('-', 1);
				i = i * -1;
			}
			while(conv->precision-- != 0)
				ft_write('0', 1);
			ft_putnbr(i);
		}
	}
	else
	{
		if ((i < 0 && conv->dot == 0) || (i < 0 && conv->precision != 0))
		{
			ft_write('-', 1);
			i = i * -1;
		}
		if (conv->dot == 1 && conv->precision == 0)
			i = -1;
		if (conv->precision <= conv->size)
			conv->precision = 0;
		while (conv->precision-- != 0)
		{
			ft_write('0', 1);
		}
		if (i > -1)
			ft_putnbr(i);
	}*/
