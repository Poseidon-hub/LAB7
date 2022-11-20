#include "Header.h"
#include <iostream>

void process(int n, int matrix[100][100])
{

	int Flag = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			int s = 0;
			for (int k = 0; k < n; k++) {
				if (matrix[k][i] == matrix[k][j + 1 + i]) {
					s = s + 1;
				}
			}
			if (s == n) {
				Flag = Flag + 1;
				goto exit;
			}
		}
	}

	exit:

	if (Flag == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int F = 0;
				int G = abs(matrix[i][j]);
				for (int k = 2; k <= sqrt(G); k++) {
					if (G % k == 0) {
							F = 1;
					}
				}
				if (F == 0) {
					Flag = Flag + 1;
					goto exitr;
				}
			}
		}
	}

	exitr:

	// --------------------------------------------------------------

	if (Flag == 2) { 
		int sum[100];

		for (int i = 0; i < n; i++) {
			sum[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum[i] = sum[i] + abs(matrix[i][j]);

			}
		}

		int temp;
		int temp1[100][100];

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (sum[j] > sum[j + 1]) {

					temp = sum[j];
					for (int k = 0; k < n; k++) {
						temp1[0][k] = matrix[j][k];
					}

					sum[j] = sum[j + 1];
					for (int k = 0; k < n; k++) {
						matrix[j][k] = matrix[j + 1][k];
					}

					sum[j + 1] = temp;
					for (int k = 0; k < n; k++) {
						matrix[j + 1][k] = temp1[0][k];
					}

				}
			}
		}
	}
	

}