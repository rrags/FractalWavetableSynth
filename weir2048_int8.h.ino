#ifndef WEIR2048_H_
#define WEIR2048_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"

#define WEIR2048_NUM_CELLS 2048
#define WEIR2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) WEIR2048_DATA []  =
        {
                109,   74,   51,   53,   58,   45,   21,   11,   27,   51,   53,
         25,   -6,  -14,    0,   11,    4,   -7,    0,   30,   54,   47,
         14,  -15,  -21,  -12,  -14,  -33,  -48,  -36,   -6,   11,   -1,
        -29,  -42,  -29,   -8,   -4,  -13,  -11,   15,   47,   55,   29,
         -6,  -22,  -17,  -15,  -32,  -54,  -57,  -35,  -13,  -18,  -49,
        -74,  -73,  -55,  -45,  -53,  -60,  -42,   -8,   12,    0,  -33,
        -55,  -52,  -41,  -45,  -63,  -69,  -48,  -16,   -3,  -20,  -45,
        -49,  -29,  -10,   -8,  -16,   -7,   24,   54,   53,   22,  -10,
        -19,  -13,  -16,  -37,  -57,  -53,  -29,  -13,  -28,  -62,  -83,
        -78,  -61,  -58,  -70,  -74,  -52,  -20,   -9,  -32,  -67,  -85,
        -79,  -72,  -83, -102, -103,  -78,  -49,  -45,  -69,  -91,  -89,
        -67,  -51,  -55,  -60,  -44,   -9,   15,    5,  -28,  -54,  -56,
        -48,  -54,  -75,  -89,  -76,  -48,  -37,  -56,  -87,  -98,  -84,
        -66,  -65,  -74,  -68,  -38,   -5,    0,  -26,  -56,  -63,  -52,
        -46,  -58,  -72,  -64,  -32,   -5,   -8,  -33,  -49,  -38,  -14,
         -3,   -8,   -9,   12,   48,   64,   45,   10,  -11,   -9,   -5,
        -18,  -42,  -52,  -35,  -11,  -10,  -39,  -70,  -77,  -63,  -52,
        -59,  -70,  -62,  -32,   -8,  -15,  -49,  -79,  -83,  -74,  -77,
        -96, -109,  -97,  -66,  -49,  -62,  -90, -102,  -88,  -67,  -63,
        -71,  -68,  -41,   -8,   -1,  -27,  -62,  -77,  -72,  -70,  -86,
       -108, -110,  -86,  -64,  -70, -100, -125, -122, -103,  -94, -101,
       -106,  -88,  -53,  -32,  -45,  -78,  -98,  -94,  -83,  -87, -104,
       -109,  -86,  -53,  -40,  -57,  -81,  -84,  -63,  -43,  -42,  -48,
        -37,   -4,   24,   23,   -7,  -38,  -46,  -39,  -41,  -62,  -81,
        -76,  -50,  -35,  -50,  -83, -103,  -95,  -78,  -75,  -87,  -89,
        -66,  -33,  -22,  -45,  -79,  -95,  -88,  -81,  -92, -110, -110,
        -83,  -54,  -50,  -74,  -95,  -91,  -68,  -52,  -55,  -60,  -42,
         -6,   17,    7,  -25,  -50,  -51,  -43,  -49,  -70,  -82,  -67,
        -39,  -28,  -48,  -78,  -88,  -72,  -54,  -53,  -62,  -55,  -24,
          8,   13,  -12,  -41,  -48,  -35,  -30,  -42,  -55,  -46,  -13,
         12,    9,  -15,  -30,  -18,    5,   16,   10,   10,   34,   69,
         85,   66,   30,    9,   11,   16,    3,  -21,  -30,  -12,   11,
         10,  -17,  -48,  -55,  -40,  -29,  -37,  -48,  -39,   -8,   14,
          5,  -28,  -57,  -61,  -53,  -56,  -75,  -88,  -75,  -44,  -28,
        -42,  -70,  -82,  -67,  -47,  -43,  -52,  -49,  -21,   10,   16,
        -11,  -45,  -60,  -55,  -53,  -71,  -93,  -94,  -70,  -49,  -56,
        -87, -111, -109,  -90,  -81,  -90,  -95,  -76,  -41,  -22,  -36,
        -69,  -90,  -85,  -74,  -80,  -97, -102,  -79,  -47,  -35,  -53,
        -78,  -80,  -59,  -40,  -40,  -46,  -35,   -3,   25,   22,   -9,
        -40,  -48,  -41,  -44,  -66,  -85,  -79,  -54,  -40,  -56,  -90,
       -109, -102,  -85,  -83,  -95,  -97,  -74,  -42,  -33,  -57,  -91,
       -107, -100,  -94, -105, -124, -123,  -96,  -68,  -66,  -90, -111,
       -106,  -84,  -69,  -73,  -77,  -59,  -23,    0,  -11,  -45,  -70,
        -70,  -62,  -69,  -90, -102,  -87,  -59,  -49,  -70,  -99, -109,
        -93,  -75,  -75,  -84,  -76,  -45,  -13,   -9,  -35,  -64,  -70,
        -57,  -52,  -65,  -78,  -67,  -35,   -9,  -13,  -38,  -52,  -39,
        -15,   -5,  -10,  -10,   14,   49,   64,   44,    9,  -10,   -7,
         -3,  -17,  -40,  -48,  -30,   -6,   -7,  -36,  -66,  -72,  -56,
        -45,  -53,  -64,  -53,  -22,    0,   -8,  -42,  -70,  -73,  -64,
        -67,  -86,  -98,  -84,  -53,  -36,  -51,  -79,  -89,  -73,  -52,
        -49,  -57,  -52,  -23,    8,   13,  -13,  -47,  -60,  -54,  -52,
        -69,  -91,  -90,  -65,  -44,  -51,  -82, -105, -100,  -81,  -72,
        -80,  -84,  -64,  -28,   -9,  -23,  -56,  -75,  -69,  -58,  -62,
        -79,  -82,  -58,  -25,  -14,  -32,  -55,  -56,  -34,  -14,  -14,
        -19,   -7,   26,   55,   52,   20,   -9,  -15,   -8,  -11,  -32,
        -50,  -43,  -17,   -3,  -19,  -52,  -70,  -61,  -44,  -42,  -53,
        -54,  -29,    2,   11,  -12,  -46,  -60,  -52,  -45,  -57,  -75,
        -72,  -45,  -16,  -14,  -38,  -58,  -52,  -29,  -14,  -18,  -21,
         -2,   33,   56,   44,   11,  -12,  -12,   -3,  -10,  -31,  -42,
        -26,    1,   11,   -9,  -39,  -47,  -31,  -13,  -13,  -22,  -13,
         18,   50,   53,   26,   -1,   -6,    6,   10,   -2,  -14,   -3,
         29,   54,   49,   24,   11,   24,   48,   58,   52,   53,   78,
        113,  127,  105,   70,   50,   54,   57,   43,   19,   11,   30,
         53,   51,   21,   -8,  -13,    1,   11,    2,   -7,    3,   33,
         55,   45,   10,  -17,  -20,  -12,  -16,  -36,  -48,  -33,   -3,
         11,   -4,  -32,  -42,  -26,   -7,   -4,  -13,   -9,   19,   50,
         53,   25,   -9,  -22,  -16,  -16,  -35,  -56,  -56,  -32,  -12,
        -21,  -52,  -76,  -72,  -53,  -46,  -55,  -59,  -39,   -4,   12,
         -3,  -37,  -56,  -51,  -41,  -47,  -65,  -68,  -44,  -13,   -3,
        -23,  -47,  -48,  -26,   -8,   -9,  -16,   -4,   28,   56,   50,
         17,  -12,  -19,  -12,  -17,  -40,  -58,  -51,  -26,  -14,  -32,
        -66,  -84,  -76,  -60,  -59,  -72,  -73,  -48,  -17,  -10,  -36,
        -70,  -85,  -78,  -72,  -85, -104, -101,  -74,  -47,  -47,  -72,
        -93,  -87,  -64,  -51,  -56,  -59,  -40,   -5,   15,    2,  -32,
        -55,  -55,  -48,  -56,  -78,  -89,  -73,  -45,  -37,  -60,  -89,
        -98,  -81,  -65,  -66,  -75,  -66,  -34,   -3,   -2,  -30,  -58,
        -63,  -50,  -46,  -60,  -73,  -61,  -28,   -4,  -10,  -36,  -49,
        -35,  -12,   -3,   -9,   -8,   16,   51,   64,   42,    6,  -12,
         -9,   -5,  -20,  -44,  -51,  -32,   -9,  -12,  -43,  -72,  -76,
        -61,  -52,  -61,  -71,  -59,  -28,   -7,  -18,  -53,  -81,  -83,
        -74,  -78,  -98, -109,  -93,  -63,  -49,  -65,  -93, -102,  -85,
        -65,  -63,  -72,  -66,  -37,   -6,   -3,  -32,  -65,  -77,  -71,
        -71,  -89, -110, -108,  -83,  -63,  -73, -104, -126, -120, -101,
        -94, -103, -106,  -84,  -49,  -32,  -49,  -81,  -99,  -93,  -82,
        -88, -105, -107,  -82,  -50,  -41,  -60,  -83,  -82,  -60,  -42,
        -42,  -48,  -34,    0,   26,   21,  -11,  -40,  -46,  -38,  -43,
        -65,  -82,  -73,  -47,  -35,  -53,  -86, -103,  -93,  -77,  -76,
        -88,  -87,  -62,  -30,  -23,  -49,  -82,  -95,  -87,  -81,  -94,
       -111, -108,  -79,  -52,  -52,  -77,  -96,  -89,  -65,  -52,  -56,
        -59,  -38,   -2,   18,    4,  -29,  -52,  -50,  -42,  -50,  -72,
        -82,  -64,  -36,  -29,  -51,  -80,  -87,  -70,  -53,  -54,  -62,
        -53,  -20,   10,   11,  -16,  -43,  -47,  -34,  -30,  -44,  -56,
        -43,   -9,   13,    7,  -18,  -30,  -15,    7,   16,   10,   12,
         38,   73,   84,   62,   26,    8,   12,   15,    0,  -23,  -29,
         -9,   12,    8,  -21,  -50,  -54,  -38,  -29,  -39,  -48,  -36,
         -5,   15,    2,  -32,  -59,  -60,  -52,  -57,  -77,  -88,  -72,
        -41,  -28,  -45,  -73,  -81,  -65,  -45,  -44,  -53,  -47,  -17,
         12,   14,  -15,  -48,  -60,  -54,  -54,  -74,  -94,  -92,  -67,
        -48,  -59,  -91, -112, -107,  -88,  -81,  -91,  -94,  -72,  -38,
        -22,  -40,  -73,  -90,  -84,  -74,  -81,  -99, -101,  -75,  -44,
        -36,  -57,  -80,  -78,  -56,  -39,  -40,  -46,  -32,    1,   27,
         20,  -13,  -42,  -47,  -40,  -46,  -69,  -86,  -77,  -52,  -40,
        -60,  -93, -110, -100,  -84,  -84,  -97,  -96,  -70,  -39,  -34,
        -61,  -94, -107,  -99,  -94, -108, -125, -121,  -92,  -66,  -67,
        -93, -112, -104,  -81,  -68,  -74,  -76,  -55,  -19,    0,  -14,
        -49,  -71,  -69,  -62,  -71,  -93, -102,  -84,  -56,  -50,  -73,
       -102, -108,  -91,  -74,  -76,  -84,  -74,  -41,  -10,  -11,  -39,
        -66,  -69,  -56,  -53,  -67,  -78,  -64,  -31,   -8,  -15,  -40,
        -52,  -37,  -13,   -5,  -11,   -8,   18,   52,   63,   40,    5,
        -11,   -6,   -3,  -19,  -43,  -47,  -27,   -5,   -9,  -40,  -68,
        -70,  -54,  -45,  -55,  -64,  -50,  -18,    1,  -11,  -47,  -72,
        -72,  -64,  -69,  -89,  -98,  -80,  -49,  -37,  -54,  -81,  -88,
        -70,  -51,  -49,  -57,  -50,  -19,   10,   12,  -17,  -50,  -60,
        -53,  -53,  -72,  -92,  -88,  -62,  -43,  -54,  -85, -106,  -98,
        -79,  -72,  -81,  -83,  -60,  -24,   -9,  -27,  -59,  -75,  -67,
        -57,  -64,  -81,  -81,  -54,  -22,  -15,  -35,  -57,  -54,  -31,
        -13,  -14,  -19,   -4,   30,   56,   49,   16,  -11,  -15,   -7,
        -13,  -35,  -51,  -40,  -14,   -3,  -22,  -55,  -70,  -59,  -43,
        -43,  -54,  -52,  -25,    5,   10,  -16,  -49,  -60,  -51,  -46,
        -59,  -76,  -70,  -41,  -14,  -16,  -41,  -59,  -50,  -27,  -14,
        -19,  -20,    1,   37,   56,   41,    7,  -13,  -11,   -3,  -12,
        -34,  -42,  -23,    4,   10,  -13,  -41,  -46,  -28,  -12,  -14,
        -22,  -10,   22,   52,   51,   22,   -3,   -5,    7,   10,   -4,
        -14,    0,   33,   55,   47,   22,   11,   27,   50,   58,   51,
         54,   82,  116,  126,  101,   66,   50,   54,   57,   40,   17,
         12,   33,   55,   49,   17,  -10,  -12,    3,   11,    1,   -7,
          6,   37,   56,   41,    5,  -19,  -19,  -11,  -18,  -38,  -48,
        -30,    0,   11,   -7,  -35,  -41,  -24,   -5,   -5,  -14,   -7,
         23,   52,   51,   20,  -12,  -22,  -15,  -17,  -37,  -58,  -54,
        -29,  -11,  -24,  -56,  -77,  -70,  -51,  -46,  -56,  -58,  -35,
         -1,   12,   -7,  -40,  -56,  -49,  -40,  -49,  -67,  -67,  -41,
        -10,   -4,  -26,  -49,  -46,  -24,   -8,  -10,  -16,   -1,   33,
         57,   48,   13,  -14,  -18,  -12,  -19,  -43,  -59,  -49,  -23,
        -14,  -35,  -69,  -84,  -74,  -59,  -60,  -73,  -71,  -45,  -15,
        -12,  -40,  -73,  -85,  -76,  -73,  -88, -105,  -99,  -70,  -45,
        -49,  -75,  -93,  -85,  -62,  -51,  -57,  -58,  -37,   -1,   16,
         -1,  -35,  -57,  -54,  -48,  -58,  -80,  -88,  -70,  -43,  -39,
        -63,  -92,  -97,  -79,  -64,  -67,  -75,  -63,  -30,   -1,   -4,
        -34,  -60,  -62,  -49,  -47,  -62,  -73,  -58,  -24,   -3,  -13,
        -38,  -49,  -33,  -10,   -3,  -10,   -6,   20,   54,   63,   38,
          3,  -12,   -8,   -6,  -23,  -46,  -50,  -29,   -8,  -15,  -47,
        -74,  -75,  -59,  -52,  -62,  -71,  -56,  -24,   -6,  -22,  -57,
        -82,  -82,  -73,  -80, -100, -109,  -90,  -60,  -49,  -68,  -95,
       -101,  -82,  -64,  -64,  -72,  -64,  -33,   -3,   -5,  -36,  -68,
        -77,  -70,  -72,  -92, -111, -106,  -80,  -63,  -76, -107, -127,
       -118,  -99,  -94, -104, -105,  -80,  -46,  -32,  -52,  -85,  -99,
        -91,  -82,  -90, -107, -106,  -78,  -47,  -42,  -64,  -85,  -81,
        -57,  -41,  -43,  -48,  -31,    3,   27,   18,  -15,  -42,  -45,
        -38,  -45,  -68,  -82,  -71,  -45,  -35,  -57,  -90, -103,  -91,
        -76,  -77,  -89,  -86,  -58,  -28,  -25,  -53,  -85,  -95,  -86,
        -82,  -96, -112, -105,  -75,  -50,  -54,  -80,  -97,  -86,  -63,
        -52,  -57,  -58,  -35,    0,   18,    0,  -33,  -53,  -49,  -42,
        -53,  -74,  -81,  -61,  -34,  -30,  -55,  -82,  -86,  -67,  -52,
        -55,  -63,  -50,  -15,   12,    9,  -20,  -45,  -46,  -33,  -31,
        -46,  -56,  -39,   -5,   14,    4,  -20,  -30,  -13,    9,   16,
          9,   13,   42,   76,   83,   58,   23,    8,   13,   15,   -2,
        -25,  -28,   -6,   13,    6,  -26,  -52,  -53,  -36,  -29,  -40,
        -48,  -33,   -1,   15,    0,  -36,  -60,  -59,  -51,  -59,  -79,
        -88,  -68,  -38,  -28,  -49,  -75,  -80,  -62,  -44,  -45,  -53,
        -44,  -13,   14,   12,  -19,  -51,  -60,  -53,  -56,  -76,  -96,
        -90,  -64,  -48,  -62,  -94, -113, -105,  -86,  -82,  -92,  -93,
        -68,  -34,  -22,  -43,  -76,  -91,  -82,  -74,  -83, -100,  -99,
        -71,  -41,  -37,  -60,  -81,  -77,  -54,  -38,  -41,  -46,  -29,
          5,   28,   17,  -17,  -44,  -47,  -40,  -48,  -72,  -86,  -75,
        -49,  -41,  -64,  -97, -110,  -98,  -83,  -86,  -98,  -94,  -66,
        -37,  -36,  -65,  -97, -107,  -98,  -95, -110, -126, -119,  -89,
        -64,  -70,  -96, -112, -102,  -79,  -68,  -75,  -75,  -51,  -16,
          0,  -18,  -52,  -72,  -68,  -62,  -73,  -95, -101,  -81,  -54,
        -51,  -77, -104, -107,  -88,  -74,  -77,  -84,  -71,  -36,   -9,
        -13,  -43,  -68,  -68,  -55,  -54,  -69,  -78,  -61,  -27,   -7,
        -18,  -43,  -51,  -34,  -11,   -5,  -12,   -6,   22,   55,   62,
         36,    2,  -11,   -6,   -4,  -22,  -45,  -46,  -24,   -4,  -12,
        -44,  -70,  -69,  -52,  -46,  -56,  -64,  -47,  -15,    1,  -15,
        -51,  -73,  -71,  -63,  -71,  -91,  -98,  -77,  -47,  -37,  -57,
        -83,  -87,  -67,  -49,  -50,  -58,  -47,  -15,   12,    9,  -21,
        -52,  -60,  -52,  -55,  -75,  -93,  -86,  -59,  -43,  -57,  -89,
       -106,  -96,  -77,  -73,  -82,  -82,  -56,  -21,   -9,  -30,  -62,
        -75,  -66,  -57,  -66,  -82,  -79,  -50,  -20,  -16,  -38,  -58,
        -52,  -28,  -12,  -15,  -19,    0,   34,   57,   46,   12,  -13,
        -14,   -7,  -15,  -38,  -51,  -38,  -11,   -4,  -26,  -58,  -70,
        -57,  -42,  -44,  -55,  -50,  -21,    7,    8,  -20,  -51,  -59,
        -49,  -46,  -61,  -77,  -68,  -37,  -13,  -18,  -44,  -60,  -48,
        -24,  -14,  -20,  -19,    5,   41,   56,   37,    3,  -14,   -9,
         -3,  -14,  -36,  -41,  -20,    6,    8,  -17,  -43,  -45,  -26,
        -11,  -15,  -22,   -7,   27,   54,   48,   18,   -5,   -4,    8,
          9,   -6,  -14,    3,   37,   56,   44,   19,   11,   29,   52,
         57,   50,   56,
        };

#endif /* WEIR2048_H_ */
