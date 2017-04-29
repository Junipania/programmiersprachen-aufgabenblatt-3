
class Mat2
{
    public:
    Mat2();
    Mat2(float a1,float a2,float b1,float b2);

    float a1;
    float a2;
    float b1;
    float b2;
    float det () const ;
    Mat2 & operator *=( Mat2 const & m );    

};
