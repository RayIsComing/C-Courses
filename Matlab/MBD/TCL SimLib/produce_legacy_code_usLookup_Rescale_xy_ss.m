def = legacy_code ('initialize');
def.SFunctionName = 'usLookup_Rescale_xy_ss';
def.OutputFcnSpec = 'uint16 y1 = usLookup_Rescale_xy_ss(int16 u1[1], int16 u2)';
def.HeaderFiles = {'mathlib.h'};
def.SourceFiles = {'mathlib.c'};

legacy_code('sfcn_cmex_generate',def);

legacy_code('compile',def);

legacy_code('slblock_generate',def);

legacy_code('sfcn_tlc_generate',def);



