
(cl:in-package :asdf)

(defsystem "ferns_detector-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DetectedPoint" :depends-on ("_package_DetectedPoint"))
    (:file "_package_DetectedPoint" :depends-on ("_package"))
    (:file "Detection" :depends-on ("_package_Detection"))
    (:file "_package_Detection" :depends-on ("_package"))
    (:file "ModelStatus" :depends-on ("_package_ModelStatus"))
    (:file "_package_ModelStatus" :depends-on ("_package"))
  ))