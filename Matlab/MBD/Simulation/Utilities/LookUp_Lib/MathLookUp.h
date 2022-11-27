#include "data_types.h"

/********** Table Look-Up ***********/

/******* 16Bit ******/
/**** 2D : Idx vs. Val ***/
#define usCvrtSizeToN_us(Size)\
( ((Size) <= 2) ? \
(0) : \
( ((Size) <= 3) ? \
(1) : \
( ((Size) <= 5) ? \
(2) : \
( ((Size) <= 9) ? \
(3) : \
( ((Size) <= 17) ? \
(4) : \
(5) ) ) ) ) )

/* Independent Look Up Tables */
extern U16 usLookup_Independent_xy_us(const U16 * TableAddr, U16 Value,U16 Intervals);
extern U16 usLookup_Independent_xy_ss(const S16 * TableAddr, S16 Value,U16 Intervals);

/* XY Look Up Table */
extern U16 usLookup_xy_us(const U16 *TableAddr, U16 index, U16 Intervals);
extern S16 ssLookup_xy_us(const S16 *TableAddr, U16 index, U16 Intervals);

/* XYZ Look Up Table */
extern U16 usLookup_xyz_us_us(const U16* TableAddr,U16 TableIndexX,U16 TableIndexY, U16 SizeX, U16 SizeY);
extern S16 ssLookup_xyz_us_us(const S16* TableAddr,U16 TableIndexX,U16 TableIndexY, U16 SizeX, U16 SizeY);

/*XYZ 32 Bit Look up Table*/
extern U32 ulLookup_xyz_us_us(const U32* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);
extern S32 slLookup_xyz_us_us(const S32* TblData,U16 x_idx,U16 y_idx, U16 x_length, U16 y_length);

extern U32 ulLookup_xy_us(const U32 *TableAddr, U16 index, U16 Intervals);