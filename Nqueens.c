#include <io.h>
#include <stdlib.h>

void	ft_put_nbr(unsigned int nb)
{
	if (nb >= 10)
		ft_put_nbr(nb / 10);
	_write(1, "0123456789" + (nb % 10), 1);
}

void	put_tab(int* tab, int n, unsigned int *result)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (j == tab[i])
				_write(1, "db", 2);
			else
				_write(1, "[]", 2);
			j++;
		}
		_write(1, "\n", 1);
		i++;
	}
	_write(1, "\n", 1);
}

int canplace(int* tab, int x, int y)
{
	int i = 1;
	while (y - i >= 0)
	{
		if (tab[y - i] == x || tab[y - i] == x - i || tab[y - i] == x + i)
			return 0;
		i++;
	}
	return 1;
}

unsigned int recurs(int* tab, int y, int n, unsigned int *result)
{
	int x;
	
	x = 0;
	while(x < n)
	{	
		if (canplace(tab, x, y))
		{
			tab[y] = x;
			if (y == n - 1)
			{
				*result += 1;
				put_tab(tab, n, result);
				return 1;
			}
			else
				recurs(tab, y + 1, n, result);
		}
		x++;
	}
	return (unsigned int)result;
}


int Nqueens(int n)
{
	int *tab;
	unsigned int result;

	tab = malloc(sizeof(int) * n);
	result = 0;
	recurs(tab, 0, n, &result);
	free(tab);
	return result;
}

int main()
{
	unsigned int n = Nqueens(10);

	_write(1, "result :", 9);
	ft_put_nbr(n);
	_write(1, "\n", 1);
}