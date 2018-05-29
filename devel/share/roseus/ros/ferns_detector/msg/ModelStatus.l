;; Auto-generated. Do not edit!


(when (boundp 'ferns_detector::ModelStatus)
  (if (not (find-package "FERNS_DETECTOR"))
    (make-package "FERNS_DETECTOR"))
  (shadow 'ModelStatus (find-package "FERNS_DETECTOR")))
(unless (find-package "FERNS_DETECTOR::MODELSTATUS")
  (make-package "FERNS_DETECTOR::MODELSTATUS"))

(in-package "ROS")
;;//! \htmlinclude ModelStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ferns_detector::ModelStatus
  :super ros::object
  :slots (_header _model _loaded _active ))

(defmethod ferns_detector::ModelStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:model __model) "")
    ((:loaded __loaded) nil)
    ((:active __active) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _model (string __model))
   (setq _loaded __loaded)
   (setq _active __active)
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
  (:loaded
   (&optional __loaded)
   (if __loaded (setq _loaded __loaded)) _loaded)
  (:active
   (&optional __active)
   (if __active (setq _active __active)) _active)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _model
    4 (length _model)
    ;; bool _loaded
    1
    ;; bool _active
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _model
       (write-long (length _model) s) (princ _model s)
     ;; bool _loaded
       (if _loaded (write-byte -1 s) (write-byte 0 s))
     ;; bool _active
       (if _active (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _model
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _model (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _loaded
     (setq _loaded (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _active
     (setq _active (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ferns_detector::ModelStatus :md5sum-) "6f51fe3ba1a4dacfef45b8036b90a8d3")
(setf (get ferns_detector::ModelStatus :datatype-) "ferns_detector/ModelStatus")
(setf (get ferns_detector::ModelStatus :definition-)
      "Header 								header
string                              model
bool                             loaded
bool                             active

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

")



(provide :ferns_detector/ModelStatus "6f51fe3ba1a4dacfef45b8036b90a8d3")


