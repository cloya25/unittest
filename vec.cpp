//Author: Gordon Griesel
//Date: July 8, 2017
//Purpose: Framework for coding exam
//MODIFIED BY : Cesar Loya
//
//
//See instructions to produce a unit-test for the vecNormalize function.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;
//type defines
typedef double Flt;
typedef Flt Vec[2];

//prototype
//Flt is float 
Flt vecNormalize(Vec v);

#ifdef UNIT_TEST       //2.a
void unittest(Flt tolerance);
#endif

//Array of vector values
//this is what is popping out ... smh
const Flt arr[] = {
    1.00,   0.00,
    1.00,   1.00,
    -1.20,   2.50,
    99.99,  99.99,
    2.22,  -1.22
};


//int size = sizeof(UNIT_TEST) / sizeof(UNIT_TEST);

Flt myArray[] = {
    4.3186, 6.3839, 7.7074, 0.5603, 0.8283,
    -7.3129,    -6.6919,    7.9126, -0.7377,    -0.6751,
    -2.3822,    -0.9827,    2.5769, 0.9244, -0.3814,
    4.2963, -7.7387,    8.8513, 0.4854, 0.8743,
    2.1622, 3.2164, 3.8756, 0.5579, 0.8299,
    9.8215, -3.3814,    10.3872,    0.9505, -0.3255,
    -3.8446,    -7.6765,    8.5855, -0.4478,    -0.8891,
    9.0431, -1.7387,    9.2088, 0.9820, -0.1888,
    -2.8685,    9.7789, 10.1910,    -0.2815,    0.9596,
    7.0079, -3.7690,    7.9572, 0.8807, -0.4737,
    2.3359, 1.5720, 2.8156, 0.8296, 0.5583,
    7.1103, -5.4922,    8.9844, 0.7914, -0.6113,
    -1.4481,    7.9055, 8.0370, -0.1802,    0.9836,
    7.1591, -2.9631,    7.7481, 0.9240, -0.3824,
    -7.0436,    -8.1469,    10.7696,    -0.6540,    -0.7565,
    3.2548, 6.2749, 7.0689, 0.4604, 0.8877,
    7.2370, 4.9419, 8.7634, 0.8258, 0.5639,
    8.5830, -5.1452,    10.0071,    0.8577, -0.5142,
    -6.0408,    2.8794, 6.6919, -0.9027,    0.4303,
    -3.8839,    5.1214, 6.4275, -0.6043,    0.7968,
    -3.9043,    -4.0624,    5.6344, -0.6929,    -0.7210,
    -8.2600,    1.2511, 8.3542, -0.9887,    0.1498,
    -2.7390,    9.7832, 10.1594,    -0.2696,    0.9630,
    8.5124, 3.3925, 9.1636, 0.9289, 0.3702,
    9.5621, 5.5204, 11.0412,    0.8660, 0.5000,
    8.6235, 1.8980, 8.8299, 0.9766, 0.2150,
    -2.9077,    5.7337, 6.4289, -0.4523,    0.8919,
    5.4059, 4.6443, 7.1269, 0.7585, 0.6517,
    3.6392, 2.5650, 4.4523, 0.8174, 0.5761,
    -8.3189,    5.5956, 10.0257,    -0.8298,    0.5581,
    3.4181, 3.9360, 5.2130, 0.6557, 0.7550,
    1.8706, 0.6551, 1.9820, 0.9438, 0.3305,
    -1.1221,    0.4536, 1.2103, -0.9271,    0.3748,
    4.5099, 1.8371, 4.8697, 0.9261, 0.3773,
    -6.6670,    9.6260, 11.7093,    -0.5694,    0.8221,
    -3.0415,    -1.5713,    3.4234, -0.8884,    -0.4590,
    -4.4365,    -2.3014,    4.9979, -0.8877,    -0.4605,
    8.6798, 1.8245, 8.8695, 0.9786, 0.2057,
    -2.5182,    7.1922, 7.6204, -0.3305,    0.9438,
    -4.7830,    -2.9561,    5.6228, -0.8506,    -0.5257,   /*aqui*/
    2.7126, -6.1595,    6.7303, 0.4030, -0.9152,
    7.9419, 8.8049, 11.8575,    0.6698, 0.7426,
    8.5743, 3.3478, 9.2046, 0.9315, 0.3637,
    3.4492, 2.2135, 4.0984, 0.8416, 0.5401,
    -4.0872,    4.1303, 5.8108, -0.7034,    0.7108,
    -2.1909,    8.3309, 8.6142, -0.2543,    0.9671,
    -1.9337,    8.6797, 8.8925, -0.2175,    0.9761,
    -1.0140,    5.9442, 6.0301, -0.1682,    0.9858,
    -0.8667,    -6.5041,    6.5616, -0.1321,    -0.9912,
    -2.2186,    1.4662, 2.6594, -0.8343,    0.5514,
    -6.8781,    3.7399, 7.8291, -0.8785,    0.4777,
    8.8949, -2.3146,    9.1911, 0.9678, -0.2518,
    -8.5615,    7.5747, 11.4314,    -0.7490,    0.6626,
    8.5099, -2.0798,    8.7604, 0.9714, -0.2374,
    4.7670, -6.2730,    7.8788, 0.6050, -0.7962,
    3.9641, -2.5205,    4.6975, 0.8439, -0.5365,
    -3.4325,    1.9060, 3.9262, -0.8743,    0.4855,
    -3.7155,    -4.8583,    6.1162, -0.6075,    -0.7943,
    -4.7462,    8.7337, 9.9400, -0.4775,    0.8786,
    6.3552, 0.1666, 6.3574, 0.9997, 0.0262,
    2.8640, -5.8357,    6.5006, 0.4406, -0.8977,
    -1.5024,    9.9304, 10.0434,    -0.1496,    0.9887,
    -7.1560,    6.4836, 9.6564, -0.7411,    0.6714,
    5.8746, 0.9773, 5.9553, 0.9864, 0.1641,
    8.9795, -6.3440,    10.9945,    0.8167, -0.5770,
    -7.5565,    -7.8986,    10.9311,    -0.6913,    -0.7226,
    6.3959, -8.6616,    10.7671,    0.5940, -0.8044,
    -1.2132,    6.8344, 6.9412, -0.1748,    0.9846,
    7.9131, -2.7033,    8.3622, 0.9463, -0.3233,
    -5.2454,    2.6801, 5.8904, -0.8905,    0.4550,
    0.0237, 7.7187, 7.7187, 0.0031, 1.0000,
    9.1596, 5.5911, 10.7313,    0.8535, 0.5210,
    -0.3753,    -4.5559,    4.5713, -0.0821,    -0.9966,
    9.7329, 3.8785, 10.4772,    0.9290, 0.3702,
    -5.8222,    6.0881, 8.4239, -0.6911,    0.7227,
    -5.9549,    6.0419, 8.4832, -0.7020,    0.7122,
    9.2524, 1.5427, 9.3802, 0.9864, 0.1645,
    5.9722, -7.9036,    9.9063, 0.6029, -0.7978,
    -1.9737,    1.8468, 2.7030, -0.7302,    0.6833,
    2.0737, -2.9942,    3.6421, 0.5694, -0.8221,
    4.5028, 3.5172, 5.7137, 0.7881, 0.6156,
    -1.8928,    0.8987, 2.0953, -0.9033,    0.4289,
    3.8556, 5.8940, 7.0431, 0.5474, 0.8369,
    -2.2669,    1.7687, 2.8753, -0.7884,    0.6151,
    -6.8093,    1.4876, 6.9699, -0.9770,    0.2134,
    -5.5512,    2.2144, 5.9765, -0.9288,    0.3705,
    -0.7937,    -6.3915,    6.4406, -0.1232,    -0.9924,
    -2.1945,    7.8310, 8.1327, -0.2698,    0.9629,
    -1.9474,    -2.4616,    3.1388, -0.6204,    -0.7843,
    1.7095, 1.2305, 2.1063, 0.8116, 0.5842,
    -6.3735,    4.7547, 7.9516, -0.8015,    0.5980,
    -2.7277,    -7.1211,    7.6256, -0.3577,    -0.9338,
    -3.7026,    -6.7554,    7.7036, -0.4806,    -0.8769,
    -6.0247,    3.3237, 6.8807, -0.8756,    0.4831,
    4.0914, 5.0490, 6.4986, 0.6296, 0.7769,
    9.3296, -1.4058,    9.4349, 0.9888, -0.1490,
    -1.4339,    -2.5632,    2.9370, -0.4882,    -0.8727,
    8.4930, -7.5783,    11.3825,    0.7461, -0.6658,
    -6.6692,    -3.7740,    7.6629, -0.8703,    -0.4925,
    3.1904, -4.4785,    5.4987, 0.5802, -0.8145,
    6.7137, 6.6393, 9.4421, 0.7110, 0.7032,
    6.7359, -4.0800,    7.8752, 0.8553, -0.5181,
    9.2478, -5.4586,    10.7386,    0.8612, -0.5083,
    -6.2490,    -2.6996,    6.8072, -0.9180,    -0.3966,
    1.0798, 4.4605, 4.5894, 0.2353, 0.9719,
    7.5308, 3.7063, 8.3934, 0.8972, 0.4416,
    -0.7848,    -5.1968,    5.2558, -0.1493,    -0.9888,
    5.5852, 4.5126, 7.1804, 0.7778, 0.6285,
    -2.9523,    8.5605, 9.0553, -0.3260,    0.9454,
    -2.1636,    -8.8608,    9.1212, -0.2372,    -0.9715,
    3.6095, -2.8340,    4.5891, 0.7865, -0.6176,
    -1.2666,    -7.8244,    7.9263, -0.1598,    -0.9871,
    3.6028, -2.7736,    4.5468, 0.7924, -0.6100,
    -6.4027,    5.9336, 8.7294, -0.7335,    0.6797,
    2.4524, 5.7877, 6.2858, 0.3901, 0.9208,
    -8.5448,    -0.8340,    8.5854, -0.9953,    -0.0971,
    2.4270, 7.1911, 7.5896, 0.3198, 0.9475,
    4.0860, 1.6748, 4.4159, 0.9253, 0.3793,
    -8.2676,    6.8370, 10.7283,    -0.7706,    0.6373,
    7.9751, 1.8122, 8.1784, 0.9751, 0.2216,
    1.2976, 5.5060, 5.6568, 0.2294, 0.9733,
    -4.4815,    9.5128, 10.5156,    -0.4262,    0.9046,
    9.3091, -8.8963,    12.8765,    0.7230, -0.6909,
    4.0254, -3.6432,    5.4292, 0.7414, -0.6710,
    8.6642, -8.1382,    11.8869,    0.7289, -0.6846,
    -3.5040,    2.2737, 4.1770, -0.8389,    0.5443,
    -1.9722,    4.2294, 4.6666, -0.4226,    0.9063,
    3.4492, -8.3694,    9.0523, 0.3810, -0.9246,
    -8.5443,    6.0465, 10.4673,    -0.8163,    0.5777,
    6.5643, 2.9081, 7.1796, 0.9143, 0.4051,
    1.8343, 7.0194, 7.2551, 0.2528, 0.9675,
    -7.9259,    -5.7387,    9.7853, -0.8100,    -0.5865,
    4.2105, 5.1602, 6.6600, 0.6322, 0.7748,
    4.9360, 4.9429, 6.9855, 0.7066, 0.7076,
    1.9972, 2.9111, 3.5304, 0.5657, 0.8246,
    -3.2449,    -6.7052,    7.4491, -0.4356,    -0.9001,
    -1.5829,    1.2736, 2.0317, -0.7791,    0.6269,
    -7.1925,    -2.2738,    7.5433, -0.9535,    -0.3014,
    1.3773, 5.8330, 5.9934, 0.2298, 0.9732,
    3.0830, 0.0415, 3.0833, 0.9999, 0.0135,
    6.6948, 8.5790, 10.8821,    0.6152, 0.7884,
    -7.6848,    -5.2774,    9.3224, -0.8243,    -0.5661,
    2.8084, 4.7644, 5.5306, 0.5078, 0.8615,
    -4.6468,    3.2642, 5.6787, -0.8183,    0.5748,
    0.8110, -8.0825,    8.1231, 0.0998, -0.9950,
    -3.8277,    -7.3548,    8.2912, -0.4617,    -0.8871,
    7.9369, -2.7536,    8.4010, 0.9448, -0.3278,
    -4.0935,    2.1474, 4.6226, -0.8856,    0.4645,
    -7.5934,    9.8425, 12.4312,    -0.6108,    0.7918,
    -2.9097,    3.4038, 4.4779, -0.6498,    0.7601,
    2.7536, 2.8455, 3.9597, 0.6954, 0.7186,
    5.6985, -8.8293,    10.5085,    0.5423, -0.8402,
    -5.8809,    7.5061, 9.5355, -0.6167,    0.7872,
    -2.1031,    4.4964, 4.9639, -0.4237,    0.9058,
    3.3391, 9.9800, 10.5237,    0.3173, 0.9483,
    -5.4621,    0.0339, 5.4622, -1.0000,    0.0062,
    8.5590, -4.1469,    9.5107, 0.8999, -0.4360,
    3.7565, 1.3674, 3.9976, 0.9397, 0.3421,
    9.6175, 8.1097, 12.5803,    0.7645, 0.6446,
    -5.3684,    0.4285, 5.3855, -0.9968,    0.0796,
    9.0272, -0.1961,    9.0293, 0.9998, -0.0217,
    2.0737, 6.9641, 7.2663, 0.2854, 0.9584,
    6.0503, 6.9802, 9.2374, 0.6550, 0.7556,
    -0.8885,    7.4569, 7.5097, -0.1183,    0.9930,
    6.8227, 5.2018, 8.5795, 0.7952, 0.6063,
    0.8607, -0.4237,    0.9593, 0.8972, -0.4416,
    -1.9528,    -3.4408,    3.9563, -0.4936,    -0.8697,
    -0.2529,    1.1663, 1.1934, -0.2119,    0.9773,
    -5.9347,    6.6440, 8.9086, -0.6662,    0.7458,
    -4.3373,    6.4044, 7.7348, -0.5607,    0.8280,
    6.6240, -0.7993,    6.6720, 0.9928, -0.1198,
    -3.5618,    5.1830, 6.2888, -0.5664,    0.8242,
    4.0538, 9.1947, 10.0487,    0.4034, 0.9150,
    -3.4496,    3.6714, 5.0377, -0.6848,    0.7288,
    7.3044, 0.1820, 7.3067, 0.9997, 0.0249,
    -5.9001,    6.3316, 8.6545, -0.6817,    0.7316,
    8.9859, 5.1736, 10.3689,    0.8666, 0.4990,
    3.2956, 5.0363, 6.0187, 0.5476, 0.8368,
    2.1538, -7.5929,    7.8925, 0.2729, -0.9620,
    2.4932, -1.0235,    2.6951, 0.9251, -0.3798,
    6.6089, -6.6461,    9.3727, 0.7051, -0.7091,
    7.5528, -5.3439,    9.2522, 0.8163, -0.5776,
    -1.0868,    -2.7001,    2.9106, -0.3734,    -0.9277,
    4.8224, 1.9785, 5.2125, 0.9252, 0.3796,
    -6.0561,    9.4851, 11.2536,    -0.5381,    0.8429,
    -1.6172,    9.5679, 9.7036, -0.1667,    0.9860,
    -1.3142,    3.8211, 4.0407, -0.3252,    0.9456,
    4.7508, -7.2604,    8.6766, 0.5475, -0.8368,
    3.0158, -8.6987,    9.2067, 0.3276, -0.9448,
    5.4110, 0.3201, 5.4205, 0.9983, 0.0591,
    0.4833, 8.5109, 8.5246, 0.0567, 0.9984,
    -3.3483,    -0.5308,    3.3901, -0.9877,    -0.1566,
    3.6845, 8.9473, 9.6763, 0.3808, 0.9247,
    -5.4945,    -4.1618,    6.8927, -0.7971,    -0.6038,
    -8.6456,    5.9987, 10.5228,    -0.8216,    0.5701,
    3.8148, 6.9633, 7.9398, 0.4805, 0.8770,
    8.3526, 1.3676, 8.4639, 0.9869, 0.1616,
    -8.3806,    -2.7342,    8.8154, -0.9507,    -0.3102,
    7.6675, 5.4418, 9.4023, 0.8155, 0.5788,
    8.2443, -8.3886,    11.7616,    0.7009, -0.7132,
    4.9269, -3.3729,    5.9708, 0.8252, -0.5649,
    -8.8207,    -6.3873,    10.8905,    -0.8099,    -0.5865,
    9.4482, 4.9301, 10.6571,    0.8866, 0.4626,
    -4.6476,    2.4639, 5.2603, -0.8835,    0.4684,
    5.2314, 9.7634, 11.0766,    0.4723, 0.8814,
    -7.2159,    -4.2853,    8.3925, -0.8598,    -0.5106,
    8.2742, -1.5642,    8.4208, 0.9826, -0.1858,
    4.1839, 1.9587, 4.6197, 0.9057, 0.4240,
    -2.6169,    7.6894, 8.1225, -0.3222,    0.9467,
    6.7969, -2.2625,    7.1636, 0.9488, -0.3158,
    3.6881, 0.6117, 3.7385, 0.9865, 0.1636,
    -5.2992,    2.0407, 5.6785, -0.9332,    0.3594,
    -8.0207,    -4.6798,    9.2861, -0.8637,    -0.5040,
    8.3065, 8.6468, 11.9902,    0.6928, 0.7212,
    9.7620, 6.5508, 11.7563,    0.8304, 0.5572,
    9.2582, 4.6889, 10.3779,    0.8921, 0.4518,
    -6.8221,    9.4375, 11.6451,    -0.5858,    0.8104,
    7.3017, -7.3740,    10.3774,    0.7036, -0.7106,
    4.3676, -7.3460,    8.5463, 0.5111, -0.8595,
    4.0899, -0.4010,    4.1095, 0.9952, -0.0976,
    -7.5826,    5.8740, 9.5916, -0.7905,    0.6124,
    4.3137, 9.6917, 10.6083,    0.4066, 0.9136,
    -5.6903,    -1.5024,    5.8853, -0.9669,    -0.2553,
    1.6503, 0.6928, 1.7899, 0.9220, 0.3871,
    -3.8130,    -1.5527,    4.1171, -0.9262,    -0.3771,
    7.4304, 8.8751, 11.5749,    0.6419, 0.7668,
    8.0590, -7.8688,    11.2634,    0.7155, -0.6986,
    0.9158, 9.0383, 9.0845, 0.1008, 0.9949,
    -3.5485,    -0.7776,    3.6327, -0.9768,    -0.2141,
    7.6850, -3.7865,    8.5672, 0.8970, -0.4420,
    -4.2269,    6.9432, 8.1286, -0.5200,    0.8542,
    9.9024, -2.0490,    10.1122,    0.9793, -0.2026,
    6.3807, 7.2041, 9.6235, 0.6630, 0.7486,
    -0.4229,    0.7483, 0.8596, -0.4920,    0.8706,
    8.8581, -6.3330,    10.8891,    0.8135, -0.5816,
    9.3473, -8.7245,    12.7863,    0.7310, -0.6823,
    8.5410, 3.6610, 9.2925, 0.9191, 0.3940,
    9.9672, -7.1493,    12.2661,    0.8126, -0.5828,
    -7.8414,    1.6175, 8.0065, -0.9794,    0.2020,
    2.5436, -2.6545,    3.6764, 0.6919, -0.7220,
    9.0648, -0.0260,    9.0649, 1.0000, -0.0029,
    -3.7794,    7.1238, 8.0643, -0.4687,    0.8834,
    1.1052, 6.1364, 6.2352, 0.1773, 0.9842,
    6.1620, 6.5567, 8.9978, 0.6848, 0.7287,
    -4.6412,    3.8471, 6.0283, -0.7699,    0.6382,
    -7.2299,    0.1319, 7.2311, -0.9998,    0.0182,
    0.7903, -7.3275,    7.3700, 0.1072, -0.9942,
    7.0830, -2.8290,    7.6270, 0.9287, -0.3709,
    8.8766, -3.3400,    9.4842, 0.9359, -0.3522,
    6.9194, 7.7347, 10.3780,    0.6667, 0.7453,
    -0.6730,    6.2667, 6.3027, -0.1068,    0.9943,
    8.0102, -2.1320,    8.2891, 0.9664, -0.2572,
    -0.0723,    7.9774, 7.9778, -0.0091,    1.0000,
    -0.2813,    1.0862, 1.1220, -0.2507,    0.9681,
    -0.4050,    -7.7377,    7.7483, -0.0523,    -0.9986,
    7.4317, -1.3402,    7.5516, 0.9841, -0.1775,
    1.2363, -6.3477,    6.4669, 0.1912, -0.9816,
    -4.2164,    -7.6585,    8.7425, -0.4823,    -0.8760,
    8.7888, -8.0544,    11.9212,    0.7372, -0.6756,
    7.8981, -5.8525,    9.8301, 0.8035, -0.5954
};



int main(int argc, char *argv[])
{
#ifdef UNIT_TEST
    //Program to analyze a vector normalization process.
    printf("\n3350 programming exam               \n");
    printf("Cesar Loya <--your name goes there\n");
    printf("Display of normalized vectors.        \n\n");
    printf("---------------  --------------------------  \n");
    printf("known input:      actual output:              \n");
    printf("X        Y        length    X        Y        \n");
    printf("-------  -------  --------  -------  -------  \n");

    for (int i=0; i<5; i++) {
        //this is not being called
        Vec ki = { arr[i*2+0], arr[i*2+1] };
        Vec ao = { ki[0], ki[1] };
        Flt ret = vecNormalize(ao);
        printf("%3i  %7.4lf  %7.4lf  %8.4lf  %7.4lf  %7.4lf\n",
                i+1, ki[0], ki[1], ret, ao[0], ao[1] );
    }
    //probando
    unittest(2);
    printf("\nProgram complete.\n\n");
    return 0;
#endif
}

Flt vecNormalize(Vec v)
{
    //----------------------------
    //Do not modify this function.
    //----------------------------
    //Normalize a 2-dimensional vector.
    //Calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //Check for degenerative vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //Vector has a magnitude, so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

/*sizeof(array)*/


void unittest(Flt tolerance){
    int errors = 0;

    cout << "please enter tolerance value below\n";
    cin >> tolerance;
    cout << "Tolerance: " << tolerance << endl;

    cout << "-------  -------  --------  -------  -------  \n";   
    cout << "known input:      actual output:              \n";
    cout << "X        Y        length    X        Y        \n";
    cout << "-------  -------  --------  -------  -------  \n";   
    for(int i=0; i < 1000; i++){  // i+=5  ..259
        //will use this in a bit .. no pues wow 
        float known_x = *(myArray + i + 0);
        float known_y = *(myArray + i +  1);
        float length = *(myArray + i + 2);
        float output_x = *(myArray + i + 3);
        float output_y = *(myArray + i+ 4);
        //wrong param
        //Vec ki = { arr[i*2+0], arr[i*2+1] };
        //Vec ao = { ki[0], ki[1] };
        //Flt real_output = vecNormalize(ao);

        //Flt ret = vecNormalize(ao);


        /*cout << fixed << setprecision(6);*/
        cout << known_x << "\t    " << known_y << "\t    " << length << "\t    " << output_x << "\t    " << output_y;
        if(abs(known_x - output_x) > tolerance ){  /*output_x*/
            cout << "   <--- Error: x is out of tolerance! \n";
            errors++;
        }else{
            cout << "\n";
        }



    }
    cout << "Total amount of Errors: " << errors << endl;
    cout << "hello\n";
}

