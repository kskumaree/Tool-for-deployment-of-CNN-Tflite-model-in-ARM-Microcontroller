#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "arm_const_structs.h"
#include "arm_nnfunctions.h"



#define CONV3_IN_y 8
#define CONV3_IN_x 10
#define CONV3_IN_CH 24
#define CONV3_OUT_CH 48																		
#define CONV3_KER_y 3
#define CONV3_KER_x 3
#define CONV3_PAD_y 1
#define CONV3_PAD_x 1																		
#define CONV3_STRIDE_y 1
#define CONV3_STRIDE_x 1
#define CONV3_BIAS_LSHIFT 3
#define CONV3_OUT_RSHIFT 6
#define CONV3_OUT_y 8
#define CONV3_OUT_x 10

#define MAX3_IN_y 8
#define MAX3_IN_x 10
#define MAX3_OUT_y 8
#define MAX3_OUT_x 6
#define MAX3_STRIDE_y 1
#define MAX3_STRIDE_x 1
#define MAX3_KERNEL_y 1
#define MAX3_KERNEL_x 5
#define MAX3_PAD_y 0
#define MAX3_PAD_x 0
#define MAX3_ACT_min 0
#define MAX3_ACT_max 127
#define MAX3_CHANNEL_in 48




const q7_t W_3[CONV3_IN_CH*CONV3_KER_y*CONV3_KER_x*CONV3_OUT_CH]={


1,-8,14,6,2,-16,4,-5,4,-6,-3,-10,2,4,-7,-5,-11,-4,0,-15,-15,10,16,5,
5,4,0,7,5,-18,11,14,-13,0,-6,-2,15,-17,6,-1,-17,-10,-12,-6,-4,-15,4,8,
12,-5,2,4,-4,-10,12,20,2,-9,-3,3,-11,-16,-15,-1,-2,-11,-17,3,0,-1,-10,-5,
-6,10,3,-11,-11,-7,14,6,-2,2,-1,5,-4,7,6,-6,8,-4,-5,-1,-6,3,2,-8,
-13,3,1,-6,-8,-8,7,-3,-5,11,1,-10,-12,13,14,-12,8,-5,-4,-9,12,2,12,12,
-10,-6,-11,-12,-7,-6,-2,13,13,-5,3,8,-5,-1,17,11,-3,-17,-6,-2,1,-12,3,-2,
-2,6,-3,7,7,5,-2,-6,11,10,-14,6,8,15,11,-9,-13,-4,4,-6,1,7,5,0,
7,0,8,4,-4,-10,2,-7,12,7,8,9,11,14,12,-9,10,-3,1,10,19,7,16,6,
-8,11,10,-12,8,-2,5,-4,-1,-5,10,-9,2,6,0,3,-4,8,-1,7,9,3,6,3,

-15,0,-12,10,1,14,-7,-6,9,11,8,-2,7,13,9,3,8,-8,5,3,3,-16,-6,-7,
-2,-1,-10,-1,-1,2,-22,-18,1,-11,-9,18,3,3,7,-7,11,13,-2,4,-3,-1,-15,12,
3,19,-1,6,4,8,-21,8,21,-1,-18,6,1,10,-9,-21,3,10,-10,12,-3,3,-18,14,
3,1,-17,-3,-8,-3,-6,5,8,-11,-9,-6,10,5,-6,7,-10,-6,-5,-11,-7,2,-9,8,
9,1,-5,11,-5,-8,-24,-11,-14,-8,-4,-6,7,-10,-8,3,-8,-1,-7,6,-11,-12,8,6,
15,12,5,13,8,-5,-9,3,12,-8,-4,0,10,-15,-9,-2,-8,-6,-4,10,1,-9,-7,8,
-8,-1,-15,-13,-3,12,7,-1,0,12,-2,2,-17,3,-9,4,10,-8,-8,3,-4,-1,-15,6,
-7,2,-14,1,-10,-3,-16,-1,0,0,6,-8,6,-20,-19,2,1,10,-15,2,5,4,6,-3,
3,4,-5,10,14,-4,-1,-3,1,-8,7,10,1,-8,4,7,7,-10,-3,-8,-9,-12,-15,-10,

-4,4,1,0,6,-4,-1,-3,13,12,-7,-10,-8,-9,0,-15,-11,-7,10,-4,-7,-13,13,-3,
-2,14,6,15,0,8,-8,5,8,2,6,3,-4,0,3,-1,3,1,0,2,1,1,12,4,
-6,6,10,-6,-1,0,-5,-16,4,-7,-15,8,-14,4,12,-10,4,4,-8,7,-15,-8,-13,-5,
5,-6,4,-1,-8,8,-1,2,-1,9,-10,-3,8,-13,-10,-6,6,1,4,5,-14,-1,12,8,
8,-8,-2,13,1,5,-6,-4,8,-6,-1,-6,4,10,8,8,-12,-1,-4,1,9,-16,12,-10,
7,-2,12,13,-11,9,3,-1,4,2,5,11,7,0,-3,5,-5,-17,-6,-5,0,-8,7,-2,
2,0,-9,5,-12,8,9,-8,15,-5,6,6,0,-2,-11,-9,-6,-3,3,-1,-3,-2,-8,-6,
6,-7,-8,-1,3,4,-1,-4,-3,3,-5,-9,16,-8,9,-13,2,-13,-1,0,-7,-13,6,-8,
12,-4,-5,15,0,-7,-9,7,-8,5,3,2,-6,8,-2,-8,-3,-6,0,15,-1,6,4,1,

1,1,-4,0,7,3,20,18,4,3,9,-3,-17,-1,-20,3,1,-10,-2,1,-19,10,17,3,
-23,1,-4,12,-2,-3,10,-7,7,-8,-1,-11,-16,-7,8,6,-15,-2,-4,-5,-7,10,10,-8,
3,18,2,7,-4,-12,17,5,8,1,7,-11,1,15,23,15,-11,1,1,8,-6,-8,3,3,
-8,6,-5,0,-8,0,-1,4,16,8,-2,-11,-5,-2,-11,0,-8,-6,-6,3,0,5,5,-9,
-20,12,12,16,9,-11,-9,4,10,12,10,-7,8,10,13,4,-11,-10,2,-1,-6,-6,19,-1,
1,-7,8,3,7,-1,3,22,15,-8,2,5,-4,12,13,-7,3,-12,4,-7,-1,0,1,11,
-9,-9,1,13,-5,-1,0,-2,12,0,-9,11,-4,3,-5,-14,0,6,9,12,-6,-2,22,-2,
-13,0,2,-5,-7,-4,5,5,13,0,-15,-10,5,10,-11,-19,-18,-6,3,1,-18,-6,9,6,
16,8,-8,-1,-12,-3,4,18,7,-7,-8,-14,7,4,-15,1,-8,-11,-9,1,-7,-8,-21,-14,

0,-11,2,-6,6,-7,13,13,7,-12,4,5,5,11,1,10,1,6,4,-2,-9,10,-20,10,
22,-13,7,-2,4,-8,12,-1,-7,-6,-10,-11,-4,8,1,-3,7,-5,-7,-7,11,-2,-19,-2,
15,5,-11,2,-8,6,5,1,-8,12,2,-8,-9,-12,-2,4,7,-3,7,-11,6,9,-2,-7,
-1,4,-3,2,-6,4,-6,0,-9,-3,5,13,-7,9,-2,-9,4,-6,4,10,-17,-10,2,-4,
-25,20,0,7,-6,-11,-18,-14,6,-6,-18,2,-26,0,6,-20,-3,-14,-1,6,-17,-8,-9,6,
-3,6,-3,-13,-5,10,4,-5,-11,11,-6,-5,-22,-3,7,-13,-4,-9,11,11,-5,-8,-4,-1,
16,6,-4,6,13,-1,-17,-1,-9,-3,-6,-1,8,2,9,-8,8,-20,4,13,0,-12,-5,7,
-12,5,0,-3,5,-4,1,-5,-6,3,-6,-2,-11,3,0,-8,12,-1,0,14,-1,-12,-33,15,
-6,-1,0,-15,-8,8,3,-5,0,0,-14,12,-7,10,-10,5,10,1,6,1,3,-5,3,5,

19,7,6,15,-5,-3,-7,-13,-13,4,2,9,-12,-13,-3,-8,-3,-11,-5,-6,7,-5,-20,1,
-3,-7,-7,-3,-2,-9,1,-2,17,-3,5,-7,-24,-5,6,14,-3,-4,3,6,-3,16,2,11,
-3,8,-5,0,-1,12,-2,-5,3,7,-2,3,2,-2,-10,-3,-2,3,3,-3,-1,1,7,2,
-23,-25,6,-12,11,-18,-5,7,-1,-5,-8,-9,-10,6,-4,-4,-12,-33,10,4,3,-1,-14,-1,
-2,-31,17,-20,11,-1,24,21,8,-3,7,-1,-34,5,-15,16,0,-13,18,6,-19,3,-14,1,
-4,-28,22,4,-3,13,22,17,3,5,5,0,-2,6,-2,2,-7,7,7,5,-12,0,11,1,
4,-2,16,-11,8,5,11,18,-1,-10,9,-6,-15,3,7,1,-2,-15,16,10,10,9,-21,1,
15,11,5,-23,-7,3,16,7,-11,-7,-2,8,-20,-17,-16,-4,-2,-6,-2,7,-8,-4,-5,5,
11,0,-22,-15,5,-7,-6,9,-10,7,10,-9,-12,-1,-9,0,12,-10,3,-7,8,5,0,-5,

-12,-14,-11,-1,6,8,-10,5,-5,-3,5,-8,-16,13,0,5,-8,-6,5,-7,-12,-16,7,-4,
1,-9,5,4,5,13,-8,15,-4,-6,-10,-1,-21,-6,-12,9,-8,12,11,-6,1,12,-9,4,
7,-7,2,-7,-8,0,-1,0,-7,-27,-16,-3,-23,2,-4,8,-4,10,5,8,-12,1,-11,0,
12,-12,7,-3,7,-1,-2,10,1,4,1,-1,16,-1,11,3,6,-5,13,-8,-1,-5,2,3,
16,3,7,12,2,-5,-1,-11,-10,-2,-11,4,13,-4,-1,-1,1,-6,-3,13,-9,-1,-12,9,
-10,3,-7,0,8,-5,-23,-8,11,-9,-4,11,-4,-6,-18,-22,-14,0,-16,-7,4,-5,-9,10,
25,15,-17,-14,1,7,3,-5,-7,-1,4,-5,10,-14,-16,3,-9,-7,-11,-17,-6,-10,-2,-10,
20,2,-1,-2,13,-14,-17,-7,-1,-16,-9,5,15,2,2,0,-5,-10,-4,-14,10,-6,-5,-7,
14,17,-3,3,-2,14,-9,4,-12,-8,9,14,4,4,5,-4,-4,3,11,-1,-1,6,-15,6,

0,-5,-18,0,-3,2,-22,-22,-13,10,2,13,6,14,8,-2,-4,-4,-5,2,-10,-16,6,9,
-18,10,-7,1,-1,4,-22,-18,-3,7,-6,4,-16,4,-8,-7,-1,1,-4,-5,-2,0,-5,-5,
-4,-8,-16,-15,8,6,-7,-13,-3,5,5,-6,-21,13,-18,-12,7,-5,0,1,1,8,-6,6,
-8,5,3,7,16,5,-13,0,-10,3,14,7,20,-15,11,-4,3,-1,7,0,-12,-5,9,1,
11,0,-6,22,-7,8,-21,-19,12,10,5,12,11,-12,-4,-9,1,10,-3,-6,-18,13,-7,10,
-4,-6,2,14,6,-9,-14,-7,9,-18,3,-2,-20,-17,-16,-11,3,-7,-5,-1,-16,0,13,-6,
3,18,-4,-7,-7,12,-16,-11,16,-15,0,6,8,-25,-15,-6,11,8,-9,-18,-8,16,-1,-11,
16,-6,-22,4,0,1,-4,4,7,-3,3,6,16,-14,-19,-11,-17,-7,-2,0,-13,6,12,7,
7,11,1,12,7,8,7,8,15,8,19,18,3,-14,-6,4,10,6,4,-9,-7,-1,-1,9,

4,-16,15,8,-6,-7,8,9,-14,-12,5,-9,5,8,-12,9,4,-7,5,-5,-8,1,9,-14,
-1,16,3,11,-1,-1,-10,5,-10,5,-11,-6,5,-11,-1,-5,-5,0,-4,-14,3,7,12,-1,
-7,4,-4,10,10,-5,-15,-12,2,9,-8,5,7,-14,8,-8,-14,11,-4,-1,20,-2,17,1,
16,-1,-1,15,6,8,-6,3,-4,2,10,12,-3,5,0,0,-12,-14,6,0,2,-1,9,-10,
5,2,-7,14,12,-1,-18,-18,5,-4,-10,7,9,-10,1,-14,-10,-4,3,-1,-1,2,6,5,
-17,-15,14,5,-12,1,-1,-7,5,2,3,-5,-9,-7,-12,-6,-15,-14,5,9,-9,1,16,-4,
-3,-15,0,14,3,3,-6,-15,5,-2,-10,-2,3,2,-6,5,-1,-12,4,-10,1,9,5,-12,
4,-5,10,8,6,-10,-19,6,-4,-9,12,12,-5,3,10,-6,-8,-6,8,14,8,-1,-4,6,
7,-2,20,-18,9,-3,-4,-5,5,-17,7,4,2,-1,3,9,-1,-7,-5,-7,0,12,-17,-2,

2,21,-12,2,0,-13,2,-2,6,-10,-11,0,11,4,1,-7,6,-10,2,3,6,8,-7,5,
2,20,-19,-6,-8,-4,6,-8,6,10,-4,-8,10,2,-8,-7,2,-1,2,-10,12,8,12,-2,
2,-1,2,0,4,0,-7,-4,6,9,-1,-4,3,-11,-8,4,2,8,0,-13,-1,5,-7,-6,
-15,24,-6,8,-3,-8,-12,-8,15,-5,-12,13,-20,4,-1,-10,3,8,-10,4,2,10,13,9,
-33,9,-4,-10,-17,-7,-14,-4,-2,9,5,-12,-9,-9,3,-14,-2,10,-4,-6,0,1,7,-8,
-18,-4,-13,0,-11,-11,0,4,3,-1,-9,-14,3,-15,1,-4,8,11,-4,-2,-12,-6,2,2,
-6,14,-10,6,-1,0,-14,7,5,14,-4,11,7,7,13,-10,-8,-13,-3,3,-8,6,3,13,
-17,9,11,4,2,-1,-6,-10,4,19,9,8,-1,14,15,-15,-1,4,0,-1,-10,-6,13,16,
-25,15,0,13,8,6,-14,5,14,-4,0,8,-13,18,14,-19,-8,8,-3,0,-20,-5,4,2,

16,-2,-7,-6,6,0,-10,-12,2,-15,0,1,4,8,-14,-7,10,-2,-1,-5,-6,-16,-5,0,
14,-14,11,-4,7,0,-13,-1,4,-6,-11,8,-4,-5,15,-3,7,-3,1,7,-6,-10,15,-1,
-4,-4,0,-4,4,-3,-6,1,13,-12,-2,-11,-7,-3,1,7,4,9,5,12,2,4,-11,-2,
-10,-14,6,1,6,-12,-11,3,5,18,-4,-7,0,-6,-9,10,4,13,17,-9,10,8,-5,-6,
-3,-5,16,-8,7,-6,10,10,13,-11,-12,-3,-6,-3,-6,-4,-7,-2,2,-12,-14,1,-2,-9,
10,-8,-9,-3,10,-5,-12,5,-6,4,14,5,-9,5,-7,12,-14,5,0,-2,-8,-4,11,-4,
1,-5,5,-1,9,-4,-4,13,-3,-6,-3,9,3,5,-17,8,0,13,12,8,-8,3,0,-8,
6,0,13,-7,-9,7,2,8,8,8,9,-5,-8,9,-6,6,-13,-4,0,-16,0,9,12,-13,
-6,1,-2,1,3,0,10,-7,-8,8,-11,4,11,-4,-12,-6,5,-10,5,4,1,-6,2,10,

-17,22,-11,5,-6,-8,-16,-4,-7,10,-7,-11,-8,-2,7,-11,-1,3,-1,-2,8,-7,16,11,
-26,23,8,10,-5,-8,-9,-4,9,13,10,10,-2,-6,20,-4,1,16,-3,-6,-15,-7,8,-3,
-22,17,-6,12,-8,6,-4,-11,2,3,1,3,4,0,19,5,4,10,-9,11,2,-13,-3,-5,
-3,-24,9,-10,12,14,1,5,-10,5,-12,-11,8,12,9,-11,-7,5,3,0,-12,-11,1,11,
6,-27,-2,-7,8,-6,4,0,-5,-4,0,-8,-4,18,-5,-10,-5,-5,7,15,-7,-8,14,1,
11,-7,18,7,8,7,-10,5,2,1,2,-7,2,-6,-1,5,4,1,-6,12,-5,-14,2,12,
16,-3,-2,-4,12,0,7,6,8,-1,-9,-3,10,-13,6,4,-5,6,4,-8,-3,7,-3,-7,
4,-19,-6,0,-5,-6,-11,14,2,-15,2,-7,0,-13,-1,7,-4,-10,-4,4,-22,8,4,-6,
17,-13,-8,5,-10,-14,7,14,-10,-17,8,1,-3,-3,0,-5,1,0,-6,1,0,8,12,-1,

0,13,14,-4,16,-15,-3,8,13,9,-3,-1,4,-12,-17,8,-12,-4,0,6,14,-3,-13,3,
-1,8,-2,12,3,2,-1,2,-6,10,-6,-1,1,-7,4,0,-12,12,2,-13,0,0,-7,-7,
-7,3,5,-10,1,-6,3,13,9,11,1,10,-8,-9,-13,-6,5,2,1,10,-4,-8,1,-4,
14,0,5,6,-9,-1,-5,10,-2,-6,-12,9,-9,-5,0,-7,-2,-13,-1,6,-7,-17,-25,8,
5,15,4,-16,-9,7,-16,3,-10,-3,-3,4,-11,11,-14,6,9,14,-2,4,2,-12,-26,4,
-12,11,3,0,-7,3,-17,-6,-3,-1,-12,-9,-8,14,2,12,3,13,-6,-2,9,5,-8,1,
11,-6,9,-8,9,-19,15,9,-9,-13,-11,-11,-2,-2,-12,2,-4,-7,-3,-2,26,2,-8,-5,
17,-5,3,2,10,-15,8,8,-4,-10,-19,-7,-3,-3,-24,-1,-10,-17,-4,-5,8,-4,-15,5,
3,-9,-5,-9,7,-3,-3,10,-5,7,-10,1,6,11,-9,13,-3,0,-2,6,-10,0,-17,2,

-12,8,-13,1,5,9,-7,-3,-3,-6,1,5,9,-7,1,-5,3,-5,-11,-15,2,-1,8,7,
2,1,-8,-3,-8,10,1,11,2,-4,6,6,-8,-2,-4,-4,3,-17,0,13,2,1,-23,-1,
10,-1,-1,-3,-12,10,0,11,6,4,6,-7,-22,10,-9,12,13,-10,0,-4,1,-1,-19,9,
18,-28,13,8,-5,16,-10,-13,1,-10,-10,9,13,11,3,-6,3,-13,4,16,10,-2,-16,8,
23,-10,1,5,-6,12,4,1,-1,-18,-4,-6,7,-2,-15,-2,14,-11,1,20,-16,-14,-47,0,
-5,3,6,2,2,15,3,6,-9,-12,-3,1,0,-6,-16,-10,-5,-12,-4,15,-19,-8,-24,-3,
20,-2,-9,5,0,-3,-1,5,-11,-15,7,3,15,1,7,-5,-8,-7,-9,-9,-3,-23,-2,0,
7,16,-11,8,3,-4,-5,-3,-2,1,15,4,-3,13,-8,-9,-4,-2,-2,-3,-2,-15,-29,9,
-1,-3,11,-11,13,-7,-1,7,2,-9,-2,4,1,-3,-12,14,-7,-10,6,11,-2,-11,-8,-2,

20,18,-9,14,3,14,-13,-9,-5,-5,-10,10,17,-4,-6,6,-2,-6,2,6,10,-24,5,11,
0,17,-20,9,-6,0,-11,0,4,-6,-8,-1,9,11,-15,-14,-9,14,-8,5,-9,2,-17,-11,
19,-5,-15,8,-12,6,-10,-1,1,-8,-8,-1,-11,-13,0,8,3,-1,0,4,2,-1,-1,9,
4,14,-9,2,-3,-3,-12,-19,-8,-3,4,7,17,-14,-8,-5,2,-9,-11,7,6,-2,-5,-7,
0,28,-10,14,3,-11,-12,-15,-6,-2,-5,7,-6,8,-9,-3,0,-2,-11,14,-5,11,-8,16,
-28,31,-5,10,2,-12,-4,-12,11,8,-14,5,-6,-10,14,11,-2,-9,-13,-5,5,5,10,4,
-11,-11,-1,6,0,-7,-8,-2,0,-3,4,8,-5,-8,-3,-1,-4,-4,-6,5,1,-9,-6,-5,
-5,-11,-7,15,14,5,1,-5,-10,-10,-16,-9,3,0,-6,7,-11,-9,1,-5,11,10,-8,10,
-1,0,3,13,13,8,-13,-8,-2,-10,-5,-4,1,-2,-5,15,-11,-2,1,5,11,0,3,7,

-10,-5,2,1,-6,-14,4,9,-10,-9,16,3,-28,-9,-3,-14,-8,2,13,11,-18,7,-8,-9,
-10,-15,1,7,-11,-5,9,5,17,12,-2,2,15,-3,0,2,7,5,21,-7,-8,13,7,0,
-3,-19,-3,4,13,-4,-3,16,3,-3,-15,10,9,5,9,-6,9,10,3,1,-18,-11,-5,8,
2,-5,10,-8,1,-3,9,11,10,13,-5,7,-10,6,-2,0,4,-5,3,-4,8,-6,-9,8,
10,-4,-8,-11,-15,-2,13,-1,3,10,0,-8,18,-16,-8,-15,3,-1,-7,-6,-8,-7,2,-3,
9,-16,-2,6,6,-3,-3,-2,5,-7,13,-7,-2,-13,13,-5,-8,13,-1,-8,6,2,8,-4,
11,2,-10,10,7,14,-7,-2,1,-7,1,11,12,-2,7,-3,11,2,4,15,-20,-2,-15,10,
-20,1,-9,10,-11,11,4,9,16,-1,-9,-8,-11,3,-17,-4,-6,9,2,18,-5,-7,17,1,
-13,11,9,11,-6,-9,-2,-8,-6,12,12,7,-6,2,-6,-4,5,1,1,-13,-12,5,6,-4,

-24,8,-4,4,-4,-16,-8,-6,-2,-12,1,6,-12,6,0,-12,9,-19,-2,-9,-1,-17,10,11,
-20,-6,14,-11,5,-3,6,8,-15,-12,-12,-14,1,1,5,-10,-12,-21,9,4,-18,-20,5,1,
10,-6,21,-10,9,-3,14,5,0,-4,2,-11,6,5,2,6,-5,-11,14,-9,7,-14,-20,4,
-13,-27,-2,5,6,4,7,14,-12,10,8,-10,2,16,-3,5,-4,0,6,4,-2,2,-12,3,
15,-22,16,-2,-11,-6,9,15,5,-20,9,6,-8,-2,7,12,7,-2,2,-3,-3,-11,-16,5,
2,7,-2,-5,-9,-11,1,20,-7,-16,-5,-6,5,8,2,6,-7,-1,-5,4,-17,4,-19,10,
6,15,12,6,10,8,-9,14,0,-2,-14,-13,1,-5,-3,-1,-12,6,4,12,-3,2,-4,-12,
22,33,-7,11,7,0,-11,6,-10,-15,-18,-12,3,0,-7,-1,4,-7,-9,-3,0,-11,15,-12,
12,38,-5,4,-7,3,-18,3,3,-2,-13,8,7,13,2,-11,8,0,4,1,5,-8,4,-4,

7,-9,-7,17,14,-1,-6,-10,13,15,6,-2,20,-2,1,-21,2,-5,-2,-3,1,-5,5,16,
6,27,2,14,1,-3,-14,2,2,1,7,12,-4,-11,2,7,6,8,-10,0,-7,22,-8,10,
-17,11,-19,-8,-4,-5,-16,2,2,-16,-11,-2,-25,-2,-16,6,-3,11,-7,-7,7,13,-3,-11,
6,4,-11,-2,-1,-4,-27,-13,8,-3,-7,7,3,-13,10,3,9,2,0,4,-3,12,-1,-8,
18,1,1,14,16,-6,-13,-5,6,-9,-3,9,16,-15,-5,-12,2,2,-12,10,6,2,-2,13,
-2,26,-3,-4,7,3,-19,-12,4,-2,-1,1,0,4,-15,-14,2,-2,-17,4,-13,-6,-19,1,
-9,17,-15,-18,5,5,-8,-10,-3,-14,-6,-15,13,-3,-11,8,-9,0,-12,-4,-13,4,-12,-11,
29,10,-7,12,-8,7,-20,-18,-22,-13,-20,-5,12,-10,-18,1,-12,-9,-14,-5,-18,-12,4,-12,
19,9,7,20,10,0,-21,4,-5,12,7,10,6,1,6,1,5,-13,-2,-7,-5,0,-1,0,

6,11,-8,-17,-13,6,2,-6,10,9,11,2,-18,-12,-9,-9,-4,6,-5,-2,5,-4,-6,-8,
16,6,-7,4,7,7,7,-2,-21,10,3,-6,3,-2,-10,-7,8,-17,-6,-3,11,-18,3,-13,
21,26,8,-10,8,-8,17,16,8,-2,2,-6,17,-4,14,14,-6,-1,-7,-7,10,-15,-10,-2,
-22,19,-3,12,5,6,-3,-24,9,-6,-5,3,-5,-4,-8,6,-5,-7,-7,5,-4,11,7,-1,
-28,9,-3,2,-10,-18,7,-14,-11,8,-13,-5,-11,-10,-3,4,-6,-6,-5,-1,-4,8,-3,12,
4,-1,15,-5,4,-15,38,4,-15,-3,4,-12,6,11,3,-3,-1,-18,7,-12,0,-9,0,3,
-12,-12,10,7,6,9,3,-6,3,-2,8,13,11,17,12,-12,-2,-16,4,9,-13,7,7,-2,
-16,-2,16,-11,10,2,14,1,3,-2,-1,-7,-13,18,3,-1,11,-16,4,1,-13,-1,-14,17,
3,-9,8,-11,-4,-1,20,14,6,-5,-7,-8,-16,12,-13,5,-10,-6,-4,3,-9,9,-7,11,

0,-9,-16,-10,4,5,0,11,7,14,-10,-1,-5,-13,-11,5,-5,-3,-4,3,8,-6,-4,-7,
-16,11,2,15,-2,-7,-15,-17,9,4,7,-2,1,-6,5,0,-5,2,0,2,-10,-4,7,8,
-8,28,-5,3,-7,2,-15,-12,6,6,3,-3,-5,13,1,5,10,-9,-4,8,11,-12,-5,4,
-13,0,-12,-5,-3,-12,-6,7,-3,2,-4,1,2,0,-9,-5,5,2,3,-12,-10,-5,8,-4,
-3,-6,11,-4,-7,1,-16,-5,9,6,11,-3,8,2,10,-8,5,-4,10,10,-2,-6,3,-3,
6,-7,3,11,12,15,-7,-8,-1,-8,4,2,-4,16,-8,6,-12,-2,8,5,3,-2,-5,-7,
-14,-4,-2,6,9,13,-4,-7,5,15,10,4,-25,7,-3,-13,4,11,2,-5,-12,4,-3,-3,
-9,3,-3,-3,-1,6,2,4,22,-10,5,-6,13,-12,-15,1,-5,4,-6,14,-3,11,8,7,
2,-6,-2,-5,-11,4,5,-5,13,1,8,-10,16,-8,6,-5,5,7,-6,-11,-6,-7,7,-9,

1,13,4,11,-6,-19,2,9,1,14,-14,-2,-11,6,4,-8,5,-14,6,-14,-6,-14,11,9,
17,-14,1,-10,1,-10,18,3,3,11,-2,9,-2,-5,12,7,8,-5,11,3,-14,4,7,5,
21,-21,3,-7,19,-16,20,23,0,0,-2,10,14,-14,-10,10,-1,1,3,-10,-12,7,-3,11,
-19,-12,3,-5,-13,-4,2,-3,-3,0,-2,-12,-3,11,1,-3,-4,2,10,4,-7,7,8,10,
-10,2,7,-17,-11,7,4,14,8,-6,-14,-14,-13,5,-7,3,0,-2,5,-1,5,-4,-3,1,
2,4,1,-14,-2,-10,-4,12,-6,8,3,-7,-18,0,-3,5,2,-3,-6,-15,6,9,-2,-1,
2,-5,19,-15,3,6,4,14,12,-2,5,-7,3,-12,-14,3,-2,-5,5,-11,-9,2,1,8,
6,-7,14,-14,-2,-15,4,-6,8,0,-3,6,-4,-11,-4,2,-2,-10,-8,-3,-9,11,-6,10,
0,-1,-11,-1,3,-8,-11,2,3,-2,-12,1,-3,-12,-14,-2,2,-10,-2,-1,-3,0,-1,-10,

-20,31,-18,10,-1,4,-18,-20,0,2,17,1,2,-8,14,-20,-11,-19,1,-1,3,-24,1,-8,
-14,18,-11,2,-9,2,4,6,-3,9,1,6,3,8,-3,11,10,3,-6,4,13,-6,3,6,
-17,6,-7,10,-11,12,4,5,-2,2,-2,1,-4,-6,0,2,-1,-12,-8,-3,7,-2,18,5,
-8,16,6,2,-4,-2,9,2,-8,-9,2,-6,-9,3,-1,-15,-9,-10,0,-3,-11,1,5,12,
-14,12,13,5,4,3,7,-9,7,-3,0,-5,3,14,4,-5,9,-7,0,6,-7,6,3,-11,
-1,-1,19,-4,6,-3,14,2,5,-5,4,-2,-10,4,-1,1,-5,-3,-1,3,1,5,16,-7,
3,-2,-2,3,8,8,-16,4,6,3,-20,-5,-13,-11,-13,-11,4,-10,1,5,-25,-2,-15,5,
1,8,-2,-3,-7,-5,-10,-1,-2,-8,-18,10,-3,-9,-2,4,5,2,-2,1,-12,5,-3,11,
2,-9,6,10,10,5,3,10,2,-5,5,0,1,4,-6,-7,2,-7,-3,-11,-13,-1,5,2,

-13,2,-9,-6,-7,-12,-5,6,-8,15,12,3,4,2,-11,-6,13,12,-7,-9,-10,-8,16,6,
-1,3,-8,16,5,-15,4,-3,13,11,-6,11,8,5,-1,5,8,15,-7,6,-11,-1,7,4,
-7,3,9,8,12,-1,0,17,16,-3,12,-4,0,4,14,-13,-3,-9,-7,8,8,12,-1,7,
4,2,7,2,-6,13,1,7,12,3,-6,11,-16,0,-5,9,-1,14,7,-1,4,8,-6,10,
7,-5,-7,13,3,4,-13,0,15,-6,-14,-9,1,-18,-15,-7,-8,-3,-3,5,-3,7,7,-5,
9,13,4,4,-2,-8,-16,12,-8,8,0,8,4,-24,-4,11,-9,8,-8,7,-2,-4,1,-1,
-3,-7,-15,5,5,-8,-7,5,2,0,-5,-13,5,-11,-1,4,-3,-5,-1,-7,-17,-12,7,-10,
8,-7,-15,-3,-14,-5,0,12,-1,2,2,-6,-2,-7,-11,5,-5,-7,-8,0,-16,-7,7,4,
15,-3,-15,-7,9,2,-1,0,8,0,-4,-7,8,-5,3,-1,8,-8,-7,-13,-11,-8,-8,-9,

-9,-1,-10,0,-10,3,-3,8,10,-8,-7,2,-11,11,7,-9,5,-11,0,5,-11,6,-16,10,
-15,9,8,-7,-7,-4,0,2,-5,-3,7,0,10,7,-12,-18,-6,-13,-4,-6,5,-7,10,-7,
-9,4,-17,16,18,9,-4,-7,15,10,-11,15,12,-13,9,3,-3,-15,-4,-8,5,5,6,-1,
11,6,-11,16,8,1,1,-6,-5,2,-3,11,19,1,8,-11,3,2,-5,-8,9,1,-10,-2,
8,14,-4,-9,-7,-5,-3,10,10,-5,11,-8,-12,1,-8,-12,6,-14,-14,6,3,9,-2,-8,
8,-3,-3,-1,-3,-13,-15,-10,-9,7,-4,8,6,-8,-11,5,-6,-9,-1,-3,0,-5,-1,11,
10,18,2,5,8,-2,12,-4,5,2,7,-7,7,0,-3,9,-9,6,-8,-8,3,2,-2,-5,
13,19,-11,2,-1,4,-5,-9,2,2,7,8,-13,13,1,-3,9,1,-8,8,-17,6,5,4,
-20,16,6,-7,-13,14,-8,0,-4,16,10,2,-3,6,-11,4,5,-3,3,-6,-19,-12,-12,-4,

30,3,3,-4,14,7,2,-13,-13,-24,-16,11,18,-13,-22,8,-10,8,-8,14,-3,-14,-21,-10,
5,6,-8,-2,7,15,-17,1,7,-18,-4,-8,-5,-2,-3,0,12,-3,-8,13,-2,11,-1,-1,
-23,8,4,1,-7,9,-25,-19,2,-1,-1,-2,-8,13,-14,-4,5,10,-1,-5,-1,-12,0,6,
27,-22,6,-4,6,15,0,3,-15,-10,3,8,17,-6,-13,10,-4,8,5,3,-12,-23,-22,2,
11,10,5,8,6,-6,-24,-17,-12,-6,-21,10,3,8,-4,-12,-9,12,-6,-6,-16,-18,-17,8,
-21,2,-7,-6,-3,-4,-6,-3,0,2,1,10,-19,-4,-10,-3,-5,-9,-3,-9,2,3,-7,-1,
8,-5,0,-3,9,3,-1,-16,5,2,-4,6,2,10,6,5,-3,6,-3,-16,-4,-4,-10,-16,
-7,-3,-7,7,6,-7,8,10,3,-4,4,-2,8,15,6,-4,14,-6,6,-7,4,-11,-12,-7,
7,-1,-2,-1,6,-1,11,11,-10,3,-7,-10,-6,7,-15,14,16,-7,1,14,-1,4,-10,5,

-1,18,7,-3,1,16,-13,-7,-2,-15,-4,5,-11,10,-4,-11,8,-4,-10,8,-6,11,-11,9,
-20,19,-19,2,10,-6,-21,-15,-3,-8,-16,-4,-9,-2,-18,-4,7,-5,-12,3,5,-2,2,-7,
0,5,-17,13,-9,-12,-16,-14,-11,8,-3,-13,15,-19,-5,-8,5,4,-4,0,10,-7,-8,-14,
11,-11,2,1,5,-1,-4,-9,-2,-10,-13,-9,6,-17,-6,-2,-16,3,-12,10,-4,-5,-11,2,
-7,5,2,10,7,1,-8,-8,16,0,-1,-4,10,13,-10,-7,11,13,-11,-6,-7,15,-12,-4,
-10,21,1,7,5,-5,-15,-2,16,-6,5,13,-8,0,4,-1,-3,8,-6,14,-6,19,-9,-8,
13,5,-3,12,11,4,1,-5,-5,-17,0,-4,10,-13,-2,-3,-7,5,-7,4,4,-15,4,-11,
17,3,-11,-12,4,-6,-5,3,9,-4,-19,5,18,10,-7,1,-2,10,-12,10,3,5,-19,-6,
14,11,-9,3,-2,-2,-4,11,4,-7,7,-1,-3,-9,-4,2,7,-4,-1,15,-10,16,1,-1,

-15,-5,-18,0,-13,-10,10,-3,2,-9,5,-14,-7,-1,2,6,-3,-17,-11,-3,-5,-9,-1,2,
-11,17,-3,2,8,-9,-11,-13,2,0,-7,-5,-11,1,-2,10,8,-6,-7,-14,-8,1,-1,-12,
-9,25,3,2,5,-1,-14,-1,-15,11,5,9,-5,-9,-10,5,9,-4,-2,-13,-3,3,-5,-5,
-13,0,-13,7,-12,-13,-10,-8,-5,5,5,-12,-10,4,8,3,7,-3,-12,-19,4,-9,-6,-11,
-25,2,-2,-12,7,5,-11,6,10,-8,-9,8,5,-5,-1,5,-5,-2,-4,1,8,-15,9,-1,
0,-4,3,-8,-6,12,-20,-10,-10,2,-3,-9,3,12,3,6,8,-9,4,1,-6,-3,-11,-6,
-10,8,-12,3,1,2,3,-15,-9,4,15,10,-1,9,-10,1,10,-15,3,-16,-1,3,0,2,
2,4,-6,-2,14,2,5,-3,-4,9,1,4,-9,-3,-7,-16,6,-10,5,0,-10,-2,6,13,
-2,-3,9,8,14,-11,0,11,-8,-12,-5,4,-12,10,3,-3,11,-1,10,2,5,-4,-12,8,

-2,2,0,9,-9,10,-3,-5,3,-3,-4,-7,3,9,-2,3,3,-7,0,8,0,1,3,5,
-12,5,-3,-8,4,5,-2,-8,-1,-2,-1,-4,-10,2,4,-7,5,-5,-4,5,-4,-3,-8,-4,
-11,2,3,9,-7,-10,-2,-4,0,1,10,-9,-3,10,-3,-9,7,5,3,-3,2,-4,8,7,
-9,5,9,3,6,-2,-2,0,-1,-2,-11,-4,-4,-1,0,7,12,4,3,0,4,-6,3,-8,
0,4,2,-2,-4,6,-2,-6,-2,-2,-7,0,-14,7,-3,4,-10,-3,-2,-1,0,-5,1,-1,
-4,2,-1,9,-12,-6,-2,-6,-1,-5,9,-2,7,2,6,-6,-8,-4,3,-2,9,-3,9,-6,
-2,5,6,3,1,7,-2,-5,-1,-4,0,-4,4,7,-2,0,-12,-4,2,3,5,6,-2,-3,
-1,4,1,5,0,-8,-2,-1,0,-7,-9,-9,-6,7,0,7,0,4,-1,6,1,-6,-4,5,
-3,2,-2,4,-4,-3,-4,-3,0,7,-5,-1,0,-4,-1,-6,2,3,2,3,3,-2,-2,3,

-1,-11,14,3,8,6,7,2,2,13,-9,-3,6,8,8,3,0,-9,10,-1,-6,-8,19,-2,
2,-21,10,1,3,-7,5,-9,-4,10,-10,-4,26,5,7,11,1,0,-3,10,-8,-20,1,9,
4,8,-8,6,-4,0,-4,5,1,6,7,8,18,1,-10,13,-8,6,-7,10,4,-7,-11,1,
0,18,6,-10,8,4,-5,-3,-2,-7,-3,6,11,-10,-13,5,5,5,2,0,-19,-10,-6,-6,
18,21,6,-7,-3,6,-15,-2,-2,-17,0,5,-1,-3,8,-6,-14,-6,-9,-15,-4,-9,19,-3,
3,5,-11,8,10,-6,-3,-6,-12,-5,6,1,0,-19,3,-6,-2,-5,-11,6,-1,-4,-5,9,
-7,6,5,4,2,-7,0,5,1,9,1,9,-5,-6,-12,3,11,6,6,6,-14,-4,-5,8,
-3,1,11,8,-12,1,-5,-10,9,-12,-14,-9,9,-5,-10,-2,-6,6,0,-10,-8,-7,-3,-8,
-1,1,1,11,5,-9,-7,10,12,-9,-16,-6,-3,-1,1,2,-9,10,0,4,7,9,-8,-12,

-14,14,-14,-16,-13,-8,-16,-10,4,2,7,-9,-17,4,-4,3,-4,6,-1,-11,6,8,7,-13,
-2,15,4,10,10,-4,-16,-17,11,7,-5,-3,17,-4,-7,4,12,-1,8,-11,-2,9,10,-3,
6,-4,11,18,16,13,-8,-3,15,14,0,9,5,-14,5,-11,-2,-6,4,-4,-5,4,-9,15,
-8,11,1,4,10,15,8,4,0,11,-1,8,1,16,0,-4,-6,-3,-1,3,-5,6,-10,9,
-2,15,-15,-12,4,9,-8,5,-5,-8,0,14,-13,11,-16,2,7,12,-18,-6,-8,0,4,-2,
14,-5,-16,-4,-10,8,-12,-8,-1,-10,7,-1,14,-3,-14,-8,5,9,-9,-5,-4,-1,-9,-8,
26,-4,9,-10,7,5,3,4,-6,-13,-2,-5,5,-2,-7,10,-14,-3,-10,-9,3,1,-4,-12,
8,-15,2,11,-10,-4,-3,-7,-2,-9,1,4,7,-15,7,-2,0,-10,0,2,-17,-1,5,3,
-14,10,-1,3,3,13,-6,-18,1,-2,-7,-7,2,3,-3,-9,0,-4,1,16,-5,4,3,-7,

10,11,6,6,7,-9,1,10,-14,-8,5,9,3,8,-11,7,8,-7,-4,2,-7,3,2,-10,
17,17,-14,-3,-4,-5,5,-7,8,-8,-20,-6,4,13,4,-5,-6,7,-13,-13,-8,-7,13,1,
0,14,-8,-8,-6,5,3,-3,-1,-2,-8,-11,12,11,-3,7,-13,-9,-6,0,-8,7,6,-10,
12,-2,13,16,2,5,-8,11,-1,-8,0,-4,23,-1,-6,9,-9,-5,12,2,-17,1,8,6,
12,-1,15,4,1,-2,-6,-11,8,-9,-11,5,19,-2,-2,-1,-14,13,-3,6,-16,-1,2,-6,
1,3,-16,5,9,9,-23,-9,-5,-1,-26,3,4,-5,-11,-7,-8,8,-12,12,-13,0,-17,6,
7,3,2,2,-9,-3,-11,-13,-5,-15,-1,-2,3,-5,-8,-1,9,12,-9,4,-5,3,13,3,
20,2,-2,7,-8,-7,-8,-15,-9,8,-2,8,21,-3,-1,-8,2,-4,-12,4,-15,5,6,-6,
3,15,10,6,11,6,-21,-6,0,-6,1,11,10,7,2,-14,-8,11,-5,10,10,10,-1,-1,

-9,1,9,9,-10,-11,-12,-12,2,9,6,-10,7,-10,-5,-13,-10,-20,3,1,10,-7,12,-12,
-1,1,-5,0,11,-14,3,14,6,11,10,7,-4,12,5,-8,1,-9,2,-4,4,5,-1,11,
-4,8,-8,14,16,-6,0,0,9,-10,7,15,-12,-6,2,3,9,7,-5,10,-5,4,-10,10,
-20,1,-1,-12,3,8,-16,-7,5,2,-15,-2,3,-9,-11,-9,-7,-9,5,7,-16,11,3,4,
12,-1,0,-6,11,-2,2,4,-8,-12,-8,-1,6,-15,-10,-3,-9,-6,-6,1,-16,16,1,-12,
21,-3,-13,-2,9,3,-14,8,6,-7,3,11,12,-13,-7,4,-6,-1,-12,7,11,1,13,-7,
0,1,14,-7,13,1,8,8,-2,-2,7,1,-18,17,5,-18,-1,-1,2,-1,-13,10,7,7,
-5,-9,4,2,-10,10,-1,6,12,-5,-5,-15,-11,-4,3,-2,-1,16,-12,7,-2,-4,3,-12,
13,-11,-6,7,-13,-4,-9,1,1,5,-14,-5,20,-11,2,12,-11,-13,-8,6,-10,7,7,-12,

32,-25,11,-3,17,-9,-1,-4,-6,0,4,14,2,4,3,-1,11,2,3,5,1,-8,-17,-5,
13,18,-3,-3,7,0,-16,-10,-6,-12,-5,-2,3,0,-12,-10,3,17,-6,13,-12,8,-23,13,
-12,16,-12,-10,12,4,-24,-13,-11,-22,-11,8,-11,-3,2,-15,7,-8,-7,-3,14,-11,-22,-4,
7,5,6,-1,-8,-5,-7,11,2,-7,-12,-13,7,-12,3,3,8,-1,-11,7,9,-21,-6,-11,
17,-5,5,8,-7,-17,-6,-8,4,3,7,-6,7,-5,-10,-7,-3,0,-1,-7,3,-19,-12,11,
-5,7,-9,15,3,5,-16,5,0,2,2,7,4,-3,-9,4,0,13,-2,15,-6,11,-16,16,
-8,13,-11,8,6,-4,5,4,6,7,3,-1,-7,0,-13,-9,-10,-8,-3,-9,9,-2,7,2,
9,5,-12,0,7,1,2,-1,4,-8,-16,-2,-2,-10,-7,0,-7,-3,2,5,-3,9,-8,-8,
8,-11,-3,2,9,-14,0,9,-11,7,-10,3,0,-17,-23,18,0,8,-4,-12,-2,-2,-15,1,

10,0,9,-1,3,7,-3,-11,-4,2,-3,8,4,2,10,0,9,-10,4,0,9,4,11,-1,
12,-5,-5,11,0,-3,-1,13,-4,-9,10,-7,2,-17,-4,9,10,-5,-12,-9,-17,10,11,1,
-1,1,4,0,1,-6,-15,-9,-2,3,-3,-8,-10,-9,9,-2,-11,-7,-3,8,-13,1,-8,12,
6,-10,16,-4,-12,7,-6,5,8,-6,5,11,-3,2,-13,17,9,1,9,11,-3,11,-2,9,
2,-7,-2,4,0,-12,-5,-11,1,-3,-2,-7,-7,-3,4,9,-7,11,-7,-11,2,10,-7,-11,
3,5,0,-1,14,5,-17,-7,-10,9,-5,-4,-10,3,-7,-10,-11,5,1,-11,-5,-16,4,13,
6,5,5,0,-10,3,-10,-1,4,4,-1,-4,-3,-4,-12,2,-9,9,3,-11,-7,14,-2,-6,
1,-9,-2,-4,-9,13,1,4,-4,9,6,8,4,11,-3,8,-10,6,-1,12,-22,8,7,-2,
6,-17,-5,6,9,-6,6,7,4,-3,-15,-2,-10,1,-3,-15,-15,-4,3,-1,-6,-15,-5,3,

3,-13,5,-4,5,4,-14,-8,-6,-2,-1,4,-12,15,-4,-4,-2,-16,4,15,-12,-15,-21,2,
6,-16,2,9,12,-4,-16,-7,3,-10,2,5,-9,16,-14,-8,7,15,0,-4,-3,-15,2,-11,
-9,-12,8,-6,-4,0,-13,-9,-12,-18,-18,3,4,8,4,15,-5,-2,4,10,6,1,1,3,
21,2,-13,2,10,-10,2,11,-12,2,2,-4,5,-10,-7,-4,12,-9,-1,-4,9,-7,-5,-5,
23,7,-1,13,-1,-14,-1,-7,2,-8,-10,-5,0,4,-17,11,-9,6,-1,2,-4,-15,-3,-13,
11,8,8,-7,0,-2,-11,14,-1,-14,0,8,8,-13,4,-5,1,-1,-2,11,-10,3,-1,-5,
0,19,6,-2,-5,-12,0,-7,-1,8,-4,7,-4,3,-1,9,6,1,10,-6,18,9,9,-5,
10,4,24,5,-5,-13,1,13,8,3,14,2,-3,5,-11,11,-3,-9,10,6,3,1,10,10,
10,-10,16,-3,11,-8,7,4,5,0,-3,-13,-13,-9,-14,16,-5,-9,6,2,5,-3,-4,-7,

18,-3,7,-10,3,0,22,11,-7,-2,10,13,13,3,1,-1,-3,0,1,2,-11,5,-17,5,
2,0,-12,-11,-7,-1,26,19,0,-5,0,-13,-10,-12,-3,5,0,-10,0,0,-3,4,1,-2,
-1,13,9,12,-1,1,13,3,-13,6,14,-3,7,1,8,-6,-4,-5,0,-8,-2,-6,11,8,
2,3,-10,-12,-8,-8,19,4,14,16,-1,-4,-25,6,2,-1,5,10,-7,1,-2,-5,-2,-6,
-14,4,-19,-5,-7,-11,1,-10,12,5,-3,-10,-25,-2,7,-8,8,-10,-5,-6,7,1,17,-14,
-14,23,17,13,-7,6,21,8,-2,17,16,1,-1,5,-5,-14,-3,9,-1,4,-2,-3,17,-5,
-2,0,9,3,-3,5,0,0,-4,0,17,1,-6,2,3,-4,-3,-10,-2,-8,-2,8,14,3,
-12,-2,4,11,3,-10,-10,-1,13,15,-6,0,-17,-1,-13,-5,4,2,10,9,-17,-3,-2,7,
-1,-5,9,6,2,-7,12,31,-7,-7,-15,-6,-1,-8,4,-11,-11,-11,5,10,-23,11,3,12,

21,2,3,6,2,4,-1,-5,-2,-3,-4,-1,13,-1,8,7,2,-4,3,3,-10,-6,3,11,
-3,-2,-13,10,-12,4,-23,2,15,1,-2,11,-16,-1,-1,-10,3,-3,-5,16,-24,-9,-8,1,
-7,-7,8,5,2,-9,-8,-12,-6,-24,-7,-13,2,11,-8,-4,-13,-4,1,-4,0,-16,3,-6,
6,-1,-17,15,-3,-6,-1,3,4,9,4,-11,4,-12,1,-2,-2,4,-9,-7,5,18,3,12,
2,9,1,10,12,-5,-19,-5,-3,3,-9,8,-1,-13,13,0,-6,9,-6,-3,1,-7,3,8,
-18,9,7,9,3,-11,-6,11,5,0,3,-2,-22,-11,-15,-1,-13,4,-13,11,4,10,-10,1,
-11,7,-20,8,-8,3,-12,-11,-6,-6,-1,-14,0,-15,-12,12,6,2,-9,-5,-10,15,7,0,
10,-5,7,16,9,-9,-2,-4,-8,11,8,6,14,-9,-7,-8,0,-3,3,5,-15,4,2,0,
8,15,-7,7,-6,-2,7,-3,4,2,-1,8,6,5,-14,7,-2,-12,-3,6,5,13,-5,15,

16,-8,1,2,15,13,-5,-4,-12,-6,-10,0,6,-6,-15,-8,8,-13,7,4,-5,-9,-17,2,
3,-1,-9,10,-4,-3,-9,1,-5,-13,-17,-1,-8,-4,-8,3,8,-3,0,0,-8,-11,-14,-7,
1,1,-8,-8,11,2,-19,9,-8,-12,-5,9,-4,2,-15,6,7,-5,1,6,-5,-7,-15,6,
25,-5,-8,-6,-7,7,0,2,-11,-7,4,-1,11,-3,-2,-14,-6,-1,5,1,4,-11,-26,-5,
16,-2,10,1,13,-3,3,-1,-9,-20,0,11,21,9,1,-2,-5,2,0,7,-17,-2,-27,-8,
0,-7,10,8,7,14,-18,-4,-2,-6,-11,-5,7,-3,-4,1,-7,3,-5,9,-9,-11,-7,-6,
6,28,-7,-7,2,-6,-15,9,12,-2,0,-6,9,3,-8,0,8,13,-8,-9,-3,-1,-11,-7,
21,22,-2,8,0,-1,-6,6,4,3,2,-1,5,-9,-14,10,11,13,-2,4,14,-6,-2,8,
2,-14,2,-7,5,-8,-11,2,7,-16,-11,-2,5,5,-1,7,-5,-6,3,12,4,12,-3,-3,

-2,-18,0,8,14,7,-18,-7,-9,-6,11,2,17,-6,0,2,0,2,6,14,3,-12,-5,12,
0,-7,-4,-4,13,18,-16,4,11,-3,-5,11,-8,-9,-12,-2,-1,16,1,9,-4,10,-10,-9,
-2,-4,14,0,-4,-2,-4,12,-12,-26,-3,10,-10,2,-3,-5,-8,-12,-5,8,1,-2,-4,0,
17,15,-26,-1,13,5,-13,6,-20,7,-11,1,17,-28,-22,5,7,-3,-8,-2,-5,6,6,-2,
28,29,-13,7,2,1,-26,-6,3,-15,-8,9,9,-19,-10,-6,-1,-12,-10,-10,3,-7,1,7,
4,30,-15,17,5,5,-7,4,-3,-15,14,1,6,-13,-9,-2,-8,4,-10,3,9,5,3,-5,
16,8,-20,9,-16,10,0,-7,5,6,-2,-12,-9,0,0,0,-8,-3,-9,6,3,-13,10,-14,
10,9,-7,9,-7,2,-1,-19,-12,6,3,10,18,1,7,-10,-11,0,-2,6,3,-16,-14,-8,
14,13,-10,-8,12,18,1,8,-4,-2,3,-3,1,10,-13,7,2,-9,2,2,-2,-1,-5,1,

6,-7,-2,17,16,-7,20,12,15,-2,6,11,8,16,14,8,3,2,3,15,-3,-1,-8,-2,
-11,-7,7,-7,0,-1,-1,0,13,-14,5,-6,-32,10,6,9,-7,15,-7,16,-22,8,1,7,
-20,6,0,-5,-4,7,-24,-18,4,10,-10,-3,-16,8,4,-12,-1,8,2,-5,-2,12,-20,-13,
-4,-16,18,-9,3,-10,20,24,0,9,3,-1,-11,-11,-4,-3,-13,-12,1,4,2,-2,-8,7,
3,-19,1,-3,-5,-5,15,-2,-2,16,1,9,-16,-14,5,0,2,-18,-5,-20,3,4,6,-3,
-16,-5,-15,4,-7,4,-7,-15,-10,6,8,9,-22,9,-3,-2,-1,6,-2,-8,-1,-1,-6,16,
-1,5,6,-4,-8,9,-9,-3,-4,-10,9,-8,-11,-3,-1,-3,2,-8,0,-8,0,7,13,-9,
-15,3,-18,11,2,5,-5,-16,-4,10,-1,-8,4,1,6,-10,9,-4,2,-5,-14,5,13,-12,
-9,-6,12,-4,11,0,8,-13,-5,7,8,9,-10,12,9,-8,-2,-1,7,-6,-10,5,-1,10,

-10,19,3,5,-3,2,-3,-9,14,-3,11,-5,-12,8,8,-5,13,3,-7,-1,1,11,10,9,
-14,8,-2,0,3,8,-4,-1,-1,-12,-8,-7,-18,-10,-11,11,11,-12,-3,-5,-13,-14,-3,10,
-7,6,-4,4,10,-1,-13,-11,-9,17,11,4,-4,-8,-1,2,-7,-24,1,1,-10,4,0,-8,
0,-15,8,12,8,17,-13,8,-3,2,7,-3,3,16,-4,4,-1,-7,-2,8,-7,-11,-4,2,
-10,-7,8,-18,12,15,0,-2,0,-10,-6,4,1,9,-16,4,1,-4,0,-6,-9,-16,-28,-10,
-9,13,-6,-8,-6,6,-6,-6,7,5,-7,14,-5,-2,-1,-10,-4,-2,0,14,-2,3,3,7,
13,0,8,8,-2,-7,-12,3,6,-7,-8,-2,6,8,8,-2,2,-18,-7,3,-9,-5,-10,-9,
0,10,-7,-1,-4,6,-12,10,5,2,9,-11,-1,8,-23,5,-9,-13,-12,6,-17,0,-15,-3,
6,-4,4,-6,-1,2,-17,-9,-6,17,8,-7,-6,-9,-12,11,8,-17,8,5,-4,2,-7,-8,

3,11,2,-22,-3,5,-6,-13,10,-9,-8,-1,-14,-4,-8,13,13,-17,-12,5,-5,11,2,-6,
-7,8,-15,-5,-14,10,-6,3,-3,-10,1,-6,-14,9,-6,12,3,-10,-11,3,4,-11,-4,3,
-8,11,-21,-28,-17,-10,-12,1,4,4,5,-3,-20,-2,-1,-9,-7,-30,-18,7,-5,-15,0,-4,
-15,8,2,-3,-4,-1,-6,-13,1,0,9,8,-7,0,-17,4,-7,5,-8,-4,-10,10,-11,-8,
-7,9,-7,-6,1,13,-5,-14,-8,-13,9,-5,-12,-9,-5,16,2,-11,-5,4,1,-7,-5,-5,
-15,0,-8,-19,-15,10,-8,-10,2,-12,-6,-8,1,1,6,11,8,-21,-4,-6,-2,5,-2,0,
-1,-4,-6,-4,0,13,4,6,13,-5,15,1,-2,-1,3,2,13,3,-6,-5,-11,-7,2,9,
-2,8,-4,-14,-3,-7,-1,12,-12,6,14,3,-8,12,-12,1,2,-2,-3,-8,7,-7,5,-9,
-2,10,-4,-17,-12,0,-1,8,0,-7,5,5,-1,2,-6,1,12,-6,-8,-14,-5,-1,-7,-5,

-17,8,5,-2,-6,13,-17,-14,0,9,-4,4,-2,4,-7,1,-3,-10,8,1,1,9,10,-6,
-12,18,6,9,1,-7,-12,-13,0,5,-1,2,-9,1,-6,-11,-14,-15,0,9,-9,5,11,-7,
-18,-1,14,6,0,-13,9,0,-11,-8,4,10,-17,-6,7,-9,9,-11,7,-10,-5,-10,3,0,
-26,9,4,9,14,-11,-13,-16,4,12,-4,1,-6,-5,-2,-7,-5,-11,-6,3,-4,2,19,-10,
-32,7,-8,14,-6,5,-8,2,-6,2,-17,3,-14,0,14,-7,1,-13,-4,0,-5,8,12,12,
-24,7,9,-1,-6,-6,5,6,-1,-1,-9,-6,-26,-2,17,-2,5,-14,-5,-1,5,-3,0,13,
-1,-4,8,6,14,-4,-4,-10,7,11,-9,-5,-12,5,-9,-20,-13,-10,9,-2,-24,14,-3,7,
-1,-12,17,9,2,-8,6,-4,3,4,-8,-8,18,-10,8,1,-12,9,8,6,-2,0,14,8,
12,-5,15,-1,-9,-3,3,1,3,-17,12,7,1,2,2,-4,-1,3,-8,9,6,8,8,9,

4,27,-5,2,4,12,-28,-10,13,-3,5,-5,-22,-2,-6,-7,-6,1,-1,9,-4,19,-15,4,
-25,12,-2,-7,-2,-6,-15,-9,4,-26,-3,-5,-20,-6,-1,-3,3,-13,2,5,6,-2,1,7,
11,-17,7,-5,-2,-11,1,12,9,2,21,-4,-2,-3,-13,-5,-8,-17,23,-11,-9,-1,10,-12,
14,-11,2,21,14,1,-20,-2,-7,4,-10,-5,12,-20,-5,-8,-6,10,-7,5,3,-4,-5,1,
-6,20,5,7,12,-6,-3,-19,13,-14,-1,7,-2,-3,0,-11,-10,-6,-19,-5,5,10,8,-4,
-7,-8,1,9,6,-7,-18,0,-7,-3,-3,-2,4,-16,-10,-3,-2,-1,-12,5,6,-9,23,0,
18,-2,-9,7,4,-16,-6,-14,-11,2,-11,-12,13,-8,-1,0,8,-8,-1,0,-11,-23,0,6,
-7,15,6,19,7,5,-2,5,-9,-3,-11,4,-6,7,0,0,4,3,0,-1,4,4,-9,2,
-1,18,20,-4,-4,16,-12,5,3,0,1,13,-7,1,8,8,16,18,-6,19,-4,3,-1,6,

-1,7,-20,3,-13,5,-20,-10,-12,-2,2,7,10,9,8,-5,-6,-5,-5,-3,0,2,11,-2,
7,0,-18,2,-21,-12,-7,-17,7,0,-5,-7,-10,-11,-5,5,2,-3,6,-1,9,-16,-12,-4,
-5,-4,-11,-11,3,-3,16,10,4,-1,11,-14,-9,-7,-1,-7,1,2,4,4,18,17,2,-17,
-20,27,-4,11,-9,4,-3,2,12,4,-2,14,17,12,-8,4,-5,15,-6,10,0,7,6,0,
-5,11,-13,-10,4,-8,-4,-12,7,-1,6,-7,-2,-15,-4,-14,-6,12,-4,-12,4,12,9,-13,
6,4,-3,-7,-3,-4,-4,-5,-17,18,7,-9,-5,3,-3,11,4,-6,6,8,2,5,2,-2,
-9,-7,8,-4,8,-10,7,-7,0,-5,-13,4,-1,-2,7,-4,-3,16,-8,12,-1,12,-4,12,
-8,-4,2,5,-6,3,-4,-8,6,3,-5,-12,-11,5,-6,0,6,-5,9,-3,9,1,9,4,
-17,-2,6,-5,-5,5,-7,-6,-23,-6,-9,-4,-10,9,2,-11,10,-8,7,4,-3,-16,-8,4,

-2,9,-1,-11,11,-3,-5,11,5,3,-12,-7,-26,-5,6,-7,10,-11,8,-1,-2,-1,-28,-6,
10,5,-8,-11,-2,-13,2,6,-3,-1,10,-12,-21,-6,-10,-9,-8,-1,12,5,-1,-3,0,-5,
5,-1,13,-2,1,9,-6,5,-16,10,11,0,4,4,-9,-8,12,-14,16,-1,-6,-6,-6,-7,
3,12,9,-7,10,-13,7,5,-7,-15,4,11,-24,-9,-1,-7,8,-13,-7,-7,11,2,-23,16,
-4,1,8,-17,-4,5,-5,-2,7,-6,-17,-11,-14,3,-14,-11,-11,5,-1,-5,-4,1,-9,9,
-8,-5,-15,-4,-2,-4,-7,6,-9,7,-3,-1,-8,-11,2,6,-2,-1,2,-9,8,-10,5,12,
14,14,1,8,6,-3,-1,1,-15,-7,11,13,2,2,-11,-8,-2,-11,-1,11,7,-14,-14,6,
1,21,11,11,-6,6,-16,-1,7,-5,-2,6,2,-4,-8,-10,12,-12,7,13,4,-4,-8,10,
-18,12,1,2,8,-4,1,-10,-11,0,5,-5,0,-3,-10,-11,-4,5,7,14,-10,-4,-3,-4,

-7,-4,-3,-7,-7,6,6,6,-1,-17,-7,-6,-11,14,2,-4,3,-10,1,8,-9,3,9,-2,
-1,-8,0,9,-5,-6,-9,2,-11,-3,6,-7,-12,-13,-7,2,-9,6,-5,6,2,-9,-13,1,
11,4,1,-5,8,7,-5,-3,3,3,-6,9,-11,-4,-10,5,3,5,4,5,-6,-4,-21,8,
1,-4,-8,-7,1,-11,2,9,12,-6,7,7,-11,-8,-22,-2,-8,-8,-10,12,-4,16,4,6,
-12,5,-14,6,-2,2,5,-5,8,9,5,-10,4,6,3,1,-11,1,-4,-5,6,6,7,0,
-2,4,0,-11,6,-5,7,14,3,-7,-7,-2,0,13,8,-6,3,-9,1,6,-2,7,-10,14,
-20,-8,-5,-6,1,-8,7,2,2,3,-8,-7,7,-8,-7,-4,9,3,2,-6,-12,-9,-9,4,
-9,-3,-2,7,0,-4,-1,2,-7,2,-8,-10,-6,6,1,2,3,-14,1,5,1,2,-4,6,
-4,-8,-10,13,12,-4,5,-5,-13,-6,3,-7,11,8,0,7,3,7,4,0,-5,0,-10,-11,

2,21,4,1,-10,-6,14,-9,-6,-1,-7,10,0,12,10,13,-1,15,-2,12,-12,11,14,3,
4,29,-17,7,1,7,5,5,-6,7,-5,-1,-7,-11,2,0,2,1,-7,-5,-12,-10,15,-11,
-10,5,1,-9,-6,-12,-7,-8,-15,10,0,-12,-11,1,14,-13,-1,7,-4,2,10,6,6,-6,
8,11,-8,7,-1,0,-1,-5,-6,-1,-6,12,7,4,-4,5,-16,7,-2,-2,-18,-1,3,8,
-14,13,-4,-1,-3,2,-8,-4,-7,4,-9,-6,1,6,3,-1,-14,4,-11,1,-19,0,17,4,
-1,-10,-4,-7,-13,6,-5,-3,4,-2,-1,-6,-6,-13,-6,-5,5,-5,0,-7,-3,-2,12,12,
3,-17,-6,-5,10,-4,1,-4,3,1,-8,6,10,-17,10,-3,-9,2,-3,7,3,-18,9,-1,
2,5,2,5,7,0,3,-5,8,8,13,8,-2,0,-2,-6,0,-9,-4,-2,0,-16,10,9,
-4,9,-4,-4,10,4,-13,-9,10,-11,9,10,0,15,3,1,3,6,-2,7,-4,8,-5,13





};

const q7_t b_3[CONV3_OUT_CH] = {
-3,3,-4,-13,6,-1,-9,10,0,-9,-5,-12,9,9,15,-19,5,-6,-3,2,0,4,-19,0,13,3,8,5,-9,-5,-11,-14,9,-10,-2,-8,-1,-2,-10,-5,16,16,-1,3,2,3,5,-7	

};



