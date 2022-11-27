/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_objects_binder.cc:205:46: error: 'PlanningParameters' has not been declared
                                              PlanningParameters* const params) {
                                              ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_objects_binder.cc:203:6: error: prototype for 'void HOBOT_NOA::SsmObjectsBinder::BindObjectsToLanePlus(HOBOT_NOA::Road*, HOBOT_NOA::Road*, int*)' does not match any in class 'HOBOT_NOA::SsmObjectsBinder'
 void SsmObjectsBinder::BindObjectsToLanePlus(Road* const road,
      ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_objects_binder.cc:9:0:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:40:8: error: candidate is: void HOBOT_NOA::SsmObjectsBinder::BindObjectsToLanePlus(HOBOT_NOA::Road*, HOBOT_NOA::Road*, HOBOT_NOA::planning_highway::PlanningParameters*)
   void BindObjectsToLanePlus(Road* const road, Road* const local_road,
        ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:790: ssm/src/CMakeFiles/ssm.dir/old_wrap/ssm_objects_binder.cc.o] Error 1
make[2]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/safety_monitor.cc:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:36:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:39:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params, bool rear_cam_fault);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:41:48: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                              planning_highway::PlanningParameters* const params);
                                                ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/safety_monitor.cc:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:118:61: error: expected ')' before '*' token
   explicit SsmGenerator(planning_highway::PlanningParameters* params);
                                                             ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h: In member function 'void HOBOT_NOA::SsmGenerator::insert_decision_result_buffer(const int&)':
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:193:26: error: 'class HOBOT_NOA::LaneSafetyChecker' has no member named 'insert_decision_result_buffer'
     lane_safety_checker_.insert_decision_result_buffer(last_decision_result);
                          ^
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:748: ssm/src/CMakeFiles/ssm.dir/old_wrap/safety_monitor.cc.o] Error 1
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:10:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:36:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:39:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params, bool rear_cam_fault);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:41:48: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                              planning_highway::PlanningParameters* const params);
                                                ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:10:0:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:118:61: error: expected ')' before '*' token
   explicit SsmGenerator(planning_highway::PlanningParameters* params);
                                                             ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h: In member function 'void HOBOT_NOA::SsmGenerator::insert_decision_result_buffer(const int&)':
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:193:26: error: 'class HOBOT_NOA::LaneSafetyChecker' has no member named 'insert_decision_result_buffer'
     lane_safety_checker_.insert_decision_result_buffer(last_decision_result);
                          ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc: At global scope:
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:39:1: error: prototype for 'HOBOT_NOA::SsmGenerator::SsmGenerator(HOBOT_NOA::PlanningParameters*)' does not match any in class 'HOBOT_NOA::SsmGenerator'
 SsmGenerator::SsmGenerator(PlanningParameters* params)
 ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:10:0:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:106:7: error: candidates are: HOBOT_NOA::SsmGenerator::SsmGenerator(const HOBOT_NOA::SsmGenerator&)
 class SsmGenerator {
       ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:21:1: error:                 HOBOT_NOA::SsmGenerator::SsmGenerator()
 SsmGenerator::SsmGenerator()
 ^
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc: In member function 'HOBOT_NOA::SsmGenerator::StatusCode HOBOT_NOA::SsmGenerator::GenerateRoad(HOBOT_SSM::SSMInput*, const TimeStamp&, HOBOT_NOA::Road*, HOBOT_NOA::RuntimeInfo::ForwardInfo&)':
/home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:1239:57: error: no matching function for call to 'HOBOT_NOA::SsmObjectsBinder::BindObjectsToLane(HOBOT_NOA::Road* const&, HOBOT_NOA::Road*, HOBOT_NOA::PlanningParameters*&, bool&)'
                                           rear_cam_fault);
                                                         ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/src/old_wrap/ssm_generator.cc:10:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:34:8: note: candidate: void HOBOT_NOA::SsmObjectsBinder::BindObjectsToLane(HOBOT_NOA::Road*, HOBOT_NOA::Road*, HOBOT_NOA::ObjectFrame&, int*)
   void BindObjectsToLane(Road* const road, Road* const local_road,
        ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:34:8: note:   no known conversion for argument 3 from 'HOBOT_NOA::PlanningParameters*' to 'HOBOT_NOA::ObjectFrame&'
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:38:8: note: candidate: void HOBOT_NOA::SsmObjectsBinder::BindObjectsToLane(HOBOT_NOA::Road*, HOBOT_NOA::Road*, int*, bool)
   void BindObjectsToLane(Road* const road, Road* const local_road,
        ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:38:8: note:   no known conversion for argument 3 from 'HOBOT_NOA::PlanningParameters*' to 'int*'
make[2]: *** [ssm/src/CMakeFiles/ssm.dir/build.make:776: ssm/src/CMakeFiles/ssm.dir/old_wrap/ssm_generator.cc.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:517: ssm/src/CMakeFiles/ssm.dir/all] Error 2
make[1]: *** Waiting for unfinished jobs....
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
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/planning_module/noa_planning_module.h:26,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/state_manager_module/state_manager_module.cpp:19:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:397:3: error: 'PlanningParameters' does not name a type
   PlanningParameters* params_;
   ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h: In member function 'void HOBOT_NOA::SsmGenerator::insert_decision_result_buffer(const int&)':
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:193:26: error: 'class HOBOT_NOA::LaneSafetyChecker' has no member named 'insert_decision_result_buffer'
     lane_safety_checker_.insert_decision_result_buffer(last_decision_result);
                          ^
make[2]: *** [hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/build.make:1420: hobot-ad-framework/src/CMakeFiles/hobot-ad-framework.dir/hobot-ad/modules/state_manager_module/state_manager_module.cpp.o] Error 1
make[2]: *** Waiting for unfinished jobs....
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:20:0,
                 from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/ssm_module/ssm_module.h:22,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.h:14,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:36:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:39:44: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                          planning_highway::PlanningParameters* const params, bool rear_cam_fault);
                                            ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_objects_binder.h:41:48: error: 'HOBOT_NOA::planning_highway::PlanningParameters' has not been declared
                              planning_highway::PlanningParameters* const params);
                                                ^
In file included from /home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/safety_monitor.h:12:0,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/include/hobot-ad/modules/ssm_module/ssm_module.h:22,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.h:14,
                 from /home/lei01.zhu/Code/SD/noa/hobot-ad-framework/src/hobot-ad/modules/ssm_module/halo_command.cpp:9:
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:118:61: error: expected ')' before '*' token
   explicit SsmGenerator(planning_highway::PlanningParameters* params);
                                                             ^
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h: In member function 'void HOBOT_NOA::SsmGenerator::insert_decision_result_buffer(const int&)':
/home/lei01.zhu/Code/SD/noa/ssm/include/ssm/old_wrap/ssm_generator.h:193:26: error: 'class HOBOT_NOA::LaneSafetyChecker' has no member named 'insert_decision_result_buffer'
     lane_safety_checker_.insert_decision_result_buffer(last_decision_result);
                          ^