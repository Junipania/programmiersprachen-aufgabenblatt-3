# ifndef VEC2_HPP
# define VEC2_HPP

// Vec2 class definition
class Vec2
{
	public: 
	Vec2();
	Vec2(float a, float b);

	Vec2 & operator +=( Vec2 const & v );
	Vec2 & operator -=( Vec2 const & v );
	Vec2 & operator *=( float s );
	Vec2 & operator /=( float s );

	
	float x ;
	float y ;
};

# endif // VEC2_HPP
