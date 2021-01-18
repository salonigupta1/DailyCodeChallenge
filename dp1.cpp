

int ks(int wt[], int val[], int w, int n) {
	int i, j;
	int t[102][1002];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			//t[i][j];
		}

	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < w + 1; j++) {
			if (wt[i - 1] <= j)
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	return t[i][j];
}


