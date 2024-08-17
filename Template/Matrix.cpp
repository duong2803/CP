template <typename T>
struct Matrix
{
	int n, m;
	T **a;
	Matrix(int n, int m) : n(n), m(m)
	{
		a = new T *[n];
		for (int i = 0; i < n; ++i)
		{
			a[i] = new T[m];
			for (int j = 0; j < m; ++j)
				a[i][j] = 0;
		}
	}
	Matrix(std::initializer_list<const std::initializer_list<T>> data)
	{
		n = data.size();
		m = data.begin()->size();
		a = new T *[n];
		for (int i = 0; i < n; ++i)
			a[i] = new T[m];
		int i = 0;
		for (const auto &row : data)
		{
			int j = 0;
			for (const auto &element : row)
			{
				a[i][j] = element;
				++j;
			}
			++i;
		}
	}
	Matrix &operator=(const std::initializer_list<std::initializer_list<T>> data)
	{
		n = data.size();
		m = data.begin()->size();
		a = new T *[n];
		for (int i = 0; i < n; ++i)
			a[i] = new T[m];
		int i = 0;
		for (const auto &row : data)
		{
			int j = 0;
			for (const auto &element : row)
			{
				a[i][j] = element;
				++j;
			}
			++i;
		}
		return *this;
	}
	Matrix &operator*=(const Matrix &other)
	{
		assert(m == other.n);
		Matrix<T> res(n, other.m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < other.m; ++j)
			{
				res.a[i][j] = 0;
				for (int k = 0; k < m; ++k)
				{
					res.a[i][j] += a[i][k] * other.a[k][j];
				}
			}
		}
		*this = res;
		return *this;
	}
	T *operator[](int i) { return a[i]; }
	const T *operator[](int i) const { return a[i]; }
};

template <typename T>
Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b) { return Matrix<T>(a) *= b; }
template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			out << a[i][j] << ' ';
		}
		out << '\n';
	}
	return out;
}

template <typename T>
Matrix<T> mpow(Matrix<T> a, long long k)
{
	assert(a.n == a.m);
	Matrix<T> res(a.n, a.m);
	for (int i = 0; i < a.n; ++i)
		res[i][i] = 1;
	while (k)
	{
		if (k & 1)
			res *= a;
		a *= a;
		k >>= 1;
	}
	return res;
}
