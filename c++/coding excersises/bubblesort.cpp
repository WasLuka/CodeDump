#include <iostream>

int main()
{
	int t, s;
	std::cin >> t;
	int num[t];

	for (int i = 0; i < t; i++)
	{
		std::cin >> num[i];
	}

	for (int j = 0; j < t; j++)
	{
		for (int i = 0; i < t - j; i++)
		{
			if (num[i] > num[i + 1])
			{
				s = num[i];
				num[i] = num[i + 1];
				num[i + 1] = s;
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		std::cout << num[i] << " ";
	}
}