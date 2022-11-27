function createsldd_test()
%创建Simulink.Signal对象
    Signal_test = Simulink.Signal;
    Signal_test.DataType = 'uint8'; %类型
    Signal_test.InitialValue = '0'; %初始值
    Signal_test.StorageClass = 'ExportedGlobal'; %存储方式
    Signal_test.Dimensions = 1; %维度
%     Signal_test.CoderInfo.CustomAttributes.HeaderFile = 'Header_Define.h'; %头文件
%     Signal_test.CoderInfo.CustomAttributes.DefinitionFile = 'Header_Define.c'; %源文件
%     Signal_test.CoderInfo.CustomAttributes.Owner = 'LuoJiayi'; %Owner

%创建Simulink.Parameter对象
    Parameter_test = Simulink.Parameter;
    Parameter_test.DataType = 'uint8'; %类型
    Parameter_test.Value = (10); %初始值
    Parameter_test.StorageClass = 'Define (Custom)'; %存储方式
    Parameter_test.Dimensions = [1 1]; %维度
    Parameter_test.CoderInfo.CustomAttributes.HeaderFile = 'Header_Define.h'; %头文件
%     Parameter_test.CoderInfo.CustomAttributes.DefinitionFile = 'Header_Define.c'; %源文件
%     Parameter_test.CoderInfo.CustomAttributes.Owner = 'LuoJiayi'; %Owner

%创建EnumTypeDefinition对象
    BrakeState=Simulink.data.dictionary.EnumTypeDefinition;    
    appendEnumeral(BrakeState,'Invalid',0,'BrakeStateInvalid')
    appendEnumeral(BrakeState,'Valid',1,'BrakeStateValid')
    appendEnumeral(BrakeState,'Unknow',2,'BrakeStateUnknow')
    removeEnumeral(BrakeState,1)
    BrakeState.Description = 'This is Vehicle Brake State.';
    BrakeState.DefaultValue = 'Invalid';
    BrakeState.HeaderFile = 'Header_Define.h';
    BrakeState.DataScope= 'Exported';
    
%创建数据字典并加入Signal1对象
    dictionaryObj = Simulink.data.dictionary.create('demo1.sldd');
    sectionObj = getSection(dictionaryObj,'Design Data');
    addEntry(sectionObj,'Signal1',Signal_test);
    addEntry(sectionObj,'Signal2',Parameter_test);
    addEntry(sectionObj,'Signal3',BrakeState);
end
