//
// Created by Kyrylo Bobrov on 10/7/17.
//

#include "rtv.h"



///normale_cone

/// find_cone_abc()


//// intersection_cone()





/*
Cone

        Definition:
C is the vertex of the cone
        V is the axis vector
k is the tangent of half angle of the cone
minm, maxm define cap points

To hit a cone we notice that:

        A = C + V*m
        ( P-A )|V = 0
len( P-A )/m = k
The (P-A)|V=0 equation is identical to the equation we know from cylinder, since cylinder is a special case of a cone.
Solution:

        m = D|V*t + X|V    (like for cylinder)
len( P-C-V*m ) = m*k
dot( D*t+X - V*(D|V*t + X|V) ) = k^2 * ( D|V*t + X|V )^2
dot( (D-V*(D|V))*t + X-V*(X|V) ) = k^2 * ( D|V*t + X|V )^2
Now the coefficients of the left-side trinomial are similar like for cylinder:
        a   = D|D - (D|V)^2
b/2 = D|X - (D|V)*(X|V)
c   = X|X - (X|V)^2
And the right-side coefficients:
k^2 * ( D|V*t + X|V )^2 =
= k^2 * ( (D|V)^2 * t^2 + 2*(D|V)*(X|V)*t + (X|V)^2 )
a   = k*k*(D|V)^2
b/2 = k*k*(D|V)*(X|V)
c   = k*k*(X|V)^2
Finally:
        a   = D|D - (1+k*k)*(D|V)^2
b/2 = D|X - (1+k*k)*(D|V)*(X|V)
c   = X|X - (1+k*k)*(X|V)^2
To calculate surface normal it is enough to notice that we have to normalize vector (P-C-V*m) - V*a. How to calculate a ? The angle between the normal and P-C-V*m must be the same as half angle of the cone. Hence:

        a/r = k
r/m = k
a = m*k*k
N = nrm( P-C-V*m - V*m*k*k )
N = nrm( P-C - (1+k*k)*V*m )
We cap the cone like a cylinder (except that the start cap point does not have to be at 0).

*/