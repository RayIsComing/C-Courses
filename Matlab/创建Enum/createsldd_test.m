function createsldd_test()
%����Simulink.Signal����
    Signal_test = Simulink.Signal;
    Signal_test.DataType = 'uint8'; %����
    Signal_test.InitialValue = '0'; %��ʼֵ
    Signal_test.StorageClass = 'ExportedGlobal'; %�洢��ʽ
    Signal_test.Dimensions = 1; %ά��
%     Signal_test.CoderInfo.CustomAttributes.HeaderFile = 'Header_Define.h'; %ͷ�ļ�
%     Signal_test.CoderInfo.CustomAttributes.DefinitionFile = 'Header_Define.c'; %Դ�ļ�
%     Signal_test.CoderInfo.CustomAttributes.Owner = 'LuoJiayi'; %Owner

%����Simulink.Parameter����
    Parameter_test = Simulink.Parameter;
    Parameter_test.DataType = 'uint8'; %����
    Parameter_test.Value = (10); %��ʼֵ
    Parameter_test.StorageClass = 'Define (Custom)'; %�洢��ʽ
    Parameter_test.Dimensions = [1 1]; %ά��
    Parameter_test.CoderInfo.CustomAttributes.HeaderFile = 'Header_Define.h'; %ͷ�ļ�
%     Parameter_test.CoderInfo.CustomAttributes.DefinitionFile = 'Header_Define.c'; %Դ�ļ�
%     Parameter_test.CoderInfo.CustomAttributes.Owner = 'LuoJiayi'; %Owner

%����EnumTypeDefinition����
    BrakeState=Simulink.data.dictionary.EnumTypeDefinition;    
    appendEnumeral(BrakeState,'Invalid',0,'BrakeStateInvalid')
    appendEnumeral(BrakeState,'Valid',1,'BrakeStateValid')
    appendEnumeral(BrakeState,'Unknow',2,'BrakeStateUnknow')
    removeEnumeral(BrakeState,1)
    BrakeState.Description = 'This is Vehicle Brake State.';
    BrakeState.DefaultValue = 'Invalid';
    BrakeState.HeaderFile = 'Header_Define.h';
    BrakeState.DataScope= 'Exported';
    
%���������ֵ䲢����Signal1����
    dictionaryObj = Simulink.data.dictionary.create('demo1.sldd');
    sectionObj = getSection(dictionaryObj,'Design Data');
    addEntry(sectionObj,'Signal1',Signal_test);
    addEntry(sectionObj,'Signal2',Parameter_test);
    addEntry(sectionObj,'Signal3',BrakeState);
end
