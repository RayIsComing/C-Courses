%%applidir = '..\..\..\appli\common\';
applidir = 'C:\cvs\MDL_GDi_LUX\Library\SimLib\';

mex('C:\cvs\MDL_GDi_LUX\Library\SimLib\ApplyFILT_1stOrderLag_ssp.c',[matlabroot,'\extern\lib\win32\microsoft\libfixedpoint.lib'], ['-I',applidir])

!copy m_lib_lookup3d.mexw32 ..\Gdi_Lib\
!del m_lib_lookup3d.mexw32

clear applidir;
