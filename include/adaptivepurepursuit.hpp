#pragma once

#include "path/path.hpp"
#include "okapi/api.hpp"
#include "odometry.hpp"

namespace pathfollowing
{
class AdaptivePurePursuit
{
private:
  std::unique_ptr<okapi::IterativePosPIDController> straightController;
  std::unique_ptr<okapi::IterativePosPIDController> turnController;
  int mainLookahead;
  int lookahead;
  double lookaheadKf;
  path::Path *path;
  path::Point target;
  int direction;
  okapi::QAngle angleTarget;

public:
  AdaptivePurePursuit(
      std::unique_ptr<okapi::IterativePosPIDController> straight,
      std::unique_ptr<okapi::IterativePosPIDController> turn,
      int lookahead, double lookaheadKf);

  void setPath(path::Path *path);

  void setLookahead(int lookahead);

  void loop();

  path::Point getPointTarget();

  bool isSettled();

  void setKf(double kf);

  void setStraightGains(double kP = -1, double kI = -1, double kD = -1);

  void setTurnGains(double kP = -1, double kI = -1, double kD = -1);
};
} // namespace pathfollowing
