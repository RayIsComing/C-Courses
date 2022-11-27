def = legacy_code ('initialize');
def.SFunctionName = 'ApplyFILT_1stOrderLag_ssp';
def.OutputFcnSpec = 'int16 y1 = ApplyFILT_1stOrderLag_ssp(int16 u1, int16 u2, uint16 u3)';
def.HeaderFiles = {'filtlib.h'};
def.SourceFiles = {'filtlib.c'};

legacy_code('sfcn_cmex_generate',def);

legacy_code('compile',def);

legacy_code('slblock_generate',def);

legacy_code('sfcn_tlc_generate',def);



