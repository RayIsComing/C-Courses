def = legacy_code ('initialize');
def.SFunctionName = 'usLookup_xyz_us_us';
def.OutputFcnSpec = 'uint16 y1 = usLookup_xyz_us_us(uint16 u1[1], uint16 u2, uint16 u3)';
def.HeaderFiles = {'mathlib.h'};
def.SourceFiles = {'mathlib.c'};

legacy_code('sfcn_cmex_generate',def);

legacy_code('compile',def);

legacy_code('slblock_generate',def);

legacy_code('sfcn_tlc_generate',def);



