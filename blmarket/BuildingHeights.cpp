#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

class BuildingHeights 
{
public:
    int minimum(vector <int> heights) 
    {		
        sort(heights.begin(), heights.end());
        int n = size(heights);
        int ret = 0;
        for(int i=1;i<n;i++) {
            int mindiff = 1000000000;
            for(int j=0;j+i < n;j++) {
                int sum = 0;
                for(int k=j;k<j+i;k++) {
                    sum += heights[j+i] - heights[k];
                }
                if(sum < mindiff) mindiff = sum;
            }
            ret ^= mindiff;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 5, 4, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 1, 6, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { int Arr0[] = {
            830, 135, 229, 1817, 539, 3484, 2808, 3690, 2428, 1943, 185, 3629, 2155, 2863, 668, 1230, 2386, 188, 2254, 3595, 86, 920, 1, 3250, 3944, 3977, 179, 2330, 496, 297, 643, 798, 3443, 36, 2183, 3025, 1768, 565, 23, 1686, 2033, 2838, 817, 1766, 2173, 3743, 2898, 603, 1979, 2773, 3327, 133, 2468, 590, 1788, 976, 1499, 2257, 2948, 1823, 2554, 500, 824, 475, 3815, 279, 2605, 3691, 459, 1300, 199, 202, 3587, 1865, 707, 3572, 3578, 1715, 2141, 2936, 722, 2614, 3945, 130, 658, 1463, 2016, 269, 3802, 2478, 3898, 3079, 3258, 3703, 1778, 2616, 1679, 1335, 4000, 3078, 863, 1443, 3353, 1092, 911, 1093, 2990, 1698, 498, 1189, 2698, 3339, 2031, 3024, 1205, 293, 3327, 2307, 1631, 2011, 1930, 2152, 1453, 76, 546, 2079, 1338, 2149, 2515, 2078, 1547, 3383, 3064, 3058, 1867, 3981, 1701, 2726, 2107, 3408, 2427, 1541, 2941, 3682, 3505, 2102, 1973, 2292, 510, 3529, 3537, 1846, 2624, 1851, 2565, 3873, 3045, 239, 2243, 1178, 849, 2121, 2855, 595, 1023, 462, 2429, 1680, 2420, 382, 241, 1228, 374, 2870, 837, 3989, 1721, 3745, 1744, 2596, 2118, 581, 171, 3333, 2585, 3862, 1455, 699, 763, 515, 2688, 3271, 3591, 670, 1159, 2837, 56, 1012, 2245, 1729, 3542, 1319, 2322, 2952, 3422, 342, 3040, 2830, 3739, 1602, 2737, 3767, 2752, 1045, 2369, 2960, 1847, 1682, 67, 1616, 298, 1690, 3028, 961, 1599, 3317, 422, 3069, 1641, 1550, 2390, 825, 789, 1278, 155, 1824, 2030, 3793, 2700, 1538, 351, 1342, 395, 2069, 407, 3280, 651, 3215, 1703, 3648, 396, 1171, 2735, 2469, 2723, 1023, 2457, 3700, 1627, 2154, 238, 3522, 1801, 3737, 3367, 3419, 3078, 965, 1378, 2913, 3366, 2896, 1309, 1420, 2120, 3859, 1727, 1935, 3730, 3418, 516, 761, 572, 1523, 902, 800, 2561, 617, 2144, 473, 2098, 738, 2725, 1144, 2075, 3058, 3328, 401, 2380, 3193, 2208, 3877, 197, 3740, 2243, 2546, 3661, 1529, 3800, 3739, 2612, 2200, 1827, 623, 1034, 2697, 880, 3726, 3999, 3347, 2052, 2478, 385, 1731, 17, 203, 2787, 2673, 8, 1417, 2805, 1610, 3952, 84, 3550, 597, 3017, 2300, 1432, 428, 1611, 1211, 645, 1629, 839, 3504, 607, 2323, 3920, 1902, 2759, 1105, 228, 2612, 2324, 1468, 3951, 3694, 2114, 3095, 3729, 3741, 3255, 2119, 3600, 2364, 3418, 3075, 3041, 681, 2646, 968, 2306, 2056, 506, 718, 1558, 3640, 1281, 566, 668, 1516, 135, 612, 2807, 726, 438, 3751, 2112, 1834, 1973, 2538, 768, 2941, 796, 2634, 2003, 3624, 643, 260, 2662, 2840, 94, 1824, 3215, 1244, 2259, 514, 2063, 267, 615, 1747, 1043, 2528, 2521, 3946, 3476, 364, 134, 1763, 3001, 2011, 965, 1234, 3455, 3836, 307, 2877, 1733, 1709, 1411, 3965, 221, 3131, 1341, 2375, 242, 312, 1784, 2090, 2105, 2044, 1304, 2916, 2796, 1788, 1424, 1982, 912, 3374, 3884, 2948, 1685, 475, 932, 2221, 1608, 2870, 1232, 1262, 1499, 3381, 417, 1460, 556, 3369, 568, 882, 2402, 2929, 3360, 2244, 2580, 2247, 3089, 143, 2330, 3336, 1451, 569, 579, 3400, 1009, 2084, 1659, 1256, 1222, 3070, 3095, 3814, 2434, 1945, 822, 526, 3825, 2843, 3149, 2547, 220, 571, 3901, 863, 1910, 2051, 1370, 3769, 1295, 2273, 3313, 185, 2829, 2930, 3005, 1786, 3095, 2468, 3560, 2159, 3624, 1845, 3688, 1675, 1186, 24, 1098, 2083, 399, 2058, 1567, 2286, 1023, 568, 1697, 2920, 1823, 430, 40, 2468, 937, 500, 566, 294, 1819, 3318, 2734, 3946, 1911, 3457, 3603, 3281, 1524, 3366, 754, 2421, 1056, 3684, 2248, 525, 2324, 337, 980, 3858, 1374, 1397, 3499, 670, 3013, 1863, 179, 568, 130, 2743, 168, 587, 1505, 1028, 2164, 294, 304, 3525, 2553, 2598, 1406, 2243, 998, 1664, 2203, 2439, 508, 2345, 2085, 2781, 3430, 972, 3297, 954, 2806, 2529, 308, 705, 2266, 1282, 3691, 1874, 2591, 2375, 225, 1541, 213, 2432, 2316, 50, 338, 3152, 3132, 3592, 835, 3232, 3213, 649, 3363, 3868, 716, 1261, 2884, 2438, 673, 2720, 3977, 3033, 722, 1664, 1849, 2277, 3242, 1330, 1058, 551, 1490, 3839, 2891, 1383, 333, 3820, 3363, 1954, 3796, 1756, 2422, 505, 2257, 3431, 3185, 3085, 1093, 3369, 748, 3893, 845, 1048, 200, 1618, 701, 3835, 1864, 797, 3963, 3584, 1691, 2369, 3349, 1528, 1850, 2207, 1135, 587, 1720, 3391, 1166, 1146, 3744, 2431, 3875, 739, 1062, 335, 3673, 912, 2585, 966, 1627, 3456, 1847, 765, 278, 2139, 2813, 3123, 3614, 1076, 3658, 3647, 1466, 3402, 2180, 3165, 3283, 611, 1075, 1157, 307, 2164, 555, 862, 2518, 2186, 2427, 3463, 3556, 1255, 3994, 3460, 1337, 2538, 611, 1315, 1509, 59, 2055, 2702, 394, 2926, 3132, 420, 2663, 3002, 1489, 3577, 2485, 736, 3498, 2096, 1346, 3708, 1232, 2104, 1248, 439, 2196, 1247, 1905, 1069, 2468, 283, 3479, 40, 3486, 2722, 1836, 2776, 3191, 582, 3792, 2906, 503, 307, 1642, 3362, 1637, 3778, 2902, 884, 2188, 2191, 3089, 2043, 1660, 1817, 2100, 599, 2405, 1259, 109, 2524, 453, 3608, 3375, 3423, 1446, 1418, 369, 2385, 2054, 3112, 3175, 734, 3392, 984, 643, 1482, 1316, 2058, 2393, 2311, 3378, 1799, 3964, 1568, 1372, 988, 2505, 1799, 2076, 791, 2170, 2367, 434, 1500, 3396, 568, 3897, 3573, 2668, 1681, 1803, 3049, 2733, 3361, 3142, 621, 2558, 3877, 620, 367, 296, 94, 2483, 3361, 932, 3694, 3106, 810, 2398, 727, 873, 2959, 2263, 1355, 48, 2117, 3909, 1974, 2405, 359, 3749, 2608, 1418, 3478, 2793, 2610, 96, 419, 3038, 2382, 1270, 1031, 1845, 65, 329, 3507, 3203, 2567, 3996, 2886, 3145, 3121, 3319, 2248, 3154, 66, 539, 2898, 2960, 3733, 2908, 1394, 391, 268, 1106, 1316, 2175, 1594, 1516, 3936, 3483, 863, 84, 990, 419, 3329, 3899, 2683, 1798, 1233, 2896, 1004, 2436, 3099, 1867, 716, 2367, 2107, 1056, 1425, 3345, 3369, 3499, 1217, 367, 2581, 1044, 1608, 17, 1102, 2408, 1921, 2456, 2093, 489, 2089, 1062, 2890, 2137, 3272, 2925, 2012, 1876, 836, 1023, 482, 3848, 2881, 969, 3113, 1918, 757, 1665, 642, 3332, 1626, 3033, 1121, 1457, 320, 256, 1469, 1106, 309, 2391, 3198, 1477, 838, 3991, 2619, 1554, 2646, 3629, 866, 2912, 3529, 3592, 3167, 1198, 2690, 1450, 216, 2794, 2829, 1063, 2010, 3906, 2585, 71, 1433, 2640, 82, 982, 3162, 243, 3822, 2187, 3676, 1472, 1825, 2759, 800, 3005, 2894, 2837, 141, 1974, 184, 3593, 2214, 358, 3054, 3351, 337, 355, 3566, 1546, 703, 1819, 841, 1774, 1465, 3941, 1918, 3171, 1778, 2925, 2490, 3665, 2909, 175, 424, 358, 65, 537, 1187, 3237, 1187, 2781, 717, 1975, 1287, 2178, 1409, 1843, 1049, 2375, 3524, 787, 3942, 1348, 2704, 963, 1117, 666, 3272, 3889, 3232, 444, 3981, 1649, 1701, 3983, 3331, 1405, 2021, 3243, 3828, 2504, 3592, 980, 671, 635, 3545, 3257, 1854, 188, 957, 3724, 1828, 474, 1888, 2574, 2488, 2646, 835, 2520, 610, 1388, 235, 2290, 2317, 291, 639, 12, 126, 2178, 2228, 2759, 2716, 3075, 2158, 1549, 3795, 1443, 1890, 3481, 3249, 3786, 1771, 3965, 501, 2027, 1164, 3569, 3025, 595, 1434, 1837, 2714, 1805, 307, 768, 833, 612, 3929, 425, 333, 938, 686, 1060, 408, 1008, 2353, 1312, 3864, 942, 2136, 838, 2227, 2038, 1609, 528, 1841, 3434, 3858, 1940, 608, 3734, 2463, 658, 907, 195, 1823, 1051, 1155, 1381, 1297, 3897, 758, 3126, 3351, 596, 780, 2936, 2337, 241, 3610, 2198, 2321, 3017, 36, 788, 1028, 1859, 2548, 3669, 3198, 650, 3416, 507, 3807, 3468, 1716, 2292, 618, 3589, 826, 1778, 1549, 1013, 3999, 413, 2668, 3910, 3051, 3205, 498, 481, 3225, 387, 2473, 1382, 3347, 3526, 658, 1906, 1847, 3842, 3865, 2288, 3142, 1208, 2766, 2288, 137, 687, 1299, 2491, 2712, 1801, 885, 3776, 1095, 1346, 2595, 3863, 3750, 263, 2794, 3085, 1405, 1517, 3157, 171, 1107, 250, 3091, 817, 1911, 2904, 3123, 2781, 3354, 1907, 426, 1881, 928, 625, 2814, 1875, 1128, 266, 2858, 2194, 2804, 2191, 1788, 2855, 3079, 3564, 2916, 1990, 2205, 875, 1144, 1632, 677, 549, 2910, 2020, 1116, 3631, 524, 3212, 1383, 3221, 627, 2998, 801, 2888, 904, 3839, 393, 1644, 2070, 2231, 2422, 3648, 1975, 3476, 3352, 2840, 3787, 1904, 3881, 191, 791, 1557, 589, 522, 2589, 61, 1985, 473, 3865, 1669, 731, 2997, 1083, 3738, 717, 817, 31, 2966, 1389, 976, 2606, 3981, 158, 1980, 2250, 3372, 3660, 3659, 1731, 3643, 2927, 1841, 474, 1077, 2121, 944, 1152, 1704, 808, 3666, 1254, 2076, 3334, 3947, 618, 3077, 2695, 3532, 1904, 35, 3916, 3311, 1619, 2282, 1703, 2884, 3933, 3877, 1859, 3267, 3463, 3190, 1800, 3356, 3656, 2517, 467, 2669, 486, 1909, 3944, 3310, 2749, 1862, 1770, 2286, 1119, 1707, 1232, 587, 3408, 3758, 1754, 771, 3802, 1208, 3001, 2161, 2787, 2133, 60, 3493, 2576, 239, 436, 2613, 1579, 25, 3902, 2771, 841, 919, 3960, 3269, 1875, 1252, 2808, 1749, 1104, 2479, 1246, 1590, 1529, 3801, 2668, 2262, 3784, 906, 3093, 2325, 674, 2369, 1584, 3672, 657, 3779, 3742, 3812, 637, 2035, 714, 3398, 2400, 2311, 1236, 560, 2887, 3328, 72, 3887, 1719, 3239, 1990, 360, 3136, 1410, 456, 1761, 1061, 651, 260, 2645, 1135, 2855, 3075, 1541, 2643, 2991, 275, 1853, 425, 250, 1506, 845, 3758, 2261, 1746, 2276, 1794, 3550, 2231, 2835, 2785, 3432, 1161, 2275, 2609, 3920, 789, 3317, 3795, 3061, 2208, 3856, 648, 2093, 650, 1338, 3545, 40, 1722, 1917, 3217, 1976, 3039, 3395, 2281, 491, 215, 532, 3497, 541, 1726, 3601, 3392, 295, 1056, 3133, 1234, 1828, 2043, 215, 1671, 3702, 1487, 337, 1113, 2287, 1215, 2322, 3912, 3654, 3919, 1645, 3161, 935, 29, 3540, 2163, 3933, 2035, 202, 3563, 2217, 1951, 3232, 3211, 3504, 3271, 3662, 555, 649, 3270, 771, 2364, 1905, 92, 2950, 666, 2916, 465, 499, 2606, 1739, 2636, 2783, 1832, 1764, 1958, 1520, 1817, 1195, 2230, 3582, 1588, 1507, 2741, 607, 289, 304, 808, 1675, 2239, 2786, 3361, 1476, 1218, 3456, 2241, 140, 3912, 2642, 2096, 2844, 2216, 3405, 2592, 233, 2289, 2544, 2488, 2542, 1980, 158, 3486, 426, 3317, 396, 1559, 2131, 2383, 3563, 94, 677, 3740, 3514, 3691, 977, 465, 193, 2782, 508, 558, 545, 2036, 2927, 592, 1924, 727, 1703, 1767, 2340, 356, 2242, 1335, 2078, 1913, 2223, 3442, 1802, 2792, 476, 3078, 820, 1515, 1061, 349, 2610, 246, 1901, 2058, 411, 757, 3358, 1816, 2809, 3045, 738, 3666, 2465, 1040, 1041, 3963, 2426, 687, 253, 512, 3805, 3248, 209, 1983, 3066, 305, 2433, 2571, 3219, 1880, 1251, 2092, 1422, 1730, 3387, 819, 1908, 1923, 1634, 1836, 3959, 2334, 1814, 3559, 981, 250, 2524, 9, 2646, 2722, 210, 521, 3291, 517, 2538, 2477, 749, 3760, 1433, 243, 1428, 596, 1459, 2991, 2319, 2202, 1058, 1938, 1757, 588, 2727, 2939, 1754, 1284, 3586, 2063, 379, 190, 3079, 2073, 1437, 1779, 1801, 3944, 3834, 3935, 238, 3270, 3283, 2877, 2912, 3772, 3858, 3567, 178, 196, 4000, 1481, 1562, 448, 3702, 1681, 1785, 1309, 2642, 2632, 1749, 1435, 2735, 554, 491, 2776, 1947, 2542, 3129, 418, 233, 3155, 3926, 3324, 2232, 3933, 3024, 3721, 1487, 2868, 2236, 2878, 1987, 2007, 1951, 916, 253, 3987, 3275, 1745, 2436, 3703, 2216, 2809, 648, 373, 2657, 2993, 999, 1810, 2659, 3062, 122, 3811, 1476, 3720, 165, 524, 1236, 2947, 10, 3051, 425, 1551, 128, 2482, 1159, 2260, 1922, 1505, 2009, 932, 994, 170, 2070, 1412, 1674, 1651, 886, 3, 3241, 1100, 1774, 1436, 2142, 2545, 590, 2256, 3759, 1926, 1732, 661, 1960, 827, 2149, 3966, 254, 2938, 2213, 3050, 322, 3618, 1245, 907, 1207, 303, 981, 502, 1153, 36, 2512, 1370, 1383, 162, 1042, 1377, 3820, 3537, 487, 2011, 3299, 1037, 3566, 2345, 1026, 1544, 1065, 632, 2197, 363, 152, 995, 3407, 3924, 3025, 3904, 2839, 2746, 1718, 3222, 3766, 3829, 2173, 3917, 1893, 481, 169, 2213, 3515, 2205, 3724, 172, 3389, 671, 3280, 1651, 1954, 3426, 3347, 2541, 3162, 1340, 2327, 3270, 159, 611, 2003, 3656, 3389, 3217, 2453, 2936, 2520, 2805, 1875, 3632, 1507, 3472, 402, 2545, 1206, 3563, 2805, 3698, 2233, 1592, 3840, 1444, 3426, 3929, 1753, 2669, 3804, 599, 687, 1891, 2201, 3778, 3050, 53, 1341, 1433, 1998, 2687, 1937, 1176, 25, 2151, 907, 2921, 2695, 1077, 1111, 2203, 2821, 2776, 2726, 3362, 1376, 2017, 1348, 3237, 3796, 714, 2629, 482, 2836, 2954, 3162, 1319, 643, 205, 3381, 3739, 584, 2669, 3465, 477, 2572, 177, 2437, 584, 3180, 1738, 997, 3278, 1831, 3960, 1802, 3386, 350, 454, 3927, 3807, 126, 1034, 1693, 992, 2408, 3209, 3696, 2283, 2700, 2708, 1938, 3245, 572, 3438, 380, 2690, 174, 3503, 1351, 2729, 2849, 3258, 1017, 2921, 3496, 2926, 2581, 1583, 3978, 2298, 2589, 3310, 1846, 2335, 2479, 3769, 2676, 714, 1778, 2045, 1321, 1136, 1657, 1297, 1965, 278, 1907, 3619, 1192, 1100, 1407, 2669, 1177, 498, 107, 721, 832, 1467, 980, 711, 2315, 1820, 2570, 919, 446, 2293, 3023, 1102, 3055, 1700, 3385, 410, 1055, 4, 900, 1725, 1328, 388, 595, 3621, 1445, 3716, 3485, 1594, 872, 1259, 1603, 1502, 2780, 1983, 2667, 2870, 3464, 1636, 1818, 382, 381, 2849, 487, 14, 1061, 377, 3824, 3547, 3847, 3188, 1463, 2314, 2396, 105, 1180, 2378, 3180, 3017, 2505, 2787, 2812, 3190, 3698, 3255, 3914, 1045, 1124, 1504, 110, 1265, 3269, 208, 1270, 3737, 3279, 2887, 1810, 3581, 3883, 1436, 1959, 418, 3008, 2022, 2115, 3648, 1585, 162, 3230, 2714, 1204, 2594, 2864, 3530, 2897, 2585, 2010, 2651, 2017, 1550, 3455, 985, 1722, 1987, 1117, 2054, 3899, 1435, 537, 1758, 72, 1844, 1935, 100, 2804, 3317, 3297, 2242, 3446, 2199, 855, 9, 2257, 240, 1895, 1333, 233, 1072, 3475, 400, 3106, 3544, 1368, 324, 468, 2702, 1464, 1424, 3876, 3519, 351, 406, 422, 3095, 1534, 2766, 1279, 844, 3368, 2587, 754, 1351, 68, 2057, 3528, 2861, 130, 2003, 74, 3607, 2609, 3959, 3901, 1429, 2917, 272, 1401, 1688, 3535, 545, 1072, 2348, 1712, 544, 3776, 2908, 2525, 3891, 698, 2466, 265, 1594, 1444, 2232, 2516, 2871, 1494, 3173, 2266, 3207, 2549, 1847, 1855, 3775, 1431, 3799, 1968, 1267, 2851, 2195, 3001, 1881, 3440, 2848, 2796, 3806, 3708, 2521, 1600, 2626, 681, 1445, 707, 1436, 1426, 263, 63, 989, 2321, 711, 2602, 3273, 3462, 553, 1840, 3276, 676, 3540, 2618, 266, 3530, 3265, 827, 3704, 2050, 3682, 3183, 505, 2554, 1196, 1320, 1494, 2864, 756, 3636, 1463, 2430, 722, 30, 2476, 3837, 2854, 2204, 849, 1119, 2610, 3787, 84, 2561, 1138, 939, 1561, 3032, 2606, 952, 2750, 2202, 1586, 3132, 1123, 1251, 1939, 30, 974, 215, 2829, 685, 459, 43, 3871, 3658, 494, 464, 1175, 3918, 2267, 1564, 733, 14, 932, 2840, 1432, 881, 3458, 1803, 2451, 2369, 239, 3056, 1487, 1494, 639, 3663, 2767, 1905, 1549, 1302, 718, 96, 3920, 2229, 2237, 1997, 1787, 635, 124, 1277, 2610, 477, 3392, 1123, 3659, 2667, 2618, 147, 834, 3012, 2318, 760, 3618, 1332, 2895, 3617, 493, 3291, 93, 2663, 749, 1161, 2423, 3326, 3958, 2409, 3152, 2203, 226, 3279, 255, 1722, 1028, 2682, 1053, 716, 2584, 1738, 45, 3822, 3754, 2088, 2239, 1616, 230, 2133, 3867, 2589, 785, 942, 1767, 3574, 2963, 3907, 494, 2166, 1224, 1434, 808, 2068, 3687, 2153, 119, 557, 1254, 1382, 3388, 1553, 2333, 3483, 2514, 3246, 166, 2225, 147, 3505, 2332, 2704, 482, 3834, 1996, 3797, 2759, 2736, 2835, 1675, 1382, 2081, 3804, 1449, 447, 3494, 1297, 574, 593, 2464, 2242, 2765, 292, 2200, 3058, 3145, 1086, 2421, 2686, 2720, 248, 2714, 1112, 2405, 2563, 3034, 2342, 1356, 657, 1874, 1322, 1407, 1711, 202, 2790, 1283, 2938, 1044, 2097, 3360, 2110, 2131, 2947, 1802, 3557, 1937, 2194, 1734, 2447, 1617, 1615, 3598, 3955, 3193, 706, 2122, 1137, 3192, 183, 2922, 1161, 176, 3729, 3684, 3680, 3033, 2026, 1442, 664, 659, 2260, 3683, 205, 3418, 1788, 3420, 3600, 963, 316, 138, 3055, 2181, 3197, 3888, 1633, 3648, 45, 1804, 714, 1562, 2331, 2728, 3787, 1034, 407, 1248, 2132, 126, 538, 3186, 2335, 3434, 1983, 1044, 1739, 2177, 3836, 3076, 2558, 2676, 1945, 2457, 1516, 2638, 1289, 3613, 685, 1479, 2087, 575, 785, 753, 2715, 3109, 1457, 943, 3433, 2736, 3872, 1035, 2117, 2158, 272, 1544, 334, 633, 416, 2250, 3429, 1404, 2098, 3817, 2977, 93, 2372, 2136, 3105, 2633, 3269, 1470, 1886, 720, 35, 974, 1688, 568, 3137, 570, 1337, 591, 2128, 3751, 2868, 316, 3598, 3497, 2485, 1862, 1520, 1498, 1083, 2275, 3809, 2070, 1679, 1718, 921, 3268, 140, 7, 289, 3565, 2574, 205, 3779, 3577, 2203, 3437, 2685, 821, 1832, 3741, 1701, 2381, 1945, 3705, 3514, 2067, 1834, 3002, 723, 1187, 797, 204, 3892, 2966, 2130, 935, 3514, 2463, 2801, 2180, 900, 3579, 664, 1188, 1090, 1413, 2171, 2025, 110, 643, 525, 264, 649, 2946, 2796, 1079, 2066, 2024, 1030, 450, 3895, 2133, 3964, 3110, 3033, 3483, 3130, 2023, 3964, 1960, 1349, 1290, 2206, 234, 2446, 849, 2013, 371, 2073, 2146, 2277, 3067, 3084, 3219, 650, 2914, 555, 500, 2343, 2706, 446, 1560, 854, 3451, 2867, 332, 1318, 3103, 241, 1088, 3400, 259, 357, 2075, 3986, 3562, 496, 152, 1397, 3351, 1252, 3622, 85, 113, 955, 222, 709, 3736, 1063, 3885, 2012, 226, 1052, 3785, 3122, 442, 13, 1119, 3462, 3364, 514, 560, 597, 1333, 2308, 475, 2341, 325, 2251, 2400, 3720, 2517, 150, 1215, 344, 2059, 3474, 3173, 2445, 3035, 3489, 2319, 3256, 666, 557, 2474, 2279, 3947, 1481, 1399, 3416, 557, 1081, 2518, 1352, 2897, 571, 1416, 874, 3762, 3174, 2376, 1498, 274, 3509, 978, 2354, 1243, 141, 2249, 465, 3587, 3460, 519, 2249, 1542, 706, 1618, 84, 1277, 1862, 57, 2897, 3117, 2799, 777, 135, 514, 1521, 3573, 561, 2451, 3549, 1350, 1931, 2095, 3088, 2339, 454, 3516, 822, 3594, 2596, 1052, 3101, 1144, 2270, 3039, 3201, 1474, 1910, 2811, 1599, 3163, 2029, 2395, 2912, 2727, 2815, 576, 2630, 2091, 2948, 2940, 40, 1119, 2327, 926, 2499, 2455, 260, 2688, 1449, 2451, 3677, 1725, 2299, 3354, 2141, 2966, 3211, 3046, 3306, 821, 1733, 1488, 1657, 205, 2778, 3933, 38, 1954, 1304, 1329, 3335, 2559, 874, 2198, 3451, 1465, 206, 1185, 2889, 3923, 1127, 1163, 3998, 275, 3462, 3538, 2205, 2904, 2982, 2703, 418, 2741, 936, 2501, 1842, 1709, 2088, 1297, 2566, 839, 1805, 731, 3502, 2700, 3495, 2855, 3585, 1506, 2951, 195, 325, 3520, 3990, 149, 558, 3627, 2112, 1979, 2464, 3502, 398, 3618, 3336, 2612, 3940, 3373, 961, 357, 3272, 699, 1703, 1373, 1190, 3392, 1467, 1852, 2961, 2256, 3994, 1858, 959, 784, 2190, 3765, 3524, 170, 3843, 3267, 334, 1457, 2387, 1237, 356, 703, 3922, 3187, 1565, 2820, 607, 787, 1422, 3058, 648, 722, 139, 1296, 1975, 3854, 2195, 3276, 3403, 47, 3974, 237, 3674, 1845, 1824, 3776, 3546, 1645, 3249, 478, 2906, 973, 3994, 2305, 861, 2633, 3803, 1700, 781, 878, 3578, 3980, 1113, 3124, 2945, 1001, 3432, 2582, 2349, 3650, 2894, 3339, 1550, 1401, 3728, 200, 3825, 3681, 1245, 2438, 94, 182, 2478, 3073, 1252, 1307, 1315, 3425, 2507, 1457, 564, 859, 3479, 2235, 2892, 402, 2409, 527, 2285, 248, 3829, 2863, 1922, 394, 109, 256, 3391, 2773, 1927, 1548, 1210, 3307, 823, 2243, 2096, 2093, 212, 3657, 3879, 2405, 672, 864, 184, 1540, 672, 859, 169, 1089, 164, 948, 2779, 139, 1765, 1010, 2605, 1910, 2395, 486, 2798, 1746, 3741, 2020, 2011, 906, 1739, 1403, 2676, 2025, 2246, 1674, 3499, 1559, 554, 1545, 1189, 257, 1704, 2093, 195, 3599, 934, 159, 2449, 2566, 1715, 2166, 2585, 636, 1775, 1532, 2271, 712, 3912, 2389, 3309, 126, 2009, 1645, 1779, 3982, 335, 3503, 2775, 2710, 782, 1131, 208, 91, 167, 851, 3315, 3027, 3606, 1879, 21, 2656, 1051, 2279, 1324, 87, 1790, 2821, 454, 3974, 1519, 1328, 72, 1932, 3858, 3926, 2988, 3756, 3769, 3205, 3893, 1973, 3701, 3957, 1084, 1290, 2795, 2786, 937, 2447, 402, 894, 555, 3759, 2074, 2749, 452, 628, 3597, 3289, 257, 1931, 2009, 920, 3946, 3016, 1208, 669, 2600, 2328, 691, 2450, 2258, 3430, 1167, 1438, 1506, 1268, 3858, 2645, 598, 941, 1168, 1030, 1632, 477, 613, 3819, 3349, 2648, 591, 3100, 1687, 1176, 2011, 3069, 2400, 2535, 1326, 1842, 1475, 3286, 3543, 2773, 846, 3006, 3728, 1619, 2034, 3322, 2247, 726, 2482, 2370, 2538, 1570, 2141, 1587, 2432, 1977, 3575, 3882, 1119, 3915, 2788, 3938, 2625, 705, 1805, 910, 554, 200, 332, 3275, 564, 259, 3443, 628, 851, 1205, 3616, 332, 1982, 3989, 553, 183, 3994, 1595, 174, 2230, 3680, 339, 2883, 1181, 1295, 24, 1141, 2517, 1455, 3647, 289, 188, 38, 3988, 1480, 1703, 3427, 2056, 1144, 3133, 1021, 1802, 3216, 919, 2510, 1189, 2741, 1920, 474, 74, 1079, 2260, 1143, 461, 3611, 482, 194, 2022, 1515, 1699, 1372, 1566, 1498, 268, 1759, 3631, 3465, 2193, 2763, 848, 10, 932, 2128, 3371, 2143, 660, 2674, 2825, 280, 2360, 2114, 2715, 3296, 3223, 1318, 2953, 3894, 3642, 3674, 2865, 144, 2748, 1214, 3218, 458, 3224, 2699, 1224, 846, 93, 3117, 2246, 1727, 1306, 1231, 3600, 3199, 511, 3160, 1356, 276, 528, 2149, 275, 3405, 617, 838, 3279, 289, 3628, 3653, 2780, 1225, 783, 3558, 1248, 565, 2464, 2315, 916, 3693, 3652, 1158, 1406, 3377, 1713, 1449, 2172, 3701, 1279, 3292, 3521, 399, 1275, 2457, 824, 2218, 2094, 3821, 104, 3360, 913, 1643, 1947, 455, 1162, 2255, 80, 2840, 2221, 3786, 2709, 555, 2758, 1718, 2701, 537, 3713, 2912, 1547, 2448, 2736, 2874, 1818, 3250, 731, 1905, 2441, 271, 2029, 1854, 2400, 3241, 346, 2520, 1743, 3135, 1671, 3957, 3399, 1048, 2534, 2905, 542, 1838, 603, 3487, 962, 887, 3023, 2170, 2177, 328, 1544, 2569, 593, 2178, 272, 2696, 21, 1341, 1823, 3227, 777, 2650, 3263, 3268, 2163, 3615, 2, 808, 1446, 3201, 1269, 3719, 3200, 2531, 333, 3472, 1007, 1735, 61, 990, 624, 3558, 1672, 1443, 2273, 2013, 3863, 2919, 1946, 2617, 1565, 3127, 2703, 3375, 313, 2607, 2728, 2590, 3362, 2601, 1414, 424, 3788, 1175, 415, 2753, 468, 1692, 638, 903, 1322, 3601, 232, 2908, 20, 2649, 323, 3643, 1226, 2145, 2291, 1272, 2052, 70, 2859, 2832, 585, 1948, 3947, 270, 1402, 1756, 667, 2791, 1173, 1867, 4, 1560, 3204, 2541, 1303, 3882, 3818, 2364, 1095, 2817, 2874, 731, 2736, 2889, 1529, 2413, 1950, 3378, 3193, 2867, 2443, 3748, 2692, 3975, 2053, 1927, 1870, 3779, 2438, 211, 2507, 1117, 444, 2477, 1465, 2198, 3944, 2328, 3346, 3204, 3422, 3682, 1007, 1050, 3737, 1371, 3922, 2509, 1624, 1415, 759, 3456, 2020, 1618, 244, 2829, 2662, 1750, 3572, 2573, 1123, 3585, 637, 1941, 24, 3367, 2402, 389, 2690, 1147, 3423, 3872, 1873, 1132, 3266, 2421, 2365, 765, 3127, 3487, 1421, 1430, 1078, 3794, 3538, 1240, 746, 3926, 1825, 2428, 3831, 119, 1645, 2528, 1072, 1732, 877, 1566, 1599, 3351, 2878, 3737, 2446, 2189, 3711, 2771, 2301, 2492, 3413, 515, 3292, 2305, 177, 1758, 1406, 1446, 1535, 2161, 892, 3011, 607, 2820, 1649, 3804, 594, 2849, 3379, 3650, 3173, 3247, 2219, 2280, 1611, 1921, 1869, 1628, 356, 3670, 3851, 2670, 3063, 2144, 304, 4000, 3001, 1378, 801, 2419, 2767, 2255, 1797, 2467, 549, 1422, 3521, 1052, 3042, 2917, 1071, 1420, 1866, 487, 2782, 2860, 3811, 3270, 2793, 3719, 3777, 2446, 165, 3114, 2110, 625, 289, 2894, 1930, 1385, 3506, 2513, 3234, 3301, 1346, 186, 2574, 3454, 937, 2354, 791, 3917, 1193, 3804, 1763, 1202, 1687, 204, 813, 2709, 1775, 626, 2063, 2575, 2824, 523, 3880, 453, 2872, 3664, 3943, 269, 2420, 250, 2102, 752, 390, 2478, 1446, 823, 2338, 1029, 1078, 2194, 938, 3895, 1399, 1730, 2423, 1390, 53, 3656, 3473, 2111, 2760, 3437, 311, 594, 700, 3749, 3420, 598, 1067, 2674, 1726, 2903, 3672, 1342, 3370, 3045, 1674, 3408, 3258, 3616, 563, 1411, 2052, 1895, 3850, 3560, 3210, 1513, 1451, 1852, 2561, 1489, 1018, 2086, 2765, 3296, 457, 2827, 381, 3303, 1829, 2479, 3109, 2554, 1102, 796, 882, 2761, 3098, 2603, 2291, 2022, 617, 1244, 3577, 2716, 151, 1959, 1923, 1340, 282, 836, 232, 1395, 1079, 3346, 2894, 3752, 300, 3397, 1345, 1963, 1692, 3743, 908, 3030, 3112, 1156, 3781, 3301, 1574, 107, 1904, 2080, 2868, 1351, 1183, 2989, 2881, 3215, 2305, 2023, 1419, 2562, 1182, 3339, 1294, 2520, 1460, 402, 2518, 39, 1692, 3600, 3891, 2253, 3236, 3676, 3593, 569, 1819, 1599, 1211, 2395, 392, 1582, 2001, 3899, 2078, 527, 2535, 3357, 1692, 1732, 3335, 3131, 3934, 3759, 1480, 783, 987, 2871, 1583, 1194, 421, 2334, 158, 2325, 2246, 1544, 1495, 890, 2470, 47, 2057, 597, 76, 183, 2454, 2778, 272, 985, 1136, 3418, 2418, 2104, 190, 988, 3441, 1544, 154, 1087, 1019, 3438, 1657, 2448, 3273, 1757, 2273, 3397, 3063, 577, 625, 2975, 886, 3057, 3445, 2073, 654, 686, 3928, 2920, 2468, 1257, 1809, 1268, 2892, 3628, 772, 1783, 1511, 1790, 3441, 2723, 3745, 2568, 1005, 2792, 3305, 683, 3480, 1770, 1230, 1902, 1570, 1686, 2370, 1183, 2404, 600, 285, 716, 498, 2040, 1958, 2097, 2147, 3908, 357, 2868, 833, 601, 648, 1267, 2935, 117, 2470, 2274, 1531, 884, 1916, 2377, 3767, 1142, 2303, 1751, 3074, 785, 1069, 116}          ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56068; verify_case(3, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BuildingHeights ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
