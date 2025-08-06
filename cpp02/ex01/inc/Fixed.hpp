#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed {
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(float n);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	_value;
		static const int _fractional_bits;
};




#endif