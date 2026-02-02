#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265358979
#define N 3 // Кількість варіантів

struct parametru {
	double teta;
	double k;
	double m;
	double t;
	double Tk;
	double c;
	double b;
	double T;
	double k0;
	double a;
	double r;
	double m0;
};

double obch_teta(double T, double t, double b, double c) {
	if (t >= 0 && t < T / 4)
		return c * t;
	else if (t >= T / 4 && t < 3 * T / 4)
		return c * T / 4;
	else if (t >= 3 * T / 4 && t <= T)
		return c * T / 4 * exp(-b * (t - 3 * T / 4));
	else {
		printf("Incorrect t = %lf\n", t);
		return -1;
	}
}

double obch_k(double k0, double a, double teta) {
	return k0 * (1 - a * teta);
}

double obch_m(double m0, double r, double t, double T) {
	if (t >= 0 && t < T / 4)
		return m0 + r * t;
	else if (t >= T / 4 && t < 3 * T / 4)
		return m0 + r * T / 4 - r * (t - T / 4);
	else if (t >= 3 * T / 4 && t <= T)
		return m0 - r * T / 4 + r * (t - 3 * T / 4);
	else {
		printf("Incorrect t = %lf\n", t);
		return -1;
	}
}

double obch_Tk(double m, double k) {
	if (k == 0 || m / k < 0) {
		printf("Error: k = %lf, m/k = %lf\n", k, m / k);
		return -1;
	}
	return 2 * pi * sqrt(m / k);
}

void vidkr_fail(struct parametru* param_arr, int size) {
	FILE* vidkrf = fopen("input.txt", "r");
	if (vidkrf == NULL) {
		printf("The input.txt file could not be opened\n");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		if (fscanf(vidkrf, "%lf %lf %lf %lf %lf %lf %lf %lf",
			&param_arr[i].T, &param_arr[i].t, &param_arr[i].k0, &param_arr[i].m0,
			&param_arr[i].a, &param_arr[i].c, &param_arr[i].b, &param_arr[i].r) != 8) {
			printf("Error reading data for variant %d!\n", i + 1);
			fclose(vidkrf);
			exit(1);
		}
	}
	fclose(vidkrf);
}

void vuvid(struct parametru* param_arr, int size) {
	FILE* vuvod = fopen("output.txt", "w");
	if (vuvod == NULL) {
		printf("Failed to open output.txt\n");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		param_arr[i].teta = obch_teta(param_arr[i].T, param_arr[i].t, param_arr[i].b, param_arr[i].c);
		param_arr[i].k = obch_k(param_arr[i].k0, param_arr[i].a, param_arr[i].teta);
		param_arr[i].m = obch_m(param_arr[i].m0, param_arr[i].r, param_arr[i].t, param_arr[i].T);
		param_arr[i].Tk = obch_Tk(param_arr[i].m, param_arr[i].k);

		fprintf(vuvod, "Варіант %d:\n", i + 1);
		fprintf(vuvod, "Teta: %.4lf, k: %.4lf, m: %.4lf, Tk: %.4lf\n\n",
			param_arr[i].teta, param_arr[i].k, param_arr[i].m, param_arr[i].Tk);
	}

	fclose(vuvod);
}

int main() {
	struct parametru param_arr[N];
	vidkr_fail(param_arr, N);
	vuvid(param_arr, N);
	printf("Готово! Результати у файлі output.txt\n");
	return 0;
}
