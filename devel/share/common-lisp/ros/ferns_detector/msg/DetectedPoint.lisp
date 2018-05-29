; Auto-generated. Do not edit!


(cl:in-package ferns_detector-msg)


;//! \htmlinclude DetectedPoint.msg.html

(cl:defclass <DetectedPoint> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:integer
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:integer
    :initform 0))
)

(cl:defclass DetectedPoint (<DetectedPoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DetectedPoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DetectedPoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ferns_detector-msg:<DetectedPoint> is deprecated: use ferns_detector-msg:DetectedPoint instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <DetectedPoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:x-val is deprecated.  Use ferns_detector-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <DetectedPoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ferns_detector-msg:y-val is deprecated.  Use ferns_detector-msg:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DetectedPoint>) ostream)
  "Serializes a message object of type '<DetectedPoint>"
  (cl:let* ((signed (cl:slot-value msg 'x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DetectedPoint>) istream)
  "Deserializes a message object of type '<DetectedPoint>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DetectedPoint>)))
  "Returns string type for a message object of type '<DetectedPoint>"
  "ferns_detector/DetectedPoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DetectedPoint)))
  "Returns string type for a message object of type 'DetectedPoint"
  "ferns_detector/DetectedPoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DetectedPoint>)))
  "Returns md5sum for a message object of type '<DetectedPoint>"
  "bd7b43fd41d4c47bf5c703cc7d016709")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DetectedPoint)))
  "Returns md5sum for a message object of type 'DetectedPoint"
  "bd7b43fd41d4c47bf5c703cc7d016709")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DetectedPoint>)))
  "Returns full string definition for message of type '<DetectedPoint>"
  (cl:format cl:nil "int32 												  x~%int32 													y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DetectedPoint)))
  "Returns full string definition for message of type 'DetectedPoint"
  (cl:format cl:nil "int32 												  x~%int32 													y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DetectedPoint>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DetectedPoint>))
  "Converts a ROS message object to a list"
  (cl:list 'DetectedPoint
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
