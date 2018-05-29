; Auto-generated. Do not edit!


(cl:in-package ferns_detector-msg)


;//! \htmlinclude Detection.msg.html

(cl:defclass <Detection> (roslisp-msg-protocol:ros-message)
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
   (top_left
    :reader top_left
    :initarg :top_left
    :type ferns_detector-msg:DetectedPoint
    :initform (cl:make-instance 'ferns_detector-msg:DetectedPoint))
   (top_right
    :reader top_right
    :initarg :top_right
    :type ferns_detector-msg:DetectedPoint
    :initform (cl:make-instance 'ferns_detector-msg:DetectedPoint))
   (bottom_right
    :reader bottom_right
    :initarg :bottom_right
    :type ferns_detector-msg:DetectedPoint
    :initform (cl:make-instance 'ferns_detector-msg:DetectedPoint))
   (bottom_left
    :reader bottom_left
    :initarg :bottom_left
    :type ferns_detector-msg:DetectedPoint
    :initform (cl:make-instance 'ferns_detector-msg:DetectedPoint)))
)

(cl:defclass Detection (<Detection>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Detection>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Detection)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ferns_detector-msg:<Detection> is deprecated: use ferns_detector-msg:Detection instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:header-val is deprecated.  Use ferns_detector-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'model-val :lambda-list '(m))
(cl:defmethod model-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:model-val is deprecated.  Use ferns_detector-msg:model instead.")
  (model m))

(cl:ensure-generic-function 'top_left-val :lambda-list '(m))
(cl:defmethod top_left-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:top_left-val is deprecated.  Use ferns_detector-msg:top_left instead.")
  (top_left m))

(cl:ensure-generic-function 'top_right-val :lambda-list '(m))
(cl:defmethod top_right-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:top_right-val is deprecated.  Use ferns_detector-msg:top_right instead.")
  (top_right m))

(cl:ensure-generic-function 'bottom_right-val :lambda-list '(m))
(cl:defmethod bottom_right-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:bottom_right-val is deprecated.  Use ferns_detector-msg:bottom_right instead.")
  (bottom_right m))

(cl:ensure-generic-function 'bottom_left-val :lambda-list '(m))
(cl:defmethod bottom_left-val ((m <Detection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:bottom_left-val is deprecated.  Use ferns_detector-msg:bottom_left instead.")
  (bottom_left m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Detection>) ostream)
  "Serializes a message object of type '<Detection>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'model))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'model))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'top_left) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'top_right) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'bottom_right) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'bottom_left) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Detection>) istream)
  "Deserializes a message object of type '<Detection>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'model) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'model) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'top_left) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'top_right) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'bottom_right) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'bottom_left) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Detection>)))
  "Returns string type for a message object of type '<Detection>"
  "ferns_detector/Detection")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Detection)))
  "Returns string type for a message object of type 'Detection"
  "ferns_detector/Detection")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Detection>)))
  "Returns md5sum for a message object of type '<Detection>"
  "32608db182e57959f8cbb42d13b3f08c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Detection)))
  "Returns md5sum for a message object of type 'Detection"
  "32608db182e57959f8cbb42d13b3f08c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Detection>)))
  "Returns full string definition for message of type '<Detection>"
  (cl:format cl:nil "Header 								header~%string                              model~%DetectedPoint 						top_left~%DetectedPoint 						top_right~%DetectedPoint 						bottom_right~%DetectedPoint 						bottom_left~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ferns_detector/DetectedPoint~%int32 												  x~%int32 													y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Detection)))
  "Returns full string definition for message of type 'Detection"
  (cl:format cl:nil "Header 								header~%string                              model~%DetectedPoint 						top_left~%DetectedPoint 						top_right~%DetectedPoint 						bottom_right~%DetectedPoint 						bottom_left~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ferns_detector/DetectedPoint~%int32 												  x~%int32 													y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Detection>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'model))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'top_left))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'top_right))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'bottom_right))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'bottom_left))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Detection>))
  "Converts a ROS message object to a list"
  (cl:list 'Detection
    (cl:cons ':header (header msg))
    (cl:cons ':model (model msg))
    (cl:cons ':top_left (top_left msg))
    (cl:cons ':top_right (top_right msg))
    (cl:cons ':bottom_right (bottom_right msg))
    (cl:cons ':bottom_left (bottom_left msg))
))
