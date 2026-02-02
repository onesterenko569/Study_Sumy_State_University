#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isDiagonallyDominant(float** A, int n);
float norm_m(float** A, int n);
float norm_l(float** A, int n);
float norm_k(float** A, int n);

int main()
{
	int n;

	// введення розміру матриці
	printf("Vvedit rozmir kvadratnoyi matrytsi: ");
	scanf_s("%d", &n);
	while (n <= 0 || n > 100)
	{
		printf("\nVy vvely nevirnyy rozmir, povtorit sprobu (rozmir povynen buty vid 1 do 100)\nVvedit rozmir kvadratnoyi matrytsi: ");
		scanf_s("%d", &n);
	}
	
	// виділяємо пам’ять для матриці коефіцієнтів A
	float** A = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		A[i] = (float*)malloc(n * sizeof(float));
	}

	// виділяємо пам’ять для матриці вільних членів B
	float** B = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		B[i] = (float*)malloc(sizeof(float));
	}

	// заповнюємо матрицю коефіцієнтів A
	printf("\nVvedit matrytsyu koefitsiyentiv A:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ryadok: ", i + 1);
		for (int j = 0; j < n; j++)
		{
			while (scanf_s("%f", &A[i][j]) != 1)
			{
				printf("Pomylka: vvedit chyslo dlya A[%d][%d] i dali: ", i + 1, j + 1);
				while (getchar() != '\n'); // очищаємо буфер (прибираємо неправильний ввід)
			}
		}
	}

	// перевіряємо діагональну перевагу 
	printf("\nPerevirymo diahonalnu perevahu\n");
	if (isDiagonallyDominant(A, n))
	{
		printf("\nMatrytsya A maye diagonalnu perevahu\n");
	}
	else
	{
		printf("\nMatrytsya A ne maye diagonalnoyi perevahy, sprobuyte znovu\n");
		return 1;
	}

	// заповнюємо матрицю матрицю вільних членів B
	printf("\nVvedit matrytsyu vilnykh chleniv B:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ryadok: ", i + 1);
		while (scanf_s("%f", &B[i][0]) != 1)
		{
			printf("Pomylka: vvedit chyslo dlya B[%d][1] i dali: ", i + 1);
			while (getchar() != '\n'); // очищаємо буфер (прибираємо неправильний ввід)
		}
	}

	// вивід розширеної матриці
	printf("\nRozshyrena matrytsya:\n");
	for (int i = 0; i < n; i++)
	{
		printf("(");  
		for (int j = 0; j < n; j++)
		{
			printf("%8.2f ", A[i][j]); 
		}
		printf("| %8.2f )\n", B[i][0]); 
	}

	// виділяємо пам’ять для еквівалентної системи А2 
	float** A2 = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		A2[i] = (float*)malloc(n * sizeof(float));
	}

	// виділяємо пам’ять для еквівалентної системи B2
	float** B2 = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		B2[i] = (float*)malloc(sizeof(float));
	}

	// знаходження еквівалентної системи A2
	printf("\nZnaydemo ekvivalentnu systemu\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				A2[i][j] = 0;
			}
			else
			{
				A2[i][j] = -A[i][j] / A[i][i];
			}
		}
	}

	// знаходження еквівалентної системи B2
	for (int i = 0; i < n; i++)
	{
		B2[i][0] = B[i][0] / A[i][i];
	}

	// вивід еквівалентної системи A2
	printf("\nEkvivalentna matrytsya alpfa:\n");
	for (int i = 0; i < n; i++)
	{
		printf("(");
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
			{
				printf("%.4f", A2[i][j]);
			}
			else
			{
				printf("%12.4f", A2[i][j]);
			}
		}
		printf(")\n");
	}

	// вивід еквівалентної системи B2
	printf("\nEkvivalentna matrytsya beta:\n");
	for (int i = 0; i < n; i++)
	{
		printf("(%.4f)\n", B2[i][0]);
	}

	// перевірка достатньої умови збіжності
	printf("\nPerevirymo dostatnyu umovu zbizhnosti za ekvivalentnoyu systemoyu\n");

	float n_m = norm_m(A2, n);
	float l_m = norm_l(A2, n);
	float k_m = norm_k(A2, n); 

	printf("\nm-norma: %.4f\n", n_m);
	printf("l-norma: %.4f\n", l_m);
	printf("k-norma: %.4f\n", k_m);

	if (fabs(n_m) < 1 && fabs(l_m) < 1 && fabs(k_m) < 1)
	{
		printf("\nMozhemo pobachyty shcho vsi normy po modulyu menshi za 1, shcho oznachaye shcho dostatnya umova zbizhnosti vykonana\n");
	}
	else
	{
		printf("\nMozhemo pobachyty shcho ne vsi normy po modulyu menshi za 1, shcho oznachaye shcho dostatnya umova zbizhnosti ne vykonana\n");
	}

	// введення точності обчислень e
	float e;
	printf("\nVvedit tochnist obchyslen:\ne = ");
	scanf_s("%f", &e);

	float* x = (float*)malloc(n * sizeof(float)); // поточні наближення
	float* x_prev = (float*)malloc(n * sizeof(float)); // попередні наближення

	// візьмемо за початкове наближення B2
	for (int i = 0; i < n; i++)
	{
		x[i] = B2[i][0];
		x_prev[i] = x[i];
	}

	printf("\nIteraciyi metodu Zeydelia:\n");
	printf("Iter\t");
	for (int i = 0; i < n; i++)
	{
		printf("x%d\t\t", i + 1);
	}
	printf("pokhybka");
	printf("\n-----------------------------------------------------------------------------------------\n");

	for (int iter = 1; iter <= 100; iter++)
	{
		for (int i = 0; i < n; i++)
		{
			float sum = 0.0;

			for (int j = 0; j < i; j++)
			{
				sum += A2[i][j] * x[j];
			}

			for (int j = i + 1; j < n; j++)
			{
				sum += A2[i][j] * x_prev[j];
			}

			x[i] = sum + B2[i][0];
		}

		// обчислення max |x(k) - x(k-1)|
		float max_diff = 0.0;
		for (int i = 0; i < n; i++)
		{
			float diff = fabs(x[i] - x_prev[i]);
			if (diff > max_diff)
			{
				max_diff = diff;
			}
		}

		// обчислення похибки за формулою Δ = max_diff * normA / (1 - normA)
		float delta = max_diff * n_m / (1.0 - n_m);

		// вивід ітерації
		printf("%d\t", iter);
		for (int i = 0; i < n; i++)
		{
			printf("%.4f\t\t", x[i]);
		}
		printf("%.8e\n", delta); // виводимо похибку 

		// перевірка умови зупинки
		if (delta < e)
		{
			printf("\nZbignennia dosyahnuto za %d iteraciy\n", iter);
			printf("Pokhybka obchyslen = %.8e", delta);
			break;
		}

		// оновлення попереднього вектора
		for (int i = 0; i < n; i++)
		{
			x_prev[i] = x[i];
		}

		if (iter == 100)
		{
			printf("\nPomylka: dosyahnuto limit v 100 iteratsiy\n");
		}
	}

	printf("\nKintsevyy rozvyazok:\n");
	for (int i = 0; i < n; i++)
	{
		printf("x%d = %.4f\n", i + 1, x[i]);
	}

	// звільнення пам'яті
	free(x);
	free(x_prev);
	for (int i = 0; i < n; i++) 
	{
		free(A[i]);
		free(B[i]);
		free(A2[i]);
		free(B2[i]);
	}
	free(A);
	free(B);
	free(A2);
	free(B2);

	return 0;
}

int isDiagonallyDominant(float** A, int n) // діагональна перевага 
{
	int counter = 0; 

	for (int i = 0; i < n; i++)
	{
		float sum = 0.0;

		// сума модулів елементів у рядку, крім діагонального
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				sum += fabs(A[i][j]);
			}
		}

		// перевірка умови діагональної переваги
		if (fabs(A[i][i]) < sum)
		{
			return 0;
		}
		else if (fabs(A[i][i]) > sum)
		{
			counter = 1; 
		}
	}

	return counter;
}

float norm_m(float** A, int n) // m-норма 
{
	float max = 0;
	for (int i = 0; i < n; i++)
	{
		float sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += fabs(A[i][j]);
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}

float norm_l(float** A, int n) // l-норма
{
	float max = 0;
	for (int j = 0; j < n; j++)
	{
		float sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += fabs(A[i][j]);
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}

float norm_k(float** A, int n) // k-норма
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += A[i][j] * A[i][j];
		}
	}
	return sqrt(sum);
}