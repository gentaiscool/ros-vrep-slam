;; Auto-generated. Do not edit!


(when (boundp 'ferns_detector::Detection)
  (if (not (find-package "FERNS_DETECTOR"))
    (make-package "FERNS_DETECTOR"))
  (shadow 'Detection (find-package "FERNS_DETECTOR")))
(unless (find-package "FERNS_DETECTOR::DETECTION")
  (make-package "FERNS_DETECTOR::DETECTION"))

(in-package "ROS")
;;//! \htmlinclude Detection.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ferns_detector::Detection
  :super ros::object
  :slots (_header _model _top_left _top_right _bottom_right _bottom_left ))

(defmethod ferns_detector::Detection
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:model __model) "")
    ((:top_left __top_left) (instance ferns_detector::DetectedPoint :init))
    ((:top_right __top_right) (instance ferns_detector::DetectedPoint :init))
    ((:bottom_right __bottom_right) (instance ferns_detector::DetectedPoint :init))
    ((:bottom_left __bottom_left) (instance ferns_detector::DetectedPoint :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _model (string __model))
   (setq _top_left __top_left)
   (setq _top_right __top_right)
   (setq _bottom_right __bottom_right)
   (setq _bottom_left __bottom_left)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:model
   (&optional __model)
   (if __model (setq _model __model)) _model)
  (:top_left
   (&rest __top_left)
   (if (keywordp (car __top_left))
       (send* _top_left __top_left)
     (progn
       (if __top_left (setq _top_left (car __top_left)))
       _top_left)))
  (:top_right
   (&rest __top_right)
   (if (keywordp (car __top_right))
       (send* _top_right __top_right)
     (progn
       (if __top_right (setq _top_right (car __top_right)))
       _top_right)))
  (:bottom_right
   (&rest __bottom_right)
   (if (keywordp (car __bottom_right))
       (send* _bottom_right __bottom_right)
     (progn
       (if __bottom_right (setq _bottom_right (car __bottom_right)))
       _bottom_right)))
  (:bottom_left
   (&rest __bottom_left)
   (if (keywordp (car __bottom_left))
       (send* _bottom_left __bottom_left)
     (progn
       (if __bottom_left (setq _bottom_left (car __bottom_left)))
       _bottom_left)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _model
    4 (length _model)
    ;; ferns_detector/DetectedPoint _top_left
    (send _top_left :serialization-length)
    ;; ferns_detector/DetectedPoint _top_right
    (send _top_right :serialization-length)
    ;; ferns_detector/DetectedPoint _bottom_right
    (send _bottom_right :serialization-length)
    ;; ferns_detector/DetectedPoint _bottom_left
    (send _bottom_left :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _model
       (write-long (length _model) s) (princ _model s)
     ;; ferns_detector/DetectedPoint _top_left
       (send _top_left :serialize s)
     ;; ferns_detector/DetectedPoint _top_right
       (send _top_right :serialize s)
     ;; ferns_detector/DetectedPoint _bottom_right
       (send _bottom_right :serialize s)
     ;; ferns_detector/DetectedPoint _bottom_left
       (send _bottom_left :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _model
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _model (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; ferns_detector/DetectedPoint _top_left
     (send _top_left :deserialize buf ptr-) (incf ptr- (send _top_left :serialization-length))
   ;; ferns_detector/DetectedPoint _top_right
     (send _top_right :deserialize buf ptr-) (incf ptr- (send _top_right :serialization-length))
   ;; ferns_detector/DetectedPoint _bottom_right
     (send _bottom_right :deserialize buf ptr-) (incf ptr- (send _bottom_right :serialization-length))
   ;; ferns_detector/DetectedPoint _bottom_left
     (send _bottom_left :deserialize buf ptr-) (incf ptr- (send _bottom_left :serialization-length))
   ;;
   self)
  )

(setf (get ferns_detector::Detection :md5sum-) "32608db182e57959f8cbb42d13b3f08c")
(setf (get ferns_detector::Detection :datatype-) "ferns_detector/Detection")
(setf (get ferns_detector::Detection :definition-)
      "Header 								header
string                              model
DetectedPoint 						top_left
DetectedPoint 						top_right
DetectedPoint 						bottom_right
DetectedPoint 						bottom_left

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: ferns_detector/DetectedPoint
int32 												  x
int32 													y

")



(provide :ferns_detector/Detection "32608db182e57959f8cbb42d13b3f08c")


