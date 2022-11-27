/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc: In member function 'void HOBOT_NOA::LaneSafetyChecker::Check(HOBOT_NOA::Road*, const string&, const HOBOT_NOA::planning_highway::PlanningParameters&)':
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:184:31: error: expected primary-expression before '.' token
           if (planning_highway.params.calib_state_mode() == 0) //改成命名空间
           {
                               ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:186:22: error: 'params' is not a member of 'HOBOT_NOA::planning_highway'
           } else if (planning_highway::params.calib_state_mode() == 1) {
                      ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:189:22: error: 'params' is not a member of 'HOBOT_NOA::planning_highway'
           } else if (planning_highway::params.calib_state_mode() == 2) {
                      ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:267:15: error: 'params' is not a member of 'HOBOT_NOA::planning_highway::PlanningParameters'
           if (planning_highway::PlanningParameters::params.calib_state_mode() == 0) {
               ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:269:22: error: 'params' is not a member of 'HOBOT_NOA::planning_highway::PlanningParameters'
           } else if (planning_highway::PlanningParameters::params.calib_state_mode() == 1) {
                      ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/lane_safety_checker.cc:272:22: error: 'params' is not a member of 'HOBOT_NOA::planning_highway::PlanningParameters'
           } else if (planning_highway::PlanningParameters::params.calib_state_mode() == 2) {
                      ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:398: ssm/src/CMakeFiles/ssm.dir/old_wrap/lane_safety_checker.cc.o] Error 1
make[2]: *** Waiting for unfinished jobs....
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_objects_binder.cc: In member function 'void HOBOT_NOA::SsmObjectsBinder::BindObjectsToLanePlus(HOBOT_NOA::Road*, HOBOT_NOA::Road*, HOBOT_NOA::planning_highway::PlanningParameters*)':
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_objects_binder.cc:209:22: error: 'params' is not a member of 'HOBOT_NOA::planning_highway'
                      planning_highway:: params);
                      ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:790: ssm/src/CMakeFiles/ssm.dir/old_wrap/ssm_objects_binder.cc.o] Error 1
/home/lei01.zhu/Code/SD/noa/ssm/src/refactor/object_process/obstacle_bind.cc: In member function 'void HOBOT_SSM::ObstacleBinder::JudgeInfrontOfEgo(HOBOT_SSM::LocalRoad&, HOBOT_NOA::Object&, HOBOT_NOA::planning_highway::PlanningParameters*)':
/home/lei01.zhu/Code/SD/noa/ssm/src/refactor/object_process/obstacle_bind.cc:95:24: error: 'planning_highway' has not been declared
   host_ref_line.XYToSL(planning_highway::params->front_edge_to_center(), 0.0f, NULL, &s_ego,
                        ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:930: ssm/src/CMakeFiles/ssm.dir/refactor/object_process/obstacle_bind.cc.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:32:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_decider.h:132:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:22:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:36:29: error: 'PlanningParameters' does not name a type
   TrajectoryEvaluator(const PlanningParameters& params,
                             ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:165:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:23:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_fusion_sampler.h:146:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:24:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_stitcher.h:63:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:21:0,
                 from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:36:32: error: 'PlanningParameters' does not name a type
   explicit TrajectoryMPC(const PlanningParameters& params,
                                ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:50:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:33:34: error: 'PlanningParameters' does not name a type
   TrajectoryIteraOptimazer(const PlanningParameters& params,
                                  ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:58:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:116:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& GetPlanningParams() const {
         ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:129:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1336: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/sd_planning_module/sd_planning_module.cpp.o] Error 1
make[2]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:0:
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:118:3: error: 'planning_highwy' does not name a type
   planning_highwy::Planner* planner_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1420: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/state_manager_module/state_manager_module.cpp.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:9:0:
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:118:3: error: 'planning_highwy' does not name a type
   planning_highwy::Planner* planner_;
   ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp: In destructor 'virtual HOBOT_NOA::NoaPlanningModule::~NoaPlanningModule()':
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:44:8: error: 'planner_' was not declared in this scope
     if(planner_) {
        ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:45:14: error: type '<type error>' argument given to 'delete', expected pointer
       delete planner_;
              ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp: In member function 'virtual int HOBOT_NOA::NoaPlanningModule::ADModuleInit(hobot::RunContext*)':
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:103:5: error: 'planner_' was not declared in this scope
     planner_ = new Planner(json_config_path);
     ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:103:20: error: expected type-specifier before 'Planner'
     planner_ = new Planner(json_config_path);
                    ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp: In member function 'void HOBOT_NOA::NoaPlanningModule::ForwardFW_PLANNING(const MessageLists&, hobot::Workflow*, hobot::spRunContext)':
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:157:15: error: 'planner_' was not declared in this scope
       traj_ = planner_->Run(time_now, road);
               ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:172:15: error: 'planner_' was not declared in this scope
       traj_ = planner_->CalRefaccForNoneTrafficLine(road);
               ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:292:35: error: 'planner_' was not declared in this scope
         traj_debug_msg->set_proto(planner_->planning_debug_message());
                                   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1322: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/planning_module/noa_planning_module.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:517: ssm/src/CMakeFiles/ssm.dir/all] Error 2
make[1]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h:18:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/ssm_module.cpp:28:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:38:51: error: 'PlanningParameters' does not name a type
   Trajectory Run(const TimeStamp &time_now, const PlanningParameters &params,
                                                   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:47:31: error: 'PlanningParameters' does not name a type
                         const PlanningParameters &params,
                               ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:50:45: error: 'PlanningParameters' does not name a type
   float CalPreviewS(const Road &road, const PlanningParameters &params,
                                             ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:53:23: error: 'PlanningParameters' does not name a type
                 const PlanningParameters &params, const int &target_lane_index);
                       ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:59:24: error: 'PlanningParameters' does not name a type
   void SetWeight(const PlanningParameters &params, const Trajectory &path,
                        ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:62:27: error: 'PlanningParameters' does not name a type
   void SetStartEndS(const PlanningParameters &params);
                           ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:63:38: error: 'PlanningParameters' does not name a type
   void CalBoundaryAndReference(const PlanningParameters &params,
                                      ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:65:39: error: 'PlanningParameters' does not name a type
   void CalLBoundaryAndReference(const PlanningParameters &params,
                                       ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:67:35: error: 'PlanningParameters' does not name a type
   void CalLBoundaryFromLane(const PlanningParameters &params, const Road &road,
                                   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:70:42: error: 'PlanningParameters' does not name a type
   void GetBoundaryFromStaticObject(const PlanningParameters &params,
                                          ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:73:26: error: 'PlanningParameters' does not name a type
   SortStaticObject(const PlanningParameters &params, const Road &road,
                          ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:77:36: error: 'PlanningParameters' does not name a type
   float CalLReferenceFromILC(const PlanningParameters &params, const Road &road,
                                    ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:79:45: error: 'PlanningParameters' does not name a type
   float CalLReferenceFromStaticObject(const PlanningParameters &params,
                                             ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/path_generator.h:104:32: error: 'PlanningParameters' does not name a type
   void BackupPathQuintic(const PlanningParameters &params, Trajectory &path);
                                ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/ssm_module.cpp:28:0:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h:38:3: error: 'PlanningParameters' does not name a type
   PlanningParameters* get_params() {return &params;}
   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h:67:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params;
   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h: In member function 'const string& HOBOT_NOA::Planner::getSensorConfig() const':
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h:36:54: error: 'params' was not declared in this scope
   const std::string& getSensorConfig() const {return params.sensor_config();}
                                                      ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h: In member function 'const bool& HOBOT_NOA::Planner::getRadarFusionConfig() const':
/home/lei01.zhu/Code/SD/noa/planning/include/planning/planner.h:37:52: error: 'params' was not declared in this scope
   const bool& getRadarFusionConfig() const {return params.enable_radar_fusion();}
                                                    ^
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/ssm_module.cpp: In member function 'virtual int HOBOT_NOA::SSMModule::ADModuleInit(hobot::RunContext*)':
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/ssm_module.cpp:117:61: error: 'class HOBOT_NOA::Planner' has no member named 'get_params'
   old_ssm_generator_ = new HOBOT_NOA::SsmGenerator(planner->get_params());
                                                             ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1378: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/ssm_module/ssm_module.cpp.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:30:0:
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:118:3: error: 'planning_highwy' does not name a type
   planning_highwy::Planner* planner_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:32:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_decider.h:132:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_decider.h:134:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:22:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:36:29: error: 'PlanningParameters' does not name a type
   TrajectoryEvaluator(const PlanningParameters& params,
                             ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:165:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:170:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:23:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_fusion_sampler.h:146:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:24:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_stitcher.h:63:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:21:0,
                 from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:36:32: error: 'PlanningParameters' does not name a type
   explicit TrajectoryMPC(const PlanningParameters& params,
                                ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:37:32: error: 'VehicleStateLimit' does not name a type
                          const VehicleStateLimit& vehicle_state_limit);
                                ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:50:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:51:9: error: 'VehicleStateLimit' does not name a type
   const VehicleStateLimit& vehicle_state_limit_;
         ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:33:34: error: 'PlanningParameters' does not name a type
   TrajectoryIteraOptimazer(const PlanningParameters& params,
                                  ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:58:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& params_;
         ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:63:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:116:9: error: 'PlanningParameters' does not name a type
   const PlanningParameters& GetPlanningParams() const {
         ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:129:3: error: 'PlanningParameters' does not name a type
   PlanningParameters params_;
   ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:130:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/grid_map_process/grid_map_process.h:37:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/road_generate/road_generate.h:17,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/ssm_module/ssm_module.h:25,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:32:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_sampler.h:91:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1504: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/workflow/hobot_ad_workflow.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:543: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/all] Error 2
make: *** [Makefile:136: all] Error 2