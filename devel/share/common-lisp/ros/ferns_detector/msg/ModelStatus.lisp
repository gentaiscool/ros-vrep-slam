; Auto-generated. Do not edit!


(cl:in-package ferns_detector-msg)


;//! \htmlinclude ModelStatus.msg.html

(cl:defclass <ModelStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (model
    :reader model
    :initarg :model
    :type cl:string
    :initform "")
   (loaded
    :reader loaded
    :initarg :loaded
    :type cl:boolean
    :initform cl:nil)
   (active
    :reader active
    :initarg :active
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ModelStatus (<ModelStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ModelStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ModelStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ferns_detector-msg:<ModelStatus> is deprecated: use ferns_detector-msg:ModelStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ModelStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:header-val is deprecated.  Use ferns_detector-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'model-val :lambda-list '(m))
(cl:defmethod model-val ((m <ModelStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:model-val is deprecated.  Use ferns_detector-msg:model instead.")
  (model m))

(cl:ensure-generic-function 'loaded-val :lambda-list '(m))
(cl:defmethod loaded-val ((m <ModelStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:loaded-val is deprecated.  Use ferns_detector-msg:loaded instead.")
  (loaded m))

(cl:ensure-generic-function 'active-val :lambda-list '(m))
(cl:defmethod active-val ((m <ModelStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:active-val is deprecated.  Use ferns_detector-msg:active instead.")
  (active m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ModelStatus>) ostream)
  "Serializes a message object of type '<ModelStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'model))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'model))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'loaded) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'active) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ModelStatus>) istream)
  "Deserializes a message object of type '<ModelStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'model) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'model) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'loaded) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'active) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ModelStatus>)))
  "Returns string type for a message object of type '<ModelStatus>"
  "ferns_detector/ModelStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ModelStatus)))
  "Returns string type for a message object of type 'ModelStatus"
  "ferns_detector/ModelStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ModelStatus>)))
  "Returns md5sum for a message object of type '<ModelStatus>"
  "6f51fe3ba1a4dacfef45b8036b90a8d3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ModelStatus)))
  "Returns md5sum for a message object of type 'ModelStatus"
  "6f51fe3ba1a4dacfef45b8036b90a8d3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ModelStatus>)))
  "Returns full string definition for message of type '<ModelStatus>"
  (cl:format cl:nil "Header 								header~%string                              model~%bool                             loaded~%bool                             active~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ModelStatus)))
  "Returns full string definition for message of type 'ModelStatus"
  (cl:format cl:nil "Header 								header~%string                              model~%bool                             loaded~%bool                             active~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ModelStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'model))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ModelStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'ModelStatus
    (cl:cons ':header (header msg))
    (cl:cons ':model (model msg))
    (cl:cons ':loaded (loaded msg))
    (cl:cons ':active (active msg))
))
