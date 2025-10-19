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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &right_operand) const;
		bool	operator<(const Fixed &right_operand) const;
		bool	operator>=(const Fixed &right_operand) const;
		bool	operator<=(const Fixed &right_operand) const;
		bool	operator==(const Fixed &right_operand) const;
		bool	operator!=(const Fixed &right_operand) const;

		Fixed	operator+(const Fixed &right_operand) const;
		Fixed	operator-(const Fixed &right_operand) const;
		Fixed	operator*(const Fixed &right_operand) const;
		Fixed	operator/(const Fixed &right_operand);

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed &min(Fixed &n1, Fixed &n2);
		static Fixed &min(const Fixed &n1, const Fixed &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static Fixed &max(const Fixed &n1, const Fixed &n2);

	private:
		int	_value;
		static const int _fractional_bits;
};


std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif