#include "spwm.h"
#include "main.h"
//sin函数的900个点（30000倍）//
const float sin_value_SHIGH[600] = {
0,33,67,100,134,167,200,234,267,301,334,367,401,434,467,500,
533,566,599,632,665,698,730,763,795,828,860,892,924,956,988,1020,
1052,1083,1115,1146,1177,1209,1240,1270,1301,1332,1362,1392,1422,1452,1482,1512,
1541,1570,1600,1628,1657,1686,1714,1742,1770,1798,1826,1853,1880,1907,1934,1961,
1987,2013,2039,2065,2090,2116,2141,2166,2190,2214,2238,2262,2286,2309,2332,2355,
2378,2400,2422,2444,2465,2486,2507,2528,2548,2569,2588,2608,2627,2646,2665,2683,
2701,2719,2737,2754,2771,2787,2804,2820,2835,2851,2866,2881,2895,2909,2923,2936,
2949,2962,2975,2987,2999,3010,3022,3032,3043,3053,3063,3072,3082,3090,3099,3107,
3115,3122,3130,3136,3143,3149,3155,3160,3165,3170,3174,3178,3182,3185,3188,3191,
3193,3195,3197,3198,3199,3199,3200,3199,3199,3198,3197,3195,3193,3191,3188,3185,
3182,3178,3174,3170,3165,3160,3155,3149,3143,3136,3130,3122,3115,3107,3099,3090,
3082,3072,3063,3053,3043,3032,3022,3010,2999,2987,2975,2962,2949,2936,2923,2909,
2895,2881,2866,2851,2835,2820,2804,2787,2771,2754,2737,2719,2701,2683,2665,2646,
2627,2608,2588,2569,2548,2528,2507,2486,2465,2444,2422,2400,2378,2355,2332,2309,
2286,2262,2238,2214,2190,2166,2141,2116,2090,2065,2039,2013,1987,1961,1934,1907,
1880,1853,1826,1798,1770,1742,1714,1686,1657,1628,1600,1570,1541,1512,1482,1452,
1422,1392,1362,1332,1301,1270,1240,1209,1177,1146,1115,1083,1052,1020,988,956,
924,892,860,828,795,763,730,698,665,632,599,566,533,500,467,434,
401,367,334,301,267,234,200,167,134,100,67,33,0,-33,-67,-100,
-134,-167,-200,-234,-267,-301,-334,-367,-401,-434,-467,-500,-533,-566,-599,-632,
-665,-698,-730,-763,-795,-828,-860,-892,-924,-956,-988,-1020,-1052,-1083,-1115,-1146,
-1177,-1209,-1240,-1270,-1301,-1332,-1362,-1392,-1422,-1452,-1482,-1512,-1541,-1570,-1599,-1628,
-1657,-1686,-1714,-1742,-1770,-1798,-1826,-1853,-1880,-1907,-1934,-1961,-1987,-2013,-2039,-2065,
-2090,-2116,-2141,-2166,-2190,-2214,-2238,-2262,-2286,-2309,-2332,-2355,-2378,-2400,-2422,-2444,
-2465,-2486,-2507,-2528,-2548,-2569,-2588,-2608,-2627,-2646,-2665,-2683,-2701,-2719,-2737,-2754,
-2771,-2787,-2804,-2820,-2835,-2851,-2866,-2881,-2895,-2909,-2923,-2936,-2949,-2962,-2975,-2987,
-2999,-3010,-3022,-3032,-3043,-3053,-3063,-3072,-3082,-3090,-3099,-3107,-3115,-3122,-3130,-3136,
-3143,-3149,-3155,-3160,-3165,-3170,-3174,-3178,-3182,-3185,-3188,-3191,-3193,-3195,-3197,-3198,
-3199,-3199,-3200,-3199,-3199,-3198,-3197,-3195,-3193,-3191,-3188,-3185,-3182,-3178,-3174,-3170,
-3165,-3160,-3155,-3149,-3143,-3136,-3130,-3122,-3115,-3107,-3099,-3090,-3082,-3072,-3063,-3053,
-3043,-3032,-3022,-3010,-2999,-2987,-2975,-2962,-2949,-2936,-2923,-2909,-2895,-2881,-2866,-2851,
-2835,-2820,-2804,-2787,-2771,-2754,-2737,-2719,-2701,-2683,-2665,-2646,-2627,-2608,-2588,-2569,
-2548,-2528,-2507,-2486,-2465,-2444,-2422,-2400,-2378,-2355,-2332,-2309,-2286,-2262,-2238,-2214,
-2190,-2166,-2141,-2116,-2090,-2065,-2039,-2013,-1987,-1961,-1934,-1907,-1880,-1853,-1826,-1798,
-1770,-1742,-1714,-1686,-1657,-1628,-1599,-1570,-1541,-1512,-1482,-1452,-1422,-1392,-1362,-1332,
-1301,-1270,-1240,-1209,-1177,-1146,-1115,-1083,-1052,-1020,-988,-956,-924,-892,-860,-828,
-795,-763,-730,-698,-665,-632,-599,-566,-533,-500,-467,-434,-401,-367,-334,-301,
-267,-234,-200,-167,-134,-100,-67,-33
};
const float sin_value_HIGH[810] = {	
0,24,49,74,99,124,148,173,198,223,247,272,297,322,346,371,
396,420,445,469,494,518,543,567,592,616,641,665,689,713,737,762,
786,810,834,858,882,905,929,953,977,1000,1024,1047,1071,1094,1117,1140,
1164,1187,1210,1233,1256,1278,1301,1324,1346,1369,1391,1413,1436,1458,1480,1502,
1524,1545,1567,1589,1610,1632,1653,1674,1695,1716,1737,1758,1779,1799,1820,1840,
1860,1880,1900,1920,1940,1960,1979,1999,2018,2037,2056,2075,2094,2113,2131,2150,
2168,2186,2204,2222,2240,2258,2275,2293,2310,2327,2344,2361,2378,2394,2410,2427,
2443,2459,2475,2490,2506,2521,2536,2551,2566,2581,2596,2610,2624,2638,2652,2666,
2680,2693,2707,2720,2733,2746,2758,2771,2783,2795,2807,2819,2831,2842,2854,2865,
2876,2886,2897,2908,2918,2928,2938,2948,2957,2966,2976,2985,2994,3002,3011,3019,
3027,3035,3043,3050,3058,3065,3072,3079,3086,3092,3098,3104,3110,3116,3122,3127,
3132,3137,3142,3146,3151,3155,3159,3163,3167,3170,3173,3176,3179,3182,3184,3187,
3189,3191,3193,3194,3195,3197,3198,3198,3199,3199,3199,3199,3199,3199,3198,3198,
3197,3195,3194,3193,3191,3189,3187,3184,3182,3179,3176,3173,3170,3167,3163,3159,
3155,3151,3146,3142,3137,3132,3127,3122,3116,3110,3104,3098,3092,3086,3079,3072,
3065,3058,3050,3043,3035,3027,3019,3011,3002,2994,2985,2976,2966,2957,2948,2938,
2928,2918,2908,2897,2886,2876,2865,2854,2842,2831,2819,2807,2795,2783,2771,2758,
2746,2733,2720,2707,2693,2680,2666,2652,2638,2624,2610,2596,2581,2566,2551,2536,
2521,2506,2490,2475,2459,2443,2427,2410,2394,2378,2361,2344,2327,2310,2293,2275,
2258,2240,2222,2204,2186,2168,2150,2131,2113,2094,2075,2056,2037,2018,1999,1979,
1960,1940,1920,1900,1880,1860,1840,1820,1799,1779,1758,1737,1716,1695,1674,1653,
1632,1610,1589,1567,1545,1524,1502,1480,1458,1436,1413,1391,1369,1346,1324,1301,
1278,1256,1233,1210,1187,1164,1140,1117,1094,1071,1047,1024,1000,977,953,929,
905,882,858,834,810,786,762,737,713,689,665,641,616,592,567,543,
518,494,469,445,420,396,371,346,322,297,272,247,223,198,173,148,
124,99,74,49,24,0,-24,-49,-74,-99,-124,-148,-173,-198,-223,-247,
-272,-297,-322,-346,-371,-396,-420,-445,-469,-494,-518,-543,-567,-592,-616,-641,
-665,-689,-713,-737,-762,-786,-810,-834,-858,-882,-905,-929,-953,-977,-1000,-1024,
-1047,-1071,-1094,-1117,-1140,-1164,-1187,-1210,-1233,-1256,-1278,-1301,-1324,-1346,-1369,-1391,
-1413,-1436,-1458,-1480,-1502,-1524,-1545,-1567,-1589,-1610,-1632,-1653,-1674,-1695,-1716,-1737,
-1758,-1779,-1799,-1820,-1840,-1860,-1880,-1900,-1920,-1940,-1960,-1979,-1999,-2018,-2037,-2056,
-2075,-2094,-2113,-2131,-2150,-2168,-2186,-2204,-2222,-2240,-2258,-2275,-2293,-2310,-2327,-2344,
-2361,-2378,-2394,-2410,-2427,-2443,-2459,-2475,-2490,-2506,-2521,-2536,-2551,-2566,-2581,-2596,
-2610,-2624,-2638,-2652,-2666,-2680,-2693,-2707,-2720,-2733,-2746,-2758,-2771,-2783,-2795,-2807,
-2819,-2831,-2842,-2854,-2865,-2876,-2886,-2897,-2908,-2918,-2928,-2938,-2948,-2957,-2966,-2976,
-2985,-2994,-3002,-3011,-3019,-3027,-3035,-3043,-3050,-3058,-3065,-3072,-3079,-3086,-3092,-3098,
-3104,-3110,-3116,-3122,-3127,-3132,-3137,-3142,-3146,-3151,-3155,-3159,-3163,-3167,-3170,-3173,
-3176,-3179,-3182,-3184,-3187,-3189,-3191,-3193,-3194,-3195,-3197,-3198,-3198,-3199,-3199,-3199,
-3199,-3199,-3199,-3198,-3198,-3197,-3195,-3194,-3193,-3191,-3189,-3187,-3184,-3182,-3179,-3176,
-3173,-3170,-3167,-3163,-3159,-3155,-3151,-3146,-3142,-3137,-3132,-3127,-3122,-3116,-3110,-3104,
-3098,-3092,-3086,-3079,-3072,-3065,-3058,-3050,-3043,-3035,-3027,-3019,-3011,-3002,-2994,-2985,
-2976,-2966,-2957,-2948,-2938,-2928,-2918,-2908,-2897,-2886,-2876,-2865,-2854,-2842,-2831,-2819,
-2807,-2795,-2783,-2771,-2758,-2746,-2733,-2720,-2707,-2693,-2680,-2666,-2652,-2638,-2624,-2610,
-2596,-2581,-2566,-2551,-2536,-2521,-2506,-2490,-2475,-2459,-2443,-2427,-2410,-2394,-2378,-2361,
-2344,-2327,-2310,-2293,-2275,-2258,-2240,-2222,-2204,-2186,-2168,-2150,-2131,-2113,-2094,-2075,
-2056,-2037,-2018,-1999,-1979,-1960,-1940,-1920,-1900,-1880,-1860,-1840,-1820,-1799,-1779,-1758,
-1737,-1716,-1695,-1674,-1653,-1632,-1610,-1589,-1567,-1545,-1524,-1502,-1480,-1458,-1436,-1413,
-1391,-1369,-1346,-1324,-1301,-1278,-1256,-1233,-1210,-1187,-1164,-1140,-1117,-1094,-1071,-1047,
-1024,-1000,-977,-953,-929,-905,-882,-858,-834,-810,-786,-762,-737,-713,-689,-665,
-641,-616,-592,-567,-543,-518,-494,-469,-445,-420,-396,-371,-346,-322,-297,-272,
-247,-223,-198,-173,-148,-124,-99,-74,-49,-24
};
const float sin_value_LOW[1800] = {
0,11,22,33,44,55,67,78,89,100,111,122,134,145,156,167,
178,189,200,212,223,234,245,256,267,278,290,301,312,323,334,345,
356,367,378,389,401,412,423,434,445,456,467,478,489,500,511,522,
533,544,555,566,577,588,599,610,621,632,643,654,665,676,687,698,
708,719,730,741,752,763,774,784,795,806,817,828,839,849,860,871,
882,892,903,914,924,935,946,956,967,978,988,999,1010,1020,1031,1041,
1052,1062,1073,1083,1094,1104,1115,1125,1136,1146,1157,1167,1177,1188,1198,1209,
1219,1229,1240,1250,1260,1270,1281,1291,1301,1311,1321,1332,1342,1352,1362,1372,
1382,1392,1402,1412,1422,1432,1442,1452,1462,1472,1482,1492,1502,1512,1521,1531,
1541,1551,1561,1570,1580,1590,1599,1609,1619,1628,1638,1648,1657,1667,1676,1686,
1695,1705,1714,1724,1733,1742,1752,1761,1770,1780,1789,1798,1807,1817,1826,1835,
1844,1853,1862,1871,1880,1889,1898,1907,1916,1925,1934,1943,1952,1961,1970,1978,
1987,1996,2005,2013,2022,2031,2039,2048,2056,2065,2073,2082,2090,2099,2107,2116,
2124,2132,2141,2149,2157,2166,2174,2182,2190,2198,2206,2214,2222,2230,2238,2246,
2254,2262,2270,2278,2286,2294,2301,2309,2317,2325,2332,2340,2347,2355,2363,2370,
2378,2385,2392,2400,2407,2415,2422,2429,2436,2444,2451,2458,2465,2472,2479,2486,
2493,2500,2507,2514,2521,2528,2535,2542,2548,2555,2562,2569,2575,2582,2588,2595,
2601,2608,2614,2621,2627,2634,2640,2646,2652,2659,2665,2671,2677,2683,2689,2695,
2701,2707,2713,2719,2725,2731,2737,2742,2748,2754,2760,2765,2771,2776,2782,2787,
2793,2798,2804,2809,2814,2820,2825,2830,2835,2841,2846,2851,2856,2861,2866,2871,
2876,2881,2885,2890,2895,2900,2904,2909,2914,2918,2923,2927,2932,2936,2941,2945,
2949,2954,2958,2962,2966,2971,2975,2979,2983,2987,2991,2995,2999,3003,3007,3010,
3014,3018,3022,3025,3029,3032,3036,3039,3043,3046,3050,3053,3056,3060,3063,3066,
3069,3072,3076,3079,3082,3085,3088,3090,3093,3096,3099,3102,3104,3107,3110,3112,
3115,3117,3120,3122,3125,3127,3130,3132,3134,3136,3139,3141,3143,3145,3147,3149,
3151,3153,3155,3157,3158,3160,3162,3164,3165,3167,3168,3170,3171,3173,3174,3176,
3177,3178,3180,3181,3182,3183,3184,3185,3186,3187,3188,3189,3190,3191,3192,3192,
3193,3194,3195,3195,3196,3196,3197,3197,3198,3198,3198,3199,3199,3199,3199,3199,
3199,3199,3200,3199,3199,3199,3199,3199,3199,3199,3198,3198,3198,3197,3197,3196,
3196,3195,3195,3194,3193,3192,3192,3191,3190,3189,3188,3187,3186,3185,3184,3183,
3182,3181,3180,3178,3177,3176,3174,3173,3171,3170,3168,3167,3165,3164,3162,3160,
3158,3157,3155,3153,3151,3149,3147,3145,3143,3141,3139,3136,3134,3132,3130,3127,
3125,3122,3120,3117,3115,3112,3110,3107,3104,3102,3099,3096,3093,3090,3088,3085,
3082,3079,3076,3072,3069,3066,3063,3060,3056,3053,3050,3046,3043,3039,3036,3032,
3029,3025,3022,3018,3014,3010,3007,3003,2999,2995,2991,2987,2983,2979,2975,2971,
2966,2962,2958,2954,2949,2945,2941,2936,2932,2927,2923,2918,2914,2909,2904,2900,
2895,2890,2885,2881,2876,2871,2866,2861,2856,2851,2846,2841,2835,2830,2825,2820,
2814,2809,2804,2798,2793,2787,2782,2776,2771,2765,2760,2754,2748,2742,2737,2731,
2725,2719,2713,2707,2701,2695,2689,2683,2677,2671,2665,2659,2652,2646,2640,2634,
2627,2621,2614,2608,2601,2595,2588,2582,2575,2569,2562,2555,2548,2542,2535,2528,
2521,2514,2507,2500,2493,2486,2479,2472,2465,2458,2451,2444,2436,2429,2422,2415,
2407,2400,2392,2385,2378,2370,2363,2355,2347,2340,2332,2325,2317,2309,2301,2294,
2286,2278,2270,2262,2254,2246,2238,2230,2222,2214,2206,2198,2190,2182,2174,2166,
2157,2149,2141,2132,2124,2116,2107,2099,2090,2082,2073,2065,2056,2048,2039,2031,
2022,2013,2005,1996,1987,1978,1970,1961,1952,1943,1934,1925,1916,1907,1898,1889,
1880,1871,1862,1853,1844,1835,1826,1817,1807,1798,1789,1780,1770,1761,1752,1742,
1733,1724,1714,1705,1695,1686,1676,1667,1657,1648,1638,1628,1619,1609,1599,1590,
1580,1570,1561,1551,1541,1531,1521,1512,1502,1492,1482,1472,1462,1452,1442,1432,
1422,1412,1402,1392,1382,1372,1362,1352,1342,1332,1321,1311,1301,1291,1281,1270,
1260,1250,1240,1229,1219,1209,1198,1188,1177,1167,1157,1146,1136,1125,1115,1104,
1094,1083,1073,1062,1052,1041,1031,1020,1010,999,988,978,967,956,946,935,
924,914,903,892,882,871,860,849,839,828,817,806,795,784,774,763,
752,741,730,719,708,698,687,676,665,654,643,632,621,610,599,588,
577,566,555,544,533,522,511,500,489,478,467,456,445,434,423,412,
401,389,378,367,356,345,334,323,312,301,290,278,267,256,245,234,
223,212,200,189,178,167,156,145,134,122,111,100,89,78,67,55,
44,33,22,11,0,-11,-22,-33,-44,-55,-67,-78,-89,-100,-111,-122,
-134,-145,-156,-167,-178,-189,-200,-212,-223,-234,-245,-256,-267,-278,-290,-301,
-312,-323,-334,-345,-356,-367,-378,-389,-401,-412,-423,-434,-445,-456,-467,-478,
-489,-500,-511,-522,-533,-544,-555,-566,-577,-588,-599,-610,-621,-632,-643,-654,
-665,-676,-687,-698,-708,-719,-730,-741,-752,-763,-774,-784,-795,-806,-817,-828,
-839,-849,-860,-871,-882,-892,-903,-914,-924,-935,-946,-956,-967,-978,-988,-999,
-1010,-1020,-1031,-1041,-1052,-1062,-1073,-1083,-1094,-1104,-1115,-1125,-1136,-1146,-1157,-1167,
-1177,-1188,-1198,-1209,-1219,-1229,-1240,-1250,-1260,-1270,-1281,-1291,-1301,-1311,-1321,-1332,
-1342,-1352,-1362,-1372,-1382,-1392,-1402,-1412,-1422,-1432,-1442,-1452,-1462,-1472,-1482,-1492,
-1502,-1512,-1521,-1531,-1541,-1551,-1561,-1570,-1580,-1590,-1599,-1609,-1619,-1628,-1638,-1648,
-1657,-1667,-1676,-1686,-1695,-1705,-1714,-1724,-1733,-1742,-1752,-1761,-1770,-1780,-1789,-1798,
-1807,-1817,-1826,-1835,-1844,-1853,-1862,-1871,-1880,-1889,-1898,-1907,-1916,-1925,-1934,-1943,
-1952,-1961,-1970,-1978,-1987,-1996,-2005,-2013,-2022,-2031,-2039,-2048,-2056,-2065,-2073,-2082,
-2090,-2099,-2107,-2116,-2124,-2132,-2141,-2149,-2157,-2166,-2174,-2182,-2190,-2198,-2206,-2214,
-2222,-2230,-2238,-2246,-2254,-2262,-2270,-2278,-2286,-2294,-2301,-2309,-2317,-2325,-2332,-2340,
-2347,-2355,-2363,-2370,-2378,-2385,-2392,-2400,-2407,-2415,-2422,-2429,-2436,-2444,-2451,-2458,
-2465,-2472,-2479,-2486,-2493,-2500,-2507,-2514,-2521,-2528,-2535,-2542,-2548,-2555,-2562,-2569,
-2575,-2582,-2588,-2595,-2601,-2608,-2614,-2621,-2627,-2634,-2640,-2646,-2652,-2659,-2665,-2671,
-2677,-2683,-2689,-2695,-2701,-2707,-2713,-2719,-2725,-2731,-2737,-2742,-2748,-2754,-2760,-2765,
-2771,-2776,-2782,-2787,-2793,-2798,-2804,-2809,-2814,-2820,-2825,-2830,-2835,-2841,-2846,-2851,
-2856,-2861,-2866,-2871,-2876,-2881,-2885,-2890,-2895,-2900,-2904,-2909,-2914,-2918,-2923,-2927,
-2932,-2936,-2941,-2945,-2949,-2954,-2958,-2962,-2966,-2971,-2975,-2979,-2983,-2987,-2991,-2995,
-2999,-3003,-3007,-3010,-3014,-3018,-3022,-3025,-3029,-3032,-3036,-3039,-3043,-3046,-3050,-3053,
-3056,-3060,-3063,-3066,-3069,-3072,-3076,-3079,-3082,-3085,-3088,-3090,-3093,-3096,-3099,-3102,
-3104,-3107,-3110,-3112,-3115,-3117,-3120,-3122,-3125,-3127,-3130,-3132,-3134,-3136,-3139,-3141,
-3143,-3145,-3147,-3149,-3151,-3153,-3155,-3157,-3158,-3160,-3162,-3164,-3165,-3167,-3168,-3170,
-3171,-3173,-3174,-3176,-3177,-3178,-3180,-3181,-3182,-3183,-3184,-3185,-3186,-3187,-3188,-3189,
-3190,-3191,-3192,-3192,-3193,-3194,-3195,-3195,-3196,-3196,-3197,-3197,-3198,-3198,-3198,-3199,
-3199,-3199,-3199,-3199,-3199,-3199,-3200,-3199,-3199,-3199,-3199,-3199,-3199,-3199,-3198,-3198,
-3198,-3197,-3197,-3196,-3196,-3195,-3195,-3194,-3193,-3192,-3192,-3191,-3190,-3189,-3188,-3187,
-3186,-3185,-3184,-3183,-3182,-3181,-3180,-3178,-3177,-3176,-3174,-3173,-3171,-3170,-3168,-3167,
-3165,-3164,-3162,-3160,-3158,-3157,-3155,-3153,-3151,-3149,-3147,-3145,-3143,-3141,-3139,-3136,
-3134,-3132,-3130,-3127,-3125,-3122,-3120,-3117,-3115,-3112,-3110,-3107,-3104,-3102,-3099,-3096,
-3093,-3090,-3088,-3085,-3082,-3079,-3076,-3072,-3069,-3066,-3063,-3060,-3056,-3053,-3050,-3046,
-3043,-3039,-3036,-3032,-3029,-3025,-3022,-3018,-3014,-3010,-3007,-3003,-2999,-2995,-2991,-2987,
-2983,-2979,-2975,-2971,-2966,-2962,-2958,-2954,-2949,-2945,-2941,-2936,-2932,-2927,-2923,-2918,
-2914,-2909,-2904,-2900,-2895,-2890,-2885,-2881,-2876,-2871,-2866,-2861,-2856,-2851,-2846,-2841,
-2835,-2830,-2825,-2820,-2814,-2809,-2804,-2798,-2793,-2787,-2782,-2776,-2771,-2765,-2760,-2754,
-2748,-2742,-2737,-2731,-2725,-2719,-2713,-2707,-2701,-2695,-2689,-2683,-2677,-2671,-2665,-2659,
-2652,-2646,-2640,-2634,-2627,-2621,-2614,-2608,-2601,-2595,-2588,-2582,-2575,-2569,-2562,-2555,
-2548,-2542,-2535,-2528,-2521,-2514,-2507,-2500,-2493,-2486,-2479,-2472,-2465,-2458,-2451,-2444,
-2436,-2429,-2422,-2415,-2407,-2400,-2392,-2385,-2378,-2370,-2363,-2355,-2347,-2340,-2332,-2325,
-2317,-2309,-2301,-2294,-2286,-2278,-2270,-2262,-2254,-2246,-2238,-2230,-2222,-2214,-2206,-2198,
-2190,-2182,-2174,-2166,-2157,-2149,-2141,-2132,-2124,-2116,-2107,-2099,-2090,-2082,-2073,-2065,
-2056,-2048,-2039,-2031,-2022,-2013,-2005,-1996,-1987,-1978,-1970,-1961,-1952,-1943,-1934,-1925,
-1916,-1907,-1898,-1889,-1880,-1871,-1862,-1853,-1844,-1835,-1826,-1817,-1807,-1798,-1789,-1780,
-1770,-1761,-1752,-1742,-1733,-1724,-1714,-1705,-1695,-1686,-1676,-1667,-1657,-1648,-1638,-1628,
-1619,-1609,-1599,-1590,-1580,-1570,-1561,-1551,-1541,-1531,-1521,-1512,-1502,-1492,-1482,-1472,
-1462,-1452,-1442,-1432,-1422,-1412,-1402,-1392,-1382,-1372,-1362,-1352,-1342,-1332,-1321,-1311,
-1301,-1291,-1281,-1270,-1260,-1250,-1240,-1229,-1219,-1209,-1198,-1188,-1177,-1167,-1157,-1146,
-1136,-1125,-1115,-1104,-1094,-1083,-1073,-1062,-1052,-1041,-1031,-1020,-1010,-999,-988,-978,
-967,-956,-946,-935,-924,-914,-903,-892,-882,-871,-860,-849,-839,-828,-817,-806,
-795,-784,-774,-763,-752,-741,-730,-719,-708,-698,-687,-676,-665,-654,-643,-632,
-621,-610,-599,-588,-577,-566,-555,-544,-533,-522,-511,-500,-489,-478,-467,-456,
-445,-434,-423,-412,-401,-389,-378,-367,-356,-345,-334,-323,-312,-301,-290,-278,
-267,-256,-245,-234,-223,-212,-200,-189,-178,-167,-156,-145,-134,-122,-111,-100,
-89,-78,-67,-55,-44,-33,-22,-11
};


int sin_max;
u16 sin_i0=0;
u16 sin_hhigh=300;
u16 sin_i1=0;	//正弦波1
u16 sin_high=405;
u16 sin_i2=0;
u16 sin_low=900;
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
//		if(Hz<=46)
//		{
//		sin_i2 = (sin_i2+1)%1800;
//		sin_low = (sin_low+1)%1800;
//		TIM2->CCR1 = sin_value_LOW[sin_i2]*sin_max/3200+rrr/2;
//		TIM2->CCR2 = sin_value_LOW[sin_low]*sin_max/3200+rrr/2;
//		}
		
	
//		sin_i1 = (sin_i1+1)%810;
//		sin_high = (sin_high+1)%810;

//		TIM2->CCR3 = sin_value_HIGH[sin_i1]*sin_max/3200+rrr/2;
//		TIM2->CCR2 = sin_value_HIGH[sin_high]*sin_max/3200+rrr/2;
		TIM2->CCR3 =sin_max;
		TIM2->CCR2 = sin_max;
//		 else
//		{
//			sin_i0 = (sin_i0+1)%600;
//		sin_hhigh = (sin_hhigh+1)%600;

//		TIM2->CCR1 = sin_value_SHIGH[sin_i0]*sin_max/3200+rrr/2;
//		TIM2->CCR2 = sin_value_SHIGH[sin_hhigh]*sin_max/3200+rrr/2;
//		
//		}
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

