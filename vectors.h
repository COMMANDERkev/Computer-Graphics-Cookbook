#ifndef _H_MATH_VECTORS_
#define _H_MATH_VECTORS_

// a macro for comparing floating point numbers
#define CMP(x, y)   \
    (fabsf((x) - (y)) <= FLT_EPSILON * \
        fmaxf(1.0f, \
        fmaxf(fabsf(x), fabsf(y)))  \
    )
// absolute tolerance epsilon test
#define ABSOLUTE(x, y) (fabsf((x) - (y)) <= FLT_EPSILON)
// relative tolerance epsilon test
#define RELATIVE(x, y)  \
    (fabsf((x) - (y)) <= FLT_EPSILON * Max(fabsf(x), fabsf(y)))

//more intuitive to think of angles in terms of degrees
#define RAD2DEG(x) ((x) * 57.295754f)
#define DEG2RAD(x) ((x) * 0.0174533f)



// structure def
typedef struct vec2
{
    vec2() : x(0.0f), y(0.0f) {}
    vec2(float a, float b) : x(a), y(b) {}

    union 
    {
        struct
        {
            float x, y;
        };
        float asArray[2];
    };
    float& operator[] (int i)
    {
        return asArray[i];
    }
} vec2;

typedef struct vec3
{
    vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    union {
        struct
        {
            float x, y, z;
        };
        float asArray[3];
    };
    float &operator[](int i)
    {
        return asArray[i];
    }
} vec3;

//***************** implementation of Chapter 1 basic operations
vec2 operator+(const vec2 &l, const vec2 &r);
vec3 operator+(const vec3 &l, const vec3 &r);

vec2 operator-(const vec2 &l, const vec2 &r);
vec3 operator-(const vec3 &l, const vec3 &r);

vec2 operator*(const vec2 &l, const vec2 &r);
vec3 operator*(const vec3 &l, const vec3 &r);

vec2 operator*(const vec2 &l, float r);
vec3 operator*(const vec3 &l, float r);

vec2 operator==(const vec2 &l, float r);
vec3 operator==(const vec3 &l, float r);

vec2 operator!=(const vec2 &l, float r);
vec3 operator!=(const vec3 &l, float r);

float Dot(const vec2& l, const vec2& r);
float Dot(const vec3 &l, const vec3 &r);

float Magnitude(const vec2 &v);
float Magnitude(const vec3 &v);

float MagnitudeSq(const vec2 &v);
float MagnitudeSq(const vec3 &v);

void Normalize(vec2& v);
void Normalize(vec3& v);

vec2 Normalized(const vec2& v);
vec3 Normalized(const vec3& v);

vec3 Cross(const vec3& l, const vec3& r);

float Angle(const vec2& l, const vec2& r);
float Angle(const vec3& l, const vec3& r);

vec2 Projection(const vec2& length, const vec2& direction);
vec3 Projection(const vec3& length, const vec3& direction);

vec2 Perpendicular(const vec2& len, const vec2& dir);
vec3 Perpendicular(const vec3& len, const vec3& dir);

vec2 Reflection(const vec2& vec, const vec2& normal);
vec3 Reflection(const vec3& vec, const vec3& normal);

//*************


#endif