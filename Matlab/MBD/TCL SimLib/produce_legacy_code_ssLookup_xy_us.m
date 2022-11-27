def = legacy_code ('initialize');
def.SFunctionName = 'ssLookup_xy_us';
def.OutputFcnSpec = 'int16 y1 = ssLookup_xy_us(int16 u1[1], uint16 u2)';
def.HeaderFiles = {'mathlib.h'};
def.SourceFiles = {'mathlib.c'};

legacy_code('sfcn_cmex_generate',def);

legacy_code('compile',def);

legacy_code('slblock_generate',def);

legacy_code('sfcn_tlc_generate',def);



