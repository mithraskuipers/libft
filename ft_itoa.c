/*
** FILE NAME:
** ft_itoa.c
**
** DESCRIPTION:
** ft_itoa(1) allocates (with malloc(3)) and returns a string representing the
** integer received as an argument. Negative numbers must be handled.
**
** PROTOTYPE AND ARGUMENTS:
** char		*ft_itoa(int n)
**
** n:	Integer to convert to string.
**
** RETURN VALUE:
** String representing the integer. It returns NULL if the allocation fails.
**
** EXPLANATION:
** First the function determines if the inputted integer n is negative or
** positive. Then I need to decide how much character positions are necessary
** to store the string representation of n. This can be done by simply finding
** out the number of digits of n using the helper function n_digits() and
** storing the outcome in 'i'. Next, using ft_strnew() a new string 'int2str'
** is created with enough space to store n in string format. IF 'n' is negative,
** the first position in 'int2str' is filled with '-'. ELSE IF 'n' is greater
** than 0, 'i' is decremented.
*/