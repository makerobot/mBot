# Line following and obstacle avoidance with mBot

mBot comes with three built in functions:
- it can be driven through phone/tablet
- obstacle avoidance
- line following

We were invited to a math-camp to make presentation about our workshops in the local school (we have computer science unplugged and robotics workshops).
We decided to make live coding for (with) the kids in mblock (Scratch with makeblock extensions).

Our program combined the line following and the obstacle avoidance:
- if something is in front of the robot - avoid obstacle, else follow the line.

## Simple solution

The program for obstacle avoidance and line following had to be very simple.
![solution](https://github.com/makerobot/mBot/blob/master/followLineAndAvoidObstacle/img/followLine.png)

Line following:
- if both line follower sensors above black -> move forward
- if line follower sensors right on black, left on white -> turn right
- if line follower sensors right on white, left on black -> turn left
- if both line follower sensors above white -> move backward

Obstacle avoidance:
- turn left (approx 90 degrees)
- move in circle till black line is crossed

You can download the solution used in live coding here: [followLineAndAvoidObstacle](https://github.com/makerobot/mBot/blob/master/followLineAndAvoidObstacle/followLineAndAvoidObstacle.sb2)

Remarks: you need to upload the code to the mBot, in mBlock mode it will not work well (communication between mBot and mBlock takes time, it's not fast enough).

Of course, the movement of the mBot with this code is not that nice. (But we have used this solution during the live coding).

## Advanced solution

I have also implemented a better line follower algorithm.
In fact I have translated the built in line following program from Arduino to mBlock.
In this case mBot does not try to correct the path as soon as it losts the line with one sensor.
The movement is smoother than in previous solution.

![better line following solution](https://github.com/makerobot/mBot/blob/master/followLineAndAvoidObstacle/img/followLine2.png)

You can download the code here: [followLineAndAvoidObstacle](https://github.com/makerobot/mBot/blob/master/followLineAndAvoidObstacle/followLineAndAvoidObstacleAdvanced.sb2)











