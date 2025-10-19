#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed {
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int	_value;
		static const int _fractional_bits;
};


std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif