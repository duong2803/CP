template<class F>
struct y_combinate_t {
	F f;
	template<class...Args>
	decltype(auto) operator()(Args&&...args)const {
	return f(*this, std::forward<Args>(args)...);
	}
};

template<class F>
y_combinate_t<std::decay_t<F>> y_combinate( F&& f ) {
	return {std::forward<F>(f)};
};
