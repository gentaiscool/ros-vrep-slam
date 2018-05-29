    else if(in->topicType == "control_msgs/JointControllerState")
    {
        publisherProxy->publisher = nh->advertise<control_msgs::JointControllerState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "control_msgs/JointTolerance")
    {
        publisherProxy->publisher = nh->advertise<control_msgs::JointTolerance>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "diagnostic_msgs/DiagnosticArray")
    {
        publisherProxy->publisher = nh->advertise<diagnostic_msgs::DiagnosticArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "diagnostic_msgs/DiagnosticStatus")
    {
        publisherProxy->publisher = nh->advertise<diagnostic_msgs::DiagnosticStatus>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "diagnostic_msgs/KeyValue")
    {
        publisherProxy->publisher = nh->advertise<diagnostic_msgs::KeyValue>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/BoolParameter")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::BoolParameter>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/Config")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::Config>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/ConfigDescription")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::ConfigDescription>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/DoubleParameter")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::DoubleParameter>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/Group")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::Group>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/GroupState")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::GroupState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/IntParameter")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::IntParameter>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/ParamDescription")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::ParamDescription>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/SensorLevels")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::SensorLevels>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "dynamic_reconfigure/StrParameter")
    {
        publisherProxy->publisher = nh->advertise<dynamic_reconfigure::StrParameter>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ContactState")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ContactState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ContactsState")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ContactsState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/LinkState")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::LinkState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/LinkStates")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::LinkStates>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ModelState")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ModelState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ModelStates")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ModelStates>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ODEJointProperties")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ODEJointProperties>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/ODEPhysics")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::ODEPhysics>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "gazebo_msgs/WorldState")
    {
        publisherProxy->publisher = nh->advertise<gazebo_msgs::WorldState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Accel")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Accel>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/AccelStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::AccelStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/AccelWithCovariance")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::AccelWithCovariance>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/AccelWithCovarianceStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::AccelWithCovarianceStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Inertia")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Inertia>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/InertiaStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::InertiaStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Point")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Point>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Point32")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Point32>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PointStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PointStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Polygon")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Polygon>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PolygonStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PolygonStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Pose")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Pose>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Pose2D")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Pose2D>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PoseArray")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PoseArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PoseStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PoseStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PoseWithCovariance")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PoseWithCovariance>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/PoseWithCovarianceStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Quaternion")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Quaternion>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/QuaternionStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::QuaternionStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Transform")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Transform>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/TransformStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::TransformStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Twist")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Twist>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/TwistStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::TwistStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/TwistWithCovariance")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::TwistWithCovariance>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/TwistWithCovarianceStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::TwistWithCovarianceStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Vector3")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Vector3>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Vector3Stamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Vector3Stamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/Wrench")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::Wrench>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "geometry_msgs/WrenchStamped")
    {
        publisherProxy->publisher = nh->advertise<geometry_msgs::WrenchStamped>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "map_msgs/OccupancyGridUpdate")
    {
        publisherProxy->publisher = nh->advertise<map_msgs::OccupancyGridUpdate>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "map_msgs/PointCloud2Update")
    {
        publisherProxy->publisher = nh->advertise<map_msgs::PointCloud2Update>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "map_msgs/ProjectedMap")
    {
        publisherProxy->publisher = nh->advertise<map_msgs::ProjectedMap>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "map_msgs/ProjectedMapInfo")
    {
        publisherProxy->publisher = nh->advertise<map_msgs::ProjectedMapInfo>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "nav_msgs/GridCells")
    {
        publisherProxy->publisher = nh->advertise<nav_msgs::GridCells>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "nav_msgs/MapMetaData")
    {
        publisherProxy->publisher = nh->advertise<nav_msgs::MapMetaData>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "nav_msgs/OccupancyGrid")
    {
        publisherProxy->publisher = nh->advertise<nav_msgs::OccupancyGrid>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "nav_msgs/Odometry")
    {
        publisherProxy->publisher = nh->advertise<nav_msgs::Odometry>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "nav_msgs/Path")
    {
        publisherProxy->publisher = nh->advertise<nav_msgs::Path>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "roscpp/Logger")
    {
        publisherProxy->publisher = nh->advertise<roscpp::Logger>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "rosgraph_msgs/Clock")
    {
        publisherProxy->publisher = nh->advertise<rosgraph_msgs::Clock>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "rosgraph_msgs/Log")
    {
        publisherProxy->publisher = nh->advertise<rosgraph_msgs::Log>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "rosgraph_msgs/TopicStatistics")
    {
        publisherProxy->publisher = nh->advertise<rosgraph_msgs::TopicStatistics>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/CameraInfo")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::CameraInfo>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/ChannelFloat32")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::ChannelFloat32>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/CompressedImage")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::CompressedImage>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/FluidPressure")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::FluidPressure>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Illuminance")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Illuminance>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Image")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Image>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Imu")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Imu>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/JointState")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::JointState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Joy")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Joy>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/JoyFeedback")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::JoyFeedback>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/JoyFeedbackArray")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::JoyFeedbackArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/LaserEcho")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::LaserEcho>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/LaserScan")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::LaserScan>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/MagneticField")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::MagneticField>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/MultiDOFJointState")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::MultiDOFJointState>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/MultiEchoLaserScan")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::MultiEchoLaserScan>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/NavSatFix")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::NavSatFix>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/NavSatStatus")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::NavSatStatus>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/PointCloud")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::PointCloud>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/PointCloud2")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::PointCloud2>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/PointField")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::PointField>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Range")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Range>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/RegionOfInterest")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::RegionOfInterest>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/RelativeHumidity")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::RelativeHumidity>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/Temperature")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::Temperature>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "sensor_msgs/TimeReference")
    {
        publisherProxy->publisher = nh->advertise<sensor_msgs::TimeReference>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "shape_msgs/Mesh")
    {
        publisherProxy->publisher = nh->advertise<shape_msgs::Mesh>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "shape_msgs/MeshTriangle")
    {
        publisherProxy->publisher = nh->advertise<shape_msgs::MeshTriangle>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "shape_msgs/Plane")
    {
        publisherProxy->publisher = nh->advertise<shape_msgs::Plane>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "shape_msgs/SolidPrimitive")
    {
        publisherProxy->publisher = nh->advertise<shape_msgs::SolidPrimitive>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "smach_msgs/SmachContainerInitialStatusCmd")
    {
        publisherProxy->publisher = nh->advertise<smach_msgs::SmachContainerInitialStatusCmd>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "smach_msgs/SmachContainerStatus")
    {
        publisherProxy->publisher = nh->advertise<smach_msgs::SmachContainerStatus>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "smach_msgs/SmachContainerStructure")
    {
        publisherProxy->publisher = nh->advertise<smach_msgs::SmachContainerStructure>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Bool")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Bool>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Byte")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Byte>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/ByteMultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::ByteMultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Char")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Char>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/ColorRGBA")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::ColorRGBA>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Duration")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Duration>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Empty")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Empty>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Float32")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Float32>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Float32MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Float32MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Float64")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Float64>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Float64MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Float64MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Header")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Header>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int16")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int16>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int16MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int16MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int32")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int32>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int32MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int32MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int64")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int64>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int64MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int64MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int8")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int8>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Int8MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Int8MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/MultiArrayDimension")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::MultiArrayDimension>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/MultiArrayLayout")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::MultiArrayLayout>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/String")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::String>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/Time")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::Time>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt16")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt16>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt16MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt16MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt32")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt32>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt32MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt32MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt64")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt64>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt64MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt64MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt8")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt8>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "std_msgs/UInt8MultiArray")
    {
        publisherProxy->publisher = nh->advertise<std_msgs::UInt8MultiArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "tf/tfMessage")
    {
        publisherProxy->publisher = nh->advertise<tf::tfMessage>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "tf2_msgs/TF2Error")
    {
        publisherProxy->publisher = nh->advertise<tf2_msgs::TF2Error>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "tf2_msgs/TFMessage")
    {
        publisherProxy->publisher = nh->advertise<tf2_msgs::TFMessage>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "trajectory_msgs/JointTrajectory")
    {
        publisherProxy->publisher = nh->advertise<trajectory_msgs::JointTrajectory>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "trajectory_msgs/JointTrajectoryPoint")
    {
        publisherProxy->publisher = nh->advertise<trajectory_msgs::JointTrajectoryPoint>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "trajectory_msgs/MultiDOFJointTrajectory")
    {
        publisherProxy->publisher = nh->advertise<trajectory_msgs::MultiDOFJointTrajectory>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "trajectory_msgs/MultiDOFJointTrajectoryPoint")
    {
        publisherProxy->publisher = nh->advertise<trajectory_msgs::MultiDOFJointTrajectoryPoint>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/ImageMarker")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::ImageMarker>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarker")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarker>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerControl")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarkerControl>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerFeedback")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarkerFeedback>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerInit")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarkerInit>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerPose")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarkerPose>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/InteractiveMarkerUpdate")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::InteractiveMarkerUpdate>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/Marker")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::Marker>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/MarkerArray")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::MarkerArray>(in->topicName, in->queueSize, in->latch);
    }
    else if(in->topicType == "visualization_msgs/MenuEntry")
    {
        publisherProxy->publisher = nh->advertise<visualization_msgs::MenuEntry>(in->topicName, in->queueSize, in->latch);
    }
