extern unsigned int usLookup_Rescale_xy_ss(int* RescaleMap,int InputVariable);
extern unsigned int usLookup_Rescale_xy_us(unsigned int* RescaleMap,unsigned int InputVariable);
extern unsigned int usLookup_xy_us(unsigned int* Map, unsigned int ScaledVariable );
extern unsigned int usLookup_xy_us(unsigned int* Map, unsigned int ScaledVariable1, unsigned int ScaledVariable2 );
extern int ssLookup_xy_us(int* Map, unsigned int ScaledVariable );
extern int ssLookup_xyz_us_us(int* Map, unsigned int ScaledVariable1, unsigned int ScaledVariable2 );
extern unsigned int usLookup_Independent_xy_us(unsigned int* Map, unsigned int ScaledVariable );
extern int ssLookup_Independent_xy_us(int* Map, unsigned int ScaledVariable );
extern unsigned int usLookup_Independent_xy_ss(unsigned int* Map, unsigned int ScaledVariable );
extern int ssLookup_Independent_xy_ss(int* Map, unsigned int ScaledVariable );
