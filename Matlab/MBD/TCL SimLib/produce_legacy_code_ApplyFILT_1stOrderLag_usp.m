def = legacy_code ('initialize');
def.SFunctionName = 'ApplyFILT_1stOrderLag_usp';
def.OutputFcnSpec = 'uint16 y1 = ApplyFILT_1stOrderLag_usp(uint16 u1, uint16 u2, uint16 u3)';
def.HeaderFiles = {'filtlib.h'};
def.SourceFiles = {'filtlib.c'};

legacy_code('sfcn_cmex_generate',def);

legacy_code('compile',def);

legacy_code('slblock_generate',def);

legacy_code('sfcn_tlc_generate',def);



