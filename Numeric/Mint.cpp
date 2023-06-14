template<typename T> T inv(T a, T m){ T u = 0, v = 1; while (a != 0) { T t = m / a; m -= t * a; swap(a, m); u -= t * v; swap(u, v); } assert(m == 1); return u; }

template<typename T>
class Modular{
public:
	long long x;
	constexpr Modular() {}
	template<typename U> Modular(U x){if(x < 0) x += mod(); this->x = x; }

	constexpr long long& operator()(){return x;}
	template<typename U> explicit operator U() const {return static_cast<U>(x);}
	constexpr static long long mod(){return T::value;}

	Modular& operator+= (const Modular &a){ x += a.x; if(x >= mod()) x -= mod(); return *this; }
	template<typename U> Modular& operator+=(const U& a){ return *this += Modular(a); }
	Modular& operator-= (const Modular &a){ x -= a.x; if(x < 0) x += mod(); return *this; }
	template<typename U> Modular& operator-=(const U& a){ return *this -= Modular(a); }
	Modular& operator*= (const Modular &a){ x = (x % mod()) * (a.x % mod()); x %= mod(); return *this; }
	Modular& operator/= (const Modular &a){ return *this *= Modular(inv(a.x, mod())); }	
	Modular& operator%=(const Modular &a){x %= a.x; return *this;}
	template<typename U> Modular& operator%=(const U& a){return *this %= Modular(a);}

	Modular& operator++(){ return *this += 1; }
	Modular operator++(int) { Modular res(*this); *this += 1; return res; }
	Modular& operator--(){ return *this -= 1; }
	Modular operator--(int){ Modular res(*this); *this -= 1; return res;}

	Modular operator-() const {return Modular(-x);}	

	template<typename U> friend bool operator==(const Modular<U> &a, const Modular<U>& b);
	template<typename U> friend bool operator<(const Modular<U> &a, const Modular<U>& b);

	template<typename U> friend std::ostream& operator<<(std::ostream& out, const Modular<U> &b);
	template<typename U> friend std::istream& operator>>(std::istream& in, Modular<U>& b);
};

template<typename T> bool operator==(const Modular<T>& a, const Modular<T>& b){ return a.x == b.x; }
template<typename T, typename U> bool operator==(const Modular<T>& a, U b){ return a == Modular<T>(b); }
template<typename T, typename U> bool operator==(T a, const Modular<U>& b){ return Modular<U>(a) == b; }

template<typename T> bool operator!=(const Modular<T>& a, const Modular<T>& b){ return !(a == b); }
template<typename T, typename U> bool operator!=(const Modular<T>& a, U b){ return !(a == b); }
template<typename T, typename U> bool operator!=(T a, const Modular<U>& b){ return !(a == b); }

template<typename T> bool operator<(const Modular<T>& a, const Modular<T>& b){ return a.x < b.x; }
template<typename T, typename U> bool operator<(const Modular<T>& a, U b){ return a < Modular<T>(b); }
template<typename T, typename U> bool operator<(T a, const Modular<U>& b){ return Modular<U>(a) < b; }

template<typename T> bool operator>(const Modular<T>& a, const Modular<T>& b){ return a.x > b.x; }
template<typename T, typename U> bool operator>(const Modular<T>& a, U b){ return a > Modular<T>(b); }
template<typename T, typename U> bool operator>(T a, const Modular<U>& b){ return Modular<U>(a) > b; }

template<typename T> bool operator<=(const Modular<T>& a, const Modular<T>& b){ return !(a > b); }
template<typename T, typename U> bool operator<=(const Modular<T>& a, U b){ return !(a > b); }
template<typename T, typename U> bool operator<=(T a, const Modular<U>& b){ return !(a > b); }

template<typename T> bool operator>=(const Modular<T>& a, const Modular<T>& b){ return !(a < b); }
template<typename T, typename U> bool operator>=(const Modular<T>& a, U b){ return !(a < b); }
template<typename T, typename U> bool operator>=(T a, const Modular<U>& b){ return !(a < b); }

template<typename T> Modular<T> operator+(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) += b; }
template<typename T, typename U> Modular<T> operator+(const Modular<T>& a, U b){ return Modular<T>(a) += b; }
template<typename T, typename U> Modular<U> operator+(T a, const Modular<U>& b){ return Modular<U>(a) += b; }

template<typename T> Modular<T> operator-(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) -= b; }
template<typename T, typename U> Modular<T> operator-(const Modular<T>& a, U b){ return Modular<T>(a) -= b; }
template<typename T, typename U> Modular<U> operator-(T a, const Modular<U>& b){ return Modular<U>(a) -= b; }

template<typename T> Modular<T> operator*(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) *= b; }
template<typename T, typename U> Modular<T> operator*(const Modular<T>& a, U b){ return Modular<T>(a) *= b; }
template<typename T, typename U> Modular<U> operator*(T a, const Modular<U>& b){ return Modular<U>(a) *= b; }

template<typename T> Modular<T> operator/(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) /= b; }
template<typename T, typename U> Modular<T> operator/(const Modular<T>& a, U b){ return Modular<T>(a) /= b; }
template<typename T, typename U> Modular<U> operator/(T a, const Modular<U>& b){ return Modular<U>(a) /= b; }

template<typename T> Modular<T> operator%(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) %= b; }
template<typename T, typename U> Modular<T> operator%(const Modular<T>& a, U b){ return Modular<T>(a) %= b; }
template<typename T, typename U> Modular<U> operator%(T a, const Modular<U>& b){ return Modular<U>(a) %= b; }

template<typename T, typename U> 
Modular<T> Pow(const Modular<T>& a, const U& b){ assert(b >= 0); Modular<T> x = a,res = 1; U p = b; while(p){ if(p & 1) res *= x; x *= x; p >>= 1; } return res; }

template<typename T> 
Modular<T> Pow(const Modular<T>& a, const Modular<T>& b){return Pow(a, (typename decay<decltype(T::value)>::type) b);}

template<typename T> std::ostream& operator<<(std::ostream& out, const Modular<T> &a){ out << a.x; return out; }
template<typename T> std::istream& operator>>(std::istream& in, Modular<T> &a){ in >> a.x; a.x %= Modular<T>::mod(); return in; }

const int mod = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;
