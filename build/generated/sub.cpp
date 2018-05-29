    else if(in->topicType == "control_msgs/JointControllerState")
    {
        subscriberProxy->subscriber = nh->subscribe<control_msgs::JointControllerState>(in->topicName, in->queueSize, boost::bind(ros_callback__control_msgs__JointControllerState, _1, subscriberProxy));
    }
    else if(in->topicType == "control_msgs/JointTolerance")
    {
        subscriberProxy->subscriber = nh->subscribe<control_msgs::JointTolerance>(in->topicName, in->queueSize, boost::bind(ros_callback__control_msgs__JointTolerance, _1, subscriberProxy));
    }
    else if(in->topicType == "diagnostic_msgs/DiagnosticArray")
    {
        subscriberProxy->subscriber = nh->subscribe<diagnostic_msgs::DiagnosticArray>(in->topicName, in->queueSize, boost::bind(ros_callback__diagnostic_msgs__DiagnosticArray, _1, subscriberProxy));
    }
    else if(in->topicType == "diagnostic_msgs/DiagnosticStatus")
    {
        subscriberProxy->subscriber = nh->subscribe<diagnostic_msgs::DiagnosticStatus>(in->topicName, in->queueSize, boost::bind(ros_callback__diagnostic_msgs__DiagnosticStatus, _1, subscriberProxy));
    }
    else if(in->topicType == "diagnostic_msgs/KeyValue")
    {
        subscriberProxy->subscriber = nh->subscribe<diagnostic_msgs::KeyValue>(in->topicName, in->queueSize, boost::bind(ros_callback__diagnostic_msgs__KeyValue, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/BoolParameter")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::BoolParameter>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__BoolParameter, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/Config")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::Config>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__Config, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/ConfigDescription")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::ConfigDescription>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__ConfigDescription, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/DoubleParameter")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::DoubleParameter>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__DoubleParameter, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/Group")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::Group>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__Group, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/GroupState")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::GroupState>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__GroupState, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/IntParameter")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::IntParameter>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__IntParameter, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/ParamDescription")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::ParamDescription>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__ParamDescription, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/SensorLevels")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::SensorLevels>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__SensorLevels, _1, subscriberProxy));
    }
    else if(in->topicType == "dynamic_reconfigure/StrParameter")
    {
        subscriberProxy->subscriber = nh->subscribe<dynamic_reconfigure::StrParameter>(in->topicName, in->queueSize, boost::bind(ros_callback__dynamic_reconfigure__StrParameter, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ContactState")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ContactState>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ContactState, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ContactsState")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ContactsState>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ContactsState, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/LinkState")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::LinkState>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__LinkState, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/LinkStates")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::LinkStates>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__LinkStates, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ModelState")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ModelState>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ModelState, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ModelStates")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ModelStates>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ModelStates, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ODEJointProperties")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ODEJointProperties>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ODEJointProperties, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/ODEPhysics")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::ODEPhysics>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__ODEPhysics, _1, subscriberProxy));
    }
    else if(in->topicType == "gazebo_msgs/WorldState")
    {
        subscriberProxy->subscriber = nh->subscribe<gazebo_msgs::WorldState>(in->topicName, in->queueSize, boost::bind(ros_callback__gazebo_msgs__WorldState, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Accel")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Accel>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Accel, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/AccelStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::AccelStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__AccelStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/AccelWithCovariance")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::AccelWithCovariance>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__AccelWithCovariance, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/AccelWithCovarianceStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::AccelWithCovarianceStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__AccelWithCovarianceStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Inertia")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Inertia>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Inertia, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/InertiaStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::InertiaStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__InertiaStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Point")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Point>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Point, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Point32")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Point32>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Point32, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PointStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PointStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PointStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Polygon")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Polygon>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Polygon, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PolygonStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PolygonStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PolygonStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Pose")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Pose>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Pose, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Pose2D")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Pose2D>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Pose2D, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PoseArray")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PoseArray>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PoseArray, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PoseStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PoseStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PoseStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PoseWithCovariance")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PoseWithCovariance>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PoseWithCovariance, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/PoseWithCovarianceStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::PoseWithCovarianceStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__PoseWithCovarianceStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Quaternion")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Quaternion>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Quaternion, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/QuaternionStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::QuaternionStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__QuaternionStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Transform")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Transform>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Transform, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/TransformStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::TransformStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__TransformStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Twist")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Twist>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Twist, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/TwistStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::TwistStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__TwistStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/TwistWithCovariance")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::TwistWithCovariance>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__TwistWithCovariance, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/TwistWithCovarianceStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::TwistWithCovarianceStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__TwistWithCovarianceStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Vector3")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Vector3>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Vector3, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Vector3Stamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Vector3Stamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Vector3Stamped, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/Wrench")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::Wrench>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__Wrench, _1, subscriberProxy));
    }
    else if(in->topicType == "geometry_msgs/WrenchStamped")
    {
        subscriberProxy->subscriber = nh->subscribe<geometry_msgs::WrenchStamped>(in->topicName, in->queueSize, boost::bind(ros_callback__geometry_msgs__WrenchStamped, _1, subscriberProxy));
    }
    else if(in->topicType == "map_msgs/OccupancyGridUpdate")
    {
        subscriberProxy->subscriber = nh->subscribe<map_msgs::OccupancyGridUpdate>(in->topicName, in->queueSize, boost::bind(ros_callback__map_msgs__OccupancyGridUpdate, _1, subscriberProxy));
    }
    else if(in->topicType == "map_msgs/PointCloud2Update")
    {
        subscriberProxy->subscriber = nh->subscribe<map_msgs::PointCloud2Update>(in->topicName, in->queueSize, boost::bind(ros_callback__map_msgs__PointCloud2Update, _1, subscriberProxy));
    }
    else if(in->topicType == "map_msgs/ProjectedMap")
    {
        subscriberProxy->subscriber = nh->subscribe<map_msgs::ProjectedMap>(in->topicName, in->queueSize, boost::bind(ros_callback__map_msgs__ProjectedMap, _1, subscriberProxy));
    }
    else if(in->topicType == "map_msgs/ProjectedMapInfo")
    {
        subscriberProxy->subscriber = nh->subscribe<map_msgs::ProjectedMapInfo>(in->topicName, in->queueSize, boost::bind(ros_callback__map_msgs__ProjectedMapInfo, _1, subscriberProxy));
    }
    else if(in->topicType == "nav_msgs/GridCells")
    {
        subscriberProxy->subscriber = nh->subscribe<nav_msgs::GridCells>(in->topicName, in->queueSize, boost::bind(ros_callback__nav_msgs__GridCells, _1, subscriberProxy));
    }
    else if(in->topicType == "nav_msgs/MapMetaData")
    {
        subscriberProxy->subscriber = nh->subscribe<nav_msgs::MapMetaData>(in->topicName, in->queueSize, boost::bind(ros_callback__nav_msgs__MapMetaData, _1, subscriberProxy));
    }
    else if(in->topicType == "nav_msgs/OccupancyGrid")
    {
        subscriberProxy->subscriber = nh->subscribe<nav_msgs::OccupancyGrid>(in->topicName, in->queueSize, boost::bind(ros_callback__nav_msgs__OccupancyGrid, _1, subscriberProxy));
    }
    else if(in->topicType == "nav_msgs/Odometry")
    {
        subscriberProxy->subscriber = nh->subscribe<nav_msgs::Odometry>(in->topicName, in->queueSize, boost::bind(ros_callback__nav_msgs__Odometry, _1, subscriberProxy));
    }
    else if(in->topicType == "nav_msgs/Path")
    {
        subscriberProxy->subscriber = nh->subscribe<nav_msgs::Path>(in->topicName, in->queueSize, boost::bind(ros_callback__nav_msgs__Path, _1, subscriberProxy));
    }
    else if(in->topicType == "roscpp/Logger")
    {
        subscriberProxy->subscriber = nh->subscribe<roscpp::Logger>(in->topicName, in->queueSize, boost::bind(ros_callback__roscpp__Logger, _1, subscriberProxy));
    }
    else if(in->topicType == "rosgraph_msgs/Clock")
    {
        subscriberProxy->subscriber = nh->subscribe<rosgraph_msgs::Clock>(in->topicName, in->queueSize, boost::bind(ros_callback__rosgraph_msgs__Clock, _1, subscriberProxy));
    }
    else if(in->topicType == "rosgraph_msgs/Log")
    {
        subscriberProxy->subscriber = nh->subscribe<rosgraph_msgs::Log>(in->topicName, in->queueSize, boost::bind(ros_callback__rosgraph_msgs__Log, _1, subscriberProxy));
    }
    else if(in->topicType == "rosgraph_msgs/TopicStatistics")
    {
        subscriberProxy->subscriber = nh->subscribe<rosgraph_msgs::TopicStatistics>(in->topicName, in->queueSize, boost::bind(ros_callback__rosgraph_msgs__TopicStatistics, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/CameraInfo")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::CameraInfo>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__CameraInfo, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/ChannelFloat32")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::ChannelFloat32>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__ChannelFloat32, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/CompressedImage")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::CompressedImage>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__CompressedImage, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/FluidPressure")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::FluidPressure>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__FluidPressure, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Illuminance")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Illuminance>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Illuminance, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Image")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Image>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Image, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Imu")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Imu>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Imu, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/JointState")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::JointState>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__JointState, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Joy")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Joy>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Joy, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/JoyFeedback")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::JoyFeedback>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__JoyFeedback, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/JoyFeedbackArray")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::JoyFeedbackArray>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__JoyFeedbackArray, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/LaserEcho")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::LaserEcho>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__LaserEcho, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/LaserScan")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::LaserScan>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__LaserScan, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/MagneticField")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::MagneticField>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__MagneticField, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/MultiDOFJointState")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::MultiDOFJointState>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__MultiDOFJointState, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/MultiEchoLaserScan")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::MultiEchoLaserScan>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__MultiEchoLaserScan, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/NavSatFix")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::NavSatFix>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__NavSatFix, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/NavSatStatus")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::NavSatStatus>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__NavSatStatus, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/PointCloud")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::PointCloud>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__PointCloud, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/PointCloud2")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::PointCloud2>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__PointCloud2, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/PointField")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::PointField>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__PointField, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Range")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Range>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Range, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/RegionOfInterest")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::RegionOfInterest>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__RegionOfInterest, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/RelativeHumidity")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::RelativeHumidity>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__RelativeHumidity, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/Temperature")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::Temperature>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__Temperature, _1, subscriberProxy));
    }
    else if(in->topicType == "sensor_msgs/TimeReference")
    {
        subscriberProxy->subscriber = nh->subscribe<sensor_msgs::TimeReference>(in->topicName, in->queueSize, boost::bind(ros_callback__sensor_msgs__TimeReference, _1, subscriberProxy));
    }
    else if(in->topicType == "shape_msgs/Mesh")
    {
        subscriberProxy->subscriber = nh->subscribe<shape_msgs::Mesh>(in->topicName, in->queueSize, boost::bind(ros_callback__shape_msgs__Mesh, _1, subscriberProxy));
    }
    else if(in->topicType == "shape_msgs/MeshTriangle")
    {
        subscriberProxy->subscriber = nh->subscribe<shape_msgs::MeshTriangle>(in->topicName, in->queueSize, boost::bind(ros_callback__shape_msgs__MeshTriangle, _1, subscriberProxy));
    }
    else if(in->topicType == "shape_msgs/Plane")
    {
        subscriberProxy->subscriber = nh->subscribe<shape_msgs::Plane>(in->topicName, in->queueSize, boost::bind(ros_callback__shape_msgs__Plane, _1, subscriberProxy));
    }
    else if(in->topicType == "shape_msgs/SolidPrimitive")
    {
        subscriberProxy->subscriber = nh->subscribe<shape_msgs::SolidPrimitive>(in->topicName, in->queueSize, boost::bind(ros_callback__shape_msgs__SolidPrimitive, _1, subscriberProxy));
    }
    else if(in->topicType == "smach_msgs/SmachContainerInitialStatusCmd")
    {
        subscriberProxy->subscriber = nh->subscribe<smach_msgs::SmachContainerInitialStatusCmd>(in->topicName, in->queueSize, boost::bind(ros_callback__smach_msgs__SmachContainerInitialStatusCmd, _1, subscriberProxy));
    }
    else if(in->topicType == "smach_msgs/SmachContainerStatus")
    {
        subscriberProxy->subscriber = nh->subscribe<smach_msgs::SmachContainerStatus>(in->topicName, in->queueSize, boost::bind(ros_callback__smach_msgs__SmachContainerStatus, _1, subscriberProxy));
    }
    else if(in->topicType == "smach_msgs/SmachContainerStructure")
    {
        subscriberProxy->subscriber = nh->subscribe<smach_msgs::SmachContainerStructure>(in->topicName, in->queueSize, boost::bind(ros_callback__smach_msgs__SmachContainerStructure, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Bool")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Bool>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Bool, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Byte")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Byte>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Byte, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/ByteMultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::ByteMultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__ByteMultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Char")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Char>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Char, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/ColorRGBA")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::ColorRGBA>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__ColorRGBA, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Duration")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Duration>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Duration, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Empty")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Empty>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Empty, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Float32")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Float32>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Float32, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Float32MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Float32MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Float32MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Float64")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Float64>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Float64, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Float64MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Float64MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Float64MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Header")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Header>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Header, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int16")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int16>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int16, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int16MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int16MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int16MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int32")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int32>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int32, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int32MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int32MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int32MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int64")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int64>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int64, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int64MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int64MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int64MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int8")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int8>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int8, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Int8MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Int8MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Int8MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/MultiArrayDimension")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::MultiArrayDimension>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__MultiArrayDimension, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/MultiArrayLayout")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::MultiArrayLayout>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__MultiArrayLayout, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/String")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::String>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__String, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/Time")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::Time>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__Time, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt16")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt16>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt16, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt16MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt16MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt16MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt32")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt32>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt32, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt32MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt32MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt32MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt64")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt64>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt64, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt64MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt64MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt64MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt8")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt8>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt8, _1, subscriberProxy));
    }
    else if(in->topicType == "std_msgs/UInt8MultiArray")
    {
        subscriberProxy->subscriber = nh->subscribe<std_msgs::UInt8MultiArray>(in->topicName, in->queueSize, boost::bind(ros_callback__std_msgs__UInt8MultiArray, _1, subscriberProxy));
    }
    else if(in->topicType == "tf/tfMessage")
    {
        subscriberProxy->subscriber = nh->subscribe<tf::tfMessage>(in->topicName, in->queueSize, boost::bind(ros_callback__tf__tfMessage, _1, subscriberProxy));
    }
    else if(in->topicType == "tf2_msgs/TF2Error")
    {
        subscriberProxy->subscriber = nh->subscribe<tf2_msgs::TF2Error>(in->topicName, in->queueSize, boost::bind(ros_callback__tf2_msgs__TF2Error, _1, subscriberProxy));
    }
    else if(in->topicType == "tf2_msgs/TFMessage")
    {
        subscriberProxy->subscriber = nh->subscribe<tf2_msgs::TFMessage>(in->topicName, in->queueSize, boost::bind(ros_callback__tf2_msgs__TFMessage, _1, subscriberProxy));
    }
    else if(in->topicType == "trajectory_msgs/JointTrajectory")
    {
        subscriberProxy->subscriber = nh->subscribe<trajectory_msgs::JointTrajectory>(in->topicName, in->queueSize, boost::bind(ros_callback__trajectory_msgs__JointTrajectory, _1, subscriberProxy));
    }
    else if(in->topicType == "trajectory_msgs/JointTrajectoryPoint")
    {
        subscriberProxy->subscriber = nh->subscribe<trajectory_msgs::JointTrajectoryPoint>(in->topicName, in->queueSize, boost::bind(ros_callback__trajectory_msgs__JointTrajectoryPoint, _1, subscriberProxy));
    }
    else if(in->topicType == "trajectory_msgs/MultiDOFJointTrajectory")
    {
        subscriberProxy->subscriber = nh->subscribe<trajectory_msgs::MultiDOFJointTrajectory>(in->topicName, in->queueSize, boost::bind(ros_callback__trajectory_msgs__MultiDOFJointTrajectory, _1, subscriberProxy));
    }
    else if(in->topicType == "trajectory_msgs/MultiDOFJointTrajectoryPoint")
    {
        subscriberProxy->subscriber = nh->subscribe<trajectory_msgs::MultiDOFJointTrajectoryPoint>(in->topicName, in->queueSize, boost::bind(ros_callback__trajectory_msgs__MultiDOFJointTrajectoryPoint, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/ImageMarker")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::ImageMarker>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__ImageMarker, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarker")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarker>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarker, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerControl")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarkerControl>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarkerControl, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerFeedback")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarkerFeedback>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarkerFeedback, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerInit")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarkerInit>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarkerInit, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerPose")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarkerPose>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarkerPose, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerUpdate")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::InteractiveMarkerUpdate>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__InteractiveMarkerUpdate, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/Marker")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::Marker>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__Marker, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/MarkerArray")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::MarkerArray>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__MarkerArray, _1, subscriberProxy));
    }
    else if(in->topicType == "visualization_msgs/MenuEntry")
    {
        subscriberProxy->subscriber = nh->subscribe<visualization_msgs::MenuEntry>(in->topicName, in->queueSize, boost::bind(ros_callback__visualization_msgs__MenuEntry, _1, subscriberProxy));
    }
