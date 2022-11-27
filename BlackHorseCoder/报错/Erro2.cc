In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/safety_monitor.cc:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:748: ssm/src/CMakeFiles/ssm.dir/old_wrap/safety_monitor.cc.o] Error 1
make[2]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:10:0:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:39:27: error: expected constructor, destructor, or type conversion before '(' token
 SsmGenerator::SsmGenerator(planning_highway::PlanningParameters* params)
                           ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc: In member function 'HOBOT_NOA::SsmGenerator::StatusCode HOBOT_NOA::SsmGenerator::GenerateRoad(HOBOT_SSM::SSMInput*, const TimeStamp&, HOBOT_NOA::Road*, HOBOT_NOA::RuntimeInfo::ForwardInfo&)':
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:1274:3: error: 'lane_efficiency_checker_' was not declared in this scope
   lane_efficiency_checker_.Run(
   ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:776: ssm/src/CMakeFiles/ssm.dir/old_wrap/ssm_generator.cc.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:517: ssm/src/CMakeFiles/ssm.dir/all] Error 2
make[1]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/ssm_module/ssm_module.h:22,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.h:14,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1364: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/ssm_module/halo_command.cpp.o] Error 1
make[2]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:15:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/lane_safety_checker.h:22:20: error: 'PlanningParameters' does not name a type
              const PlanningParameters& params);
                    ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ndm_ssm_road_generator.h:36:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:18,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/road_generate/road_input.h:168:14: error: 'PlanningParameters' in namespace 'HOBOT_NOA' does not name a type
   HOBOT_NOA::PlanningParameters* GetPlanningParams() {
              ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/road_generate/road_input.h:323:14: error: 'PlanningParameters' in namespace 'HOBOT_NOA' does not name a type
   HOBOT_NOA::PlanningParameters planning_params_;
              ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:36:26: error: 'PlanningParameters' has not been declared
                          PlanningParameters* const params);
                          ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:39:26: error: 'PlanningParameters' has not been declared
                          PlanningParameters* const params, bool rear_cam_fault);
                          ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:41:30: error: 'PlanningParameters' has not been declared
                              PlanningParameters* const params);
                              ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:118:43: error: expected ')' before '*' token
   explicit SsmGenerator(PlanningParameters* params);
                                           ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:397:3: error: 'PlanningParameters' does not name a type
   PlanningParameters* params_;
   ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:0:
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:118:3: error: 'planning_highwy' does not name a type
   planning_highwy::Planner* planner_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1420: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/state_manager_module/state_manager_module.cpp.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:15:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/lane_safety_checker.h:22:20: error: 'PlanningParameters' does not name a type
              const PlanningParameters& params);
                    ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ndm_ssm_road_generator.h:36:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:18,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/road_generate/road_input.h:168:14: error: 'PlanningParameters' in namespace 'HOBOT_NOA' does not name a type
   HOBOT_NOA::PlanningParameters* GetPlanningParams() {
              ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/refactor/road_generate/road_input.h:323:14: error: 'PlanningParameters' in namespace 'HOBOT_NOA' does not name a type
   HOBOT_NOA::PlanningParameters planning_params_;
              ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:36:26: error: 'PlanningParameters' has not been declared
                          PlanningParameters* const params);
                          ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:39:26: error: 'PlanningParameters' has not been declared
                          PlanningParameters* const params, bool rear_cam_fault);
                          ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:41:30: error: 'PlanningParameters' has not been declared
                              PlanningParameters* const params);
                              ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/planning_module/noa_planning_module.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:118:43: error: expected ')' before '*' token
   explicit SsmGenerator(PlanningParameters* params);
                                           ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:397:3: error: 'PlanningParameters' does not name a type
   PlanningParameters* params_;
   ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
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
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/ssm_module/ssm_module.h:22,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/ssm_module.cpp:10:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1378: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/ssm_module/ssm_module.cpp.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:30:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:403:3: error: 'LaneEfficiencyChecker' does not name a type
   LaneEfficiencyChecker lane_efficiency_checker_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:30:0:
/home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:118:3: error: 'planning_highwy' does not name a type
   planning_highwy::Planner* planner_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:32:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_decider.h:134:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:22:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_evaluator.h:170:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:21:0,
                 from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:37:32: error: 'VehicleStateLimit' does not name a type
                          const VehicleStateLimit& vehicle_state_limit);
                                ^
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_mpc.h:51:9: error: 'VehicleStateLimit' does not name a type
   const VehicleStateLimit& vehicle_state_limit_;
         ^
In file included from /home/lei01.zhu/Code/SD/noa/planning/include/planning/sd_planner.h:28:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
/home/lei01.zhu/Code/SD/noa/planning/include/planning/trajectory_itera_optimazer.h:63:3: error: 'VehicleStateLimit' does not name a type
   VehicleStateLimit vehicle_state_limit_;
   ^
In file included from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/sd_planning_module/sd_planning_module.h:33:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/workflow/hobot_ad_workflow.cpp:31:
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