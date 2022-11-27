/*************************/




 HOBOT_SSM::LocalRoad* local_road = NULL;
  //TODO 定义一个空指针：当空指针没有在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。
  //赋为 NULL 值的指针被称为空指针。NULL指针是一个定义在标准库中的值为零的常量。
  //空指针不是什么都没干，是给了个NULL

  if (enable_ssm_) {
    // use ssm road from ssm msg
    // ssm_msg->road_data_v2
    std::shared_ptr<SsmMsgV2> ssm_msg = GetSsmMsg();
    //获得ssm_msg

    if (ssm_msg) {
      local_road = &ssm_msg->road_data_v2;
    }
  }
  static HOBOT_NOA::Road road;  // NOTE use local road instead
  ///////////////////////////////////////////////////////////////
  bool enable_playback_counter = (enable_playback_ && counter % 5 == 0);
  if (!enable_playback_ || enable_playback_counter) {
    TimeStamp ssm_start_ts = GetTimeStamp();
    float ssm_cost = static_cast<float>(GetTimeStamp() - ssm_start_ts);
    int64_t diff = GetTimeStamp() - start_ts;
    forward_info.extend.push_back(
        RuntimeInfo::ExtendInfo("ssm_cost", ssm_cost));
    // ssm_status = ssm_generator_->GenerateRoad(time_now, &road, forward_info);
    int64_t beg_ts = GetTimeStamp();
    if (local_road) {
      traj_ = planner_->Run(time_now, *local_road, forward_info);
      //TODO 这个位置的Local_road为什么要加*？？？？
      if (traj_.trajectory.empty()) {
        traj_ = planner_->CalRefaccForNoneTrafficLine(*local_road);
      }
      VLOG(1) << "traj_.trajectory.size(): " << traj_.trajectory.size()
              << std::endl;
      safety_monitor_->EmergencyStatusTrans(road, ssm_status, traj_, time_now);
      if (planner_->get_reset_set_speed_flag()) {
        // ssm_generator_->reset_speed_limit_to_road_speed(
        //     planner_->get_final_set_speed());
      }
    } else {
      traj_ = planner_->CalRefaccForNoneTrafficLine(*local_road);
      safety_monitor_->EmergencyStatusTrans(road, ssm_status, traj_, time_now);
    }