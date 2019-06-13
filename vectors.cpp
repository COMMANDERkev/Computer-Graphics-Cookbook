#include "vectors.h"
#include <cmath>
#include <cfloat>

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


// implementation of basic vector operations
vec2 operator+(const vec2& l, const vec2& r)
{
    return {l.x + r.x, l.y + r.y};
}

vec3 operator+(const vec3 &l, const vec3 &r)
{
    return {l.x + r.x, l.y + r.y, l.z + r.z};
}

vec2 operator-(const vec2 &l, const vec2 &r)
{
    return {l.x - r.x, l.y - r.y};
}

vec3 operator-(const vec3 &l, const vec3 &r)
{
    return {l.x - r.x, l.y - r.y, l.z - r.z};
}

vec2 operator*(const vec2 &l, const vec2 &r)
{
    return {l.x * r.x, l.y * r.y};
}
vec3 operator*(const vec3 &l, const vec3 &r)
{
    return {l.x * r.x, l.y * r.y, l.z * r.z};
}

vec2 operator*(const vec2 &l, float r)
{
    return {l.x * r, l.y * r};
}

vec3 operator*(const vec3 &l, float r)
{
    return {l.x * r, l.y * r, l.z * r};
}

bool operator==(const vec2 &l, const vec2 &r)
{
    return CMP(l.x, r.x) && CMP(l.y, r.y);
}
bool operator==(const vec3 &l, const vec3 &r)
{
    return CMP(l.x, r.x) && CMP(l.y, r.y) && CMP(l.z, r.z);
}
bool operator!=(const vec2 &l, const vec2 &r)
{
    return !(l == r);
}
bool operator!=(const vec3 &l, const vec3 &r)
{
    return !(l == r);
}

// implementation of basic vector functions
float Dot(const vec2& l, const vec2& r)
{
    return (l.x * r.x) + (l.y * r.y);
} 

float Dot(const vec3& l, const vec3& r)
{
    return (l.x * r.x) + (l.y * r.y) + (l.z * r.z);
}

float Magnitude(const vec2& v)
{
    return sqrtf(Dot(v, v));
}

float Magnitude(const vec3 &v)
{
    return sqrtf(Dot(v, v));
}

float MagnitudeSq(const vec2& v)
{
    return Dot(v, v);
}

float MagnitudeSq(const vec3 &v)
{
    return Dot(v, v);
}

float Distance(const vec3& p1, const vec3& p2)
{
    vec3 t = p1 - p2;
    return Magnitude(t);
}

void Normalize(vec2 &v)
{
    // can normalize by dividing each component by the length of the vector
    v = v * (1.0f / Magnitude(v));
}

void Normalize(vec3 &v)
{
    // can normalize by dividing each component by the length of the vector
    v = v * (1.0f / Magnitude(v));
}

vec2 Normalized(const vec2& v)
{
    return v * (1.0f / Magnitude(v));
}

vec3 Normalized(const vec3& v)
{
    return v * (1.0f / Magnitude(v));
}

