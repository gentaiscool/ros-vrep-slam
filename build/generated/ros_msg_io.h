#ifndef VREP_ROS_PLUGIN__ROS_MSG_IO__H
#define VREP_ROS_PLUGIN__ROS_MSG_IO__H

#include <ros_msg_builtin_io.h>
#include <vrep_ros_interface.h>

#include <control_msgs/JointControllerState.h>
#include <control_msgs/JointTolerance.h>
#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>
#include <dynamic_reconfigure/BoolParameter.h>
#include <dynamic_reconfigure/Config.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/DoubleParameter.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/GroupState.h>
#include <dynamic_reconfigure/IntParameter.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/SensorLevels.h>
#include <dynamic_reconfigure/StrParameter.h>
#include <gazebo_msgs/ContactState.h>
#include <gazebo_msgs/ContactsState.h>
#include <gazebo_msgs/LinkState.h>
#include <gazebo_msgs/LinkStates.h>
#include <gazebo_msgs/ModelState.h>
#include <gazebo_msgs/ModelStates.h>
#include <gazebo_msgs/ODEJointProperties.h>
#include <gazebo_msgs/ODEPhysics.h>
#include <gazebo_msgs/WorldState.h>
#include <geometry_msgs/Accel.h>
#include <geometry_msgs/AccelStamped.h>
#include <geometry_msgs/AccelWithCovariance.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>
#include <geometry_msgs/Inertia.h>
#include <geometry_msgs/InertiaStamped.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point32.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/PolygonStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/TwistWithCovariance.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Wrench.h>
#include <geometry_msgs/WrenchStamped.h>
#include <map_msgs/OccupancyGridUpdate.h>
#include <map_msgs/PointCloud2Update.h>
#include <map_msgs/ProjectedMap.h>
#include <map_msgs/ProjectedMapInfo.h>
#include <nav_msgs/GridCells.h>
#include <nav_msgs/MapMetaData.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <roscpp/Logger.h>
#include <rosgraph_msgs/Clock.h>
#include <rosgraph_msgs/Log.h>
#include <rosgraph_msgs/TopicStatistics.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/ChannelFloat32.h>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/FluidPressure.h>
#include <sensor_msgs/Illuminance.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedback.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <sensor_msgs/LaserEcho.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/MagneticField.h>
#include <sensor_msgs/MultiDOFJointState.h>
#include <sensor_msgs/MultiEchoLaserScan.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointField.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/RegionOfInterest.h>
#include <sensor_msgs/RelativeHumidity.h>
#include <sensor_msgs/Temperature.h>
#include <sensor_msgs/TimeReference.h>
#include <shape_msgs/Mesh.h>
#include <shape_msgs/MeshTriangle.h>
#include <shape_msgs/Plane.h>
#include <shape_msgs/SolidPrimitive.h>
#include <smach_msgs/SmachContainerInitialStatusCmd.h>
#include <smach_msgs/SmachContainerStatus.h>
#include <smach_msgs/SmachContainerStructure.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Byte.h>
#include <std_msgs/ByteMultiArray.h>
#include <std_msgs/Char.h>
#include <std_msgs/ColorRGBA.h>
#include <std_msgs/Duration.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int64MultiArray.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/String.h>
#include <std_msgs/Time.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/UInt32MultiArray.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/UInt64MultiArray.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt8MultiArray.h>
#include <tf/tfMessage.h>
#include <tf2_msgs/TF2Error.h>
#include <tf2_msgs/TFMessage.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>
#include <trajectory_msgs/MultiDOFJointTrajectoryPoint.h>
#include <visualization_msgs/ImageMarker.h>
#include <visualization_msgs/InteractiveMarker.h>
#include <visualization_msgs/InteractiveMarkerControl.h>
#include <visualization_msgs/InteractiveMarkerFeedback.h>
#include <visualization_msgs/InteractiveMarkerInit.h>
#include <visualization_msgs/InteractiveMarkerPose.h>
#include <visualization_msgs/InteractiveMarkerUpdate.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/MenuEntry.h>


void write__control_msgs__JointControllerState(const control_msgs::JointControllerState& msg, int stack, const WriteOptions *opt = NULL);

void read__control_msgs__JointControllerState(int stack, control_msgs::JointControllerState *msg, const ReadOptions *opt = NULL);

void ros_callback__control_msgs__JointControllerState(const boost::shared_ptr<control_msgs::JointControllerState const>& msg, SubscriberProxy *proxy);

void write__control_msgs__JointTolerance(const control_msgs::JointTolerance& msg, int stack, const WriteOptions *opt = NULL);

void read__control_msgs__JointTolerance(int stack, control_msgs::JointTolerance *msg, const ReadOptions *opt = NULL);

void ros_callback__control_msgs__JointTolerance(const boost::shared_ptr<control_msgs::JointTolerance const>& msg, SubscriberProxy *proxy);

void write__diagnostic_msgs__DiagnosticArray(const diagnostic_msgs::DiagnosticArray& msg, int stack, const WriteOptions *opt = NULL);

void read__diagnostic_msgs__DiagnosticArray(int stack, diagnostic_msgs::DiagnosticArray *msg, const ReadOptions *opt = NULL);

void ros_callback__diagnostic_msgs__DiagnosticArray(const boost::shared_ptr<diagnostic_msgs::DiagnosticArray const>& msg, SubscriberProxy *proxy);

void write__diagnostic_msgs__DiagnosticStatus(const diagnostic_msgs::DiagnosticStatus& msg, int stack, const WriteOptions *opt = NULL);

void read__diagnostic_msgs__DiagnosticStatus(int stack, diagnostic_msgs::DiagnosticStatus *msg, const ReadOptions *opt = NULL);

void ros_callback__diagnostic_msgs__DiagnosticStatus(const boost::shared_ptr<diagnostic_msgs::DiagnosticStatus const>& msg, SubscriberProxy *proxy);

void write__diagnostic_msgs__KeyValue(const diagnostic_msgs::KeyValue& msg, int stack, const WriteOptions *opt = NULL);

void read__diagnostic_msgs__KeyValue(int stack, diagnostic_msgs::KeyValue *msg, const ReadOptions *opt = NULL);

void ros_callback__diagnostic_msgs__KeyValue(const boost::shared_ptr<diagnostic_msgs::KeyValue const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__BoolParameter(const dynamic_reconfigure::BoolParameter& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__BoolParameter(int stack, dynamic_reconfigure::BoolParameter *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__BoolParameter(const boost::shared_ptr<dynamic_reconfigure::BoolParameter const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__Config(const dynamic_reconfigure::Config& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__Config(int stack, dynamic_reconfigure::Config *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__Config(const boost::shared_ptr<dynamic_reconfigure::Config const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__ConfigDescription(const dynamic_reconfigure::ConfigDescription& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__ConfigDescription(int stack, dynamic_reconfigure::ConfigDescription *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__ConfigDescription(const boost::shared_ptr<dynamic_reconfigure::ConfigDescription const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__DoubleParameter(const dynamic_reconfigure::DoubleParameter& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__DoubleParameter(int stack, dynamic_reconfigure::DoubleParameter *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__DoubleParameter(const boost::shared_ptr<dynamic_reconfigure::DoubleParameter const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__Group(const dynamic_reconfigure::Group& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__Group(int stack, dynamic_reconfigure::Group *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__Group(const boost::shared_ptr<dynamic_reconfigure::Group const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__GroupState(const dynamic_reconfigure::GroupState& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__GroupState(int stack, dynamic_reconfigure::GroupState *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__GroupState(const boost::shared_ptr<dynamic_reconfigure::GroupState const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__IntParameter(const dynamic_reconfigure::IntParameter& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__IntParameter(int stack, dynamic_reconfigure::IntParameter *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__IntParameter(const boost::shared_ptr<dynamic_reconfigure::IntParameter const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__ParamDescription(const dynamic_reconfigure::ParamDescription& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__ParamDescription(int stack, dynamic_reconfigure::ParamDescription *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__ParamDescription(const boost::shared_ptr<dynamic_reconfigure::ParamDescription const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__SensorLevels(const dynamic_reconfigure::SensorLevels& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__SensorLevels(int stack, dynamic_reconfigure::SensorLevels *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__SensorLevels(const boost::shared_ptr<dynamic_reconfigure::SensorLevels const>& msg, SubscriberProxy *proxy);

void write__dynamic_reconfigure__StrParameter(const dynamic_reconfigure::StrParameter& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__StrParameter(int stack, dynamic_reconfigure::StrParameter *msg, const ReadOptions *opt = NULL);

void ros_callback__dynamic_reconfigure__StrParameter(const boost::shared_ptr<dynamic_reconfigure::StrParameter const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ContactState(const gazebo_msgs::ContactState& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ContactState(int stack, gazebo_msgs::ContactState *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ContactState(const boost::shared_ptr<gazebo_msgs::ContactState const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ContactsState(const gazebo_msgs::ContactsState& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ContactsState(int stack, gazebo_msgs::ContactsState *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ContactsState(const boost::shared_ptr<gazebo_msgs::ContactsState const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__LinkState(const gazebo_msgs::LinkState& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__LinkState(int stack, gazebo_msgs::LinkState *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__LinkState(const boost::shared_ptr<gazebo_msgs::LinkState const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__LinkStates(const gazebo_msgs::LinkStates& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__LinkStates(int stack, gazebo_msgs::LinkStates *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__LinkStates(const boost::shared_ptr<gazebo_msgs::LinkStates const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ModelState(const gazebo_msgs::ModelState& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ModelState(int stack, gazebo_msgs::ModelState *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ModelState(const boost::shared_ptr<gazebo_msgs::ModelState const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ModelStates(const gazebo_msgs::ModelStates& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ModelStates(int stack, gazebo_msgs::ModelStates *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ModelStates(const boost::shared_ptr<gazebo_msgs::ModelStates const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ODEJointProperties(const gazebo_msgs::ODEJointProperties& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ODEJointProperties(int stack, gazebo_msgs::ODEJointProperties *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ODEJointProperties(const boost::shared_ptr<gazebo_msgs::ODEJointProperties const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__ODEPhysics(const gazebo_msgs::ODEPhysics& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__ODEPhysics(int stack, gazebo_msgs::ODEPhysics *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__ODEPhysics(const boost::shared_ptr<gazebo_msgs::ODEPhysics const>& msg, SubscriberProxy *proxy);

void write__gazebo_msgs__WorldState(const gazebo_msgs::WorldState& msg, int stack, const WriteOptions *opt = NULL);

void read__gazebo_msgs__WorldState(int stack, gazebo_msgs::WorldState *msg, const ReadOptions *opt = NULL);

void ros_callback__gazebo_msgs__WorldState(const boost::shared_ptr<gazebo_msgs::WorldState const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Accel(const geometry_msgs::Accel& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Accel(int stack, geometry_msgs::Accel *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Accel(const boost::shared_ptr<geometry_msgs::Accel const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__AccelStamped(const geometry_msgs::AccelStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__AccelStamped(int stack, geometry_msgs::AccelStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__AccelStamped(const boost::shared_ptr<geometry_msgs::AccelStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__AccelWithCovariance(const geometry_msgs::AccelWithCovariance& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__AccelWithCovariance(int stack, geometry_msgs::AccelWithCovariance *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__AccelWithCovariance(const boost::shared_ptr<geometry_msgs::AccelWithCovariance const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__AccelWithCovarianceStamped(const geometry_msgs::AccelWithCovarianceStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__AccelWithCovarianceStamped(int stack, geometry_msgs::AccelWithCovarianceStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__AccelWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::AccelWithCovarianceStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Inertia(const geometry_msgs::Inertia& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Inertia(int stack, geometry_msgs::Inertia *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Inertia(const boost::shared_ptr<geometry_msgs::Inertia const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__InertiaStamped(const geometry_msgs::InertiaStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__InertiaStamped(int stack, geometry_msgs::InertiaStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__InertiaStamped(const boost::shared_ptr<geometry_msgs::InertiaStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Point(const geometry_msgs::Point& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Point(int stack, geometry_msgs::Point *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Point(const boost::shared_ptr<geometry_msgs::Point const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Point32(const geometry_msgs::Point32& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Point32(int stack, geometry_msgs::Point32 *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Point32(const boost::shared_ptr<geometry_msgs::Point32 const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PointStamped(const geometry_msgs::PointStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PointStamped(int stack, geometry_msgs::PointStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PointStamped(const boost::shared_ptr<geometry_msgs::PointStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Polygon(const geometry_msgs::Polygon& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Polygon(int stack, geometry_msgs::Polygon *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Polygon(const boost::shared_ptr<geometry_msgs::Polygon const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PolygonStamped(const geometry_msgs::PolygonStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PolygonStamped(int stack, geometry_msgs::PolygonStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PolygonStamped(const boost::shared_ptr<geometry_msgs::PolygonStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Pose(const geometry_msgs::Pose& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Pose(int stack, geometry_msgs::Pose *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Pose(const boost::shared_ptr<geometry_msgs::Pose const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Pose2D(const geometry_msgs::Pose2D& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Pose2D(int stack, geometry_msgs::Pose2D *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Pose2D(const boost::shared_ptr<geometry_msgs::Pose2D const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PoseArray(const geometry_msgs::PoseArray& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PoseArray(int stack, geometry_msgs::PoseArray *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PoseArray(const boost::shared_ptr<geometry_msgs::PoseArray const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PoseStamped(const geometry_msgs::PoseStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PoseStamped(int stack, geometry_msgs::PoseStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PoseStamped(const boost::shared_ptr<geometry_msgs::PoseStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PoseWithCovariance(const geometry_msgs::PoseWithCovariance& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PoseWithCovariance(int stack, geometry_msgs::PoseWithCovariance *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PoseWithCovariance(const boost::shared_ptr<geometry_msgs::PoseWithCovariance const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__PoseWithCovarianceStamped(const geometry_msgs::PoseWithCovarianceStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__PoseWithCovarianceStamped(int stack, geometry_msgs::PoseWithCovarianceStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__PoseWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Quaternion(const geometry_msgs::Quaternion& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Quaternion(int stack, geometry_msgs::Quaternion *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Quaternion(const boost::shared_ptr<geometry_msgs::Quaternion const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__QuaternionStamped(const geometry_msgs::QuaternionStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__QuaternionStamped(int stack, geometry_msgs::QuaternionStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__QuaternionStamped(const boost::shared_ptr<geometry_msgs::QuaternionStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Transform(const geometry_msgs::Transform& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Transform(int stack, geometry_msgs::Transform *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Transform(const boost::shared_ptr<geometry_msgs::Transform const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__TransformStamped(const geometry_msgs::TransformStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__TransformStamped(int stack, geometry_msgs::TransformStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__TransformStamped(const boost::shared_ptr<geometry_msgs::TransformStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Twist(const geometry_msgs::Twist& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Twist(int stack, geometry_msgs::Twist *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Twist(const boost::shared_ptr<geometry_msgs::Twist const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__TwistStamped(const geometry_msgs::TwistStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__TwistStamped(int stack, geometry_msgs::TwistStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__TwistStamped(const boost::shared_ptr<geometry_msgs::TwistStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__TwistWithCovariance(const geometry_msgs::TwistWithCovariance& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__TwistWithCovariance(int stack, geometry_msgs::TwistWithCovariance *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__TwistWithCovariance(const boost::shared_ptr<geometry_msgs::TwistWithCovariance const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__TwistWithCovarianceStamped(const geometry_msgs::TwistWithCovarianceStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__TwistWithCovarianceStamped(int stack, geometry_msgs::TwistWithCovarianceStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__TwistWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::TwistWithCovarianceStamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Vector3(const geometry_msgs::Vector3& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Vector3(int stack, geometry_msgs::Vector3 *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Vector3(const boost::shared_ptr<geometry_msgs::Vector3 const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Vector3Stamped(const geometry_msgs::Vector3Stamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Vector3Stamped(int stack, geometry_msgs::Vector3Stamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Vector3Stamped(const boost::shared_ptr<geometry_msgs::Vector3Stamped const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__Wrench(const geometry_msgs::Wrench& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__Wrench(int stack, geometry_msgs::Wrench *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__Wrench(const boost::shared_ptr<geometry_msgs::Wrench const>& msg, SubscriberProxy *proxy);

void write__geometry_msgs__WrenchStamped(const geometry_msgs::WrenchStamped& msg, int stack, const WriteOptions *opt = NULL);

void read__geometry_msgs__WrenchStamped(int stack, geometry_msgs::WrenchStamped *msg, const ReadOptions *opt = NULL);

void ros_callback__geometry_msgs__WrenchStamped(const boost::shared_ptr<geometry_msgs::WrenchStamped const>& msg, SubscriberProxy *proxy);

void write__map_msgs__OccupancyGridUpdate(const map_msgs::OccupancyGridUpdate& msg, int stack, const WriteOptions *opt = NULL);

void read__map_msgs__OccupancyGridUpdate(int stack, map_msgs::OccupancyGridUpdate *msg, const ReadOptions *opt = NULL);

void ros_callback__map_msgs__OccupancyGridUpdate(const boost::shared_ptr<map_msgs::OccupancyGridUpdate const>& msg, SubscriberProxy *proxy);

void write__map_msgs__PointCloud2Update(const map_msgs::PointCloud2Update& msg, int stack, const WriteOptions *opt = NULL);

void read__map_msgs__PointCloud2Update(int stack, map_msgs::PointCloud2Update *msg, const ReadOptions *opt = NULL);

void ros_callback__map_msgs__PointCloud2Update(const boost::shared_ptr<map_msgs::PointCloud2Update const>& msg, SubscriberProxy *proxy);

void write__map_msgs__ProjectedMap(const map_msgs::ProjectedMap& msg, int stack, const WriteOptions *opt = NULL);

void read__map_msgs__ProjectedMap(int stack, map_msgs::ProjectedMap *msg, const ReadOptions *opt = NULL);

void ros_callback__map_msgs__ProjectedMap(const boost::shared_ptr<map_msgs::ProjectedMap const>& msg, SubscriberProxy *proxy);

void write__map_msgs__ProjectedMapInfo(const map_msgs::ProjectedMapInfo& msg, int stack, const WriteOptions *opt = NULL);

void read__map_msgs__ProjectedMapInfo(int stack, map_msgs::ProjectedMapInfo *msg, const ReadOptions *opt = NULL);

void ros_callback__map_msgs__ProjectedMapInfo(const boost::shared_ptr<map_msgs::ProjectedMapInfo const>& msg, SubscriberProxy *proxy);

void write__nav_msgs__GridCells(const nav_msgs::GridCells& msg, int stack, const WriteOptions *opt = NULL);

void read__nav_msgs__GridCells(int stack, nav_msgs::GridCells *msg, const ReadOptions *opt = NULL);

void ros_callback__nav_msgs__GridCells(const boost::shared_ptr<nav_msgs::GridCells const>& msg, SubscriberProxy *proxy);

void write__nav_msgs__MapMetaData(const nav_msgs::MapMetaData& msg, int stack, const WriteOptions *opt = NULL);

void read__nav_msgs__MapMetaData(int stack, nav_msgs::MapMetaData *msg, const ReadOptions *opt = NULL);

void ros_callback__nav_msgs__MapMetaData(const boost::shared_ptr<nav_msgs::MapMetaData const>& msg, SubscriberProxy *proxy);

void write__nav_msgs__OccupancyGrid(const nav_msgs::OccupancyGrid& msg, int stack, const WriteOptions *opt = NULL);

void read__nav_msgs__OccupancyGrid(int stack, nav_msgs::OccupancyGrid *msg, const ReadOptions *opt = NULL);

void ros_callback__nav_msgs__OccupancyGrid(const boost::shared_ptr<nav_msgs::OccupancyGrid const>& msg, SubscriberProxy *proxy);

void write__nav_msgs__Odometry(const nav_msgs::Odometry& msg, int stack, const WriteOptions *opt = NULL);

void read__nav_msgs__Odometry(int stack, nav_msgs::Odometry *msg, const ReadOptions *opt = NULL);

void ros_callback__nav_msgs__Odometry(const boost::shared_ptr<nav_msgs::Odometry const>& msg, SubscriberProxy *proxy);

void write__nav_msgs__Path(const nav_msgs::Path& msg, int stack, const WriteOptions *opt = NULL);

void read__nav_msgs__Path(int stack, nav_msgs::Path *msg, const ReadOptions *opt = NULL);

void ros_callback__nav_msgs__Path(const boost::shared_ptr<nav_msgs::Path const>& msg, SubscriberProxy *proxy);

void write__roscpp__Logger(const roscpp::Logger& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__Logger(int stack, roscpp::Logger *msg, const ReadOptions *opt = NULL);

void ros_callback__roscpp__Logger(const boost::shared_ptr<roscpp::Logger const>& msg, SubscriberProxy *proxy);

void write__rosgraph_msgs__Clock(const rosgraph_msgs::Clock& msg, int stack, const WriteOptions *opt = NULL);

void read__rosgraph_msgs__Clock(int stack, rosgraph_msgs::Clock *msg, const ReadOptions *opt = NULL);

void ros_callback__rosgraph_msgs__Clock(const boost::shared_ptr<rosgraph_msgs::Clock const>& msg, SubscriberProxy *proxy);

void write__rosgraph_msgs__Log(const rosgraph_msgs::Log& msg, int stack, const WriteOptions *opt = NULL);

void read__rosgraph_msgs__Log(int stack, rosgraph_msgs::Log *msg, const ReadOptions *opt = NULL);

void ros_callback__rosgraph_msgs__Log(const boost::shared_ptr<rosgraph_msgs::Log const>& msg, SubscriberProxy *proxy);

void write__rosgraph_msgs__TopicStatistics(const rosgraph_msgs::TopicStatistics& msg, int stack, const WriteOptions *opt = NULL);

void read__rosgraph_msgs__TopicStatistics(int stack, rosgraph_msgs::TopicStatistics *msg, const ReadOptions *opt = NULL);

void ros_callback__rosgraph_msgs__TopicStatistics(const boost::shared_ptr<rosgraph_msgs::TopicStatistics const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__CameraInfo(const sensor_msgs::CameraInfo& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__CameraInfo(int stack, sensor_msgs::CameraInfo *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__CameraInfo(const boost::shared_ptr<sensor_msgs::CameraInfo const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__ChannelFloat32(const sensor_msgs::ChannelFloat32& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__ChannelFloat32(int stack, sensor_msgs::ChannelFloat32 *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__ChannelFloat32(const boost::shared_ptr<sensor_msgs::ChannelFloat32 const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__CompressedImage(const sensor_msgs::CompressedImage& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__CompressedImage(int stack, sensor_msgs::CompressedImage *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__CompressedImage(const boost::shared_ptr<sensor_msgs::CompressedImage const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__FluidPressure(const sensor_msgs::FluidPressure& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__FluidPressure(int stack, sensor_msgs::FluidPressure *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__FluidPressure(const boost::shared_ptr<sensor_msgs::FluidPressure const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Illuminance(const sensor_msgs::Illuminance& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Illuminance(int stack, sensor_msgs::Illuminance *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Illuminance(const boost::shared_ptr<sensor_msgs::Illuminance const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Image(const sensor_msgs::Image& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Image(int stack, sensor_msgs::Image *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Image(const boost::shared_ptr<sensor_msgs::Image const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Imu(const sensor_msgs::Imu& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Imu(int stack, sensor_msgs::Imu *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Imu(const boost::shared_ptr<sensor_msgs::Imu const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__JointState(const sensor_msgs::JointState& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__JointState(int stack, sensor_msgs::JointState *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__JointState(const boost::shared_ptr<sensor_msgs::JointState const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Joy(const sensor_msgs::Joy& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Joy(int stack, sensor_msgs::Joy *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Joy(const boost::shared_ptr<sensor_msgs::Joy const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__JoyFeedback(const sensor_msgs::JoyFeedback& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__JoyFeedback(int stack, sensor_msgs::JoyFeedback *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__JoyFeedback(const boost::shared_ptr<sensor_msgs::JoyFeedback const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__JoyFeedbackArray(const sensor_msgs::JoyFeedbackArray& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__JoyFeedbackArray(int stack, sensor_msgs::JoyFeedbackArray *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__JoyFeedbackArray(const boost::shared_ptr<sensor_msgs::JoyFeedbackArray const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__LaserEcho(const sensor_msgs::LaserEcho& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__LaserEcho(int stack, sensor_msgs::LaserEcho *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__LaserEcho(const boost::shared_ptr<sensor_msgs::LaserEcho const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__LaserScan(const sensor_msgs::LaserScan& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__LaserScan(int stack, sensor_msgs::LaserScan *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__LaserScan(const boost::shared_ptr<sensor_msgs::LaserScan const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__MagneticField(const sensor_msgs::MagneticField& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__MagneticField(int stack, sensor_msgs::MagneticField *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__MagneticField(const boost::shared_ptr<sensor_msgs::MagneticField const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__MultiDOFJointState(const sensor_msgs::MultiDOFJointState& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__MultiDOFJointState(int stack, sensor_msgs::MultiDOFJointState *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__MultiDOFJointState(const boost::shared_ptr<sensor_msgs::MultiDOFJointState const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__MultiEchoLaserScan(const sensor_msgs::MultiEchoLaserScan& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__MultiEchoLaserScan(int stack, sensor_msgs::MultiEchoLaserScan *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__MultiEchoLaserScan(const boost::shared_ptr<sensor_msgs::MultiEchoLaserScan const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__NavSatFix(const sensor_msgs::NavSatFix& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__NavSatFix(int stack, sensor_msgs::NavSatFix *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__NavSatFix(const boost::shared_ptr<sensor_msgs::NavSatFix const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__NavSatStatus(const sensor_msgs::NavSatStatus& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__NavSatStatus(int stack, sensor_msgs::NavSatStatus *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__NavSatStatus(const boost::shared_ptr<sensor_msgs::NavSatStatus const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__PointCloud(const sensor_msgs::PointCloud& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__PointCloud(int stack, sensor_msgs::PointCloud *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__PointCloud(const boost::shared_ptr<sensor_msgs::PointCloud const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__PointCloud2(const sensor_msgs::PointCloud2& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__PointCloud2(int stack, sensor_msgs::PointCloud2 *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__PointCloud2(const boost::shared_ptr<sensor_msgs::PointCloud2 const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__PointField(const sensor_msgs::PointField& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__PointField(int stack, sensor_msgs::PointField *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__PointField(const boost::shared_ptr<sensor_msgs::PointField const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Range(const sensor_msgs::Range& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Range(int stack, sensor_msgs::Range *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Range(const boost::shared_ptr<sensor_msgs::Range const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__RegionOfInterest(const sensor_msgs::RegionOfInterest& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__RegionOfInterest(int stack, sensor_msgs::RegionOfInterest *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__RegionOfInterest(const boost::shared_ptr<sensor_msgs::RegionOfInterest const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__RelativeHumidity(const sensor_msgs::RelativeHumidity& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__RelativeHumidity(int stack, sensor_msgs::RelativeHumidity *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__RelativeHumidity(const boost::shared_ptr<sensor_msgs::RelativeHumidity const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__Temperature(const sensor_msgs::Temperature& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__Temperature(int stack, sensor_msgs::Temperature *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__Temperature(const boost::shared_ptr<sensor_msgs::Temperature const>& msg, SubscriberProxy *proxy);

void write__sensor_msgs__TimeReference(const sensor_msgs::TimeReference& msg, int stack, const WriteOptions *opt = NULL);

void read__sensor_msgs__TimeReference(int stack, sensor_msgs::TimeReference *msg, const ReadOptions *opt = NULL);

void ros_callback__sensor_msgs__TimeReference(const boost::shared_ptr<sensor_msgs::TimeReference const>& msg, SubscriberProxy *proxy);

void write__shape_msgs__Mesh(const shape_msgs::Mesh& msg, int stack, const WriteOptions *opt = NULL);

void read__shape_msgs__Mesh(int stack, shape_msgs::Mesh *msg, const ReadOptions *opt = NULL);

void ros_callback__shape_msgs__Mesh(const boost::shared_ptr<shape_msgs::Mesh const>& msg, SubscriberProxy *proxy);

void write__shape_msgs__MeshTriangle(const shape_msgs::MeshTriangle& msg, int stack, const WriteOptions *opt = NULL);

void read__shape_msgs__MeshTriangle(int stack, shape_msgs::MeshTriangle *msg, const ReadOptions *opt = NULL);

void ros_callback__shape_msgs__MeshTriangle(const boost::shared_ptr<shape_msgs::MeshTriangle const>& msg, SubscriberProxy *proxy);

void write__shape_msgs__Plane(const shape_msgs::Plane& msg, int stack, const WriteOptions *opt = NULL);

void read__shape_msgs__Plane(int stack, shape_msgs::Plane *msg, const ReadOptions *opt = NULL);

void ros_callback__shape_msgs__Plane(const boost::shared_ptr<shape_msgs::Plane const>& msg, SubscriberProxy *proxy);

void write__shape_msgs__SolidPrimitive(const shape_msgs::SolidPrimitive& msg, int stack, const WriteOptions *opt = NULL);

void read__shape_msgs__SolidPrimitive(int stack, shape_msgs::SolidPrimitive *msg, const ReadOptions *opt = NULL);

void ros_callback__shape_msgs__SolidPrimitive(const boost::shared_ptr<shape_msgs::SolidPrimitive const>& msg, SubscriberProxy *proxy);

void write__smach_msgs__SmachContainerInitialStatusCmd(const smach_msgs::SmachContainerInitialStatusCmd& msg, int stack, const WriteOptions *opt = NULL);

void read__smach_msgs__SmachContainerInitialStatusCmd(int stack, smach_msgs::SmachContainerInitialStatusCmd *msg, const ReadOptions *opt = NULL);

void ros_callback__smach_msgs__SmachContainerInitialStatusCmd(const boost::shared_ptr<smach_msgs::SmachContainerInitialStatusCmd const>& msg, SubscriberProxy *proxy);

void write__smach_msgs__SmachContainerStatus(const smach_msgs::SmachContainerStatus& msg, int stack, const WriteOptions *opt = NULL);

void read__smach_msgs__SmachContainerStatus(int stack, smach_msgs::SmachContainerStatus *msg, const ReadOptions *opt = NULL);

void ros_callback__smach_msgs__SmachContainerStatus(const boost::shared_ptr<smach_msgs::SmachContainerStatus const>& msg, SubscriberProxy *proxy);

void write__smach_msgs__SmachContainerStructure(const smach_msgs::SmachContainerStructure& msg, int stack, const WriteOptions *opt = NULL);

void read__smach_msgs__SmachContainerStructure(int stack, smach_msgs::SmachContainerStructure *msg, const ReadOptions *opt = NULL);

void ros_callback__smach_msgs__SmachContainerStructure(const boost::shared_ptr<smach_msgs::SmachContainerStructure const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Bool(const std_msgs::Bool& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Bool(int stack, std_msgs::Bool *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Bool(const boost::shared_ptr<std_msgs::Bool const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Byte(const std_msgs::Byte& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Byte(int stack, std_msgs::Byte *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Byte(const boost::shared_ptr<std_msgs::Byte const>& msg, SubscriberProxy *proxy);

void write__std_msgs__ByteMultiArray(const std_msgs::ByteMultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__ByteMultiArray(int stack, std_msgs::ByteMultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__ByteMultiArray(const boost::shared_ptr<std_msgs::ByteMultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Char(const std_msgs::Char& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Char(int stack, std_msgs::Char *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Char(const boost::shared_ptr<std_msgs::Char const>& msg, SubscriberProxy *proxy);

void write__std_msgs__ColorRGBA(const std_msgs::ColorRGBA& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__ColorRGBA(int stack, std_msgs::ColorRGBA *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__ColorRGBA(const boost::shared_ptr<std_msgs::ColorRGBA const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Duration(const std_msgs::Duration& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Duration(int stack, std_msgs::Duration *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Duration(const boost::shared_ptr<std_msgs::Duration const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Empty(const std_msgs::Empty& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Empty(int stack, std_msgs::Empty *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Empty(const boost::shared_ptr<std_msgs::Empty const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Float32(const std_msgs::Float32& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Float32(int stack, std_msgs::Float32 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Float32(const boost::shared_ptr<std_msgs::Float32 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Float32MultiArray(const std_msgs::Float32MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Float32MultiArray(int stack, std_msgs::Float32MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Float32MultiArray(const boost::shared_ptr<std_msgs::Float32MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Float64(const std_msgs::Float64& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Float64(int stack, std_msgs::Float64 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Float64(const boost::shared_ptr<std_msgs::Float64 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Float64MultiArray(const std_msgs::Float64MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Float64MultiArray(int stack, std_msgs::Float64MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Float64MultiArray(const boost::shared_ptr<std_msgs::Float64MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Header(const std_msgs::Header& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Header(int stack, std_msgs::Header *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Header(const boost::shared_ptr<std_msgs::Header const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int16(const std_msgs::Int16& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int16(int stack, std_msgs::Int16 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int16(const boost::shared_ptr<std_msgs::Int16 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int16MultiArray(const std_msgs::Int16MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int16MultiArray(int stack, std_msgs::Int16MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int16MultiArray(const boost::shared_ptr<std_msgs::Int16MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int32(const std_msgs::Int32& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int32(int stack, std_msgs::Int32 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int32(const boost::shared_ptr<std_msgs::Int32 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int32MultiArray(const std_msgs::Int32MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int32MultiArray(int stack, std_msgs::Int32MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int32MultiArray(const boost::shared_ptr<std_msgs::Int32MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int64(const std_msgs::Int64& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int64(int stack, std_msgs::Int64 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int64(const boost::shared_ptr<std_msgs::Int64 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int64MultiArray(const std_msgs::Int64MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int64MultiArray(int stack, std_msgs::Int64MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int64MultiArray(const boost::shared_ptr<std_msgs::Int64MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int8(const std_msgs::Int8& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int8(int stack, std_msgs::Int8 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int8(const boost::shared_ptr<std_msgs::Int8 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Int8MultiArray(const std_msgs::Int8MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Int8MultiArray(int stack, std_msgs::Int8MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Int8MultiArray(const boost::shared_ptr<std_msgs::Int8MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__MultiArrayDimension(const std_msgs::MultiArrayDimension& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__MultiArrayDimension(int stack, std_msgs::MultiArrayDimension *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__MultiArrayDimension(const boost::shared_ptr<std_msgs::MultiArrayDimension const>& msg, SubscriberProxy *proxy);

void write__std_msgs__MultiArrayLayout(const std_msgs::MultiArrayLayout& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__MultiArrayLayout(int stack, std_msgs::MultiArrayLayout *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__MultiArrayLayout(const boost::shared_ptr<std_msgs::MultiArrayLayout const>& msg, SubscriberProxy *proxy);

void write__std_msgs__String(const std_msgs::String& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__String(int stack, std_msgs::String *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__String(const boost::shared_ptr<std_msgs::String const>& msg, SubscriberProxy *proxy);

void write__std_msgs__Time(const std_msgs::Time& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__Time(int stack, std_msgs::Time *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__Time(const boost::shared_ptr<std_msgs::Time const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt16(const std_msgs::UInt16& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt16(int stack, std_msgs::UInt16 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt16(const boost::shared_ptr<std_msgs::UInt16 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt16MultiArray(const std_msgs::UInt16MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt16MultiArray(int stack, std_msgs::UInt16MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt16MultiArray(const boost::shared_ptr<std_msgs::UInt16MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt32(const std_msgs::UInt32& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt32(int stack, std_msgs::UInt32 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt32(const boost::shared_ptr<std_msgs::UInt32 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt32MultiArray(const std_msgs::UInt32MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt32MultiArray(int stack, std_msgs::UInt32MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt32MultiArray(const boost::shared_ptr<std_msgs::UInt32MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt64(const std_msgs::UInt64& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt64(int stack, std_msgs::UInt64 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt64(const boost::shared_ptr<std_msgs::UInt64 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt64MultiArray(const std_msgs::UInt64MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt64MultiArray(int stack, std_msgs::UInt64MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt64MultiArray(const boost::shared_ptr<std_msgs::UInt64MultiArray const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt8(const std_msgs::UInt8& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt8(int stack, std_msgs::UInt8 *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt8(const boost::shared_ptr<std_msgs::UInt8 const>& msg, SubscriberProxy *proxy);

void write__std_msgs__UInt8MultiArray(const std_msgs::UInt8MultiArray& msg, int stack, const WriteOptions *opt = NULL);

void read__std_msgs__UInt8MultiArray(int stack, std_msgs::UInt8MultiArray *msg, const ReadOptions *opt = NULL);

void ros_callback__std_msgs__UInt8MultiArray(const boost::shared_ptr<std_msgs::UInt8MultiArray const>& msg, SubscriberProxy *proxy);

void write__tf__tfMessage(const tf::tfMessage& msg, int stack, const WriteOptions *opt = NULL);

void read__tf__tfMessage(int stack, tf::tfMessage *msg, const ReadOptions *opt = NULL);

void ros_callback__tf__tfMessage(const boost::shared_ptr<tf::tfMessage const>& msg, SubscriberProxy *proxy);

void write__tf2_msgs__TF2Error(const tf2_msgs::TF2Error& msg, int stack, const WriteOptions *opt = NULL);

void read__tf2_msgs__TF2Error(int stack, tf2_msgs::TF2Error *msg, const ReadOptions *opt = NULL);

void ros_callback__tf2_msgs__TF2Error(const boost::shared_ptr<tf2_msgs::TF2Error const>& msg, SubscriberProxy *proxy);

void write__tf2_msgs__TFMessage(const tf2_msgs::TFMessage& msg, int stack, const WriteOptions *opt = NULL);

void read__tf2_msgs__TFMessage(int stack, tf2_msgs::TFMessage *msg, const ReadOptions *opt = NULL);

void ros_callback__tf2_msgs__TFMessage(const boost::shared_ptr<tf2_msgs::TFMessage const>& msg, SubscriberProxy *proxy);

void write__trajectory_msgs__JointTrajectory(const trajectory_msgs::JointTrajectory& msg, int stack, const WriteOptions *opt = NULL);

void read__trajectory_msgs__JointTrajectory(int stack, trajectory_msgs::JointTrajectory *msg, const ReadOptions *opt = NULL);

void ros_callback__trajectory_msgs__JointTrajectory(const boost::shared_ptr<trajectory_msgs::JointTrajectory const>& msg, SubscriberProxy *proxy);

void write__trajectory_msgs__JointTrajectoryPoint(const trajectory_msgs::JointTrajectoryPoint& msg, int stack, const WriteOptions *opt = NULL);

void read__trajectory_msgs__JointTrajectoryPoint(int stack, trajectory_msgs::JointTrajectoryPoint *msg, const ReadOptions *opt = NULL);

void ros_callback__trajectory_msgs__JointTrajectoryPoint(const boost::shared_ptr<trajectory_msgs::JointTrajectoryPoint const>& msg, SubscriberProxy *proxy);

void write__trajectory_msgs__MultiDOFJointTrajectory(const trajectory_msgs::MultiDOFJointTrajectory& msg, int stack, const WriteOptions *opt = NULL);

void read__trajectory_msgs__MultiDOFJointTrajectory(int stack, trajectory_msgs::MultiDOFJointTrajectory *msg, const ReadOptions *opt = NULL);

void ros_callback__trajectory_msgs__MultiDOFJointTrajectory(const boost::shared_ptr<trajectory_msgs::MultiDOFJointTrajectory const>& msg, SubscriberProxy *proxy);

void write__trajectory_msgs__MultiDOFJointTrajectoryPoint(const trajectory_msgs::MultiDOFJointTrajectoryPoint& msg, int stack, const WriteOptions *opt = NULL);

void read__trajectory_msgs__MultiDOFJointTrajectoryPoint(int stack, trajectory_msgs::MultiDOFJointTrajectoryPoint *msg, const ReadOptions *opt = NULL);

void ros_callback__trajectory_msgs__MultiDOFJointTrajectoryPoint(const boost::shared_ptr<trajectory_msgs::MultiDOFJointTrajectoryPoint const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__ImageMarker(const visualization_msgs::ImageMarker& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__ImageMarker(int stack, visualization_msgs::ImageMarker *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__ImageMarker(const boost::shared_ptr<visualization_msgs::ImageMarker const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarker(const visualization_msgs::InteractiveMarker& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarker(int stack, visualization_msgs::InteractiveMarker *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarker(const boost::shared_ptr<visualization_msgs::InteractiveMarker const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarkerControl(const visualization_msgs::InteractiveMarkerControl& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarkerControl(int stack, visualization_msgs::InteractiveMarkerControl *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarkerControl(const boost::shared_ptr<visualization_msgs::InteractiveMarkerControl const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarkerFeedback(const visualization_msgs::InteractiveMarkerFeedback& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarkerFeedback(int stack, visualization_msgs::InteractiveMarkerFeedback *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarkerFeedback(const boost::shared_ptr<visualization_msgs::InteractiveMarkerFeedback const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarkerInit(const visualization_msgs::InteractiveMarkerInit& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarkerInit(int stack, visualization_msgs::InteractiveMarkerInit *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarkerInit(const boost::shared_ptr<visualization_msgs::InteractiveMarkerInit const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarkerPose(const visualization_msgs::InteractiveMarkerPose& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarkerPose(int stack, visualization_msgs::InteractiveMarkerPose *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarkerPose(const boost::shared_ptr<visualization_msgs::InteractiveMarkerPose const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__InteractiveMarkerUpdate(const visualization_msgs::InteractiveMarkerUpdate& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__InteractiveMarkerUpdate(int stack, visualization_msgs::InteractiveMarkerUpdate *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__InteractiveMarkerUpdate(const boost::shared_ptr<visualization_msgs::InteractiveMarkerUpdate const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__Marker(const visualization_msgs::Marker& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__Marker(int stack, visualization_msgs::Marker *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__Marker(const boost::shared_ptr<visualization_msgs::Marker const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__MarkerArray(const visualization_msgs::MarkerArray& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__MarkerArray(int stack, visualization_msgs::MarkerArray *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__MarkerArray(const boost::shared_ptr<visualization_msgs::MarkerArray const>& msg, SubscriberProxy *proxy);

void write__visualization_msgs__MenuEntry(const visualization_msgs::MenuEntry& msg, int stack, const WriteOptions *opt = NULL);

void read__visualization_msgs__MenuEntry(int stack, visualization_msgs::MenuEntry *msg, const ReadOptions *opt = NULL);

void ros_callback__visualization_msgs__MenuEntry(const boost::shared_ptr<visualization_msgs::MenuEntry const>& msg, SubscriberProxy *proxy);


#endif // VREP_ROS_PLUGIN__ROS_MSG_IO__H
